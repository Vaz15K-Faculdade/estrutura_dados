#include "utils.h"

/*
Keven Eduardo Vaz Bilibio
05/05/2025
Trabalho de Estruturas de Dados
Arquivo utils.c
Possui o codigo principal do arquivo de utilidades,
    com as funções comuns que sao ultilizadas mais vezes no programa
*/

void limpar_buffer() {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
    return;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_disp(Disp *a, Disp *b) {
    Disp temp = *a;
    *a = *b;
    *b = temp;
}

void alocar_float(float **array, int tamanho) {
    *array = (float *)malloc(tamanho * sizeof(float));

    if (*array == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
}
