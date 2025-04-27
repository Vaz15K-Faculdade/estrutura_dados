#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

void limpar_buffer();
void swap(int *a, int *b);
void swap_disp(Disp *a, Disp *b);

void alocar_inteiro(int **array, int tamanho);
void alocar_float(float **array, int tamanho);
void alocar_char(char **array, int tamanho);

#endif