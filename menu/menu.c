#include "menu.h"
#include "utils/utils.h"
#include "utils/arquivo.h"

/*
Keven Eduardo Vaz Bilibio 
05/05/2025
Trabalho de Estruturas de Dados
Arquivo menu.c
Possui o codigo do menu principal do programa
*/

// Cadastro de dispositivos
// Listar dispositivos ativos 
// Buscar endereço ip
// Ordenação ip (alpha) - consumo (ordem decre) - tipo (alpha ou cat)
// Filtrar por tipo de dispositivo
// Detecção de anomalias
// Resumo - Numero de disp - Consumo medio - percentagem disp ativos

void menu_cad_disp(Disp listaDisp[], int *numDisp) {
    char nome[TAMANHO_BUFFER], ip[16], tipo[TAMANHO_BUFFER];
    float consumoBanda;
    int status;

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
    int novoId = (*numDisp > 0) ? listaDisp[*numDisp-1].id + 1 : 1;

    listaDisp[*numDisp].nome = (char*)malloc((strlen(nome) + 1) * sizeof(char));
    listaDisp[*numDisp].tipo = (char*)malloc((strlen(tipo) + 1) * sizeof(char));

    listaDisp[*numDisp].id = novoId;
    strcpy(listaDisp[*numDisp].nome, nome);
    strcpy(listaDisp[*numDisp].ip, ip);
    strcpy(listaDisp[*numDisp].tipo, tipo);
    listaDisp[*numDisp].consumoBanda = consumoBanda;
    listaDisp[*numDisp].status = status;

    (*numDisp)++;
    salvar_arquivo(arquivo, listaDisp, *numDisp);

    return;
}

void menu_list_dev(Disp listaDisp[], int numDisp) {
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

void menu_busca_ip(Disp listaDisp[], int numDisp) {
    int opcao;
    char ip[16];

    printf("Informe como deseja buscar:\n");
    printf("1 - Busca Sequencial | 2 - Busca Binaria\n");
    scanf("%d", &opcao);
    limpar_buffer();

    printf("Informe o IP que dejesa buscar: ");
    scanf("%s", ip);
    limpar_buffer();

    (opcao == 1) ? busca_sequencial_ip(listaDisp, numDisp, ip) : busca_binaria_ip(listaDisp, numDisp, ip);

    return;
}

void menu_ordenacao(Disp listaDisp[], int numDisp) {
    int opcao;

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

void menu_filtro(Disp listaDisp[], int numDisp) {
    int opcao;

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

void menu_resumo(Disp listaDisp[], int numDisp) {
    int count = 0;
    float soma_consumo = 0, media_consumo;

    for (int i = 0; i < numDisp; i++)
        if (listaDisp[i].status == 1) {
            count++;
            soma_consumo += listaDisp[i].consumoBanda;
        }

    printf("############################################\n");
    printf("Total de dispositivos: %d\n", numDisp);
    printf("Porcentagem Dispositivos ativos: %.2f%%\n", ((float)count / numDisp) * 100);
    printf("Media Consumo de Banda dos Ativos: %.2f MB/s\n", soma_consumo / (float)count);
    printf("############################################\n");

    return;
}

void menu_anomalias(Disp listaDisp[], int numDisp){
    int i, j;
    int ipsDuplicados = 0, dispAcima = 0;
    float somaConsumo = 0;

    printf("\n===== DETECÇÃO DE ANOMALIAS =====\n");
    printf("IPs Duplicados Detectados:\n\n");

    // Procurar por IPs duplicados
    for (i = 0; i < numDisp - 1; i++) {
        somaConsumo += listaDisp[i].consumoBanda;
        for (j = i + 1; j < numDisp; j++) {
            if (strcmp(listaDisp[i].ip, listaDisp[j].ip) == 0) {
                printf("IP DUPLICADO: %s\n", listaDisp[i].ip);
                printf("  Dispositivo 1: %s (%s)\n", listaDisp[i].nome, listaDisp[i].tipo);
                printf("  Dispositivo 2: %s (%s)\n\n", listaDisp[j].nome, listaDisp[j].tipo);
                ipsDuplicados++;
            }
        }
    }

    if (ipsDuplicados == 0) printf("Nenhum IP duplicado encontrado na rede.\n");

    printf("===================================\n\n");
    printf("Dispositivos com consumo acima da media:\n");

    for (i = 0; i < numDisp - 1; i++) {
        if (listaDisp[i].consumoBanda > (somaConsumo / (float)numDisp)){
            printf("Dispositivo: %s, Consumo %.2f\n acima da media %.2f", listaDisp[i].nome, listaDisp[i].consumoBanda, (somaConsumo / (float)numDisp));
            dispAcima ++;
        }
    }

    if (dispAcima == 0) printf("Nenhum Dispositivo com consumo acima da media\n");

    printf("===================================\n\n");

    sleep(3);
    return;
}

void menu(Disp listaDisp[]) {
    int opcao = 0;
    int numDisp = ler_arquivo(arquivo, listaDisp);
    
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
                menu_cad_disp(listaDisp, &numDisp); 
                break;
            case 2: 
                menu_list_dev(listaDisp, numDisp); 
                break;
            case 3: 
                menu_busca_ip(listaDisp, numDisp); 
                break;
            case 4: 
                menu_ordenacao(listaDisp, numDisp); 
                break;
            case 5: 
                menu_filtro(listaDisp, numDisp); 
                break;
            case 6: 
                menu_anomalias(listaDisp, numDisp); 
                break;
            case 7: 
                menu_resumo(listaDisp, numDisp); 
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}