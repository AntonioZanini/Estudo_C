#include <stdio.h>
#include <stdlib.h>
int main()
{
	double c;
	int f;
	printf("DIGITE O VALOR NA ESCALA FAHREINHEIT PARA CONVERTER EM CELSIUS:\n");
	scanf("%i", &f);
	c = (f - 32) * (5/9);
	printf("O VALOR EM CELSIUS PARA %i GRAUS FAHREINHEIT EQUIVALE A %.2f.\n",  f, c);
	return 0;
}