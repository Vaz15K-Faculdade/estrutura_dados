#ifndef BUSCA_H
#define BUSCA_H

/*
Keven Eduardo Vaz Bilibio 
05/05/2025
Trabalho de Estruturas de Dados
Arquivo busca.h
Possui as inpotações do arquivo busca.c
    referente as funções de busca de dispositivos
*/

#include "utils/arquivo.h"

void busca_sequencial_ip(Disp array[], int tamArray, char *strIp);
void busca_binaria_ip(Disp array[], int tamArray, char *strIp);

#endif /* BUSCA_H */