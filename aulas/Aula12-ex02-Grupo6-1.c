#include <stdio.h>
#include <stdlib.h>

#define U_MI_AGUDO 		'\xA3' 	/* ú */
#define ORDINAL_MASC	'\xA7' 	/* º */

int main()
{
	int i, num[10], maior, menor;
	for (i = 0; i < 10; i++) {
		printf(" Insira o %2i%c n%cmero: ", i+1, ORDINAL_MASC, U_MI_AGUDO);
		scanf("%i", &num[i]);
	}
	menor = num[0];
	maior = num[0];
	for (i = 1; i < 10; i++) {
		if (menor > num[i])
			menor = num[i];

		if (maior < num[i])
			maior = num[i];
	}
	printf("\n Menor: %i\n Maior: %i\n\n", menor, maior);
	system("pause");
	return 0;
}