#include <stdio.h>
#include <stdlib.h>

/* Programa que executa o método de ordenação Merge Sort 
   em uma sequência aleatória de valores inteiros 			*/

#define COMPRIMENTO 10	/* Constante para tamanho da matriz de ordenação. */

void 	merge_sort	(int *, int);

int main(int argc, char const *argv[])  /* Função principal que cria a matriz numérica, chama a */
{										/* rotina de ordenação e faz as exibições na tela. 		*/
	int x;		/* Incremento de for */
	int lista_num[COMPRIMENTO] = { 5, 4, 9, 3, 2, 8, 7, 1, 10, 6 }; /* Matriz para ordenação. */
	printf(" DESORDENADO:\n  ");
	for (x = 0; x < COMPRIMENTO; x++) {		/* Exibição dos números desdordenados. */
		printf(" %i ", lista_num[x]);
		if (COMPRIMENTO != x+1)
			printf("-");
	}
	printf("\n ORDENADO:\n  ");
	merge_sort(lista_num, COMPRIMENTO);		/* Chama rotina de ordenação. 		*/
	for (x = 0; x < COMPRIMENTO; x++) {		/* Exibição dos números ordenados. 	*/
		printf(" %i ", lista_num[x]);
		if (COMPRIMENTO != x+1)
			printf("-");
	}
	printf("\n\n");
	return 0;
}

void merge_sort(int *lista, int tamanho)	/* Rotina que realiza o método de ordenação MergeSort. */
{
	int x, y, i = 0, y_ini = 0;			/* Variáveis auxiliares para a ordenação. */
	int *bloco_a;						/* Armazenará a primeira metade da lista. */
	int *bloco_b;						/* Armazenará a segunda metade da lista.	 */
	int tamanho_a 	= (tamanho / 2);	/* Armazenando os tamanhos das metades. */
	int tamanho_b 	= (tamanho / 2) + (tamanho % 2);
	bloco_a 		= malloc(sizeof(int) * tamanho_a);	/* Alocando o tamanho de um array de 	 */
	bloco_b 		= malloc(sizeof(int) * tamanho_b);	/* números inteiros com o tamanho certo. */

	for (x = 0; x < tamanho_a; x++ ) {	/* Adicionando primeira metade da lista ao bloco_a. */
		bloco_a[x] = lista[x];
	}
	for (x = 0; x < tamanho_b; x++) {	/* Adicionando segunda metade da lista ao bloco_b. */
		bloco_b[x] = lista[x+tamanho_a];
	}

	if (1 < tamanho_a)					/* Se ainda for possível dividir, usa a recursividade para 	*/
		merge_sort(bloco_a, tamanho_a);	/* dividir a lista até sobrar apenas valores unitários. 	*/
	if (1 < tamanho_b)
		merge_sort(bloco_b, tamanho_b);

	for (x = 0; x < tamanho_a; x++)		/* Laços de ordenação. */
	{
		for (y = y_ini; y < tamanho_b; y++) /* Elementos do bloco_a são comparados ao bloco_b para 	*/
		{									/* determinar quais serão reinseridos primeiro na lista.*/
			if (bloco_a[x] >= bloco_b[y]){
				lista[i] = bloco_b[y];
				i++;
				y_ini++;
			}
		}
		lista[i] = bloco_a[x];
		i++;
	}
	
	if (y_ini < tamanho_b) {			/* Caso ainda sobrem valores no bloco_b não reincorporados	*/
		for (y = y_ini; y < tamanho_b; y++)	/* à lista, eles serão adicionados ao final da lista. 	*/
		{
			lista[i] = bloco_b[y];
			i++;
		}
	}
}