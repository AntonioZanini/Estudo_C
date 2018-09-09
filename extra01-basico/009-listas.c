#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/* Exercício com o objetivo de recordar e aprimorar os conhecimentos sobre a criação de listas na linguagem C */

typedef struct reg
{
	char nome[30];
	struct reg * prox;
} elemento;

void inserirNome(char * nome, elemento * primeiroElemento);
void imprimirNomes(elemento * lista);

int main()
{
	elemento *pri;
	char tecla, nomedigitado[30];
	pri = malloc(sizeof(elemento));
	pri->prox = NULL;
	printf("Insira nome: ");
	scanf("%s", pri->nome);
	printf("Mais nomes? ");
	tecla = getche();
	if (tecla == 13){
		do 
		{
			printf("Insira nome: ");
			scanf("%s", nomedigitado);
			inserirNome(nomedigitado, pri);
			printf("Mais nomes? ");
			tecla = getche();		
		} while (tecla == 13);
	}
	printf("\n\nNomes listados:\n");
	imprimirNomes(pri);
	return 0;
}

void inserirNome(char * nome, elemento * primeiroElemento)
{
	elemento *novo;
	novo = malloc(sizeof(elemento));
	strcpy(novo->nome,nome);
	novo->prox = NULL;
	do 
	{	
		if (primeiroElemento->prox != NULL)
			primeiroElemento = primeiroElemento->prox;
	} while (primeiroElemento->prox != NULL);
	primeiroElemento->prox = novo;
}

void imprimirNomes(elemento * lista)
{
	do {
		printf("Nome: %s\n", lista->nome);
		lista = lista->prox;
	}
	while (lista !=NULL);
}