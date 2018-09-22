#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	float bolsa[10], variacao_bolsa[9];
	int i;
	for (i = 0; i < 10; i++) {
		printf("Insira o valor da bolsa durante o periodo %2i : ", i + 1);
		scanf("%f", &bolsa[i]);
		if (i != 0) {
			variacao_bolsa[i-1] = (bolsa[i] - bolsa[i-1]);
		}
	}
	for (i = 0; i < 9; i++) {
		printf("A variacao %i : %.2f\n", i + 1, variacao_bolsa[i] );
	}
	system("pause");
	return 0;
}