#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>  // _getcwd
#include <limits.h>  // PATH_MAX

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Uso: %s <arquivo.c> [nome_executavel.exe]\n", argv[0]);
        return 1;
    }

    char *arquivoFonte = argv[1];
    char *nomeExecutavel = (argc == 3) ? argv[2] : "temp_exec.exe";

    char cwd[PATH_MAX];
    if (_getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("Erro ao obter diretório atual");
        return 1;
    }

    // Caminho completo do .c
    char caminhoFonte[PATH_MAX * 2];
    snprintf(caminhoFonte, sizeof(caminhoFonte), "%s\\%s", cwd, arquivoFonte);

    // Comando de compilação
    char comandoCompilar[PATH_MAX * 3];
    snprintf(comandoCompilar, sizeof(comandoCompilar), "gcc \"%s\" -o \"%s\"", caminhoFonte, nomeExecutavel);

    if (system(comandoCompilar) != 0) {
        fprintf(stderr, "Erro na compilação de %s\n", caminhoFonte);
        return 1;
    }

    // Só executa se o nome do executável não foi fornecido
    if (argc == 2) {
        char comandoExecutar[PATH_MAX];
        snprintf(comandoExecutar, sizeof(comandoExecutar), "\"%s\"", nomeExecutavel);
        system(comandoExecutar);

        // Remove após execução
        remove(nomeExecutavel);
    } else {
        printf("Executável \"%s\" gerado com sucesso.\n", nomeExecutavel);
    }

    return 0;
}
