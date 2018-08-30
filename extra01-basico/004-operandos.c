#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>		/* Biblioteca que adiciona funcionalidades para testar e manipular caracteres, ex: isdigit() e toupper(). */
#include <math.h>		/* Biblioteca que adiciona funcionalidades de operações matemáticas avançadas, ex: sin(), log(), sqrt() e pow(). */
#include <string.h>		/* Biblioteca que adiciona funcionalidades de manipulação de cadeias de caracteres, ex: strlen(). */

/*	Programa: OPERAÇÕES. 	*/
/*	Descrição: 				*/
/*	Programa que registra dois operandos e realiza operações entre estes a critério do usuário.  */

bool isNumeric(char *num);
bool verificarOperandoDivisao(int operandoVerificado);

int main()
{
	/* Códigos ASCII para a utilização de caracteres latinos na apresentação de texto:
		Ç = \x80		Õ = \xE5		Ã = \xC7		Ê = \xD2		Ú = \xE9		É = \x90		Á = \xB5
	*/
	bool sair = false;					/* Variável que controla o estado de execução do programa. */
	int operandoA = 0, operandoB = 0;	/* Variáveis dos operandos, originalmente eram float, porém a necessidade de operandos inteiros para a operação de Resto alterou isto. */
	float resultado;					/* Variável que armazena o resultado das operações. */
	char charSelecao;					/* Variável que armazena o caractere da seleção de opções. */
	char entrada[6];					/* Variável que armazena o conteúdo da entrada de operandos. */
	int entradaValida;					/* Variável que controla o estado da validação da entrada de operandos. */

	do 									/* Laço de repetição que controla a execução do programa */
	{
		printf("=======================================================\n");												/* Apresentação de texto das opções de entrada.	*/
		printf("                     OPERA%c%cES                         \n", '\x80', '\xE5');								/* Palavras com caracteres especiais tem sua  	*/
		printf("=======================================================\n");												/* exibição interrompida por '%c' de forma a 	*/
		printf(" OPERANDO A: %i                       OPERANDO B: %i\n", operandoA, operandoB);								/* inserir o código ASCII na posição adequada, 	*/
		printf("-------------------------------------------------------\n");												/* assim exibindo o caractere desejado.			*/
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
		charSelecao = toupper(getche());		/* Captura o caractere da opção selecionada e, através da função toupper(), o converte para a versão maiúscula (se houver). */
		
		switch (charSelecao)					/* Condicional que direciona cada opção para sua ação correspondente. */
		{
			case ('+'):							/* Operação de Soma. */
				resultado = operandoA + operandoB;
				printf("\n\n\n O RESULTADO DA SOMA ENTRE %i E %i %c %.0f\n\n\n", operandoA, operandoB, '\x90', resultado);
			break;
			case ('-'):							/* Operação de Subtração. */
				resultado = operandoA - operandoB;
				printf("\n\n\n O RESULTADO DA SUBTRA%c%cO ENTRE %i E %i %c %.0f\n\n\n", '\x80', '\xC7', operandoA, operandoB, '\x90', resultado);
			break;
			case ('/'):							/* Operação de Divisão. 	*/
				if (verificarOperandoDivisao(operandoB) == false)						/* Verificação do Divisor. */
					break;
				resultado = ((float) operandoA) / ((float) operandoB);	/* Divisor e dividendo inteiros estavam produzindo um divisão inteira. Um casting (float) resolve isso. */
				printf("\n\n\n O RESULTADO DA DIVIS%cO ENTRE %i E %i %c %.2f\n\n\n", '\xC7', operandoA, operandoB, '\x90', resultado);
			break;
			case ('*'):							/* Operação de Multiplicação.	*/
				resultado = operandoA * operandoB;
				printf("\n\n\n O RESULTADO DA MULTIPLICA%c%cO ENTRE %i E %i %c %.0f\n\n\n", '\x80', '\xC7', operandoA, operandoB, '\x90', resultado);
			break;
			case ('%'):							/* Operação de Resto. */
				if (verificarOperandoDivisao(operandoB) == false)
					break;
				resultado = operandoA % operandoB;
				printf("\n\n\n O RESTO DA DIVIS%cO ENTRE %i E %i %c %.0f\n\n\n", '\xC7', operandoA, operandoB, '\x90', resultado);
			break;
			case ('P'):							/* Operação de Potência. */
				resultado = pow(operandoA, operandoB);	/* Função que retorna a potência de um número a outro.  */
				printf("\n\n\n O RESULTADO DA POTENCIA%c%cO DE %i A %i %c %.0f\n\n\n", '\x80', '\xC7', operandoA, operandoB, '\x90', resultado);
			break;
			case ('R'):
				resultado = sqrt((float) operandoA);	/* Função que retorna a raiz quadade de um número. Casting em (float) para assegura precisão. */
				printf("\n\n\n A RAIZ QUADRADA DE %i %c %.3f\n\n\n", operandoA, '\x90', resultado);
			break;
			case ('A'):							/* Atribuição do Operando A. */
				do								/* Laço de Validação, para garantir que o conteúdo seja válido. */
				{
					printf("\n\n\n INSIRA UM NOVO VALOR INTEIRO PARA O OPERANDO A: ");
					scanf("%s", entrada);						/* Captura de um valor string para ser analisado sem gerar falhas no programa. */
					entradaValida = isNumeric(entrada);			/* Verificação do resultado da análise da entrada. */
					if (entradaValida)
						operandoA = atoi(entrada);				/* Função que recebe um valor em formato string e o converte para inteiro ignorando espaços em branco. */
					else
						printf("\n N%cMERO INV%cLIDO!", '\xE9', '\xB5');

				} while (entradaValida != 1);
				printf("\n\n\n");
			break;
			case ('B'):							/* Atribuição do Operando B. */
				do
				{
					printf("\n\n\n INSIRA UM NOVO VALOR INTEIRO PARA O OPERANDO B: ");
					scanf("%s", entrada);
					entradaValida = isNumeric(entrada);
					if (entradaValida)
						operandoB = atoi(entrada);
					else
						printf("\n N%cMERO INV%cLIDO!", '\xE9', '\xB5');

				} while (entradaValida != 1);
				printf("\n\n\n");
			break;
			case ('S'):							/* Saída do Programa. */
				printf("\n\n OBRIGADO POR UTILIZAR ESTE PROGRAMA!\n\n");
				sair = true;
			break;
			default:
				printf("\n\n OP%c%cO N%cO ENCONTRADA!\n\n", '\x80', '\xC7', '\xC7');
		}
		getchar();
	} while (sair != true);
	return 0;
}

bool verificarOperandoDivisao(int operandoVerificado) 			/* Função que verifica se o operando é 0, utilizado no caso de divisores. */
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
																/* Função que verifica as posições de uma string para ocorrência de caracteres não-numéricos. 			*/
bool isNumeric(char *num)										/* *num é um ponteiro para char, é um parâmetro utilizado para passar um valor de uma string (char[]) 	*/
{																/* que, apesar de diferentes, possuem alguns tratamentos semelhantes por parte do compilador.			*/
	bool retorno = true;										
	int len = strlen(num);										/* Função que retorna o comprimento exato de uma cadeira de caracteres. */
	int x;
	for (x=0; x<len; x++)
	{
		if (!isdigit(num[x]))									/* Função que verifica se um caractere é numérico. 	*/
			if (num[x] != '-')									/* Exceção para o símbolo do número negativo. 		*/
				retorno = false;	
	}
	return retorno;
}