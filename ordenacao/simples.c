#include "simples.h"

/*
Keven Eduardo Vaz Bilibio
05/05/2025
Trabalho de Estruturas de Dados
Arquivo simples.c
Possui o codigo principal do arquivo de ordenacao,
    com os algoritimos de ordenacao simples
*/

void bolha(int array[], int tamArray) {
    int i, j;

    for (i = 0; i < tamArray - 1; i++) {
        for (j = 0; j < tamArray - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void bolha_disp(Disp array[], int tamArray) {
    int i, j;
    int trocas;

    for (i = 0; i < tamArray - 1; i++) {
        trocas = 0;

        for (j = 0; j < tamArray - i - 1; j++) {
            if (strcmp(array[j].ip, array[j + 1].ip) > 0) {
                swap_disp(&array[j], &array[j + 1]);
                trocas = 1;
            }
        }

        if (trocas == 0) break;
    }
}

void selecao(int array[], int tamanho) {
    int i, j, minIdx;

    for (i = 0; i < tamanho - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < tamanho; j++) {
            if (array[j] < array[minIdx]) {
                minIdx = j;
            }
        }
        swap(&array[minIdx], &array[i]);
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