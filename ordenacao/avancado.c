#include "avancado.h"

// Funções Auxiliares
void merge(int array[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    int *L, *R;

    alocar_memoria(&L, n1);
    alocar_memoria(&R, n2);

    for (i = 0; i < n1; i++)
        L[i] = array[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = array[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerda;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    liberar_memoria(&L);
    liberar_memoria(&R);
}

int partition(int array[], int comeco, int fim) {
    int pivot = array[fim];
    int i = comeco - 1;

    for (int j = comeco; j < fim; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[fim]);
    return i + 1;
}
// Fim das Funções Auxiliares

// Quick Sort
void quick_sort(int array[], int comeco, int fim) {
    if (comeco < fim) {
        int p = partition(array, comeco, fim);

        quick_sort(array, comeco, p - 1);
        quick_sort(array, p + 1, fim);
    }
}

// Merge Sort
// Divide o array em duas metades, ordena cada metade
// Depois mescla as duas metades ordenadas
void merge_sort(int array[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        merge_sort(array, esquerda, meio);
        merge_sort(array, meio + 1, direita);

        merge(array, esquerda, meio, direita);
    }
}