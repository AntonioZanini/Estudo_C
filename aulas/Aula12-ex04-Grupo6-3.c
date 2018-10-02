#include <stdio.h>
#include <stdlib.h>

#define ORDINAL_FEM		'\xA6' 	/* ª */
#define E_MI_AGUDO		'\x82' 	/* é */

float media(int *, int);

int main(int argc, char const *argv[])
{
	int i, notas[5];
	for (i = 0; i < 5; i++) {
		printf(" Insira a %2i%c nota do aluno: ", i+1, ORDINAL_FEM);
		scanf("%i", &notas[i]);
	}
	printf("\n A m%cdia do aluno %c: %.2f", E_MI_AGUDO, E_MI_AGUDO, media(notas, 5));
	return 0;
}

float media(int *notas, int quantidade)
{
	int i, total = 0;
	for (i = 0; i < quantidade; i++) {
		total += notas[i];
	}
	return (total / (quantidade * 1.0f));
}
