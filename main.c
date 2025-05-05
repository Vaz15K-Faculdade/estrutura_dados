#include <stdio.h>
#include "menu/menu.h"

/*
Keven Eduardo Vaz Bilibio
05/05/2025
Trabalho de Estruturas de Dados
Arquivo main.c
Possui o codigo principal do programa,
    com a função main
*/

const char *arquivo = "dispositivos.csv";

int main(){
    Disp dispositivos[MAX_DISPOSITIVOS];

    ler_arquivo(arquivo, dispositivos);

    menu(dispositivos);

    return 0;
}