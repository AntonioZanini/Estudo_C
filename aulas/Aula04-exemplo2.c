#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
main ()
{
	float n1, n2;
	char r;
	printf("Introduza o primeiro valor\n");
	scanf("%f", &n1);
	printf("Introduza o segundo valor\n");
	scanf("%f", &n2);
	if (n1 == n2)
		printf("%.2f igual a %.2f\n", n1, n2 );
	else if (n1 < n2)
		printf("%.2f maior do que %.2f\n", n2, n1);
	else
		printf("%.2f maior do que %.2f\n", n1, n2);			
	system("pause");
}