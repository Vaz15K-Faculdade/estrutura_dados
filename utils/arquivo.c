#include "arquivo.h"

static void alocar_strings_dispositivo(Disp *dispositivo, const char *nome, const char *tipo) {
    dispositivo->nome = (char *)malloc(strlen(nome) + 1);

    if (dispositivo->nome == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nome do dispositivo\n");
        exit(EXIT_FAILURE);
    }
    strcpy(dispositivo->nome, nome);

    dispositivo->tipo = (char *)malloc(strlen(tipo) + 1);

    if (dispositivo->tipo == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o tipo do dispositivo\n");
        free(dispositivo->nome);
        exit(EXIT_FAILURE);
    }
    strcpy(dispositivo->tipo, tipo);
}

int ler_arquivo(const char *nomeArquivo, Disp dispositivos[]) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Arquivo nao encontrado, Criando...");
        return 0;
    }

    char buffer[TAMANHO_BUFFER];
    int count = 0;

    // if (fgets(buffer, TAMANHO_BUFFER, arquivo) == NULL) {
    //     fclose(arquivo);
    //     return 0;
    // }

    while (fgets(buffer, TAMANHO_BUFFER, arquivo) && count < MAX_DISPOSITIVOS) {
        char tempNome[TAMANHO_BUFFER], tempTipo[TAMANHO_BUFFER], tempStatus[10];

        if (sscanf(buffer, "%d;%[^;];%[^;];%[^;];%f;%d",
            &dispositivos[count].id,
            tempNome,
            &dispositivos[count].ip,
            tempTipo,
            &dispositivos[count].consumoBanda,
            &dispositivos[count].status) != 6)
        {
            continue;
        }

        alocar_strings_dispositivo(&dispositivos[count], tempNome, tempTipo);

        count ++;
    }

    fclose(arquivo);
    return count;
}

void salvar_arquivo(const char *nomeArquivo, Disp dispositivos[], int numDispositivos){
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo...");
        return;
    }

    // fprintf(arquivo, "id;nome;ip;tipo;consumoBanda;status\n");

    for (int i = 0; i < numDispositivos; i++) {
        fprintf(arquivo, "%d;%s;%s;%s;%.2f;%d\n",
                dispositivos[i].id,
                dispositivos[i].nome,
                dispositivos[i].ip,
                dispositivos[i].tipo,
                dispositivos[i].consumoBanda,
                dispositivos[i].status);
    }

    fclose(arquivo);
    return;
}
