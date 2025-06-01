#ifndef ARQUIVO_H
#define ARQUIVO_H

/*
Keven Eduardo Vaz Bilibio
25/05/2025
Trabalho de Estruturas de Dados
Arquivo arquivo.h
Contem os prototipos das funcoes para salvar e carregar pedidos em arquivos.
*/

typedef struct {
    char nomelanche[31];
    float valor;
    int qtd;
} Lanche;

typedef struct Pedido {
    int id_pedido;
    int id_cliente;
    char localizacao[31];
    char data_hora[20];
    char data_hora_fim[20];
    Lanche lanche[10];
    int num_lanches;
    struct Pedido *proximo;
} Pedido;

void salvar_pedidos(Pedido *lista_em_andamento, Pedido *lista_finalizados);
void carregar_pedidos(Pedido **lista_em_andamento, Pedido **lista_finalizados);

#endif /* ARQUIVO_H */