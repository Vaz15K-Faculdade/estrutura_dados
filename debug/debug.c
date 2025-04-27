#include "debug.h"

void mostrar_array(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}
