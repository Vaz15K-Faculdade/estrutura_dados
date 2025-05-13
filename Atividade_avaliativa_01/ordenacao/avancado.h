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

#include "utils/arquivo.h"

void merge_sort_consumo_banda(Disp array[], int esquerda, int direita);
void quick_sort_tipo(Disp array[], int comeco, int fim);
void quick_sort_tipo_prioritario(Disp array[], int comeco, int fim, char *tipo_prioritario);

#endif /* AVANCADO_H */