#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, t[10], num;
	printf("DIGITE O VALOR PARA CALCULAR A TABUADA: ");
	scanf("%i", &num);
	printf("\n\n  TABUADA DO %i:\n", num);
	printf("================\n");

	for (i = 0; i < 11; i++)
	{
		t[i] = (num) * (i);
	}
	for (i = 0; i < 11; i++)
	{
		printf(" %2d x %2d = %3d\n", num, i, t[i]);
	}
	system("pause");
	return 0;
}

