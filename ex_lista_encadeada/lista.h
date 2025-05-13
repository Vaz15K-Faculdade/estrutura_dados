#include <stdio.h>
#include <stdlib.h>

#define FMT "%d "

typedef int Item;
typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

/*======================================*/

Lista no(Item x, Lista p);
void exibe(Lista L);
void exibe_inv(Lista L);
void anexa(Lista *A, Lista B);
void destroi(Lista *L);
int tam(Lista L);
int pert(Item x, Lista L);
Lista clone(Lista L);