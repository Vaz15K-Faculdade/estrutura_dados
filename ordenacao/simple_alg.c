#include "simple_alg.h"

int selmin(int v[], int i, int n) {
    int j, k = i;
    
    for(j = i+1; j < n; j++)
        if(v[k] > v[j])
            k = j;
        return k;
}

void bolha(int v[], int n) {
    int i, j;
    
    for(i=1; i<n; i++)
        for(j=0; j<n-i; j++)
            if(v[j] > v[j+1]) {
                int x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
            }
}

void selecao(int v[], int n) {
    int i, k, x;
    
    for(i=0; i < n-1; i++) {
        k = selmin(v, i, n);
        x = v[i];
        v[i] = v[k];
        v[k] = x;
    }
}

void insercao(int v[], int n) {
    int i, j, x;
    
    for(i=1; i < n; i++) {
        x = v[i];
        
        for(j = i-1; (j >= 0) && (x < v[j]); j--)
            v[j+1] = v[j];
        v[j+1] = x;
    }
}