#include<unistd.h>

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

void menu_cad_disp(Disp listaDisp[]) {
    char nome[TAMANHO_BUFFER], ip[16], tipo[TAMANHO_BUFFER];
    float consumoBanda;
    int status;

    int numDisp = ler_arquivo(arquivo, listaDisp);

    printf("Informe o nome:\n");
    scanf("%s", nome);
    limpar_buffer();

    printf("Informe o IP:\n");
    scanf("%s", ip);
    limpar_buffer();

    int opcao;
    do{
        printf("Informe o tipo\n");
        printf("1 - Computador | 2 - Notebook\n");
        printf("3 - Roteador   | 4 - Switch\n");
        printf("5 - Impressora | 6 - Smart TV\n");
        printf("7 - Telefone   | 8 - Tablet\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1: strcpy(tipo, "Computador"); break;
        case 2: strcpy(tipo, "Notebook"); break;
        case 3: strcpy(tipo, "Roteador"); break;
        case 4: strcpy(tipo, "Switch"); break;
        case 5: strcpy(tipo, "Impressora"); break;
        case 6: strcpy(tipo, "Smart TV"); break;
        case 7: strcpy(tipo, "Celular"); break;
        case 8: strcpy(tipo, "Tablet"); break;
        default:
            printf("Opção Invalida\n");
        }
    } while (opcao < 1 || opcao > 8);

    printf("Informe o Consumo de Banda (MB/s):\n");
    scanf("%f", &consumoBanda);
    limpar_buffer();

    printf("Informe status do dispositivo\n");
    printf("0 - Desativado | 1 - Ativo\n");
    scanf("%d", &status);

    // Adicionando um novo dispositivo ao final do array
    int novoId = (numDisp > 0) ? listaDisp[numDisp-1].id + 1 : 1;

    listaDisp[numDisp].nome = (char*)malloc((strlen(nome) + 1) * sizeof(char));
    listaDisp[numDisp].tipo = (char*)malloc((strlen(tipo) + 1) * sizeof(char));

    listaDisp[numDisp].id = novoId;
    strcpy(listaDisp[numDisp].nome, nome);
    strcpy(listaDisp[numDisp].ip, ip);
    strcpy(listaDisp[numDisp].tipo, tipo);
    listaDisp[numDisp].consumoBanda = consumoBanda;
    listaDisp[numDisp].status = status;

    numDisp++;
    salvar_arquivo(arquivo, listaDisp, numDisp);

    return;
}

void menu_list_dev(Disp listaDisp[]) {
    int numDisp = ler_arquivo(arquivo, listaDisp);
    int dispositivosAtivos = 0;

    printf("\n===== DISPOSITIVOS ATIVOS =====\n");
    printf("ID | Nome | IP | Tipo | Consumo (MB/s)\n");
    printf("----------------------------------\n");

    for (int i = 0; i < numDisp; i++) {
        if (listaDisp[i].status == 1) {
            printf("%d | %s | %s | %s | %.2f\n", 
                listaDisp[i].id, 
                listaDisp[i].nome, 
                listaDisp[i].ip, 
                listaDisp[i].tipo, 
                listaDisp[i].consumoBanda);
            dispositivosAtivos++;
        }
    }

    if (dispositivosAtivos == 0) {
        printf("Nenhum dispositivo ativo encontrado.\n");
    }

    printf("\nTotal de dispositivos ativos: %d\n", dispositivosAtivos);
    printf("===========================\n\n");

    sleep(3);

    return;
}

void menu_busca_ip(Disp listaDisp[]) {
    int opcao;
    char ip[16];

    printf("Informe como deseja buscar:\n");
    printf("1 - Busca Sequencial | 2 - Busca Binaria\n");
    scanf("%d", &opcao);
    limpar_buffer();

    printf("Informe o IP que dejesa buscar: ");
    scanf("%s", ip);
    limpar_buffer();

    (opcao == 1) ? busca_sequencial_ip(listaDisp, ler_arquivo(arquivo, listaDisp), ip) : busca_binaria_ip(listaDisp, ler_arquivo(arquivo, listaDisp), ip);

    return;
}

void menu_ordenacao(Disp listaDisp[]) {
    int opcao;
    int numDisp = ler_arquivo(arquivo, listaDisp);

    printf("Informe como deseja ordernar:\n");
    printf("1 - Endereco de IP | 2 - Consumo de banda\n");
    printf("3 - Tipo de dispositivo\n");
    scanf("%d", &opcao);
    limpar_buffer();

    if (opcao == 1)
        bolha_disp(listaDisp, numDisp);
    else if (opcao == 2)
        merge_sort_consumo_banda(listaDisp, 0, numDisp - 1);
    else
        quick_sort_tipo(listaDisp, 0, numDisp - 1);

    return;
}

void menu_filtro(Disp listaDisp[]) {
    int opcao;
    int numDisp = ler_arquivo(arquivo, listaDisp);

    do{
        printf("Informe como deseja filtrar\n");
        printf("1 - Computador | 2 - Notebook\n");
        printf("3 - Roteador   | 4 - Switch\n");
        printf("5 - Impressora | 6 - Smart TV\n");
        printf("7 - Telefone   | 8 - Tablet\n");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
        case 1: filtrar_disp(listaDisp, numDisp, "Computador"); break;
        case 2: filtrar_disp(listaDisp, numDisp, "Notebook"); break;
        case 3: filtrar_disp(listaDisp, numDisp, "Roteador"); break;
        case 4: filtrar_disp(listaDisp, numDisp, "Switch"); break;
        case 5: filtrar_disp(listaDisp, numDisp, "Impressora"); break;
        case 6: filtrar_disp(listaDisp, numDisp, "SmartTV"); break;
        case 7: filtrar_disp(listaDisp, numDisp, "Telefone"); break;
        case 8: filtrar_disp(listaDisp, numDisp, "Tablet"); break;
        default:
            printf("Opção Invalida\n");
        }
    } while (opcao < 1 || opcao > 8);

    return;
}

void menu(Disp listaDisp[]) {
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
            case 1: menu_cad_disp(listaDisp); break;
            case 2: menu_list_dev(listaDisp); break;
            case 3: menu_busca_ip(listaDisp); break;
            case 4: menu_ordenacao(listaDisp); break;
            case 5: menu_filtro(listaDisp); break;
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