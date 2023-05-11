#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void troca(tabela_t** vet, int a, int b){
    tabela_t* aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;
}

int busca(int chave, tabela_t** vet, int a, int b){
    if (a > b)
        return -1;
    if (vet[b]->valor <= chave)
        return b;
    return busca(chave, vet, a, b-1);
}

void insere(tabela_t** vet, int a, int b){
    int p = busca(vet[b]->valor, vet, a, b-1);
    int i = b;
    while (i > p+1){
        troca(vet, i, i-1);
        i--;
    }
}


int sort(tabela_t** vet, int a, int b){

    if (a >= b) 
        return 0;
    sort(vet, a, b-1);
    insere(vet, a, b);
    return 0;
}



