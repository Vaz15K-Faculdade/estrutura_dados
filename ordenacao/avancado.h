#ifndef AVANCADO_H
#define AVANCADO_H

/*
Keven Eduardo Vaz Bilibio
05/05/2025
Trabalho de Estruturas de Dados
Arquivo avancado.h
Possui as inpotações do arquivo avancado.c
    referente as funções de ordenação avançadas/sofisticadas
*/

#include <stdio.h>
#include <stdlib.h>

#include "utils/utils.h"

void merge_sort_consumo_banda(Disp array[], int esquerda, int direita);
void quick_sort_tipo(Disp array[], int comeco, int fim);

#endif /* AVANCADO_H */