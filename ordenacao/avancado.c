#include "avancado.h"
#include "utils/utils.h"
#include <stdlib.h>
#include <string.h>

/*
Keven Eduardo Vaz Bilibio 
05/05/2025
Trabalho de Estruturas de Dados
Arquivo avancado.c
Possui o codigo principal do arquivo de ordenacao,
    com os algoritimos de ordenacao avançados/sofisticados
*/

// Quick Sort
int partition(Disp array[], int comeco, int fim) {
    char *pivot = array[fim].tipo;
    int i = comeco - 1;

    for (int j = comeco; j < fim; j++) {
        if (strcmp(array[j].tipo, pivot) < 0) { // > (Z-A), < (A-Z)
            i++;
            swap_disp(&array[i], &array[j]);
        }
    }
    swap_disp(&array[i + 1], &array[fim]);
    return i + 1;
}

void quick_sort_tipo(Disp array[], int comeco, int fim) {
    if (comeco < fim) {
        int p = partition(array, comeco, fim);

        quick_sort_tipo(array, comeco, p - 1);
        quick_sort_tipo(array, p + 1, fim);
    }
}

// Quick Sort com tipo prioritário
int partition_prioritario(Disp array[], int comeco, int fim, char *tipo_prioritario) {
    char *pivot = array[fim].tipo;
    int i = comeco - 1;

    for (int j = comeco; j < fim; j++) {
        // Prioriza o tipo escolhido, depois ordena alfabeticamente
        if (strcmp(array[j].tipo, tipo_prioritario) == 0 && strcmp(array[fim].tipo, tipo_prioritario) != 0) {
            // Se elemento atual é do tipo prioritário e o pivot não, o elemento atual vem primeiro
            i++;
            swap_disp(&array[i], &array[j]);
        } else if (strcmp(array[j].tipo, tipo_prioritario) != 0 && strcmp(array[fim].tipo, tipo_prioritario) == 0) {
            // Se pivot é do tipo prioritário e o elemento atual não, não troca
            continue;
        } else if (strcmp(array[j].tipo, pivot) < 0) {
            // Se ambos são do mesmo tipo (prioritário ou não), ordena alfabeticamente
            i++;
            swap_disp(&array[i], &array[j]);
        }
    }
    swap_disp(&array[i + 1], &array[fim]);
    return i + 1;
}

void quick_sort_tipo_prioritario(Disp array[], int comeco, int fim, char *tipo_prioritario) {
    if (comeco < fim) {
        int p = partition_prioritario(array, comeco, fim, tipo_prioritario);

        quick_sort_tipo_prioritario(array, comeco, p - 1, tipo_prioritario);
        quick_sort_tipo_prioritario(array, p + 1, fim, tipo_prioritario);
    }
}

// Merge Sort Para Consumo de Banda
// Divide o array em duas metades, ordena cada metade
// Depois mescla as duas metades ordenadas
void merge(Disp array[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    float *L, *R;

    alocar_float(&L, n1);
    alocar_float(&R, n2);

    for (i = 0; i < n1; i++)
        L[i] = array[esquerda + i].consumoBanda;
    for (j = 0; j < n2; j++)
        R[j] = array[meio + 1 + j].consumoBanda;

    i = 0;
    j = 0;
    k = esquerda;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k].consumoBanda = L[i];
            i++;
        } else {
            array[k].consumoBanda = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k].consumoBanda = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k].consumoBanda = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort_consumo_banda(Disp array[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        merge_sort_consumo_banda(array, esquerda, meio);
        merge_sort_consumo_banda(array, meio + 1, direita);

        merge(array, esquerda, meio, direita);
    }
}
