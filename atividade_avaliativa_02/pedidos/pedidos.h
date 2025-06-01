#ifndef PEDIDOS_H
#define PEDIDOS_H

#include "../arquivo/arquivo.h"

int gerar_proximo_id();
void atualizar_ultimo_id(int id);
Pedido* criar_pedido(int id_cliente, char *localizacao, char *data_hora);
void adicionar_lanche_pedido(Pedido *pedido, char *nome_lanche, float valor, int qtd);
Pedido* inserir_pedido_lista(Pedido *lista, Pedido *novo_pedido);
Pedido* inserir_pedido_ordenado(Pedido *lista, Pedido *novo_pedido);
Pedido* remover_pedido(Pedido *lista, int id_pedido);
Pedido* buscar_pedido_por_id(Pedido *lista, int id_pedido);
Pedido* buscar_pedido_por_nome_lanche(Pedido *lista, char *nome_lanche);
void listar_pedidos_em_andamento(Pedido *lista);
void listar_pedidos_finalizados(Pedido *lista);
float calcular_total_vendas(Pedido *lista_finalizados);
void liberar_lista(Pedido *lista);

#endif
