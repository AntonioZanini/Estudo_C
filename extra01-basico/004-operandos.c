#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

bool isNumeric(char *num);
bool verificarOperandoDivisao(int operandoVerificado);

int main()
{

	/*Codigos ASCII:
	Ç = \x80		Õ = \xE5		Ã = \xC7		Ê = \xD2		Ú = \xE9		É = \x90
	*/
	bool sair = false;
	int operandoA = 0, operandoB = 0;
	float resultado;
	char charSelecao;
	char entrada[6];
	int entradaValida = 1;
	do 
	{
		printf("=======================================================\n");
		printf("                     OPERA%c%cES                         \n", '\x80', '\xE5');
		printf("=======================================================\n");
		printf(" OPERANDO A: %i                       OPERANDO B: %i\n", operandoA, operandoB);
		printf("-------------------------------------------------------\n");
		printf(" OP%c%cES:\n", '\x80', '\xE5');
		printf("-------------------------------------------------------\n");
		printf(" OPERADORES\n");
		printf(" + SOMA	    - SUBTRA%c%cO   / DIVIS%cO   * MULTIPLICA%c%cO\n", '\x80', '\xC7',  '\xC7', '\x80', '\xC7');
		printf(" % RESTO    P POT%cNCIA     R RAIZ QUADRADA\n", '\xD2');
		printf("-------------------------------------------------------\n");
		printf(" OPERANDOS\n");
		printf(" A Alterar Operando A            B Alterar Operando B\n");
		printf("-------------------------------------------------------\n");
		printf(" S Sair\n");
		printf("-------------------------------------------------------\n");
		printf(" SELECIONE A OP%c%cO DESEJADA: ", '\x80', '\xC7');
		charSelecao = toupper(getche());
		
		switch (charSelecao)
		{
			case ('+'):
				resultado = operandoA + operandoB;
				printf("\n\n\nO RESULTADO DA SOMA ENTRE %i E %i %c %.0f\n\n\n", operandoA, operandoB, '\x90', resultado);
			break;
			case ('-'):
				resultado = operandoA - operandoB;
				printf("\n\n\nO RESULTADO DA SUBTRA%c%cO ENTRE %i E %i %c %.0f\n\n\n", '\x80', '\xC7', operandoA, operandoB, '\x90', resultado);
			break;
			case ('/'):
				if (verificarOperandoDivisao(operandoB) == false)
					break;
				resultado = ((float) operandoA) / ((float) operandoB);
				printf("\n\n\nO RESULTADO DA DIVIS%cO ENTRE %i E %i %c %.2f\n\n\n", '\xC7', operandoA, operandoB, '\x90', resultado);
			break;
			case ('*'):
				resultado = operandoA * operandoB;
				printf("\n\n\nO RESULTADO DA MULTIPLICA%c%cO ENTRE %i E %i %c %.0f\n\n\n", '\x80', '\xC7', operandoA, operandoB, '\x90', resultado);
			break;
			case ('%'):
				if (verificarOperandoDivisao(operandoB) == false)
					break;
				resultado = operandoA % operandoB;
				printf("\n\n\nO RESTO DA DIVIS%cO ENTRE %i E %i %c %.0f\n\n\n", '\xC7', operandoA, operandoB, '\x90', resultado);
			break;
			case ('P'):
				resultado = pow(operandoA, operandoB);
				printf("\n\n\nO RESULTADO DA POTENCIA%c%cO DE %i A %i %c %.0f\n\n\n", '\x80', '\xC7', operandoA, operandoB, '\x90', resultado);
			break;
			case ('R'):
				resultado = sqrt((float) operandoA);
				printf("\n\n\nA RAIZ QUADRADA DE %i %c %.3f\n\n\n", operandoA, '\x90', resultado);
			break;
			case ('A'):
				do
				{
					printf("\n\n\nINSIRA UM NOVO VALOR INTEIRO PARA O OPERANDO A: ");
					scanf("%s", entrada);
					entradaValida = isNumeric(entrada);
					if (entradaValida)
						operandoA = atoi(entrada);
					else
						printf("\nN%cMERO INV%cLIDO!", '\xE9', '\xB5');

				} while (entradaValida != 1);
				printf("\n\n\n");
			break;
			case ('B'):
				do
				{
					printf("\n\n\nINSIRA UM NOVO VALOR INTEIRO PARA O OPERANDO B: ");
					scanf("%s", entrada);
					entradaValida = isNumeric(entrada);
					if (entradaValida)
						operandoB = atoi(entrada);
					else
						printf("\nN%cMERO INV%cLIDO!", '\xE9', '\xB5');

				} while (entradaValida != 1);
				printf("\n\n\n");
			break;
			case ('S'):
				sair = true;
			break;
			default:
				printf("Nao Foi\n");
		}
		getchar();
	} while (sair != true);
	return 0;
}

bool verificarOperandoDivisao(int operandoVerificado) 
{
	bool retorno = true;

	if (operandoVerificado == 0) 
	{
		printf("\n\n\n ERRO! DIVIS%cO POR ZERO!\n", '\xC7');
		printf(" ALTERE O OPERANDO B PARA UM N%cMERO DIFERENTE DE ZERO.\n\n\n", '\xE9');
		retorno = false;
	}

	return retorno;
}

bool isNumeric(char *num)
{
	bool retorno = true;
	int len = strlen(num);
	int x;
	for (x=0; x<len; x++)
	{
		if (!isdigit(num[x]))
			retorno = false;	
	}
	return retorno;
}