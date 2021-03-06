#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Programa: ORDENAÇÕES */
/* Descrição: */
/* Programa que gera uma sequência numérica e a ordena utilizando múltiplos algoritmos de ordenação. */


/* CONSTANTES */
#define FAIXA 100					/* Constantes de para facilitar alteração de valores chave do programa, */
#define COMPRIMENTO 10				/* como faixa para a geração de números aleatórios ou o comprimento padrão das matrizes. */

#define Ccedil '\x80'				/* Constantes para exibição de caracteres utf-8. */
#define Atilde '\xC7'
#define Otilde '\xE5'

void OrdenaBolha(int * lista);
void OrdenaSelecao(int * lista);
void OrdenaInsercao(int * lista);
void GerarOriginal(int * lista);
void CopiaLista(int * original, int * lista);

int main ()
{	/* Declaração das matrizes utilizadas, a que receberá os números aleatórios e as que receberão as ordenações. */
	int original[COMPRIMENTO], lb[COMPRIMENTO], ls[COMPRIMENTO], li[COMPRIMENTO], lq[COMPRIMENTO];
	int i;

	GerarOriginal(original);		/* Chama função que gera número aleatórios e preenche a matriz original, */
									/* a geração é baseada nos valores de FAIXA e COMPRIMENTO. */
	CopiaLista(original, lb);
	CopiaLista(original, ls);		/* Executa função que copia a matriz aleatória para cada uma das matrizes a */
	CopiaLista(original, li);		/* serem ordenadas. */
	CopiaLista(original, lq);

	OrdenaBolha(lb);				/* Executa a função de ordenação enviando uma matriz a sua respectiva função. */
	OrdenaSelecao(ls);
	OrdenaInsercao(li);
	OrdenaQuick(lq);
									/* Tela de Exibição. */
	printf("=============================================================================\n\n");
	printf("                                  ORDENA%c%cES\n\n", Ccedil, Otilde);
	printf("=============================================================================\n\n");
	printf("                VALORES ORIGINAIS: ");
	for (i = 0; i < COMPRIMENTO; i++)
	{
		printf("%d", original[i]);
		if (i == (COMPRIMENTO - 1))
			printf("\n");
		else
			printf("-");
	}
	printf("\n=============================================================================\n\n");
	printf("                                ORDENA%c%cO BOLHA: ", Ccedil, Atilde);
	for (i = 0; i < COMPRIMENTO; i++)
	{
		printf("%i", lb[i]);
		if (i == (COMPRIMENTO - 1))
			printf("\n");
		else
			printf("-");
	}
	printf("\n=============================================================================\n\n");
	printf("                          ORDENA%c%cO POR SELE%c%cO: ", Ccedil, Atilde, Ccedil, Atilde);
	for (i = 0; i < COMPRIMENTO; i++)
	{
		printf("%i", ls[i]);
		if (i == (COMPRIMENTO - 1))
			printf("\n");
		else
			printf("-");
	}
	printf("\n=============================================================================\n\n");
	printf("                         ORDENA%c%cO POR INSER%c%cO: ", Ccedil, Atilde, Ccedil, Atilde);
	for (i = 0; i < COMPRIMENTO; i++)
	{
		printf("%i", li[i]);
		if (i == (COMPRIMENTO - 1))
			printf("\n");
		else
			printf("-");
	}
	printf("\n=============================================================================\n\n");
	printf("                         ORDENA%c%cO POR QUCK SORT: ", Ccedil, Atilde);
	for (i = 0; i < COMPRIMENTO; i++)
	{
		printf("%i", lq[i]);
		if (i == (COMPRIMENTO - 1))
			printf("\n");
		else
			printf("-");
	}
	printf("\n=============================================================================\n");
	return 0;
}

void OrdenaBolha(int * lista)			/* Função que realizada a ordenação de uma matriz numérica por BubbleSort */
{
	int x, aux =0, ultimoOrdenado;
	bool novamente;
	ultimoOrdenado = COMPRIMENTO - 1;
	do
	{
		novamente = false;
		for (x = 0; x < ultimoOrdenado; x++)
		{
			if (lista[x] > lista[x+1])
			{
				aux = lista[x];
				lista[x] = lista[x+1];
				lista[x+1] = aux;
				novamente = true;
			}
		}
		ultimoOrdenado = x;
	} while (novamente);
}

void OrdenaSelecao(int * lista)			/* Função que realizada a ordenação de uma matriz numérica por SelectionSort */
{
	int x, aux, indAux, primeiro = 0;
	aux = primeiro;
	do
	{
		indAux = primeiro;
		aux = lista[indAux];
		for (x = primeiro + 1; x < COMPRIMENTO; x++)
		{
			if (aux > lista[x])
			{
				aux = lista[x];
				indAux = x;
			}
		}
		lista[indAux] = lista[primeiro];
		lista[primeiro] = aux;
		primeiro++;
	} while (primeiro < (COMPRIMENTO -1));
}

void OrdenaInsercao(int * lista)		/* Função que realizada a ordenação de uma matriz numérica por InsertionSort */
{
	int y, x, indSorted = 0, indSorting, aux;
	for (x = indSorted+1; x < COMPRIMENTO; x++)
	{
		if (lista[indSorted] > lista[x])
		{
			indSorting = x;
			for (y = (x - 1); y >= 0; y--)
			{
				if (lista[y] > lista[indSorting])
				{
					aux = lista[y];
					lista[y] = lista[indSorting];
					lista[indSorting] = aux;
					indSorting = y;
				}
			}
		}
		indSorted = x;
	}
}

void OrdenaQuick(int * lista)		/* Função que realizada a ordenação de uma matriz numérica por QuickSort */
{
	QuickSetor(lista, 0, (COMPRIMENTO - 1));
}

void QuickSetor(int * lista, int inicial, int final)	/* Função efetiva que realiza o processo de QuickSort através de  */
{														/* execuções recursivas. */
	int pivot, wall, x, aux;
	pivot = final;
	wall = inicial;
	if (inicial < final)
	{
		for (x = inicial; x < final; x++)
		{
			if (lista[pivot] > lista[x])
			{
				aux = lista[wall];
				lista[wall] = lista[x];
				lista[x] = aux;
				wall++;
			}
		}
		aux = lista[wall];
		lista[wall] = lista[pivot];
		lista[pivot] = aux;
		QuickSetor(lista, inicial, (wall - 1));
		QuickSetor(lista, (wall + 1), final);
	}
}

void GerarOriginal(int * lista)						/* Função que gera uma matriz aleatória de COMPRIMENTO números com */
{													/* valores que varias de 0 à FAIXA - 1. */
	int x;
	srand(time(NULL));
	for (x = 0; x < COMPRIMENTO; x++)
	{
		lista[x] = rand() % FAIXA;
	}
}

void CopiaLista(int * original, int * lista)		/* Função que copia cada elemento de uma matriz inteira para outra. */
{
	int x;
	for (x = 0; x < COMPRIMENTO; x++)
	{
		lista[x] = original[x];
	}
}
