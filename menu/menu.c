#include "menu.h"

#include "utils/utils.h"
#include "utils/arquivo.h"

// Cadastro de dispositivos
// Listar dispositivos ativos 
// Buscar endereço ip
// Ordenação ip (alpha) - consumo (ordem decre) - tipo (alpha ou cat)
// Filtrar por tipo de dispositivo
// Detecção de anomalias
// Resumo - Numero de disp - Consumo medio - percentagem disp ativos

void menu_cad_disp(Disp lista_disp[]) {
    char nome[TAMANHO_BUFFER], ip[16], tipo[TAMANHO_BUFFER];
    float consumoBanda;
    int status, ver = 0;

    int num_disp = ler_arquivo(arquivo, lista_disp);

    printf("Informe o nome:\n");
    scanf("%s", nome);
    limpar_buffer();

    printf("Informe o IP:\n");
    scanf("%s", ip);
    limpar_buffer();

    do{
        int opcao;
        printf("Informe o tipo\n");
        printf("1 - Computador | 2 - Notebook\n");
        printf("3 - Roteador   | 4 - Switch\n");
        printf("5 - Impressora | 6 - Smart TV\n");
        printf("7 - Telefone   | 8 - Tablet\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1: strcpy(tipo, "Computador"); ver = 1; break;
        case 2: strcpy(tipo, "Notebook"); ver = 1; break;
        case 3: strcpy(tipo, "Roteador"); ver = 1; break;
        case 4: strcpy(tipo, "Switch"); ver = 1; break;
        case 5: strcpy(tipo, "Impressora"); ver = 1; break;
        case 6: strcpy(tipo, "Smart TV"); ver = 1; break;
        case 7: strcpy(tipo, "Celular"); ver = 1; break;
        case 8: strcpy(tipo, "Tablet"); ver = 1; break;
        default:
            printf("Opção Invalida\n");
        }
    } while (ver != 1);

    printf("Informe o Consumo de Banda (MB/s):\n");
    scanf("%f", &consumoBanda);
    limpar_buffer();

    printf("Informe status do dispositivo\n");
    printf("0 - Desativado | 1 - Ativo\n");
    scanf("%d", &status);

    // Adicionando um novo dispositivo ao final do array
    int novo_id = (num_disp > 0) ? lista_disp[num_disp-1].id + 1 : 1;

    lista_disp[num_disp].nome = (char*)malloc((strlen(nome) + 1) * sizeof(char));
    lista_disp[num_disp].tipo = (char*)malloc((strlen(tipo) + 1) * sizeof(char));

    lista_disp[num_disp].id = novo_id;
    strcpy(lista_disp[num_disp].nome, nome);
    strcpy(lista_disp[num_disp].ip, ip);
    strcpy(lista_disp[num_disp].tipo, tipo);
    lista_disp[num_disp].consumoBanda = consumoBanda;
    lista_disp[num_disp].status = status;

    num_disp++;
    salvar_arquivo(arquivo, lista_disp, num_disp);

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

void menu(Disp lista_disp[]) {
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
            case 1: menu_cad_disp(lista_disp); break;
            case 2: menu_list_dev(); break;
            case 3: menu_busca_ip(); break;
            case 4: menu_ordenacao(); break;
            case 5: menu_filtro(); break;
            case 6: break;
            case 7: break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}