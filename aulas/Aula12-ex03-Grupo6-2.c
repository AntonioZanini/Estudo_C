#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define U_MI_AGUDO 		'\xA3' 	/* ú */
#define ORDINAL_MASC	'\xA7' 	/* º */

void ordenar(int *, int);

int main()
{
	int i, num[10];
	for (i = 0; i < 10; i++) {
		printf(" Insira o %2i%c n%cmero: ", i+1, ORDINAL_MASC, U_MI_AGUDO);
		scanf("%i", &num[i]);
	}
	ordenar(num, 10);
	printf("\n N%cmeros Ordenados: \n\n", U_MI_AGUDO);
	for (i = 0; i < 10; i++) {
		printf(" %i ", num[i]);
		if (i != 9)
			printf("-");
		else
			printf("\n\n");
	}

	system("pause");
	return 0;
}

void ordenar(int *lista, int tamanho)
{
	int aux, final, i;
	bool ordenado;
	final = tamanho - 1;
	do {
		ordenado = true;
		for (i = 0; i < final; i++) {
			if (lista[i] > lista[i+1]) {
				aux = lista[i+1];
				lista[i+1] = lista[i];
				lista[i] = aux;
				ordenado = false;
			}
		}
		final--;
	} while (!ordenado);
}
