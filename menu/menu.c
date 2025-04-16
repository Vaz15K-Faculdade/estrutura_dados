#include "menu.h"
#include "../ordenacao/simple_alg.h"
#include "../ordenacao/advanced_alg.h"
#include "../utils/utils.h"

void menu() {
    int *d;
    int opc, tamanho, modo_entrada, valor_max;
    
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    alocar(&d, tamanho);
    
    printf("Escolha o modo de entrada:\n");
    printf("1 - Informar valores manualmente\n");
    printf("2 - Gerar valores aleatórios\n");
    scanf("%d", &modo_entrada);
    
    switch(modo_entrada) {
        case 1:
            informar(d, tamanho);
            break;
        case 2:
            printf("Informe o valor máximo a ser gerado: ");
            scanf("%d", &valor_max);
            gerar_aleatorio(d, tamanho, valor_max);
            break;
        default:
            printf("Opção inválida! Usando entrada manual.\n");
            informar(d, tamanho);
    }

    printf("\nInforme o metodo de ordenacao:\n");
    printf("1 - Bolha\n");
    printf("2 - Seleção\n");
    printf("3 - Inserção\n");
    printf("4 - QuickSort\n");
    printf("5 - MergeSort\n");
    printf("0 - Sair\n");
    
    scanf("%i", &opc);
    
    switch (opc) {
        case 1:
            printf("Desordenado: ");
            mostrar_vetor(d, tamanho);
            
            bolha(d, tamanho);
            
            printf("Ordenado: ");
            mostrar_vetor(d, tamanho);
            break;
            
        case 2:
            printf("Desordenado: ");
            mostrar_vetor(d, tamanho);
            
            selecao(d, tamanho);
            
            printf("Ordenado: ");
            mostrar_vetor(d, tamanho);
            break;
            
        case 3:
            printf("Desordenado: ");
            mostrar_vetor(d, tamanho);
            
            insercao(d, tamanho);
            
            printf("Ordenado: ");
            mostrar_vetor(d, tamanho);
            break;
        
        case 4:
            printf("Desordenado: ");
            mostrar_vetor(d, tamanho);
            
            quickSort(d, 0, tamanho-1);
            
            printf("Ordenado: ");
            mostrar_vetor(d, tamanho);
            break;
            
        case 5:
            printf("Desordenado: ");
            mostrar_vetor(d, tamanho);
            
            mergeSort(d, 0, tamanho-1);
            
            printf("Ordenado: ");
            mostrar_vetor(d, tamanho);
            break;
            
        case 0:
            printf("Saindo...\n");
            break;
            
        default:
            printf("Opção inválida!\n");
    }

    free(d);
}