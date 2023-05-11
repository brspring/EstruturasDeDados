#include <stdio.h>
#include<stdlib.h>
#include "avl.h"

nodo_t* cria_nodo(int valor){
    nodo_t *n = malloc(sizeof(nodo_t));
    if (!n)
        return NULL;
    n->chave = valor;
	n->altura = 0;
    n->esq = NULL;
    n->dir = NULL;

    return n;
}

void destroiArvore(nodo_t* nodo){
	if (nodo){
		destroiArvore(nodo->esq);
		destroiArvore(nodo->dir);
		free(nodo);
	}
}

void printTree (nodo_t *nodo, int alturaArvore){
	if(nodo != NULL){
		printTree(nodo->esq, alturaArvore+1);
		printf("%d,%d\n", nodo->chave, alturaArvore);
		printTree(nodo->dir, alturaArvore+1);
	}
}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int altura (nodo_t *nodo) {
	if(!nodo)
		return -1;
	return nodo->altura;
}

int fator_balanceamento(nodo_t *n){
    if (n == NULL)
        return 0;
    return (altura(n->esq) - altura(n->dir));
}

nodo_t *tree_minimum(nodo_t *n){
    if(n->esq)
        return tree_minimum(n->esq);
    return n;
}

nodo_t *tree_maximum(nodo_t *n){
    if(n->dir)
        return tree_maximum(n->dir);
    return n;
}

nodo_t* rotEsq( nodo_t *x){
    nodo_t* y = x->dir;
	nodo_t* A2 = y->esq;

	y->esq = x;
	x->dir = A2;

	x->altura = max(altura(x->esq), altura(x->dir)) + 1;
	y->altura = max(altura(y->esq), altura(y->dir)) + 1;

	return y;    
}

nodo_t* rotDir( nodo_t *x){
    nodo_t* y = x->esq;
	nodo_t* A2 = y->dir;

	y->dir = x;
	x->esq = A2;

	x->altura = max(altura(x->esq), altura(x->dir)) + 1;
	y->altura = max(altura(y->esq), altura(y->dir)) + 1;

	return y;   
}

nodo_t* insereNo(nodo_t* nodo, int valor)
{
	// Se nodo for NULL, chegou na folha da árvore
	if (!nodo)
		return cria_nodo(valor);

	// Se o valor a ser inserido for menor que a chave do nodo atual,
	// insere o valor na subárvore da esquerda
	if (valor < nodo->chave)
		nodo->esq = insereNo(nodo->esq, valor);

	// Caso contrário, insere na subárvore da direita
	else
		nodo->dir = insereNo(nodo->dir, valor);
	
	// Atualiza a altura dos nodos anteriores ao que foi inserido
	nodo->altura = 1 + max(altura(nodo->esq), altura(nodo->dir));

	// Calcula a diferença de altura entre as subárvores da esquerda e da direita
	int fb = fator_balanceamento(nodo);

	// Zig-zig na esquerda
	if (fb > 1 && valor < nodo->esq->chave)
		return rotDir(nodo);

	// Zig-zig na direita
	if (fb < -1 && valor > nodo->dir->chave)
		return rotEsq(nodo);

	// Zig-zag na esquerda
	if (fb > 1 && valor > nodo->esq->chave){
		nodo->esq = rotEsq(nodo->esq);
		return rotDir(nodo);
	}

	// Zig-zag na direita
	if (fb < -1 && valor < nodo->dir->chave){
		nodo->dir = rotDir(nodo->dir);
		return rotEsq(nodo);
	}

	return nodo;
}


nodo_t* removeNo(nodo_t* nodo, int valor){
	// Nodo não está na árvore
	if (!nodo)
		return nodo;

	// Se o valor a ser removido for menor que a chave do nodo atual,
	// procura o valor na subárvore da esquerda
	else if (valor < nodo->chave)
		nodo->esq = removeNo(nodo->esq, valor);

	// Caso seja maior, procura o valor na subárvore da direita
	else if (valor > nodo->chave)
		nodo->dir = removeNo(nodo->dir, valor);

	// Nodo foi encontrado
	else{
		// Caso o nodo tenha 0 ou 1 filhos
		if (nodo->esq == NULL){
			nodo_t* aux = nodo->dir;
			free(nodo);
			return aux;
		}
		else if (nodo->dir == NULL){
			nodo_t* aux = nodo->esq;
			free(nodo);
			return aux;
		}
		// Caso o nodo tenha 2 filhos
		else{
			nodo_t* aux = tree_maximum(nodo->esq);
			nodo->chave = aux->chave;
			nodo->esq = removeNo(nodo->esq, aux->chave);
		}
	}

	// Atualiza a altura dos nodos anteriores ao que foi inserido
	nodo->altura = 1 + max(altura(nodo->esq), altura(nodo->dir));

	// Calcula a diferença de altura entre as subárvores da esquerda e da direita
	int fb = fator_balanceamento(nodo);

	// Zig-zig na esquerda
	if (fb > 1 && fator_balanceamento(nodo->esq) >= 0)
		return rotDir(nodo);

	// Zig-zig na direita
	if (fb < -1 && fator_balanceamento(nodo->dir) >= 0)
		return rotEsq(nodo);

	// Zig-zag na esquerda
	if (fb > 1 && fator_balanceamento(nodo->esq) < 0){
		nodo->esq = rotEsq(nodo->esq);
		return rotDir(nodo);
	}

	// Zig-zag na direita
	if (fb < -1 && fator_balanceamento(nodo->dir) < 0){
		nodo->dir = rotDir(nodo->dir);
		return rotEsq(nodo);
	}

	return nodo;
}