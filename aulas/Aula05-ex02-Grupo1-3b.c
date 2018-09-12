#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	printf("     VALORES E CARACTERES\n");
	printf("================================\n");
	printf("  Dec\tHexa\tOcta\tChar\n");
	
	for (i = 0; i < 256; i++)
	{
		printf("  %3d\t%4x\t%4o\t%2c\n", i, i, i, i);
	}
	system("pause");
	return 0;
}
