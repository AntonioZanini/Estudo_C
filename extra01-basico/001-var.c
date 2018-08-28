#include <stdio.h>		/*Anexa a execução do programa o recursos da biblioteca stdio, esta é responsável pelas operações básicas de entrada e saída. Ex: printf, scanf, fprintf, puts e etc. */


int main() /*Função principal do programa, definada de forma padrão pela linguagem como retornando um valor inteiro. Declarada sem expecificar parâmetros.*/
{
	char nome[30]; /* Declara uma matriz unidimencional de caracteres para servir como uma string contendo um nome. */
	int vencimento = 5; /* Declara uma variável do tipo inteiro para armazenar o número de dias até o vencimento. Ela foi iniciada com um valor atribuido. */
	unsigned int idade = 45; /* Declara uma variável do tipo inteiro não-assinalado para armazenar o valor de idade. Ela foi iniciada com um valor atribuido */
	float saldo = 10450.5f;  /* Declara uma variável do tipo de ponto flutuante para armazenar o valor do saldo. Ela foi iniciada com um valor atribuido. 
	Valores em float devem ser finalizados com a letra f */
	
	puts("<<<<<<<<<<<<Insira o nome do associado desejado>>>>>>>>>>>>"); /* Comando que imprime na tela (stdout) uma string especificada, incluindo um quebra de linha (\n) ao final da impressão. */
	printf("Nome: "); /* printf(string) ou printf("string", parâmetros)
	Comando para imprimir uma string formada a partir de um versátil processo de formatação, manipulando parâmetros em string e outros tipos. Neste exemplo apenas exibe uma string simples, 
	mantendo o cursor na mesma linha */
	fgets(nome, sizeof(nome), stdin); /* fgets(<char[]>, <Tamanho>, <Fluxo>)
	Comando que lê um <Fluxo> de cadeia de caracteres (char[]) até o fim do tamanho especificado (<Tamanho> -1), tecla de retorno (enter) ou o final do arquivo (EOF). 
	O <Fluxo> define a origem dos caracteres que podem da entrada padrão (teclado) ou de um arquivo de texto, o valor para definir como a entrada padrão é stdin.
	O <Tamanho> é um recurso interessante pois previne erros de sobrecarga de entrada de caracteres, limitando ao definido (<Tamanho> -1 caracteres) e descartando o resto. */

	/* sizeof é um operador utilizado para computar o tamanho de um operando, em tipos nativos ele revelará a quantidade de bytes utilizados, já em matrizes ele obtem o seu número de elementos. */

	printf("\nAssociado: %s", nome); /* \n gera uma quebra de linha. %s é o marcador para exibição de um parâmetro do tipo string. */
	printf("Idade: %u\n", idade); /* %u é o marcador para a exibição de um parâmetro do tipo inteiro não-assinalado. */
	printf("Saldo: <R$%.2f>. Dias ate o vencimento: %i dias.\n", saldo, vencimento); /* %.2f é uma formatação sobre o marcador de exibição de um parâmetro do tipo float (%f) que exibe o valor sempre 
	contento duas casa decimais. %i é o marcador para a exibição de um parâmetro do tipo inteiro. */

	printf("Pressione qualquer tecla para finalizar . . .");
	getchar(); /* Comando que lê um caracter fornecido pela entrada padrão (teclado). Neste caso utilizado para impedir a finalização do executável antes da confirmação de visualização do texto exibido. */

	return 0; /* valor de retorno para a função principal do programa. */
}