#ifndef _LIBSORT_H
#define _LIBSORT_H

#include "hash.h"

void troca(tabela_t** vet, int a, int b);

int busca(int chave, tabela_t** vet, int a, int b);

int insere(tabela_t** vet, int a, int b);

int sort(tabela_t** vet, int a, int b);


#endif
