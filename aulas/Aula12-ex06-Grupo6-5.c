#include <stdio.h>
#include <stdlib.h>

#define E_MI_AGUDO			'\x82' 	/* é */

float media(int *);

int main(int argc, char const *argv[])
{
	int valores[10] = {2, 2, 2, 2, 3 , 3, 3, 1, 1 ,1};
	int i;
	float media_geral;
	media_geral = media(valores);
	printf("\n\n M%cdia: %.2f\n\n", E_MI_AGUDO, media_geral);
	for (i = 0; i < 10; i++) {
		if (valores[i] == media_geral)
			printf(" Valor mediano: %i \n", valores[i] );
	}
	return 0;
}

float media(int *valores)
{
	int i, soma = 0;
	for (i = 0; i < 10; i++) {
		soma += valores[i];
	}
	return (soma / 10.0);
}
