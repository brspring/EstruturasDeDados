#include<stdlib.h>
#include<stdio.h>
#include "heap.h"
#define MAX 50

fila_t* criaFila (){
    fila_t* filaPrio = malloc(sizeof(fila_t));
    filaPrio->v = malloc(MAX*sizeof(pessoa_t));
    filaPrio->n = 0;

    return filaPrio;
}

void queue(fila_t* fila , pessoa_t* pessoa) {
    fila ->n++;
    fila ->v[fila->n] = *pessoa;
}

void dequeue(fila_t* fila, int n){
    fila->v[fila->n].prioridade = 0;
    fila->n--;
}

void inicHeap(fila_t* fila, pessoa_t* pessoa, int n){
    int i;
    for (i=1; i < n; i++){
        if (fila->n < MAX){
            iniciaPessoa(pessoa);
            queue(fila, pessoa);
        }
    }
    heapfy(fila, fila->n);       
}

void insereHeap (fila_t* fila, int n){
    while (n > 1 && fila->v[n/2].prioridade < fila->v[n].prioridade) {
        troca(&fila->v[n], &fila->v[n/2]);
        n = n/2;
    }
}

void removeHeap(fila_t* fila){
    troca(&fila->v[1], &fila->v[fila->n]);
    fila->v[fila->n].prioridade = 0;
    fila->n--;
    sacodeHeap(fila, fila->n);
}

void heapfy (fila_t* fila, int n){
    int i;
    for (i = 0; i <= n; i++)
        insereHeap(fila, i);
}

void sacodeHeap(fila_t* fila, int n){
    int i = 2;
    while (i<= n){
        if (i < n && fila->v[i].prioridade < fila->v[i+1].prioridade)
            i++;
        if (fila->v[i/2].prioridade >= fila->v[i].prioridade)
            break;
        troca(&fila->v[i/2], &fila->v[i]);
        i = i*2;
    }
}


void heapSort (fila_t* fila, int n){
    int i;
    heapfy(fila, n);
    for (i = n; 1<i; i--){
        troca(&fila->v[1], &fila->v[i]);
        sacodeHeap(fila, i-1);
    }
} 

void imprimeHeap(fila_t* fila, int n){
    int i;
    for (i=1; i <= n; i++){
        printf("\n");
        printf ("Paciente numero %d\n", i);
        printf ("nome: %s\n", fila->v[i].nome);
        printf("idade: %d\n", fila->v[i].idade);
        printf ("prioridade: %d\n",fila->v[i].prioridade);
    }
}

void desceHeap(fila_t* fila, int k, int novo){
    fila->v[k].prioridade = novo;
    int i = k*2;
    while (i<= fila->n){
        if (i < fila->n && fila->v[i].prioridade < fila->v[i+1].prioridade)
            i++;
        if (fila->v[i/2].prioridade >= fila->v[i].prioridade)
            break;
        troca(&fila->v[i/2], &fila->v[i]);
        i = i*2;
    }
}


void alteraHeap(fila_t* fila, int i, int novo){
    fila->v[i].prioridade = novo;
    if (i == 1)
        sacodeHeap(fila, fila->n);
    else if (fila->v[i].prioridade > fila->v[i/2].prioridade)
            insereHeap(fila, i);
        else
            desceHeap(fila, i, novo);
}

int checaHeap(fila_t* fila, int n){
    int verdade = 1;
    int i = n;
    while(i>1 && verdade == 1){
        if (fila->v[i/2].prioridade < fila->v[i].prioridade)
            verdade = 0;
        i--;
    }

    return verdade;
}