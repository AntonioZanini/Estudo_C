#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 5

int main(int argc, char const *argv[])
{
	int x = 0;
	float provas_turma[MAX_ALUNOS][2];
	float nota_1, nota_2;
	float media_aluno, media_classe = 0;
	int num_alunos;
	do {
		printf("\nINSIRA AS NOTAS DO %io ALUNO:\n", x+1);
		printf("-------------------------------");
		printf("\nNOTA DA PRIMEIRA PROVA: ");
		do {
			scanf("%f", &nota_1);
			if ((0 > nota_1) || ((10 < nota_1) && 50 != nota_1))
				printf("\nNOTA INVALIDA!\nINSIRA NOVO VALOR: ");
		} while ((0 > nota_1) || ((10 < nota_1) && 50 != nota_1));
		if (50 == nota_1) {
			break;
		}
		printf("\nNOTA DA SEGUNDA PROVA: ");
		do {
			scanf("%f", &nota_2);
			if ((0 > nota_2) || (10 < nota_2))
				printf("\nNOTA INVALIDA!\nINSIRA NOVO VALOR: ");
		} while ((0 > nota_2) || (10 < nota_2));
		provas_turma[x][0] = nota_1;
		provas_turma[x][1] = nota_2;
		x++;
	} while (MAX_ALUNOS > x);
	num_alunos = x;
	printf("\n\nMEDIAS:\n\n");
	for (x = 0; x < num_alunos; x++)
	{
		media_aluno = (provas_turma[x][0] + provas_turma[x][1]) / 2.0;
		printf("ALUNO %i P1: %.2f P2: %.2f M: %.2f\n", x +1, provas_turma[x][0], provas_turma[x][1],  media_aluno);
		media_classe += media_aluno;
	}
	media_classe = media_classe / num_alunos;
	printf("\nMEDIA DA CLASSE: %.2f\n\n", media_classe);
	system("pause");
	return 0;
}
