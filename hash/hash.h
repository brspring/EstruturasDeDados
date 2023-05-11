#ifndef _LIBHASH_H
#define _LIBHASH_H

#define m 11

struct tabela {
    int indice;
    int removido;
    int valor;
    char* tabela;
};
typedef struct tabela tabela_t;

tabela_t** hash_init();

void insere_hash(tabela_t** t1, tabela_t** t2, int chave);

void remove_hash(tabela_t** t1, tabela_t** t2, int chave);

int busca_hash(tabela_t** t1, tabela_t** t2, int chave);

int hash_merge(tabela_t** t1, tabela_t** t2, tabela_t** aux);

void imprime_hash(tabela_t** t);

void destroi_hash(tabela_t** t);

tabela_t* dado_init(int valor, int indice, char* tabela);

#endif