#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

void limpar_buffer();
void swap(int *a, int *b);

void alocar_memoria(int **array, int tamanho);
void liberar_memoria(int **array);

#endif