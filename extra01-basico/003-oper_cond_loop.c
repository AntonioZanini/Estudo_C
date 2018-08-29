#include <stdio.h>
#include <stdlib.h>			/* Biblioteca geral de recursos da linguagem C, possui diversas funcionalidades, adicionada para a utilização do comando system. */
#include <stdbool.h>		/* Biblioteca que adiciona o tipo booleano. */
#include <conio.h>			/* Biblioteca que adiciona algumas funções de entrada e saída, exemplos: getch(), getche() e etc. */

int executarOperacao(int temperaturaInicial, int temperaturaFinal); 	/* Protótipo da função: todas as funções, além da função principal, devem ter seu cabeçalho 
																			duplicado e colocado antes do início da função main. */

enum opcoesTemperaturas		/*  */
{
	CELSIUS = 0,
	FAHRENHEIT,
	KELVIN
};

int main(int argc, char const *argv[])
{
	bool programaAtivo = true;
	char operacaoSelecionada;

	do
	{
		system("cls");
		printf("##########-OPERACOES COM TEMPERATURAS-##########\n");
		printf("\nCalculos disponiveis:\n");
		printf("1 - Celsius para Fahrenheit.\n");
		printf("2 - Fahrenheit para Celsius.\n");
		printf("3 - Celsius para Kelvin.\n");
		printf("4 - Kelvin para Celsius\n");
		printf("5 - Fahrenheit para Kelvin\n");
		printf("6 - Kelvin para Fahrenheit\n");
		printf("7 - Sair\n");
		printf("\nSelecione a opcao desejada: ");
		operacaoSelecionada = getche();
		
		switch (operacaoSelecionada)
		{
			case ('1'):
				executarOperacao(CELSIUS, FAHRENHEIT);
			break;
			case ('2'):
				executarOperacao(FAHRENHEIT, CELSIUS);
			break;
			case ('3'):
				executarOperacao(CELSIUS, KELVIN);
			break;
			case ('4'):
				executarOperacao(KELVIN, CELSIUS);
			break;
			case ('5'):
				executarOperacao(FAHRENHEIT, KELVIN);
			break;
			case ('6'):
				executarOperacao(KELVIN, FAHRENHEIT);
			break;
			case ('7'):
				programaAtivo = false;
			break;
			default:
			printf("\nOpcao nao encontrada!\n");
		}

		printf("\nPressione qualquer tecla para continuar . . .\a");
		getchar();
		
		/* code */
	} while (programaAtivo == true);
	return 0;
}

int executarOperacao(int temperaturaInicial, int temperaturaFinal)
{
	float valorTemperatura ;
	char nomeTemperatura[3][11] = {"CELSIUS" , "FAHRENHEIT" , "KELVIN"};
	system("cls");
	printf("CONVERCAO DE %s EM %s:\n", nomeTemperatura[temperaturaInicial], nomeTemperatura[temperaturaFinal] );
	printf("Insira o valor em %s: ", nomeTemperatura[temperaturaInicial]);
	scanf("%f", &valorTemperatura );
	switch (temperaturaInicial)
	{
		case (CELSIUS):
			if (temperaturaFinal == FAHRENHEIT){
				valorTemperatura = valorTemperatura * 1.8f + 32;
			}
			if (temperaturaFinal == KELVIN)
			{
				valorTemperatura = valorTemperatura + 273.15f;
			}
		break;
		case (FAHRENHEIT):
			if (temperaturaFinal == CELSIUS)
			{
				valorTemperatura = (valorTemperatura - 32) / 1.8f;
			}
			if (temperaturaFinal == KELVIN)
			{
				valorTemperatura = (valorTemperatura + 459.67f) * (5 / 9);
			}
		break;
		case (KELVIN):
			if (temperaturaFinal == CELSIUS)
			{
				valorTemperatura = valorTemperatura - 273.15f;
			}
			if (temperaturaFinal == FAHRENHEIT)
			{
				valorTemperatura = (valorTemperatura * (9 / 5)) - 459.67f;
			}
		break;
	}

	printf("\nValor da temperatura em %s: %.2f", nomeTemperatura[temperaturaFinal], valorTemperatura );
	getchar();
	return 0;
}