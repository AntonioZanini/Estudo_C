#include <stdio.h>
#include <stdlib.h>

int main()
{
	double c, f;
	printf("DIGITE O VALOR NA ESCALA FAHREINHEIT PARA CONVERTER EM CELSIUS:\n");
	scanf("%lf", &f);

	c = (f - 32.0) * (5.0/9.0);
	printf("O VALOR EM CELSIUS PARA %.2f GRAUS FAHREINHEIT EQUIVALE A %.2f.\n",  f, c);
	return 0;
}