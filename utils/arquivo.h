#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DISPOSITIVOS 100
#define TAMANHO_BUFFER 256

typedef struct {
    int id;
    char *nome;
    char ip[16];
    char *tipo;
    float consumoBanda;
    int status;
} Disp;

extern const char *arquivo;

int ler_arquivo(const char *nome_arquivo, Disp dispositivos[]);
void salvar_arquivo(const char *nome_arquivo, Disp dispositivos[], int num_dispositivos);

#endif /* ARQUIVO_H */