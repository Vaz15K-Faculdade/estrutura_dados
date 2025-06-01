#include "arquivo.h"
#include "../pedidos/pedidos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Keven Eduardo Vaz Bilibio
25/05/2025
Trabalho de Estruturas de Dados
Arquivo arquivo.c
Contem as funcoes para salvar e carregar pedidos em arquivos.
*/

void salvar_pedidos(Pedido *lista_em_andamento, Pedido *lista_finalizados) {
    FILE *arq_em_andamento = fopen("pedidos_em_andamento.dat", "wb");
    FILE *arq_finalizados = fopen("pedidos_finalizados.dat", "wb");

    if (arq_em_andamento == NULL || arq_finalizados == NULL) {
        printf("Erro ao abrir arquivos para salvar pedidos.\n");
        return;
    }

    Pedido *atual = lista_em_andamento;
    while (atual != NULL) {
        fwrite(atual, sizeof(Pedido), 1, arq_em_andamento);
        atual = atual->proximo;
    }

    atual = lista_finalizados;
    while (atual != NULL) {
        fwrite(atual, sizeof(Pedido), 1, arq_finalizados);
        atual = atual->proximo;
    }

    fclose(arq_em_andamento);
    fclose(arq_finalizados);
}

void carregar_pedidos(Pedido **lista_em_andamento, Pedido **lista_finalizados) {
    FILE *arq_em_andamento = fopen("pedidos_em_andamento.dat", "rb");
    FILE *arq_finalizados = fopen("pedidos_finalizados.dat", "rb");
    Pedido temp;

    if (arq_em_andamento != NULL) {
        while (fread(&temp, sizeof(Pedido), 1, arq_em_andamento) == 1) {
            Pedido *novo = malloc(sizeof(Pedido));
            *novo = temp;
            novo->proximo = NULL;
            *lista_em_andamento = inserir_pedido_lista(*lista_em_andamento, novo);
            atualizar_ultimo_id(novo->id_pedido);
        }
        fclose(arq_em_andamento);
    }

    if (arq_finalizados != NULL) {
        while (fread(&temp, sizeof(Pedido), 1, arq_finalizados) == 1) {
            Pedido *novo = malloc(sizeof(Pedido));
            *novo = temp;
            novo->proximo = NULL;
            *lista_finalizados = inserir_pedido_ordenado(*lista_finalizados, novo);
            atualizar_ultimo_id(novo->id_pedido);
        }
        fclose(arq_finalizados);
    }
}
