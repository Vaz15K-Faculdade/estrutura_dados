#include "utils.h"

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

void alocar_memoria(int **array, int tamanho) {
    *array = (int *)malloc(tamanho * sizeof(int));

    if (*array == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
}

void liberar_memoria(int **array) {
    free(*array);
    *array = NULL;
}