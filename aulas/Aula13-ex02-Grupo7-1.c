#include <stdio.h>
#include <string.h>

#define U_MI_AGUDO 		'\xA3' 	/* ú */

int contar_minusculas(char *);
int contar_pontuacao(char *string);
int contar_numeros(char *string);

int main(int argc, char const *argv[])
{
	char palavra[80];
	int tamanho, letras_min, qtd_num, qdt_pont;
	printf("\n Insira uma palavra: ");
	scanf("%s", palavra);

	printf("\n Palavra inserida: %s\n\n", palavra);
	
	tamanho = strlen(palavra);
	letras_min = contar_minusculas(palavra);
	qtd_num = contar_numeros(palavra);
	qdt_pont = contar_pontuacao(palavra);
	
	printf(" Tamanho: %i\n", tamanho);
	printf(" Min%csculas: %i\n", U_MI_AGUDO, letras_min);
	printf(" N%cmeros: %i\n", U_MI_AGUDO, qtd_num);
	printf(" Pontuacao: %i\n", qdt_pont);
	
	return 0;
}


int contar_minusculas(char *string)
{
	int max, i, somatoria = 0;
	max = strlen(string);
	for (i = 0; i < max; i++)
		if(string[i] > 96 && string[i] < 123)
			somatoria++;
	return somatoria;
}

int contar_numeros(char *string)
{
	int max, i, somatoria = 0;
	max = strlen(string);
	for (i = 0; i < max; i++)
		if(string[i] > 47 && string[i] < 58)
			somatoria++;
	return somatoria;
}

int contar_pontuacao(char *string)
{
	int max, i, j, somatoria = 0, pont_max;
	char pontuacao[] = ",.:;-!?()";
	pont_max = strlen(pontuacao);
	max = strlen(string);
	for (i = 0; i < max; i++){
		for (j = 0; j < pont_max; j++)
		{
			if(string[i] == pontuacao[j]){
				somatoria++;
				break;
			}
		}
	}
	return somatoria;
}
