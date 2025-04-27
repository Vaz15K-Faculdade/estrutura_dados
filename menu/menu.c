#include "menu.h"

#include "utils/utils.h"

// Cadastro de dispositivos
// Listar dispositivos ativos 
// Buscar endereço ip
// Ordenação ip (alpha) - consumo (ordem decre) - tipo (alpha ou cat)
// Filtrar por tipo de dispositivo
// Detecção de anomalias
// Resumo - Numero de disp - Consumo medio - percentagem disp ativos

void menu_cad_disp() {
    return;
}

void menu_list_dev() {
    return;
}

void menu_busca_ip() {
    return;
}

void menu_ordenacao() {
    return;
}

void menu_filtro() {
    return;
}

void menu() {
    int opcao = 0;
    
    do {
        printf("Menu:\n");
        printf("1. Cadastro de dispositivos        | 2. Listar dispositivos ativos\n");
        printf("3. Buscar endereço IP              | 4. Ordenação\n");
        printf("5. Filtrar por tipo de dispositivo | 6. Detecção de anomalias\n");
        printf("7. Resumo                          | 0. Sair\n");
        scanf("%d", &opcao);

        limpar_buffer();

        switch (opcao) {
            case 1:
                menu_cad_disp();
                break;
            case 2:
                menu_list_dev();
                break;
            case 3:
                menu_busca_ip();
                break;
            case 4:
                menu_ordenacao();
                break;
            case 5:
                menu_filtro();
                break;
            case 6:
                break;
            case 7:
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}