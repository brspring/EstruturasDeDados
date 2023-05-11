#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "sort.h"

int main()
{
	tabela_t** t1 = hash_init(m);
	tabela_t** t2 = hash_init(m);
	tabela_t** aux = hash_init(m*2);

    int chave;

	char c;
	scanf("%c", &c);
	while (!feof(stdin))
	{
		if (c == 'i')
		{
			scanf(" %d", &chave);
			insere_hash(t1, t2, chave);
		}
		else if (c == 'r')
		{
			scanf(" %d", &chave);
			remove_hash(t1, t2, chave);
		}
		scanf("%c", &c);
	}

	int index = hash_merge(t1, t2, aux);
	sort (aux, 0, index);
	imprime_hash(aux);
    destroi_hash(t1);
	destroi_hash(t2);
	free(aux);

	return 0;
}
