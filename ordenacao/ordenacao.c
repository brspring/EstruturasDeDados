#include "ordenacao.h"
#include <math.h>
#include <string.h>

void getNome(char nome[]){
	//substitua por seu nome
	strncpy(nome, "Bruno Aziz Spring Machado", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

unsigned int getGRR(){
	return 20211279;
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();
	
int buscaSequencial2(int vetor[], int a, int b, int valor, int* numComparacoes){
	if (a > b)
		return -1;
	(*numComparacoes)++;

	if (valor == vetor[b])
		return b;
	
	return buscaSequencial2(vetor, a,  b-1,  valor,  numComparacoes);
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
	return buscaSequencial2(vetor, 0, tam-1, valor, numComparacoes);
}

int buscaBinaria2(int vetor[], int a, int b, int valor, int* numComparacoes){
	int m = 0;
	if (a > b)
		return -1;
	m = floor((a+b)/2);
	(*numComparacoes)++;
	if (valor == vetor[m])
		return m;

	(*numComparacoes)++;
	if (valor < vetor[m])
		return buscaBinaria2(vetor, a, m-1, valor, numComparacoes);

	return buscaBinaria2(vetor, m+1, b, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	*numComparacoes = 0;
	return buscaBinaria2(vetor, 0, tam-1, valor, numComparacoes);
}

//Funcoes necessarias no insertion sort

int Busca(int vetor[], int buscado,  int a, int b, int* numComparacoes){
	if (a > b)
		return a-1;

	(*numComparacoes)++;
	if (buscado >= vetor[b])
		return b;

	return Busca(vetor, buscado, a, b-1, numComparacoes);
	
}

void Troca(int vetor[], int a, int b){
	int x;
	x = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = x;
}

int Insere(int vetor[], int  a, int b, int* numComparacoes){
	int p, i;
	p = Busca(vetor, vetor[b],  a, b-1, numComparacoes);
	i = b;
	while  (i > p + 1){
		Troca(vetor,i,i-1);
		i--;
	}
	return *numComparacoes;
}

//Função auxiliar do insertion sort

int insertionSortAux(int vetor[], int a, int b){
	int numComparacoes = 0;

	if (a >= b)
		return 0;
	return insertionSortAux(vetor, a, b-1) + Insere(vetor, a, b, &numComparacoes);

}
int insertionSort(int vetor[], int tam){
	return insertionSortAux(vetor, 0, tam-1);
}

//Funções necessárias para o selection sort
int Minimo(int vetor[], int a, int b, int* numComp){
		int m;
		if (a == b)
		return a;
	m = Minimo(vetor, a, b-1, numComp);
	(*numComp)++;
	if (vetor[b] < vetor[m])
		m = b;
	return m;
} 

//Função auxíliar do selectionSort
int selectionSortAux(int vetor[], int a, int b){
	int numComp = 0;
	int numComp2 = 0;
	if (a >= b)
		return numComp + numComp2;
	Troca(vetor, a, Minimo(vetor,a,b, &numComp));
	numComp2 = selectionSortAux(vetor, a+1, b);	
	return numComp + numComp2;

}
int selectionSort(int vetor[], int tam){
	return selectionSortAux(vetor, 0, tam-1);
}

//Merge Sort
void  copiar(int vetor[], int a, int b, int u[]){
	int i,j=0;
	
	for (i=a; i <=b; i++){
		vetor[i] = u[i];
		j++;
	}       	
}
int merge(int vetor[], int a, int m, int b){
	int i, k, j, p;
	int u[b-a];
	int numComp2 = 0;
	if (a >=b)
		return numComp2;
	k = 0;
	i = a;
	j = m + 1;
	while (k <= b-a){
		numComp2++;
		if ((j > b) || (i <= m && vetor[i] <= vetor[j])){
			p = i;
			i++;
		}else{
			p = j;
			j++;
		}
			u[k] = vetor[p];
			k++;
		}
 	copiar(vetor, a, b, u);
	return numComp2;
}

int mergeSortAux(int vetor[], int a, int b){
	int m;
	if (a >= b)
		return 0;
	m = floor((a+b)/2);

	return merge(vetor, a, m, b) + mergeSortAux(vetor, a, m) + mergeSortAux(vetor, m+1, b);
}


int mergeSort(int vetor[], int tam){
	
	return mergeSortAux(vetor, 0, tam-1);
}
//Quick sort

int particiona(int vetor[], int a, int b, int x, int* numComparacoes){
    int i;
    int m = a - 1;  

    for(i=a; i<=b; i++){
        (*numComparacoes)++;
        if (vetor[i] <= x){
            m++;
            Troca(vetor, m, i);
        }
    }
    return m;
}

int quickSortAux(int vetor[], int a, int b){
    int m;
    int numComparacoes = 0;

    if (a>=b)
        return 0;
    
    m = particiona(vetor, a, b, vetor[b], &numComparacoes);
    
    return numComparacoes + quickSortAux(vetor, a, m-1) + quickSortAux(vetor, m+1, b);

}

int quickSort(int vetor[], int tam){
    return quickSortAux(vetor, 0, tam-1);
}


