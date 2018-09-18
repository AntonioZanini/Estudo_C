#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	float preco, inflacao, resultado;
	printf("Insira o valor do preco: ");
	scanf("%f", &preco);
	inflacao = 10 + (10 * (preco >= 100));
	resultado = preco * (1 + (inflacao/100.00));
	printf("Preco inflacionado: %.2f\n", resultado);
	return 0;
}
