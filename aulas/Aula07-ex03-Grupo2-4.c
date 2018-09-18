#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	int op1, op2, resultado;
	char opr;
	do {
	printf("Insira o operando 1: ");
	scanf("%i", &op1);
	printf("Insira o operador (+,-,*,/): ");
	opr = getche();
	printf("\nInsira o operando 2: ");
	scanf("%i", &op2);
	if (opr == '+')
		resultado = op1 + op2;
	else if (opr == '-') 
		resultado = op1 - op2;
	else if (opr == '*')
		resultado = op1 * op2;
	else if (opr == '/')
		resultado = op1 / op2;

	printf("\nResultado %d %c %d = %d \n\n", op1, opr, op2, resultado);
	} while (opr != 's');
	return 0;
}
