#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
Keven Eduardo Vaz Bilibio
25/05/2025
Trabalho de Estruturas de Dados
Arquivo menu.c
Contém as funções do menu principal do sistema de pedidos de lanches.
*/


void obter_data_hora_atual(char *buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%02d/%02d/%04d %02d:%02d:%02d", 
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void inserir_pedido(Pedido **lista_em_andamento) {
    int id_cliente, num_lanches;
    char localizacao[31], data_hora[20];
    
    printf("\n=== INSERIR NOVO PEDIDO ===\n");
    
    printf("ID do cliente: ");
    scanf("%d", &id_cliente);
    
    printf("Localização de entrega: ");
    getchar();
    fgets(localizacao, sizeof(localizacao), stdin);
    localizacao[strcspn(localizacao, "\n")] = 0;
    
    obter_data_hora_atual(data_hora);
    
    Pedido *novo_pedido = criar_pedido(id_cliente, localizacao, data_hora);
    if (novo_pedido == NULL) return;
    
    printf("Pedido criado com ID: %d\n", novo_pedido->id_pedido);
    
    printf("Quantos tipos de lanches deseja adicionar (máximo 10): ");
    scanf("%d", &num_lanches);
    
    for (int i = 0; i < num_lanches && i < 10; i++) {
        int qtd;
        char nome_lanche[31];
        float valor;
        
        printf("\nLanche %d:\n", i + 1);
        
        printf("Nome do lanche: ");
        if (i == 0) getchar();
        fgets(nome_lanche, sizeof(nome_lanche), stdin);
        nome_lanche[strcspn(nome_lanche, "\n")] = 0;
        
        printf("Valor do lanche: R$");
        scanf("%f", &valor);
        
        printf("Quantidade: ");
        scanf("%d", &qtd);
        
        adicionar_lanche_pedido(novo_pedido, nome_lanche, valor, qtd);
    }
    
    *lista_em_andamento = inserir_pedido_lista(*lista_em_andamento, novo_pedido);
    printf("Pedido inserido com sucesso!\n");
}

void finalizar_pedido(Pedido **lista_em_andamento, Pedido **lista_finalizados) {
    int id_pedido;
    
    printf("\n=== FINALIZAR PEDIDO ===\n");
    printf("ID do pedido a finalizar: ");
    scanf("%d", &id_pedido);
    
    Pedido *pedido = buscar_pedido_por_id(*lista_em_andamento, id_pedido);
    if (pedido == NULL) {
        printf("Pedido não encontrado na lista de pedidos em andamento!\n");
        return;
    }
    
    obter_data_hora_atual(pedido->data_hora_fim);
    
    *lista_em_andamento = remover_pedido(*lista_em_andamento, id_pedido);
    
    *lista_finalizados = inserir_pedido_ordenado(*lista_finalizados, pedido);
    
    printf("Pedido finalizado com sucesso!\n");
}

void excluir_pedido(Pedido **lista_em_andamento, Pedido **lista_finalizados) {
    int id_pedido, opcao;
    
    printf("\n=== EXCLUIR PEDIDO ===\n");
    printf("ID do pedido a excluir: ");
    scanf("%d", &id_pedido);
    
    printf("Excluir de qual lista?\n");
    printf("1 - Pedidos em andamento\n");
    printf("2 - Pedidos finalizados\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    
    Pedido *pedido_encontrado = NULL;
    
    switch (opcao) {
        case 1:
            pedido_encontrado = buscar_pedido_por_id(*lista_em_andamento, id_pedido);
            if (pedido_encontrado != NULL) {
                *lista_em_andamento = remover_pedido(*lista_em_andamento, id_pedido);
                printf("Pedido removido da lista de pedidos em andamento!\n");
            } else {
                printf("Pedido não encontrado na lista de pedidos em andamento!\n");
            }
            break;
        case 2:
            pedido_encontrado = buscar_pedido_por_id(*lista_finalizados, id_pedido);
            if (pedido_encontrado != NULL) {
                *lista_finalizados = remover_pedido(*lista_finalizados, id_pedido);
                printf("Pedido removido da lista de pedidos finalizados!\n");
            } else {
                printf("Pedido não encontrado na lista de pedidos finalizados!\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
    }
}

void listar_pedidos(Pedido *lista_em_andamento, Pedido *lista_finalizados) {
    listar_pedidos_em_andamento(lista_em_andamento);
    listar_pedidos_finalizados(lista_finalizados);
}

void buscar_pedido(Pedido *lista_em_andamento, Pedido *lista_finalizados) {
    int opcao;
    
    printf("\n=== BUSCAR PEDIDO ===\n");
    printf("1 - Buscar por ID do pedido\n");
    printf("2 - Buscar por nome do lanche\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    
    switch (opcao) {
        case 1: {
            int id_pedido;
            printf("ID do pedido: ");
            scanf("%d", &id_pedido);
            
            Pedido *pedido = buscar_pedido_por_id(lista_em_andamento, id_pedido);
            if (pedido == NULL) {
                pedido = buscar_pedido_por_id(lista_finalizados, id_pedido);
            }
            
            if (pedido != NULL) {
                printf("\n=== PEDIDO ENCONTRADO ===\n");
                printf("ID Pedido: %d\n", pedido->id_pedido);
                printf("ID Cliente: %d\n", pedido->id_cliente);
                printf("Localização: %s\n", pedido->localizacao);
                printf("Data/Hora Início: %s\n", pedido->data_hora);
                if (strlen(pedido->data_hora_fim) > 0) {
                    printf("Data/Hora Fim: %s\n", pedido->data_hora_fim);
                    printf("Status: Finalizado\n");
                } else {
                    printf("Status: Em andamento\n");
                }
                printf("Lanches:\n");
                float total = 0;
                for (int i = 0; i < pedido->num_lanches; i++) {
                    float subtotal = pedido->lanche[i].valor * pedido->lanche[i].qtd;
                    printf("  - %s (Qtd: %d, Valor: R$%.2f, Subtotal: R$%.2f)\n", 
                        pedido->lanche[i].nomelanche, 
                        pedido->lanche[i].qtd, 
                        pedido->lanche[i].valor,
                        subtotal);
                    total += subtotal;
                }
                printf("Total do Pedido: R$%.2f\n", total);
            } else {
                printf("Pedido não encontrado!\n");
            }
            break;
        }
        case 2: {
            char nome_lanche[31];
            printf("Nome do lanche: ");
            getchar();
            fgets(nome_lanche, sizeof(nome_lanche), stdin);
            nome_lanche[strcspn(nome_lanche, "\n")] = 0;
            
            printf("\n=== PEDIDOS COM O LANCHE '%s' ===\n", nome_lanche);
            
            Pedido *atual = lista_em_andamento;
            int encontrou = 0;
            while (atual != NULL) {
                for (int i = 0; i < atual->num_lanches; i++) {
                    if (strcmp(atual->lanche[i].nomelanche, nome_lanche) == 0) {
                        printf("ID Pedido: %d (Em andamento)\n", atual->id_pedido);
                        printf("ID Cliente: %d\n", atual->id_cliente);
                        printf("Data/Hora: %s\n", atual->data_hora);
                        printf("----------------------------\n");
                        encontrou = 1;
                        break;
                    }
                }
                atual = atual->proximo;
            }
            
            atual = lista_finalizados;
            while (atual != NULL) {
                for (int i = 0; i < atual->num_lanches; i++) {
                    if (strcmp(atual->lanche[i].nomelanche, nome_lanche) == 0) {
                        printf("ID Pedido: %d (Finalizado)\n", atual->id_pedido);
                        printf("ID Cliente: %d\n", atual->id_cliente);
                        printf("Data/Hora Início: %s\n", atual->data_hora);
                        printf("Data/Hora Fim: %s\n", atual->data_hora_fim);
                        printf("----------------------------\n");
                        encontrou = 1;
                        break;
                    }
                }
                atual = atual->proximo;
            }
            
            if (!encontrou) {
                printf("Nenhum pedido encontrado com o lanche '%s'!\n", nome_lanche);
            }
            break;
        }
        default:
            printf("Opção inválida!\n");
    }
}

void totalizar_vendas(Pedido *lista_finalizados) {
    float total = calcular_total_vendas(lista_finalizados);
    
    printf("\n=== TOTALIZAÇÃO DE VENDAS ===\n");
    printf("Total de vendas (pedidos finalizados): R$%.2f\n", total);
    
    printf("\nDetalhamento por pedido:\n");
    Pedido *atual = lista_finalizados;
    while (atual != NULL) {
        float total_pedido = 0;
        for (int i = 0; i < atual->num_lanches; i++) {
            total_pedido += atual->lanche[i].valor * atual->lanche[i].qtd;
        }
        printf("Pedido %d: R$%.2f\n", atual->id_pedido, total_pedido);
        atual = atual->proximo;
    }
}

void menu(Pedido **lista_em_andamento, Pedido **lista_finalizados) {
    int opc;
    
    do {
        printf("\n==========================================\n");
        printf("1 - Inserir pedido | 2 - Finalizar pedido\n");
        printf("3 - Excluir pedido | 4 - Listar pedidos\n");
        printf("5 - Buscar pedido  | 6 - Totalizar vendas\n");
        printf("\t\t7 - Sair\n");
        printf("==========================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);
        
        switch (opc) {
            case 1:
                inserir_pedido(lista_em_andamento);
                break;
            case 2:
                finalizar_pedido(lista_em_andamento, lista_finalizados);
                break;
            case 3:
                excluir_pedido(lista_em_andamento, lista_finalizados);
                break;
            case 4:
                listar_pedidos(*lista_em_andamento, *lista_finalizados);
                break;
            case 5:
                buscar_pedido(*lista_em_andamento, *lista_finalizados);
                break;
            case 6:
                totalizar_vendas(*lista_finalizados);
                break;
            case 7:
                printf("Salvando dados...\n");
                salvar_pedidos(*lista_em_andamento, *lista_finalizados);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opc != 7);
}