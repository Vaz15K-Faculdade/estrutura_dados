#include "busca.h"
#include "ordenacao/simples.h"

/*
Keven Eduardo Vaz Bilibio 
05/05/2025
Trabalho de Estruturas de Dados
Arquivo busca.c
Possui o codigo principal do arquivo de busca,
    com os algoritimos de busca,
    referente as funções de busca de dispositivos
*/

void busca_sequencial_ip(Disp array[], int tamArray, char *strIp) {
    int i;
    int encontrado = 0;

    bolha_disp(array, tamArray);

    for (i = 0; i < tamArray; i++) {
        if (strcmp(array[i].ip, strIp) == 0) {
            printf("Dispositivo encontrado:\n");
            printf("IP: %s\n", array[i].ip);
            printf("Nome: %s\n", array[i].nome);
            printf("Tipo: %s\n", array[i].tipo);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Dispositivo com IP %s não encontrado.\n", strIp);
    }
}

void busca_binaria_ip(Disp array[], int tamArray, char *strIp) {
    int inicio = 0, encontrado = 0;
    int fim = tamArray - 1;
    int meio;

    bolha_disp(array, tamArray);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        
        int comparacao = strcmp(array[meio].ip, strIp);
        
        if (comparacao == 0) {
            printf("Dispositivo encontrado:\n");
            printf("IP: %s\n", array[meio].ip);
            printf("Nome: %s\n", array[meio].nome);
            printf("Tipo: %s\n", array[meio].tipo);
            encontrado = 1;
            break;
        } else if (comparacao < 0) {
            // IP está na metade direita
            inicio = meio + 1;
        } else {
            // IP está na metade esquerda
            fim = meio - 1;
        }
    }
    
    if (!encontrado) {
        printf("Dispositivo com IP %s não encontrado.\n", strIp);
    }
}

