#include "pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ultimo_id_global = 0;

int gerar_proximo_id() {
    return ++ultimo_id_global;
}

void atualizar_ultimo_id(int id) {
    if (id > ultimo_id_global) {
        ultimo_id_global = id;
    }
}

Pedido* criar_pedido(int id_cliente, char *localizacao, char *data_hora) {
    Pedido *novo_pedido = malloc(sizeof(Pedido));
    if (novo_pedido == NULL) {
        printf("Erro ao alocar memória para o pedido.\n");
        return NULL;
    }
    
    novo_pedido->id_pedido = gerar_proximo_id();
    novo_pedido->id_cliente = id_cliente;
    strcpy(novo_pedido->localizacao, localizacao);
    strcpy(novo_pedido->data_hora, data_hora);
    strcpy(novo_pedido->data_hora_fim, "");
    novo_pedido->num_lanches = 0;
    novo_pedido->proximo = NULL;
    
    return novo_pedido;
}

void adicionar_lanche_pedido(Pedido *pedido, char *nome_lanche, float valor, int qtd) {
    if (pedido == NULL || pedido->num_lanches >= 10) {
        printf("Não é possível adicionar mais lanches ao pedido.\n");
        return;
    }
    
    strcpy(pedido->lanche[pedido->num_lanches].nomelanche, nome_lanche);
    pedido->lanche[pedido->num_lanches].valor = valor;
    pedido->lanche[pedido->num_lanches].qtd = qtd;
    pedido->num_lanches++;
}

Pedido* inserir_pedido_lista(Pedido *lista, Pedido *novo_pedido) {
    if (novo_pedido == NULL) return lista;
    
    novo_pedido->proximo = lista;
    return novo_pedido;
}

Pedido* inserir_pedido_ordenado(Pedido *lista, Pedido *novo_pedido) {
    if (novo_pedido == NULL) return lista;
    
    if (lista == NULL || strcmp(novo_pedido->data_hora_fim, lista->data_hora_fim) < 0) {
        novo_pedido->proximo = lista;
        return novo_pedido;
    }
    
    Pedido *atual = lista;
    while (atual->proximo != NULL && strcmp(atual->proximo->data_hora_fim, novo_pedido->data_hora_fim) < 0) {
        atual = atual->proximo;
    }
    
    novo_pedido->proximo = atual->proximo;
    atual->proximo = novo_pedido;
    
    return lista;
}

Pedido* remover_pedido(Pedido *lista, int id_pedido) {
    if (lista == NULL) return NULL;
    
    if (lista->id_pedido == id_pedido) {
        Pedido *temp = lista;
        lista = lista->proximo;
        free(temp);
        return lista;
    }
    
    Pedido *atual = lista;
    while (atual->proximo != NULL && atual->proximo->id_pedido != id_pedido) {
        atual = atual->proximo;
    }
    
    if (atual->proximo != NULL) {
        Pedido *temp = atual->proximo;
        atual->proximo = temp->proximo;
        free(temp);
    }
    
    return lista;
}

Pedido* buscar_pedido_por_id(Pedido *lista, int id_pedido) {
    Pedido *atual = lista;
    while (atual != NULL) {
        if (atual->id_pedido == id_pedido) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

Pedido* buscar_pedido_por_nome_lanche(Pedido *lista, char *nome_lanche) {
    Pedido *atual = lista;
    while (atual != NULL) {
        for (int i = 0; i < atual->num_lanches; i++) {
            if (strcmp(atual->lanche[i].nomelanche, nome_lanche) == 0) {
                return atual;
            }
        }
        atual = atual->proximo;
    }
    return NULL;
}

void listar_pedidos_em_andamento(Pedido *lista) {
    Pedido *atual = lista;
    printf("\n=== PEDIDOS EM ANDAMENTO ===\n");
    
    if (atual == NULL) {
        printf("Nenhum pedido em andamento.\n");
        return;
    }
    
    while (atual != NULL) {
        printf("ID Pedido: %d\n", atual->id_pedido);
        printf("ID Cliente: %d\n", atual->id_cliente);
        printf("Localização: %s\n", atual->localizacao);
        printf("Data/Hora: %s\n", atual->data_hora);
        printf("Lanches:\n");
        for (int i = 0; i < atual->num_lanches; i++) {
            printf("  - %s (Qtd: %d, Valor: R$%.2f)\n", 
                   atual->lanche[i].nomelanche, 
                   atual->lanche[i].qtd, 
                   atual->lanche[i].valor);
        }
        printf("----------------------------\n");
        atual = atual->proximo;
    }
}

void listar_pedidos_finalizados(Pedido *lista) {
    Pedido *atual = lista;
    printf("\n=== PEDIDOS FINALIZADOS ===\n");
    
    if (atual == NULL) {
        printf("Nenhum pedido finalizado.\n");
        return;
    }
    
    while (atual != NULL) {
        printf("ID Pedido: %d\n", atual->id_pedido);
        printf("ID Cliente: %d\n", atual->id_cliente);
        printf("Localização: %s\n", atual->localizacao);
        printf("Data/Hora Início: %s\n", atual->data_hora);
        printf("Data/Hora Fim: %s\n", atual->data_hora_fim);
        printf("Lanches:\n");
        float total_pedido = 0;
        for (int i = 0; i < atual->num_lanches; i++) {
            float subtotal = atual->lanche[i].valor * atual->lanche[i].qtd;
            printf("  - %s (Qtd: %d, Valor: R$%.2f, Subtotal: R$%.2f)\n", 
                   atual->lanche[i].nomelanche, 
                   atual->lanche[i].qtd, 
                   atual->lanche[i].valor,
                   subtotal);
            total_pedido += subtotal;
        }
        printf("Total do Pedido: R$%.2f\n", total_pedido);
        printf("----------------------------\n");
        atual = atual->proximo;
    }
}

float calcular_total_vendas(Pedido *lista_finalizados) {
    float total = 0;
    Pedido *atual = lista_finalizados;
    
    while (atual != NULL) {
        for (int i = 0; i < atual->num_lanches; i++) {
            total += atual->lanche[i].valor * atual->lanche[i].qtd;
        }
        atual = atual->proximo;
    }
    
    return total;
}

void liberar_lista(Pedido *lista) {
    Pedido *atual = lista;
    while (atual != NULL) {
        Pedido *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
