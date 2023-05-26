#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"
#define TAM 1000

//FUNÇÕES QUE CALCULAM O TEMPO DE CADA ORDENAÇÃO
void preenche_vetor(int vetor[], int tam){
    int i;
    for (i=0; i<tam; i++)
       vetor[i] = rand()%10000;
}
double tempoInsertionSort(int vetor[], int tamVetor, int* numComp, int qtTeste){
    clock_t start, end;
    double total = 0;
    int i;
    *numComp = 0;

    for(i=0; i<qtTeste; i++){
        preenche_vetor(vetor, tamVetor);
        start = clock();
        *numComp += insertionSort(vetor, tamVetor);
        end = clock();
        total += ((double)end - start)/CLOCKS_PER_SEC;
    }
    *numComp = *numComp / qtTeste; 
    total = total / qtTeste;
    return total;
}
double tempoSelectionSort(int vetor[], int tamVetor, int* numComp, int qtTeste){
    clock_t start, end;
    double total = 0;
    int i;
    *numComp = 0;

    for(i=0; i<qtTeste; i++){
        preenche_vetor(vetor, tamVetor);
        start = clock();
        *numComp += selectionSort(vetor, tamVetor);
        end = clock();
        total += ((double)end - start)/CLOCKS_PER_SEC;
    }
    *numComp = *numComp / qtTeste; 
    total = total / qtTeste;
    return total;
}
double tempoMergeSort(int vetor[], int tamVetor, int* numComp, int qtTeste){
    clock_t start, end;
    double total = 0;
    int i;
    *numComp = 0;

    for(i=0; i<qtTeste; i++){
        preenche_vetor(vetor, tamVetor);
        start = clock();
        *numComp += mergeSort(vetor, tamVetor);
        end = clock();
        total += ((double)end - start)/CLOCKS_PER_SEC;
    }
    *numComp = *numComp / qtTeste; 
    total = total / qtTeste;
    return total;
}

double tempoQuickSort(int vetor[], int tamVetor, int* numComp, int qtTeste){
    clock_t start, end;
    double total = 0;
    int i;
    *numComp = 0;

    for(i=0; i<qtTeste; i++){
        preenche_vetor(vetor, tamVetor);
        start = clock();
        *numComp += quickSort(vetor, tamVetor);
        end = clock();
        total += ((double)end - start)/CLOCKS_PER_SEC;
    }
    *numComp = *numComp / qtTeste; 
    total = total / qtTeste;
    return total;
}

//FUNÇÃO PRINCIPAL
int main(){
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp;
	double totalSec;

	//Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
	int qtTeste = 100;
	int tamVetor = TAM;
	int* vetor = malloc(tamVetor * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	getNome(nome);
	printf("\nTrabalho de %s\n", nome);
	
	printf("\nGRR %u\n", getGRR());
	totalSec = tempoInsertionSort(vetor, tamVetor, &numComp, qtTeste);
 	printf("\nORDENAÇÕES\n");
    	printf("\nInsertion Sort: %f segundos e  %d comparações\n", totalSec, numComp);
    
    	totalSec = tempoSelectionSort(vetor, tamVetor, &numComp, qtTeste);

    	printf("\nSelection Sort: %f segundos e %d comparações\n", totalSec, numComp);

    	totalSec = tempoMergeSort(vetor, tamVetor, &numComp, qtTeste);

    	printf("\nMerge Sort: %f segundos e %d comparações\n", totalSec, numComp);

    	totalSec = tempoQuickSort(vetor, tamVetor, &numComp, qtTeste);

    	printf("\nQuick Sort: %f segundos e  %d comparações\n", totalSec, numComp);
	printf("\n");
	printf("\nBUSCAS\n");
	idxBusca = buscaSequencial(vetor, TAM, 10, &numComp);
	printf("\nBusca sequencial: %d\nNum de comparacoes:  %d", idxBusca, numComp);
        printf("\n");

	idxBusca = buscaBinaria(vetor, TAM, 10, &numComp);

	printf("\nBusca binária: %d\nNum de comparacoes:  %d", idxBusca, numComp);
	printf("\n");

	//É obrigatório que você libere a memória alocada dinâmicamente via fee
	free(vetor);

	return 0;
}
