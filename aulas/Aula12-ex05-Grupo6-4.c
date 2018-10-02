#include <stdio.h>
#include <stdlib.h>

#define QUANTIDADE_MATERIAS 	6
#define ORDINAL_FEM			'\xA6' 	/* ª */
#define E_MI_AGUDO			'\x82' 	/* é */

int main(int argc, char const *argv[])
{
	int i;
	double medias[QUANTIDADE_MATERIAS];

	preencher_medias(medias);

	printf("\n\n M%cdias: \n\n", E_MI_AGUDO);
	for (i = 0; i < QUANTIDADE_MATERIAS; i++) {
		printf(" %.2lf ", medias[i]);
		if (i != (QUANTIDADE_MATERIAS - 1))
			printf("-");
		else
			printf("\n\n");
	}
	system("pause");
	return 0;
}

void preencher_medias(double *medias)
{
	int i;
	for (i = 0; i < QUANTIDADE_MATERIAS; i++) {
		printf(" Insira a m%cdia da %2i%c mat%cria do aluno: ", E_MI_AGUDO, i+1, ORDINAL_FEM, E_MI_AGUDO);
		scanf("%lf", &medias[i]);
	}
}