#include <stdio.h>
#include <stdio.h>
#include <math.h>

double		fatorial 	(int n);
float 		euler		(int x);
float 		e 			(int x, int i);

int main(int argc, char const *argv[])
{
	int valor;

		valor = 0;
		printf("\n\nDIGITE VALOR PARA A POTENCIA: ");
		scanf("%i", &valor);

		printf("RESULTADO DE E^%i: %.4f", valor, euler(valor));
}

float euler(int x)
{
	float resultado;
	resultado = e(x, 1) + 1;
	return resultado;
}

float e(int x, int i)
{
	float total = 0;
	total = (pow(x, i) / fatorial(i));
	if (fabs(total) >= 0.000001f)
		total += e(x, i + 1);

	return total;
}

double fatorial(int n)
{
	double total = 1;
	if (n >= 1)
		total *= n * fatorial(n - 1); 

	return (total);
}
