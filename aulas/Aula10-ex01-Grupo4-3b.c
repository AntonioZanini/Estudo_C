#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMITE 0.000001f

int main(int argc, char const *argv[])
{
	float termo, total, valor;
	int i;
	printf("DIGITE VALOR PARA A POTENCIA: ");
	scanf("%f", &valor);
	termo 	= 1.0f;
	total 	= 1.0f;
	i 		= 1;
	do
	{
		termo = termo * (valor / i);
		total = total + termo;
		i++;
	} while (fabs(termo) >= LIMITE);
	
	printf("\nRESULTADO: %f\n", total);
	system("pause");
	return 0;
}