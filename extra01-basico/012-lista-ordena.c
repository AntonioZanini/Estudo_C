#include <stdio.h>
#include <stdlib.h>

/*  Programa: NUMERAÇÃO ORDENADA 
    Descrição: 
	Programa que recebe números para formar uma lista, e possibilita inclusão, inserção, alteração, exclusão e ordenação.
 */

typedef struct node_t
{
	struct node_t 	*ante;
	int 			num;
	struct node_t 	*prox;
} node_t;

void 	adicionar(node_t *, int);
void 	inserir(node_t *, int);
node_t 	*ultimo(node_t *);

int main()
{
	node_t *lista;
	node_t *teste;
	lista 		= malloc(sizeof(node_t));
	lista->num 	= 0;
	lista->ante = NULL;
	lista->prox = NULL; 



	adicionar(lista, 1);
	adicionar(lista, 2);
	teste = ultimo(lista);
	adicionar(lista, 4);
	inserir(teste, 3);


	do {
		printf(" %i .", lista->num);
		lista = lista->prox;
	} while (NULL != lista);

	return 0;
}

void adicionar(node_t *lista, int valor)
{
	node_t *novo_node;
	lista = ultimo(lista);
	if (0 != lista->num){
		novo_node = malloc(sizeof(node_t));
		novo_node->num 	= valor;
		novo_node->ante = lista;
		novo_node->prox = NULL;
		lista->prox = novo_node;
	}
	else {
		lista->num = valor;
	}
}

void inserir(node_t *elemento, int valor)
{
	node_t *novo_node;
	node_t *aux;
	novo_node 		= malloc(sizeof(node_t));
	novo_node->num 	= valor;
	if (NULL != elemento->prox){
		aux 			= elemento->prox;
		aux->ante 		= novo_node;
		elemento->prox 	= novo_node;
		novo_node->ante	= elemento;
		novo_node->prox	= aux;
	}
	else {
		novo_node->prox = NULL;
		novo_node->ante = elemento;
		elemento->prox 	= novo_node;
	}
}

node_t *ultimo(node_t *lista)
{
	while (NULL != lista->prox){
		lista = lista->prox;
	}
	return lista;
}