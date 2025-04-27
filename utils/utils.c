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

void swap_disp(Disp *a, Disp *b) {
    Disp temp = *a;
    *a = *b;
    *b = temp;
}

void alocar_inteiro(int **array, int tamanho) {
    *array = (int *)malloc(tamanho * sizeof(int));

    if (*array == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
}

void alocar_float(float **array, int tamanho) {
    *array = (float *)malloc(tamanho * sizeof(float));

    if (*array == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
}

void alocar_char(char **array, int tamanho) {
    *array = (char *)malloc(tamanho * sizeof(char));

    if (*array == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
}
