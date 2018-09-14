#include <stdio.h>
#include <stdlib.h>

int main()
{
	float val1, val2;

	printf(" Insira o primeiro numero: ");
	scanf("%f", &val1);
	printf(" Insira o segundo numero: ");
	scanf("%f", &val2);

	if (val1 > val2) {
		printf(" \n\nNumeros: %.2f - %.2f\n\n", val2, val1);
	}
	else if (val1 < val2) {
		printf(" \n\nNumeros: %.2f - %.2f\n\n", val1, val2);
	}
	else if (val1 == val2) {
		printf(" \n\nNumeros iguais.\n\n");
	}
	system("pause");
	return 0;
}
