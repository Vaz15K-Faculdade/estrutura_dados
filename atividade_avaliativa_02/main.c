#include <stdio.h>
#include <stdlib.h>

#include "menu/menu.h"
#include "arquivo/arquivo.h"
#include "pedidos/pedidos.h"

/*
Keven Eduardo Vaz Bilibio
25/05/2025
Trabalho de Estruturas de Dados
Arquivo main.c
Contem a funcao principal do programa, que inicializa as listas de pedidos,
carrega os pedidos de arquivos e chama o menu principal.
*/

int main() {
    Pedido *lista_em_andamento = NULL;
    Pedido *lista_finalizados = NULL;
    
    carregar_pedidos(&lista_em_andamento, &lista_finalizados);
    
    menu(&lista_em_andamento, &lista_finalizados);
    
    liberar_lista(lista_em_andamento);
    liberar_lista(lista_finalizados);
    
    return 0;
}
