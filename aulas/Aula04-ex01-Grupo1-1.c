#include <stdio.h>
#include <stdlib.h>

main()
{
	float metros, decimetros, centimetros, milimetros;
	printf("Insira um valor em metros: ");
	scanf("%f", &metros);
	decimetros = metros * 10;
	centimetros = metros * 100;
	milimetros = metros * 1000;
	printf(" %.2f metros equivale a %.2f decimetros.\n", metros, decimetros);
	printf(" %.2f metros equivale a %.2f centimetros.\n", metros, centimetros);
	printf(" %.2f metros equivale a %.2f milimetros.\n", metros, milimetros);
	system("pause");
}
