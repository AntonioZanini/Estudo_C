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
int 	contar 					(node_t *);
void 	excluir 				(node_t *);
char 	exibir_menu_principal	();
void	exibir_tela_adicionar	(node_t *);
void 	exibir_tela_alterar 	(node_t *);
void	exibir_tela_inserir		(node_t *);
void 	exibir_tela_navegacao	(node_t *);
void 	exibir_tela_relatorio	(node_t *);
void 	inserir					(node_t *, int);
node_t 	*ordenar 				(node_t *);
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
	/*exibir_tela_alterar(teste);*/
	

	do {
		opcao = exibir_menu_principal();
		switch(opcao)
		{
			case ('A'):
				exibir_tela_adicionar(lista);
			break;
			case ('N'):
				if (!verificar_lista_vazia(lista))
					exibir_tela_navegacao(lista);
				else {
					printf("\n\nLISTA VAZIA! ADICIONE N%cMEROS!", U_MA_AGUDO);
					getch();
				}
			break;
			case ('E'):
				if (!verificar_lista_vazia(lista))
					exibir_tela_relatorio(lista);
				else {
					printf("\n\nLISTA VAZIA! ADICIONE N%cMEROS!", U_MA_AGUDO);
					getch();
				}
			break;
			case ('O'):
				if (!verificar_lista_vazia(lista)) {
					lista = ordenar(lista);
					printf("\n\nLISTA ORDENADA!");
				}
				else 
					printf("\n\nLISTA VAZIA! ADICIONE N%cMEROS!", U_MA_AGUDO);

				getch();
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

	return 0;
}

void adicionar(node_t *lista, int valor)
{
	node_t *novo_node;
	lista  = selecionar_ultimo(lista);
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
		lista 	 = lista->prox;
		contador++;
	}
	return contador;
}

node_t *ordenar(node_t *lista)
{
	node_t *aux; 
	node_t *lista_ordem;
	node_t *novo;
	novo 		= malloc(sizeof(node_t));
	novo->num 	= 0;
	novo->ante 	= NULL;
	novo->prox 	= NULL;
	do {
		lista_ordem 	= lista;
		aux 			= lista_ordem;
		lista_ordem 	= lista_ordem->prox;
		do {
			if (lista_ordem->num < aux->num) {
				aux 	= lista_ordem;
			}
			lista_ordem = lista_ordem->prox;
		} while (NULL != lista_ordem);
		adicionar(novo, aux->num);
		excluir(aux);
	} while (1 != contar(lista));
	adicionar(novo, lista->num);
	return novo;
}

void exibir_tela_alterar (node_t *elemento){
	system("cls");
	printf("-------------------------------------------\n\n");
	printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
	printf("-------------------------------------------\n\n");
	printf("         ALTERE ELEMETO SELECIONADO\n\n");
	printf("                 (%08i)\n\n", elemento->num);
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
	if ((NULL == elemento->ante) && (NULL == elemento->prox)) {
		elemento->num 	= 0;
	}
	else if (NULL == elemento->ante) {
		aux 			= elemento->prox;
		elemento->num 	= aux->num;
		aux_prox 		= aux->prox;
		elemento->prox 	= aux_prox;
		if (NULL != aux->prox) {
			aux_prox->ante = elemento;
		}
	}
	else if (NULL == elemento->prox) {
		aux_ante 		= elemento->ante;
		aux_ante->prox 	= NULL;
		elemento 		= aux_ante;
	}
	else {
		aux_ante 		= elemento->ante;
		aux_prox 		= elemento->prox;
		aux_ante->prox 	= aux_prox;
		aux_prox->ante 	= aux_ante;
		elemento 		= aux_prox;
	}
}

char exibir_menu_principal() {
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
	bool retorno 	 = true;							
	int  tamanho_num = strlen(num);					
	int  x;
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

void exibir_tela_navegacao(node_t *lista) {
	char tecla_selecao;
	char confirmacao;
	node_t *aux_prox, *aux_ante;
	do {
		system("cls");
		printf("-------------------------------------------\n\n");
		printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
		printf("-------------------------------------------\n\n");
		printf(" NAVEGA%c%cO NOS N%cMEROS DA LISTA.\n\n", C_MA_CEDILHA, A_MA_TIL, U_MA_AGUDO);
		printf("               ----------------            \n");
		printf("               |   %8i   |            \n", lista->num);
		printf("               ----------------            \n\n");
		printf(" a - ANTERIOR  p - PR%cXIMO    s - SAIR    \n", O_MA_AGUDO);
		printf(" i - INSERIR   m - MODIFICAR   e - EXCLUIR\n\n");
		printf("%i\n", (lista->ante != NULL) ? lista->ante->num : 0);
		tecla_selecao = toupper(getch());
		switch(tecla_selecao)
		{
			case ('A'):
				if (NULL != lista->ante) {
					lista = lista->ante;
				}
			break;
			case ('P'):
				if (NULL != lista->prox) {
					lista = lista->prox;
				}		
			break;
			case ('I'):
				exibir_tela_inserir(lista);
			break;
			case ('M'):
				exibir_tela_alterar(lista);
			break;
			case ('E'):
				printf("\n\nDESEJA REALMENTE EXCLUIR ESTE N%cMERO? (S) ", U_MA_AGUDO);
				confirmacao = toupper(getche());
				if ('S' == confirmacao) {
					aux_ante = lista->ante;
					aux_prox = lista->prox;
					excluir(lista);
					printf("\nN%cMERO EXCLU%cDO!\n", U_MA_AGUDO, I_MA_AGUDO);
					if ((NULL == aux_ante) && (NULL == aux_prox)) {
						if (verificar_lista_vazia(lista)) {
							tecla_selecao = 'S';
						}
					}
					else {
						lista = (NULL != aux_ante) ? aux_ante : aux_prox;
					}
					getch();
				}
			break;
			case ('S'):
			break;
			default:
				printf("OP%c%cO INV%cLIDA!\n", C_MA_CEDILHA, A_MA_TIL, A_MA_AGUDO);
				getch();
		}
	} while ('S' != tecla_selecao);
}

void exibir_tela_inserir(node_t *elemento) {
	system("cls");
	printf("-------------------------------------------\n\n");
	printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
	printf("-------------------------------------------\n\n");
	printf(" ADICIONE UM NOVO N%cMERO %c LISTA,\n",U_MA_AGUDO, A_MA_GRAVE);
	printf(" ELE SER%c INSERIDO AP%cS O N%cMERO %i\n\n",A_MA_AGUDO, O_MA_AGUDO, U_MA_AGUDO, elemento->num);
	inserir(elemento, receber_numero());
	printf("\n\nN%cMERO INSERIDO COM SUCESSO!", U_MA_AGUDO);
	getch();
}
