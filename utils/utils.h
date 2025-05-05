#ifndef UTILS_H
#define UTILS_H

/*
Keven Eduardo Vaz Bilibio
05/05/2025
Trabalho de Estruturas de Dados
Arquivo utils.h
Possui as inpotações do arquivo utils.c
    referente as funções de utilidades
*/

#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

void limpar_buffer();
void swap(int *a, int *b);
void swap_disp(Disp *a, Disp *b);

void alocar_float(float **array, int tamanho);

#endif