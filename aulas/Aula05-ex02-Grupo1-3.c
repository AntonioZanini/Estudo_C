#include <stdio.h>
#include <stdlib.h>

int main()
{
	int decimal;
	printf("DIGITE UM VALOR DECIMAL PARA SER CONVERTIDO: ");
	scanf("%i", &decimal);
	
	printf("\n=====================================\n");
	printf("\n\n %i EQUIVALE:\n", decimal);
	printf("=====================================\n");
	printf(" Hexa  \tOcta \n", decimal, decimal);
	printf(" %4x \t%4o\n\n", decimal, decimal );

	system("pause");
	return 0;
}
