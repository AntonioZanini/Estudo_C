#include <stdio.h>
#include <windows.h>
#include <dos.h>

int main(int argc, char const *argv[])
{
	int valor, total;
	/*
	Beep(10000, 600);
	Beep(2000, 600);
	Beep(1250, 600);
 	Beep(1000, 600);
	Beep(750, 600);
 	Beep(500, 600);
 	Beep(250, 600);*/
 	sound(100);
	printf("Insira valor: ");
	scanf("%d", &valor);

	total = (valor - 32) * (5/9);
	printf("Total: %d" , total);
	return 0;
}
