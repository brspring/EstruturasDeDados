#ifndef _LIBheap_t_H
#define _LIBheap_t_H
#include "prontoSocorro.h"
#define MAX 50

struct fila{
    pessoa_t *v;
    int n, tamanho;
};
typedef struct fila fila_t;


/*
 *Inicializa a heap na memória. 
*/
fila_t* criaFila ();


void queue(fila_t* fila , pessoa_t* pessoa);

void dequeue(fila_t* fila, int n);

void inicHeap(fila_t* fila, pessoa_t* pessoa, int n);

/*
 *Insere na heap o elemento enviado como parâmetro, sendo n o número de elementos.
*/
void insereHeap (fila_t* fila, int n);

/*
 *Remove o elemento na heap.
*/
void removeHeap(fila_t* fila);

/*
 *Transforma o vetor em uma heap, recebendo o vetor e o número de elementos.
*/
void heapfy (fila_t* fila, int n);


void sacodeHeap(fila_t* fila, int n);

/*
 *Ordena o vetor pelo método heapSort.
*/
void heapSort (fila_t* fila, int n);

/*
 *Imprime todos os elementos da heap.
*/
void imprimeHeap(fila_t* fila, int n);



/* 
 *Altera a prioridade de um elemento da heap e reposiciona ele
*/
void alteraHeap(fila_t* fila, int n, int novo);

/*
 *Checa se o vetor de n elementos recebido é uma heap. 
*/
int checaHeap(fila_t* fila, int n);

#endif