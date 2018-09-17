#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
/*  Programa: NUMERAÇÃO ORDENADA 
    Descrição: 
	Programa que recebe números para formar uma lista, e possibilita inclusão, inserção, alteração, exclusão e ordenação.
 */

#define U_MA_AGUDO 		'\xE9' /* Ú */
#define C_MA_CEDILHA	'\x80' /* Ç */
#define A_MA_TIL 		'\xC7' /* Ã */
#define O_MA_TIL		'\xE5' /* Õ */
#define A_MA_AGUDO		'\xB5' /* Á */
#define A_MA_GRAVE		'\xB7' /* À */
#define I_MA_AGUDO		'\xD6' /* Í */
#define E_MA_AGUDO		'\x90' /* É */
#define O_MA_AGUDO		'\xE0' /* Ó */


#define CARACTERE_ENTER	13

typedef struct node_t
{
	struct node_t 	*ante;
	int 			num;
	struct node_t 	*prox;
} node_t;

void 	adicionar				(node_t *, int);
void 	alterar 				(node_t *);
int 	contar 					(node_t *);
void 	excluir 				(node_t *);
char 	exibir_principal		();
void	exibir_tela_adicionar	(node_t *);
void 	exibir_tela_relatorio	(node_t *);
void 	inserir					(node_t *, int);
void 	ordenar					(node_t *);
int 	receber_numero 			();
node_t 	*selecionar_ultimo 		(node_t *);
bool 	verificar_lista_vazia 	(node_t *);
bool 	verificar_numero		(char *num);

int main()
{
	char opcao;
	node_t *lista;
	node_t *teste;


	lista 		= malloc(sizeof(node_t));
	lista->num 	= 0;
	lista->ante = NULL;
	lista->prox = NULL; 




	adicionar(lista, 1);
	adicionar(lista, 2);
	teste = selecionar_ultimo(lista);
	adicionar(lista, 4);
	inserir(teste, 3);
	adicionar(lista, 9);
	adicionar(lista, 1);
	/*alterar(teste);*/
	ordenar(lista);

	do {
		opcao = exibir_principal();
		switch(opcao)
		{
			case ('A'):
				exibir_tela_adicionar(lista);
			break;
			case ('N'):
		
			break;
			case ('E'):
				exibir_tela_relatorio(lista);
			break;
			case ('O'):
		
			break;
			case ('S'):
				printf("\n\nDESEJA REALMENTE SAIR? (S) ");
				opcao = toupper(getche());
			break;
			default:
				printf("\n\nOP%c%cO INV%cLIDA! TENTE NOVAMENTE!", C_MA_CEDILHA, A_MA_TIL, A_MA_AGUDO);
				getch();
		}
	} while ('S' != opcao);
/*
	printf("\n\n\n");
	do {
		printf(" %i .", lista->num);
		lista = lista->prox;
	} while (NULL != lista);
 */
	return 0;
}

