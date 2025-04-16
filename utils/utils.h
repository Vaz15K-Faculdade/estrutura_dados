#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void tratar_erro(const char *mensagem);

void alocar(int **vetor, int tamanho);

void informar(int *d, int tamanho);

void gerar_aleatorio(int *vetor, int tamanho, int valor_max);

void mostrar_vetor(int *vetor, int tamanho);

#endif