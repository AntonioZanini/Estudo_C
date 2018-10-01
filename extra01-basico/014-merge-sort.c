#include <stdio.h>
#include <stdlib.h>

#define COMPRIMENTO 10

void 	merge_sort	(int *, int);

int main(int argc, char const *argv[])
{
	int x;
	int lista_num[COMPRIMENTO] = { 5, 4, 9, 3, 2, 8, 7, 1, 10, 6 };
	printf(" DESORDENADO:\n  ");
	for (x = 0; x < COMPRIMENTO; x++) {
		printf(" %i ", lista_num[x]);
		if (COMPRIMENTO != x+1)
			printf("-");
	}
	printf("\n ORDENADO:\n  ");
	merge_sort(lista_num, COMPRIMENTO);
	for (x = 0; x < COMPRIMENTO; x++) {
		printf(" %i ", lista_num[x]);
		if (COMPRIMENTO != x+1)
			printf("-");
	}
	printf("\n\n");
	return 0;
}

void merge_sort(int *lista, int tamanho)
{
	int x, y, i = 0, y_ini = 0;
	int *bloco_a;
	int *bloco_b;
	int tamanho_a 	= (tamanho / 2);
	int tamanho_b 	= (tamanho / 2) + (tamanho % 2);
	bloco_a 		= malloc(sizeof(int) * tamanho_a);
	bloco_b 		= malloc(sizeof(int) * tamanho_b);

	for (x = 0; x < tamanho_a; x++ ) {
		bloco_a[x] = lista[x];
	}
	for (x = 0; x < tamanho_b; x++) {
		bloco_b[x] = lista[x+tamanho_a];
	}

	if (1 < tamanho_a)
		merge_sort(bloco_a, tamanho_a);
	if (1 < tamanho_b)
		merge_sort(bloco_b, tamanho_b);

	for (x = 0; x < tamanho_a; x++)
	{
		for (y = y_ini; y < tamanho_b; y++)
		{
			if (bloco_a[x] >= bloco_b[y]){
				lista[i] = bloco_b[y];
				i++;
				y_ini++;
			}
		}
		lista[i] = bloco_a[x];
		i++;
	}
	
	if (y_ini < tamanho_b) {
		for (y = y_ini; y < tamanho_b; y++)
		{
			lista[i] = bloco_b[y];
			i++;
		}
	}
}