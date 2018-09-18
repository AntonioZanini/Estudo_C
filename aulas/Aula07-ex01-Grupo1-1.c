#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	float primeiro_numero, segundo_numero;
	printf("Insira primeiro numero: ");
	scanf("%f", &primeiro_numero);
	printf("Insira segundo numero: ");
	scanf("%f", &segundo_numero);

	printf("Soma: %.3f\n", (primeiro_numero + segundo_numero));
	printf("a*(b*b): %.3f\n", (primeiro_numero * pow(segundo_numero,2)));
	printf("a*a: %.3f\n", pow(primeiro_numero,2));
	printf("Raiz de ((a*a)+(b*b)): %.3f \n", sqrt(pow(primeiro_numero,2)+pow(segundo_numero,2)));
	printf("Seno de (a - b): %.3f\n", sin(primeiro_numero - segundo_numero));
	printf("Modulo de a: %.3f\n", fabs(primeiro_numero));
	return 0;
}
