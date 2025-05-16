#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>   // _getcwd
#include <limits.h>   // PATH_MAX

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Uso: %s <arquivo.c> [nome_executavel.exe]\n", argv[0]);
        return 1;
    }

    char *arquivoFonte = argv[1];
    char nomeExecutavel[PATH_MAX];
    int executaDepois = 1;

    if (argc == 3) {
        strncpy(nomeExecutavel, argv[2], PATH_MAX - 1);
        nomeExecutavel[PATH_MAX - 1] = '\0';
        executaDepois = 0;
    } else {
        strcpy(nomeExecutavel, "temp_exec.exe");
    }

    char cwd[PATH_MAX];
    if (_getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("Erro ao obter diretório atual");
        return 1;
    }

    char caminhoFonte[PATH_MAX * 2];
    snprintf(caminhoFonte, sizeof(caminhoFonte), "%s\\%s", cwd, arquivoFonte);

    // Comando gcc para compilar
    char comandoCompilar[PATH_MAX * 3];
    snprintf(comandoCompilar, sizeof(comandoCompilar), "gcc \"%s\" -o \"%s\"", caminhoFonte, nomeExecutavel);

    // Executar compilação (ainda no processo atual)
    if (system(comandoCompilar) != 0) {
        fprintf(stderr, "Erro na compilação de %s\n", caminhoFonte);
        return 1;
    }

    if (executaDepois) {
        // Comando para abrir nova janela, executar exe e fechar a janela ao finalizar
        // O comando cmd /c executa e fecha a janela automaticamente
        char comandoNovaJanela[PATH_MAX * 4];
        snprintf(comandoNovaJanela, sizeof(comandoNovaJanela),
                 "cmd /c start \"Execucao compilerc\" \"%s\"", nomeExecutavel);

        STARTUPINFO si = {0};
        PROCESS_INFORMATION pi = {0};
        si.cb = sizeof(si);

        if (!CreateProcess(NULL,
                           comandoNovaJanela,
                           NULL, NULL, FALSE,
                           0, NULL, NULL,
                           &si, &pi)) {
            fprintf(stderr, "Erro ao criar nova janela cmd.\n");
            return 1;
        }

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        printf("Executável \"%s\" gerado com sucesso. Não será executado automaticamente.\n", nomeExecutavel);
    }

    return 0;
}
