#ifndef _LIBAVL_
#define _LIBAVL_

struct nodo {
    int chave;      
    int altura;
    struct nodo* esq;
    struct nodo* dir;
};
typedef struct nodo nodo_t;

//aloca memoria para o nodo e insere o valor passado
nodo_t* cria_nodo(int valor);

//libera memoria destruindo todos os nodos
void destroiArvore(nodo_t* nodo);

//imprime a arvore por travessia em ordem
void printTree (nodo_t *n, int alturaArvore);

//retorna o menor valor da árvore
nodo_t *tree_minimum(nodo_t *n);

//retorna o maior valor da árvore 
nodo_t *tree_maximum(nodo_t *n);

//econtra o maior entre dois numeros
int max(int a, int b);

//retorna a altura do nodo, se nao existir retorna -1
int altura (nodo_t *p);

//determina se a arvore esta desbalanceada pela diferença de altura entre subarvores da esquerda e da direita
int fatorBalanceamento(nodo_t *n);

//rotaciona nodo x para esquerda
nodo_t* rotEsq( nodo_t *x);

//rotaciona nodo y para a direita
nodo_t* rotDir( nodo_t *x);

//insere e balanceia a arvore
nodo_t *insereNo(nodo_t *n, int chave);

//remove e balanceia a arvore
nodo_t* removeNo(nodo_t* nodo, int valor);

#endif