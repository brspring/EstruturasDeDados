#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include <math.h>

#define  m 11

//h1(k) = k mod m
//h2(k) = ⌊m * (k * 0.9 − ⌊k * 0.9⌋)⌋

int h2(int chave)
{
    return floor(m * ((chave * 0.9) - floor(chave * 0.9)));
}

tabela_t** hash_init(int size){
    tabela_t** t =  malloc(sizeof(tabela_t*)*size);
    for (int i = 0; i < size; i++){
        t[i] = NULL;
    }
    return t;
}

tabela_t* dado_init(int chave, int index, char* tabela){
    tabela_t* aux = malloc(sizeof(tabela_t));
    aux->valor = chave;
    aux->indice = index;
    aux->tabela = tabela;
    aux->removido = 0;

    return aux;
}

int busca_hash(tabela_t** t1, tabela_t** t2, int chave){
    int index1 = chave%m;
    int index2 = floor(m * ((chave * 0.9) - floor(chave * 0.9)));

    if ((t1[index1]->valor = chave) && (!t1[index1]->removido))
        return index1;
    else if ((t2[index2] != NULL) && (t2[index2]->valor = chave) && (!t2[index2]->removido))
        return index2;
    else
        return -1;
}

void insere_hash(tabela_t** t1, tabela_t** t2, int chave){
    int index = chave%m;
    if (t1[index] == NULL)
        t1[index] = dado_init(chave, index, "T1");
    else if (t1[index]->removido)
    {
        t1[index]->valor = chave;
        t1[index]->removido = 0;
        t1[index]->indice = index;
    }
    else
    {
        int index2 = h2(t1[index]->valor);
        if (t2[index2] == NULL)
            t2[index2] = dado_init(t1[index]->valor, index2, "T2");
        else if (t2[index2]->removido)
        {
            t2[index2]->valor = t1[index]->valor;
            t2[index2]->removido = 0;
            t2[index2]->indice = index2;
        }
        t1[index]->valor = chave;
    }
}   

void remove_hash(tabela_t** t1, tabela_t** t2, int chave){
    int index1 = chave%m;
    int index2 = floor(m * ((chave * 0.9) - floor(chave * 0.9)));
    if (t2[index2] != NULL && t2[index2]->valor == chave)
    {
        t2[index2]->removido = 1;
        free(t2[index2]);
        t2[index2] = NULL;
    }
    else if (t1[index1] != NULL && t1[index1]->valor == chave)
        t1[index1]->removido = 1;
}



void imprime_hash(tabela_t** t){
    for (int i = 0; i < m*2; i++)
        if (t[i] != NULL)
            printf("%d,%s,%d\n", t[i]->valor, t[i]->tabela, t[i]->indice);
}            

void destroi_hash(tabela_t** t){
    for (int i = 0; i < m; i++){
        if (t[i] != NULL){
            free(t[i]);
        }
    }
    free(t);
}

int hash_merge(tabela_t** t1, tabela_t** t2, tabela_t** aux){
    int j = 0;
    for (int i = 0; i < m; i++)
        if ((t1[i] != NULL) && (t1[i]->removido == 0))
        {
            aux[j] = t1[i];
            j++;
        }
    for (int i = 0; i < m; i++)
        if ((t2[i] != NULL) && (t2[i]->removido == 0))
        {
            aux[j] = t2[i];
            j++;
        }
    return j-1;
}