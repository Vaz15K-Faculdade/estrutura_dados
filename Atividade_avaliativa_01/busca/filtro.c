#include "filtro.h"
#include <stdio.h>
#include <string.h>

/*
Keven Eduardo Vaz Bilibio
05/05/2025
Trabalho de Estruturas de Dados
Arquivo filtro.c
Possui o codigo principal do arquivo de filtro,
    com os algoritimos de filtro,
    referente as funções de filtro de dispositivos
*/

void filtrar_disp(Disp array[], int tamArray, char *dispositivo) {
    printf("--------------------------------------------\n");
    printf("ID | Nome | IP | Tipo | Consumo | Status\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < tamArray; i++) {
        if (strcmp(array[i].tipo, dispositivo) == 0) {
            printf("%d | %s | %s | %s | %.2f | %s\n", 
                array[i].id, 
                array[i].nome, 
                array[i].ip, 
                array[i].tipo, 
                array[i].consumoBanda,
                array[i].status ? "Ativo" : "Desativado");
        }
    }
    printf("--------------------------------------------\n");
}