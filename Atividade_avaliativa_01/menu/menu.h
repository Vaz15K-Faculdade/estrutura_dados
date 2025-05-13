#ifndef MENU_H
#define MENU_H

/*
Keven Eduardo Vaz Bilibio 
05/05/2025
Trabalho de Estruturas de Dados
Arquivo menu.h
Possui as importações do menu principal do programa,
    referente ao menu.c
*/

#include <stdio.h>
#include "utils/arquivo.h"
#include "busca/busca.h"
#include "busca/filtro.h"
#include "ordenacao/avancado.h"

extern const char *arquivo;

void menu_cad_disp(Disp listaDisp[], int *numDisp);
void menu_list_dev(Disp listaDisp[], int numDisp);
void menu_busca_ip(Disp listaDisp[], int numDisp);
void menu_ordenacao(Disp listaDisp[], int numDisp);
void menu_filtro(Disp listaDisp[], int numDisp);
void menu_anomalias(Disp listaDisp[], int numDisp);
void menu_resumo(Disp listaDisp[], int numDisp);
void menu(Disp listaDisp[]);

#endif /* MENU_H */