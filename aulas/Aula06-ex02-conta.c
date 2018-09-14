#include <stdio.h>
#include <stdlib.h>

int main()
{
	float c, f;
	printf(" Insira um n%cmero em graus Celsius: " , '\xA3');
	scanf("%f", &c);

	f = (c * (9.0/5.0)) + 32.0;

	printf("\n\n %.2f graus celsius equivale a %.2f graus fahrenheit.\n\n", c, f);
	system("pause");
	return 0;
}