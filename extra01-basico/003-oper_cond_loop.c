#include <stdio.h>
#include <stdlib.h>			/* Biblioteca geral de recursos da linguagem C, possui diversas funcionalidades, adicionada para a utilização do comando system. */
#include <stdbool.h>		/* Biblioteca que adiciona o tipo booleano. */
#include <conio.h>			/* Biblioteca que adiciona algumas funções de entrada e saída, exemplos: getch(), getche() e etc. */

int executarOperacao(int temperaturaInicial, int temperaturaFinal); 	/* Protótipo da função: todas as funções, além da função principal, devem ter seu cabeçalho 
																			duplicado e colocado antes do início da função main. */

enum opcoesTemperaturas		/* Enumerador criado para representar as temperaturas dentro da estrutura condicional switch */
{
	CELSIUS = 0,			/* Definindo o primeiro termo para 0, assim a numeração equivale à de uma matriz. */
	FAHRENHEIT,
	KELVIN
};

int main()
{
	bool programaAtivo = true;		/* Variável booleana para relacionar a execução do programa através da estrutura repetitiva Do. */
	char operacaoSelecionada;		/* Variável que armazena o caractere digitado na seleção do menu. */

	do								/* Estrutura repetitiva responsável pela execução do programa, quando ela for abandonada o programa será encerrado. */
	{
		system("cls");														/* Comando da biblioteca conio que aplica comandos do sistema, neste caso, limpa a tela do console. */
		printf("##########-OPERACOES COM TEMPERATURAS-##########\n");		/* Exibição do menu, escrevendo o título e as opções disponíveis. */
		printf("\nCalculos disponiveis:\n");
		printf("1 - Celsius para Fahrenheit.\n");
		printf("2 - Fahrenheit para Celsius.\n");
		printf("3 - Celsius para Kelvin.\n");
		printf("4 - Kelvin para Celsius\n");
		printf("5 - Fahrenheit para Kelvin\n");
		printf("6 - Kelvin para Fahrenheit\n");
		printf("7 - Sair\n");
		printf("\nSelecione a opcao desejada: ");
		operacaoSelecionada = getche();										/* getche está capturando um único caractere digitado e o armazenando em variável. */
		
		switch (operacaoSelecionada)										/* Estrutura condicional que realiza uma filtragem simples exibe alternativas paralelamente. */
		{																	/* Ela compara o objeto de comparação (a variavel com tecla digitada) com as opções (case)   */
			case ('1'):														/* e executa o código daquela a qual a comparação é equivalente. */
				executarOperacao(CELSIUS, FAHRENHEIT);						/* Chamado de função de operação transmitindo dois parâmetros, neste caso, valores definido no enum. */
			break;															/* BREAK: quebra de fluxo, parte integral da estrutura switch, também utilizado para sair de */
			case ('2'):														/* estruturas repetitivas. */
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
				programaAtivo = false;										/* Alteração do estado desta variável que implica no encerramento do programa.    */
			break;
			default:														/* Um tipo especial de case (deve ser o último) que é ativado quando nenhum outra */
			printf("\nOpcao nao encontrada!\n");							/* se faz ativo. Neste caso, quando a tecla não está entre nenhuma das desejadas. */
		}																	/* OPERADORES DE COMPARAÇÃO: == igual, > maior, < menor, >= maior ou igual,       */
																			/* <= menor ou igual, != diferente.*/
		printf("\nPressione qualquer tecla para continuar . . .\a");
		getchar();
		
	} while (programaAtivo == true);										/* Verificação sobre a variável que define o estado do programa. */
	return 0;
}

int executarOperacao(int temperaturaInicial, int temperaturaFinal)			/* Função que realiza a apresentação e os cálculos das operações, os parâmetros definem as operações.*/
{
	float valorTemperatura = 0 ;											/* Variável que armazenará os valores do cálculo. */
	char nomeTemperatura[3][11] = {"CELSIUS" , "FAHRENHEIT" , "KELVIN"};	/* Matriz responsável por converter os valores do enum para os nomes das temperaturas para apresentação. */
	system("cls");
	printf("CONVERCAO DE %s EM %s:\n", nomeTemperatura[temperaturaInicial], nomeTemperatura[temperaturaFinal] );
	printf("Insira o valor em %s: ", nomeTemperatura[temperaturaInicial]);
	scanf("%f", &valorTemperatura );										/* scanf captura caracteres que precedem um <Enter> vindos da entrada padrão. %f define que os caracteres  */
																			/* serão inseridos na variável sob o formato float.														 */
	switch (temperaturaInicial)												/* Estrutura condicional que verifica a primeira parte da operação de conversão.						 */
	{																		/* As estruturas condicionais poderiam ser realizadas outras formas, mas estão assim para maior legibilidade.*/
		case (CELSIUS):
			if (temperaturaFinal == FAHRENHEIT){							/* Estrura condicional IF, mas poderosa e versátil que SWITCH, porém menos expositiva. */
				valorTemperatura = valorTemperatura * 1.8f + 32;			/* Ela está responsável por verificar a segunda parte da operação e definir o cálculo. */
			}																/* "*" é o operador matemático de multiplicação.  */
			if (temperaturaFinal == KELVIN)
			{
				valorTemperatura = valorTemperatura + 273.15f;
			}
		break;
		case (FAHRENHEIT):
			if (temperaturaFinal == CELSIUS)
			{
				valorTemperatura = (valorTemperatura - 32) / 1.8f;			/* "/" é o operador matemático de divisão. */
			}
			if (temperaturaFinal == KELVIN)
			{
				valorTemperatura = (valorTemperatura + 459.67f) * 5.0f / 9.0f;
			}
		break;
		case (KELVIN):
			if (temperaturaFinal == CELSIUS)
			{
				valorTemperatura = valorTemperatura - 273.15f;
			}
			if (temperaturaFinal == FAHRENHEIT)
			{
				valorTemperatura = (valorTemperatura * (9.0f / 5.0f)) - 459.67f;
			}
		break;
	}																		/* Ao não existir nenhuma outra opção apresentada pelo código, esta estrutura switch não necessita de */
																			/* uma clausula default. */
	printf("\nValor da temperatura em %s: %.2f", nomeTemperatura[temperaturaFinal], valorTemperatura ); /* Apresentação do resultado final. */
	getchar();
	return 0;
}