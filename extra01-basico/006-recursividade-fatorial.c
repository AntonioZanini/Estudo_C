#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

long fatorial(int n);

int main()
{
	int valor;
	long resultado;
	printf("DIGITE O N%cMERO PARA DESCOBRIR SEU FATORIAL: ", '\xE9');
	scanf("%d", &valor);

	resultado = fatorial(valor);

	printf("%d! = %d", valor, resultado);
	getch();
	return 0;
}

long fatorial(int n)
{
	long total = n;
	if (n > 1)
	{
		total *= fatorial(n - 1);
	}
	return total;
}