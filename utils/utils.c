#include "utils.h"

void alocar(int **vetor, int tamanho) {
    *vetor = (int *) malloc(tamanho * sizeof(int));
    
    if (*vetor == NULL) {
        printf("Falha na alocação de memória");
    }
}

void informar(int *d, int tamanho) {
    for(int i=0; i < tamanho; i++){
        printf("Informe o numero da posição %i: ", i+1);
        scanf("%i", &d[i]);
    }
}

void gerar_aleatorio(int *vetor, int tamanho, int valor_max) {
    // Inicializa o gerador de números aleatórios
    static int semente_inicializada = 0;
    if (!semente_inicializada) {
        srand(time(NULL));
        semente_inicializada = 1;
    }
    
    // Preenche o vetor com números aleatórios
    for(int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (valor_max + 1);
    }
}

void mostrar_vetor(int *vetor, int tamanho) {
    for(int i = 0; i < tamanho; i++){
        printf("%i ", vetor[i]);
    }
    printf("\n");
}