#include <stdio.h>
#include <stdlib.h>

float soma(float a, float b) 
{
	return (a + b);
}

int main () 
{
	float valor_a, valor_b;
	do {
		printf(" Insira o valor de A: ");
		scanf("%f", &valor_a);
		printf(" Insira o valor de B: ");
		scanf("%f", &valor_b);
		printf("\n %.2f + %.2f = %.2f\n\n", valor_a, valor_b, soma(valor_a, valor_b));
	} while ((0 != valor_a) || (0 != valor_a));
	system("pause");
	return 0;
}
