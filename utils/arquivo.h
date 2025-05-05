#ifndef ARQUIVO_H
#define ARQUIVO_H

/*
Keven Eduardo Vaz Bilibio
05/05/2025
Trabalho de Estruturas de Dados
Arquivo arquivo.h
Possui as inpotações do arquivo arquivo.c
    referente as funções de leitura e escrita de arquivos
*/

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