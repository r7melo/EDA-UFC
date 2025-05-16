# README - compilerc

Este projeto contém um programa em C chamado `compilerc` que compila e executa arquivos `.c` automaticamente, e pode ser usado como um comando global no Windows.

---

## Pré-requisitos

- **GCC instalado no Windows**

Você precisa ter o compilador GCC instalado e disponível no PATH para usar este projeto.

### Como verificar se o GCC está instalado e configurado no PATH

Abra o Prompt de Comando e execute:

```bash
gcc --version
```

Se aparecer a versão do GCC, está tudo certo. Caso contrário, instale o [MinGW-w64](https://www.mingw-w64.org/) ou [TDM-GCC](https://jmeubank.github.io/tdm-gcc/) e adicione o diretório `bin` do GCC ao PATH do sistema.

---

## Passo 1: Compilar o programa `compilerc`

1. Clone este repositório ou baixe o arquivo `compilerc.c`.

2. Abra o Prompt de Comando na pasta onde está o arquivo `compilerc.c`.

3. Compile com o GCC:

```bash
gcc compilerc.c -o compilerc.exe
```

---

## Passo 2: Colocar o executável na pasta `bin` do GCC

1. Localize a pasta `bin` onde o GCC está instalado. Por exemplo:  
`C:\MinGW\bin`  
ou  
`C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin`

2. Copie o arquivo `compilerc.exe` para essa pasta.

---

## Passo 3: Configurar para usar o `compilerc` globalmente

Se o diretório `bin` do GCC já estiver no PATH, o comando `compilerc` estará disponível em qualquer terminal.

Para testar, abra um novo Prompt de Comando e execute:

```bash
compilerc nome_do_arquivo.c
```

Se o seu código compilar e executar, está tudo certo!

---

## Como usar o comando `compilerc`

### Sintaxe

```bash
compilerc <arquivo.c> [nome_do_executavel.exe]
```

- `<arquivo.c>`: arquivo fonte que você quer compilar.
- `[nome_do_executavel.exe]` (opcional): se informado, o programa compila o `.c` para o `.exe` com esse nome e **não executa** automaticamente.  
Se não informado, o programa compila, executa e remove o executável temporário.

### Exemplos

- Compilar e executar, apagando o executável após:

```bash
compilerc programa.c
```

- Compilar somente e salvar o executável com nome personalizado:

```bash
compilerc programa.c meu_programa.exe
```

---

## Observações

- O programa espera que o arquivo `.c` seja informado com o caminho relativo ao diretório atual do terminal, ou caminho absoluto.
- Para garantir que o comando `compilerc` funcione globalmente, certifique-se de abrir um novo terminal após atualizar o PATH.

---

## Suporte

Se você encontrar problemas ou quiser melhorias, abra uma issue no repositório.
