#include <stdio.h>
#include<stdlib.h>
#include "avl.h"

int main(){
    nodo_t* nodo = NULL;
    int valor;
    char c;
    scanf("%c", &c); 
    while(!feof(stdin)){
        if (c == 'i'){
            scanf("%d", &valor);
            nodo = insereNo(nodo, valor);
        }
        else if (c == 'r'){
            scanf("%d", &valor);
            nodo = removeNo(nodo, valor);
        }
        scanf("%c", &c);
    }   
    printTree(nodo, 0);
    destroiArvore(nodo);

    return 0;
}