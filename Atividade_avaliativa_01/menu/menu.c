#include "menu.h"
#include <unistd.h>
#include "utils/utils.h"
#include "ordenacao/simples.h"

/*
Keven Eduardo Vaz Bilibio 
05/05/2025
Trabalho de Estruturas de Dados
Arquivo menu.c
Possui o codigo do menu principal do programa
*/

void menu_cad_disp(Disp listaDisp[], int *numDisp) {
    char nome[TAMANHO_BUFFER], ip[16], tipo[TAMANHO_BUFFER];
    float consumoBanda;
    int status;

    printf("===== CADASTRO DE DISPOSITIVO =====\n");
    printf("Informe o nome: ");
    scanf("%s", nome);
    limpar_buffer();

    printf("Informe o IP: ");
    scanf("%s", ip);
    limpar_buffer();

    int opcao;
    do{
        printf("Informe o tipo:\n");
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

    printf("Informe o Consumo de Banda (MB/s): ");
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

    printf("\nDispositivo cadastrado com sucesso!\n");

    return;
}

void menu_list_dev(Disp listaDisp[], int numDisp) {
    int dispositivosAtivos = 0;

    printf("=========== DISPOSITIVOS ATIVOS ===========\n");
    printf("ID | Nome | IP | Tipo | Consumo (MB/s)\n");
    printf("-------------------------------------------\n");

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

    printf("Total de dispositivos ativos: %d\n", dispositivosAtivos);
    printf("========================================\n");

    return;
}

void menu_busca_ip(Disp listaDisp[], int numDisp) {
    int opcao;
    char ip[16];

    do{
        printf("========= BUSCA POR IP =========\n");
        printf("Informe o tipo de busca:\n");
        printf("1 - Busca Sequencial | 2 - Busca Binaria\n");
        scanf("%d", &opcao);
        limpar_buffer();

        if (opcao < 1 || opcao > 2) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao < 1 || opcao > 2);

    printf("Informe o IP que dejesa buscar: ");
    scanf("%s", ip);
    limpar_buffer();

    (opcao == 1) ? busca_sequencial_ip(listaDisp, numDisp, ip) : busca_binaria_ip(listaDisp, numDisp, ip);

    return;
}

void listar_todos_dispositivos(Disp listaDisp[], int numDisp) {
    printf("============== LISTA DE DISPOSITIVOS ==============\n");
    printf("ID | Nome | IP | Tipo | Consumo (MB/s) | Status\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < numDisp; i++) {
        printf("%d | %s | %s | %s | %.2f | %s\n",
            listaDisp[i].id,
            listaDisp[i].nome,
            listaDisp[i].ip,
            listaDisp[i].tipo,
            listaDisp[i].consumoBanda,
            listaDisp[i].status ? "Ativo" : "Desativado");
    }
    printf("==================================================\n");
}

void menu_ordenacao(Disp listaDisp[], int numDisp) {
    int opcao;
    do {
        printf("===== ORDENAÇÃO DE DISPOSITIVOS =====\n");
        printf("Informe como deseja ordernar:\n");
        printf("1 - Endereco de IP        | 2 - Consumo de banda\n");
        printf("3 - Tipo de dispositivo   | 4 - Categoria prioritaria\n");
        scanf("%d", &opcao);
        limpar_buffer();
        
        if (opcao < 1 || opcao > 4) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao < 1 || opcao > 4);

    if (opcao == 1) {
        bolha_disp(listaDisp, numDisp);
        listar_todos_dispositivos(listaDisp, numDisp);
    }
    else if (opcao == 2) {
        merge_sort_consumo_banda(listaDisp, 0, numDisp - 1);
        listar_todos_dispositivos(listaDisp, numDisp);
    }
    else if (opcao == 3) {
        quick_sort_tipo(listaDisp, 0, numDisp - 1);
        listar_todos_dispositivos(listaDisp, numDisp);
    }
    else if (opcao == 4) {
        char tipo_prioritario[TAMANHO_BUFFER];
        int opcao_tipo;
        
        do {
            printf("Escolha o tipo prioritario:\n");
            printf("1 - Computador | 2 - Notebook\n");
            printf("3 - Roteador   | 4 - Switch\n");
            printf("5 - Impressora | 6 - Smart TV\n");
            printf("7 - Celular    | 8 - Tablet\n");
            scanf("%d", &opcao_tipo);
            limpar_buffer();
            
            switch (opcao_tipo) {
                case 1: strcpy(tipo_prioritario, "Computador"); break;
                case 2: strcpy(tipo_prioritario, "Notebook"); break;
                case 3: strcpy(tipo_prioritario, "Roteador"); break;
                case 4: strcpy(tipo_prioritario, "Switch"); break;
                case 5: strcpy(tipo_prioritario, "Impressora"); break;
                case 6: strcpy(tipo_prioritario, "Smart TV"); break;
                case 7: strcpy(tipo_prioritario, "Celular"); break;
                case 8: strcpy(tipo_prioritario, "Tablet"); break;
                default:
                    printf("Opção Inválida\n");
            }
        } while (opcao_tipo < 1 || opcao_tipo > 8);
        
        quick_sort_tipo_prioritario(listaDisp, 0, numDisp - 1, tipo_prioritario);
        printf("\nDispositivos ordenados com prioridade para: %s\n", tipo_prioritario);
        listar_todos_dispositivos(listaDisp, numDisp);
    }
    else {
        printf("Opção inválida!\n");
    }

    return;
}

void menu_filtro(Disp listaDisp[], int numDisp) {
    int opcao;

    do{
        printf("===== FILTRAR DISPOSITIVOS POR TIPO =====\n");
        printf("Informe como deseja filtrar:\n");
        printf("1 - Computador | 2 - Notebook\n");
        printf("3 - Roteador   | 4 - Switch\n");
        printf("5 - Impressora | 6 - Smart TV\n");
        printf("7 - Telefone   | 8 - Tablet\n");
        printf("=========================================\n");
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

    printf("################ RESUMO ################\n");
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

    printf("========= DETECÇÃO DE ANOMALIAS =========\n");
    printf("IPs Duplicados Detectados:\n");

    // Procurar por IPs duplicados
    for (i = 0; i < numDisp - 1; i++) {
        somaConsumo += listaDisp[i].consumoBanda;
        for (j = i + 1; j < numDisp; j++) {
            if (strcmp(listaDisp[i].ip, listaDisp[j].ip) == 0) {
                printf("IP DUPLICADO: %s\n", listaDisp[i].ip);
                printf("  Dispositivo 1: %s (%s)\n", listaDisp[i].nome, listaDisp[i].tipo);
                printf("  Dispositivo 2: %s (%s)\n", listaDisp[j].nome, listaDisp[j].tipo);
                ipsDuplicados++;
            }
        }
    }

    if (ipsDuplicados == 0) printf("Nenhum IP duplicado encontrado na rede.\n");

    printf("===========================================\n");
    printf("Dispositivos com consumo acima da media:\n");

    for (i = 0; i < numDisp - 1; i++) {
        if (listaDisp[i].consumoBanda > (somaConsumo / (float)numDisp)){
            printf("Dispositivo: %s, Consumo %.2f - acima da media %.2f\n", listaDisp[i].nome, listaDisp[i].consumoBanda, (somaConsumo / (float)numDisp));
            dispAcima ++;
        }
    }

    if (dispAcima == 0) printf("Nenhum Dispositivo com consumo acima da media.\n");

    printf("===========================================\n");

    sleep(3);
    return;
}

void menu(Disp listaDisp[]) {
    int opcao = 0;
    int numDisp = ler_arquivo(arquivo, listaDisp);

    system("clear");

    do {
        printf("=============================== MENU ===============================\n");
        printf("1. Cadastro de dispositivos        | 2. Listar dispositivos ativos\n");
        printf("3. Buscar endereço IP              | 4. Ordenação\n");
        printf("5. Filtrar por tipo de dispositivo | 6. Detecção de anomalias\n");
        printf("7. Resumo                          | 0. Sair\n");
        printf("====================================================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        system("clear");
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