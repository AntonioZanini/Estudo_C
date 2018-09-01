#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define cedilm '\x87' /* constante para o código char do caractere 'ç' */

int main()
{
	char nome[20], endereco[30], email[25], nascimento[10];
	int cpf, telefone;

	printf("============================");
	printf("\nInsira seus dados cadastrais");
	printf("\n============================");
	printf("\nNome: ");
	scanf("%[^\n]%*c", &nome);			/* Mascara para suprimir a divisão de entrada através do espaço*/
	printf("Endere%co: ", cedilm);
	scanf("%[^\n]%*c", &endereco);
	printf("CPF: ");
	scanf("%i", &cpf);
	printf("Data de Nascimento: ");
	scanf("%s", nascimento);
	printf("Telefone: ");
	scanf("%i", &telefone);
	printf("Email: ");
	scanf("%s", email);

	printf("\n\n============================");
	printf("\nConfira seus Dados");
	printf("\n============================");
	printf("\nNome: %s", nome);
	printf("\nEndere%co: %s", cedilm, endereco);
	printf("\nCPF: %d", cpf);
	printf("\nData de Nascimento: %s", nascimento);
	printf("\nTelefone: %d", telefone);
	printf("\nEmail: %s\n\n", email);

	printf("Cadastro preenchido corretamente? ");
	getch();
}