void adicionar(node_t *lista, int valor)
{
	node_t *novo_node;
	lista = selecionar_ultimo(lista);
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

node_t *selecionar_ultimo(node_t *lista)
{
	while (NULL != lista->prox) {
		lista = lista->prox;
	}
	return lista;
}

int contar(node_t *lista)
{
	int contador = 0;
	while (NULL != lista) {
		lista = lista->prox;
		contador++;
	}
	return contador;
}

void ordenar(node_t *lista)
{
	int x;
	int ultimo_elemento;
	bool ordenado;
	int aux_num;
	node_t *aux_prox;
	node_t *aux_ante;
	node_t *lista_ordem;
	ultimo_elemento = contar(lista) - 1;
	do {
		ordenado = true;
		lista_ordem = lista;
		for (x = 0; x < ultimo_elemento; x++) {
			aux_prox = lista_ordem->prox;
			if (lista_ordem->num > aux_prox->num) {
				if (NULL == lista_ordem->ante){
					aux_num = lista_ordem->num;
					lista_ordem->num = aux_prox->num;
					aux_prox->num = aux_num;
					ordenado = false;
				}
				else {
					aux_ante = lista_ordem->ante;
					lista_ordem->prox = aux_prox->prox;
					lista_ordem->ante = aux_prox;
					aux_prox->prox = lista_ordem;
					aux_prox->ante = aux_ante;
					aux_ante->prox = aux_prox;
					ordenado = false;
				}
			}
			lista_ordem = aux_prox;
		}
		ultimo_elemento = x;
	} while (!ordenado);
}

void alterar (node_t *elemento){
	system("cls");
	printf("-------------------------------------------\n\n");
	printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
	printf("-------------------------------------------\n\n");
	printf("         ALTERE ELEMETO SELECIONADO\n\n");
	printf("                   (%05i)\n\n", elemento->num);
	printf("-------------------------------------------\n\n");
	elemento->num = receber_numero();
	printf("\n\nNOVO VALOR DO ELEMENTO: %i", elemento->num);
	getch();
}

int receber_numero () {
	bool entrada_valida;
	char entrada[9];
	do {
		entrada_valida = true;
		printf("N%cMERO: ", U_MA_AGUDO);
		scanf("%s", entrada);
		if (!verificar_numero(entrada)) {
			printf("\n\nN%cMERO INV%cLIDO! INSIRA UM VALOR NUM%cRICO INTEIRO DIFERENTE DE ZERO!\n\n", U_MA_AGUDO, A_MA_AGUDO, E_MA_AGUDO);
			entrada_valida = false;
		}
		else if (0 == atoi(entrada)) {
			printf("\n\nN%cMERO ZERO! INSIRA UM VALOR NUM%cRICO INTEIRO DIFERENTE DE ZERO!\n\n", U_MA_AGUDO, A_MA_AGUDO, E_MA_AGUDO);
			entrada_valida = false;
		}
	} while (!entrada_valida);
	return atoi(entrada);
}

void excluir (node_t *elemento){
	node_t *aux;
	node_t *aux_ante;
	node_t *aux_prox;
	if (NULL == elemento->ante) {
		printf("\ndebug 1\n");
		aux = elemento->prox;
		elemento->num = aux->num;
		aux_prox = aux->prox;
		elemento->prox = aux_prox;
		aux_prox->ante = elemento;
	}
	else if (NULL == elemento->prox) {
		printf("\ndebug 2\n");
		aux_ante = elemento->ante;
		aux_ante->prox = NULL;
		elemento = aux_ante;
	}
	else {
		printf("\ndebug 3\n");
		aux_ante = elemento->ante;
		aux_prox = elemento->prox;
		aux_ante->prox = aux_prox;
		aux_prox->ante = aux_ante;
		elemento = aux_prox;
	}
}

char exibir_principal() {
	system("cls");
	printf("-------------------------------------------\n\n");
	printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
	printf("-------------------------------------------\n\n");
	printf(" SELECIONE A OP%c%cO DESEJADA:\n\n", C_MA_CEDILHA, A_MA_TIL);
	printf("   a - ADICIONAR NOVO N%cMERO\n", U_MA_AGUDO);
	printf("   e - EXIBIR TODOS OS N%cMEROS\n", U_MA_AGUDO);
	printf("   o - ORDENAR N%cMEROS\n", U_MA_AGUDO);
	printf("   n - NAVEGAR PELO N%cMEROS\n", U_MA_AGUDO);
	printf("   s - SAIR\n\n", U_MA_AGUDO);
	printf("-------------------------------------------\n\n");
	printf("SELECIONAR: ");
	return toupper(getche());
}

bool verificar_lista_vazia (node_t *lista) {
	bool lista_vazia = false;
	if (NULL == lista->ante && NULL == lista->prox && lista->num == 0)
		lista_vazia = true;

	return lista_vazia;
}

bool verificar_numero(char *num)			
{											
	bool retorno = true;							
	int tamanho_num = strlen(num);					
	int x;
	for (x = 0; x < tamanho_num; x++)
	{
		if (!isdigit(num[x]))				
			if ('-' != num[x])				
				retorno = false;	
	}
	return retorno;
}

void exibir_tela_adicionar(node_t *lista) {
	char confirma_outro;
	bool novo_numero;
	do {
		novo_numero = false;
		system("cls");
		printf("-------------------------------------------\n\n");
		printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
		printf("-------------------------------------------\n\n");
		printf(" ADICIONE UM NOVO N%cMERO %c LISTA:\n\n",U_MA_AGUDO, A_MA_GRAVE);
		adicionar(lista, receber_numero());
		printf("\n\nN%cMERO ADICIONADO! ADICIONAR OUTRO? (S) ", U_MA_AGUDO);
		confirma_outro = toupper(getche());
		if ('S' == confirma_outro || CARACTERE_ENTER == confirma_outro)
			novo_numero = true;
	} while (novo_numero);
}

void exibir_tela_relatorio(node_t *lista) {
	int contador = 1;
	int total_numeros;
	total_numeros = contar(lista);
	system("cls");
	printf("-------------------------------------------\n\n");
	printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
	printf("-------------------------------------------\n\n");
	printf(" RELAT%cRIO DE N%cMEROS ADICIONADOS:\n\n", O_MA_AGUDO, U_MA_AGUDO);
	do {
		printf("#%03i - %8i\n", contador, lista->num);
		lista = lista->prox;
		contador++;
	} while (NULL != lista);
	printf("\n-------------------------------------------\n\n");
	printf("TOTAL DE %i N%cMEROS PRESENTES NA LISTA", total_numeros , U_MA_AGUDO);
	getch();
}