#include <stdio.h>
#include <stdlib.h>
int main()
{
	float val1, val2;
	int a;
	for (;;){
		printf(" Insira o primeiro numero: ");
		scanf("%f", &val1);
		printf(" Insira o segundo numero: ");
		scanf("%f", &val2);
		if (val1 > val2 || val1 < val2) {
			printf(" \n\nNumeros diferentes\n\n");
		}
		else if (val1 == val2) {
			printf(" \n\nNumeros iguais.\n\n");
		}
	}
	return 0;
}
