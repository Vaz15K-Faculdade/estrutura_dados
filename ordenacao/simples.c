#include "simples.h"

void bolha(int array[], int tamanho) {
    int i, j;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void selecao(int array[], int tamanho) {
    int i, j, min_idx;

    for (i = 0; i < tamanho - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < tamanho; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        swap(&array[min_idx], &array[i]);
    }
}

void insercao(int array[], int tamanho) {
    int i, j, chave;

    for (i = 1; i < tamanho; i++) {
        chave = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = chave;
    }
}