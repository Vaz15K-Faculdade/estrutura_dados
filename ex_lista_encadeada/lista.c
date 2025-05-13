#ifndef AVANCADO_H
#define AVANCADO_H

#include "lista.h"

Lista no(Item x, Lista p) {
    Lista n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

void exibe(Lista L) {
    while (L != NULL) {
        printf(FMT, L->item);
        L = L->prox;
    }
}
/*
void exibe(Lista L) {
    if (L == NULL) return;
    printf(FMT, L->item);
    exibe(L->prox);
}
*/

void exibe_inv(Lista L) {
    if (L == NULL) return;
    exibe(L->prox);
    printf(FMT, L->item);
}


void anexa(Lista *A, Lista B) {
    if (B == NULL) return;
    while (*A != NULL)
        A = &(*A)->prox;
    *A = B;
}

void destroi(Lista *L) {
    while (*L != NULL) {
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
    
}

/*
int tam(Lista L) {
    int tamanho = 0;
    while (L != NULL) {
        tamanho ++;
        L = L->prox;
    }
    return tamanho;
}
*/

int tam(Lista L) {
    if (L == NULL) return 0;
    return 1 + tam(L->prox);
    // return 0 ? (L == NULL) : 1 + tam(L->prox)
}

/*
int pert(Item x, Lista L) {
    if (L == 0) return 0;
    while (L != NULL) {
        if (x == L->item)
            return 1;
        L = L->prox;
    }
}
*/
int pert(Item x, Lista L) {
    if (L == NULL) return 0;
    if (x == L->item) return 1;
    return pert(x, L->prox);
}

Lista clone(Lista L) {
    if (L == NULL) return NULL;
    return no(L->item, clone(L->prox));
}

#endif