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
				/* Constantes de apresentação de caracteres especiais. 			*/
#define U_MA_AGUDO 		'\xE9' /* Ú */
#define C_MA_CEDILHA	'\x80' /* Ç */
#define A_MA_TIL 		'\xC7' /* Ã */
#define O_MA_TIL		'\xE5' /* Õ */
#define A_MA_AGUDO		'\xB5' /* Á */
#define A_MA_GRAVE		'\xB7' /* À */
#define I_MA_AGUDO		'\xD6' /* Í */
#define E_MA_AGUDO		'\x90' /* É */
#define O_MA_AGUDO		'\xE0' /* Ó */
				/* Constantes para auxílio no reconhecimento da tecla enter. 	*/
#define CARACTERE_ENTER	13
				/* Estrutura que representa o nó da lista encadeada. 			*/
typedef struct node_t
{
	struct node_t 	*ante;	/* Ponteiro para o elemento prévio. 		*/
	int 			num;	/* Valor inteiro armazenado pelo elemento. 	*/
	struct node_t 	*prox;	/* Ponteiro para o elemento posterior. 		*/
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
node_t 	*mover_registro			(node_t *, char);
node_t 	*ordenar 				(node_t *);
int 	receber_numero 			();
int 	retornar_posicao		(node_t *);
node_t 	*selecionar_ultimo 		(node_t *);
node_t 	*selecionar_primeiro	(node_t *);
node_t 	*selecionar_posicao		(node_t *, int);
bool 	verificar_lista_vazia 	(node_t *);
bool 	verificar_numero		(char *num);

int main()				/* Função principal que inicializa variáveis, recebe 	*/
{						/* as opções e chama as rotinas e funções adequadas. 	*/
	char opcao;			/* Armazena o caractere da opção digitada.		*/
	node_t *lista;		/* Ponteiro para o elemento inicial da lista.	*/

	lista 		= malloc(sizeof(node_t));	/* Aloca espaço na memória e retorna seu endereço. */
	lista->num 	= 0;		/* Atribui valores iniciais para o elemento vazio. */
	lista->ante = NULL;
	lista->prox = NULL; 
							/* Adiciona elementos à lista para facilitar testes. */
	adicionar(lista, 1);
	adicionar(lista, 30);
	adicionar(lista, 7);
	adicionar(lista, 9);
	adicionar(lista, 5);
	

	do {					/* Laço que controla a execução do programa. 	*/
		opcao = exibir_menu_principal();	/* Chama função que exibe menu e retorna o 		*/
		switch(opcao)						/* caractere para a seleção de opções. 			*/
		{
			case ('A'):
				exibir_tela_adicionar(lista);	/* Chama a rotina da tela de adicionar números. */
			break;
			case ('N'):
				if (!verificar_lista_vazia(lista))	/* Verifica se a lista não está vazia. 		*/
					exibir_tela_navegacao(lista);	/* Chama a rotina da tela de navegação. 	*/
				else {
					printf("\n\nLISTA VAZIA! ADICIONE N%cMEROS!", U_MA_AGUDO);
					getch();
				}
			break;
			case ('E'):
				if (!verificar_lista_vazia(lista))	/* Verifica se a lista não está vazia. 		*/
					exibir_tela_relatorio(lista);	/* Chama a rotina da tela de navegação. 	*/
				else {
					printf("\n\nLISTA VAZIA! ADICIONE N%cMEROS!", U_MA_AGUDO);
					getch();
				}
			break;
			case ('O'):
				if (!verificar_lista_vazia(lista)) {	/* Verifica se a lista não está vazia.	*/
					lista = ordenar(lista);				/* Chama a função de ordeção da lista. 	*/
					printf("\n\nLISTA ORDENADA!");
				}
				else 
					printf("\n\nLISTA VAZIA! ADICIONE N%cMEROS!", U_MA_AGUDO);

				getch();
			break;
			case ('S'):
				printf("\n\nDESEJA REALMENTE SAIR? (S) ");	/* Confirmação da saída do programa.*/
				opcao = toupper(getche());
			break;
			default:						/* Mensagem para entrada inválida de caracteres. 	*/
				printf("\n\nOP%c%cO INV%cLIDA! TENTE NOVAMENTE!", C_MA_CEDILHA, A_MA_TIL, A_MA_AGUDO);
				getch();
		}
	} while ('S' != opcao);

	return 0;
}

char exibir_menu_principal() 		/* Função que exibe tela do menu principal 	*/
{									/* e retorna o caractere selecionado.	  	*/
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

void exibir_tela_adicionar(node_t *lista) 	/* Rotina que exibe a tela e controla todo o */
{											/* processo da adição de números.  			*/
	char confirma_outro;		/* Resposta se haverá uma nova adição em seguida. */
	bool novo_numero;			/* Controle do laço, true: nova entrada, false: saída da rotina. */
	do {
		novo_numero = false;
		system("cls");
		printf("-------------------------------------------\n\n");
		printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
		printf("-------------------------------------------\n\n");
		printf(" ADICIONE UM NOVO N%cMERO %c LISTA:\n\n",U_MA_AGUDO, A_MA_GRAVE);
		adicionar(lista, receber_numero());		/* Chama rotinas que validam a entrada e a adicionam à lista. */
		printf("\n\nN%cMERO ADICIONADO! ADICIONAR OUTRO? (S) ", U_MA_AGUDO);
		confirma_outro = toupper(getche());
		if ('S' == confirma_outro || CARACTERE_ENTER == confirma_outro)
			novo_numero = true;
	} while (novo_numero);
}

void exibir_tela_relatorio(node_t *lista) 		/* Rotina que exibe a tela de listagem de números. */
{
	int total_numeros;				/* Armazena o número total de elementos na lista. 	*/
	total_numeros = contar(lista);	/* Chama função que conta os elementos. 			*/
	system("cls");
	printf("-------------------------------------------\n\n");
	printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
	printf("-------------------------------------------\n\n");
	printf(" RELAT%cRIO DE N%cMEROS ADICIONADOS:\n\n", O_MA_AGUDO, U_MA_AGUDO);
	do {							/* Exibe os números e suas posições. 	*/
		printf("#%03i - %8i\n", retornar_posicao(lista)+1, lista->num);
		lista = lista->prox;
	} while (NULL != lista);
	printf("\n-------------------------------------------\n\n");
	printf("TOTAL DE %i N%cMEROS PRESENTES NA LISTA", total_numeros , U_MA_AGUDO);
	getch();						/* Exibe o total de elementos na lista. */
}

void exibir_tela_navegacao(node_t *lista) 		/* Rotina que exibe a tela de navegação e 	*/
{												/* aciona todas suas funcionalidades. 		*/
	char tecla_selecao;				/* Tecla de seleção da opção. 			*/
	char confirmacao;				/* Tecla da confirmação de exclusão.	*/
	bool atualiza_lista = false;	/* Armazena a condição para atualização da exibição dos elementos. */
	int pos_atualizada = 0;			/* Valor da posição antes da atualização. 	*/
	do {							/* Laço que controla a execução da navegação. */
		if (atualiza_lista){						/* Verifica se deve atualizar a exibição, 	*/
			lista = mover_registro(lista, 'E');		/* movendo para outro elemento e voltando. 	*/
			lista = selecionar_posicao(lista, pos_atualizada);
			atualiza_lista = false;
		}
		system("cls");
		printf("-------------------------------------------\n\n");
		printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
		printf("-------------------------------------------\n\n");
		printf(" NAVEGA%c%cO NOS N%cMEROS DA LISTA.\n\n", C_MA_CEDILHA, A_MA_TIL, U_MA_AGUDO);
		printf("               ----------------            \n");
		printf("               |   %8i   |            \n", lista->num);
		printf("               ----------------            \n\n");
		printf(" a - ANTERIOR  p - PR%cXIMO     s - SAIR    \n", O_MA_AGUDO);
		printf(" i - INSERIR   m - MODIFICAR   e - EXCLUIR\n\n");
		tecla_selecao = toupper(getch());
		switch(tecla_selecao)
		{
			case ('A'):			/* Chama função que move para elemento anterior.	*/
				lista = mover_registro(lista, 'E');
			break;
			case ('P'):			/* Chama função que move para elemento posterior.	*/
				lista = mover_registro(lista, 'D');	
			break;
			case ('I'):			/* Chama rotina que insere novo número após o atual.*/
				exibir_tela_inserir(lista);
				lista = mover_registro(lista, 'D');
			break;
			case ('M'):			/* Chama rotina que altera número do elemento atual.*/
				exibir_tela_alterar(lista);
			break;
			case ('E'):			/* Verifica e chama rotina que exclui elemento.		*/
				printf("\n\nDESEJA REALMENTE EXCLUIR ESTE N%cMERO? (S) ", U_MA_AGUDO);
				confirmacao = toupper(getche());
				if ('S' == confirmacao) {						/* Confirmação de exclusão. 					*/
					pos_atualizada = retornar_posicao(lista);	/* Armazena posição para atualização. 			*/
					excluir(lista);								/* Chama rotina de exclusão. 					*/
					atualiza_lista = true;						/* Assinala posterior atualização de exibição. 	*/
					printf("\nN%cMERO EXCLU%cDO!\n", U_MA_AGUDO, I_MA_AGUDO);
					if (verificar_lista_vazia(lista)) 			/* Verifica o último registro foi excluído.		*/
						tecla_selecao = 'S';					/* Sai da tela de navegação. 					*/
						
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

void exibir_tela_inserir(node_t *elemento) 	/* Rotina que exibe tela de inserção de elementos. 	*/
{
	system("cls");
	printf("-------------------------------------------\n\n");
	printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
	printf("-------------------------------------------\n\n");
	printf(" ADICIONE UM NOVO N%cMERO %c LISTA,\n",U_MA_AGUDO, A_MA_GRAVE);
	printf(" ELE SER%c INSERIDO AP%cS O N%cMERO %i\n\n",A_MA_AGUDO, O_MA_AGUDO, U_MA_AGUDO, elemento->num);
	inserir(elemento, receber_numero());	/* Recebe número válido e chama função de inserção. */
	printf("\n\nN%cMERO INSERIDO COM SUCESSO!", U_MA_AGUDO);
	getch();
}

void exibir_tela_alterar (node_t *elemento){	/* Rotina que exibe tela de alteração de elementos. */
	system("cls");
	printf("-------------------------------------------\n\n");
	printf("            NUMERA%c%cO ORDENADA\n\n", C_MA_CEDILHA, A_MA_TIL);
	printf("-------------------------------------------\n\n");
	printf("         ALTERE O ELEMETO SELECIONADO\n\n");
	printf("                 (%08i)\n\n", elemento->num);
	printf("-------------------------------------------\n\n");
	elemento->num = receber_numero();			/* Substitui número atual por novo número válido. 	*/
	printf("\n\nNOVO VALOR DO ELEMENTO: %i", elemento->num);
	getch();
}

node_t *ordenar(node_t *lista)		/* Função que ordena a lista com algoritmo de ordenação por seleção. */
{
	node_t *aux; 					/* Ponteiro auxiliar da ordenação. 			*/
	node_t *lista_ordem;			/* Ponteiro para a movimentação da lista. 	*/
	node_t *novo;					/* Ponteiro inicial de nova lista ordenada. */
	novo 		= malloc(sizeof(node_t));
	novo->num 	= 0;				/* Alocação e inicialização de nó inicial. 	*/
	novo->ante 	= NULL;
	novo->prox 	= NULL;
	do {										/* Laço de ordenação. */
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

int receber_numero () 				/* Rotina que recebe a entrada de número de forma 	*/
{									/* iterativa até receber um número válido. 			*/
	bool entrada_valida;	/* Armazena valor lógico para saída da rotina.	*/
	char entrada[9];		/* Cadeia de caracteres da entrada. 			*/
	do {
		entrada_valida = true;				/* Assumindo a entrada como válida. */
		printf("N%cMERO: ", U_MA_AGUDO);
		scanf("%s", entrada);
		if (!verificar_numero(entrada)) {	/* Chama rotina que verifica se caracteres são numéricos. */
			printf("\n\nN%cMERO INV%cLIDO! INSIRA UM VALOR NUM%cRICO INTEIRO DIFERENTE DE ZERO!\n\n", U_MA_AGUDO, A_MA_AGUDO, E_MA_AGUDO);
			entrada_valida = false;			/* Caso não sejam, entrada é declara inválida. 	*/
		}
		else if (0 == atoi(entrada)) {		/* Verifica se número é ZERO (número que simboliza elemento vazio). */
			printf("\n\nN%cMERO ZERO! INSIRA UM VALOR NUM%cRICO INTEIRO DIFERENTE DE ZERO!\n\n", U_MA_AGUDO, A_MA_AGUDO, E_MA_AGUDO);
			entrada_valida = false;			/* Caso seja, entrada é declara inválida. 		*/
		}
	} while (!entrada_valida);
	return atoi(entrada);					/* Retorna entrada de caracteres válida convertida em inteiro. */
}

void adicionar(node_t *lista, int valor)	/* Rotina que criar novo nó e 		*/
{											/* o adiciona ao final da lista. 	*/
	node_t *novo_node;						/* ponteiro para novo nó da lista. 	*/
	lista  = selecionar_ultimo(lista);		/* Chama função que retorna último elemento da lista. 	*/
	if (0 != lista->num){					/* Se o último elemento não for 0 (lista vazia), 		*/
		novo_node = malloc(sizeof(node_t));	/* adiciona novo após último elemento da lista.			*/
		novo_node->num 	= valor;
		novo_node->ante = lista;
		novo_node->prox = NULL;
		lista->prox = novo_node;
	}
	else {								/* Caso a lista esteja vazia. */
		lista->num = valor;				/* Altera valor do elemento vazio para o valor inserido. 	*/
	}
}

void inserir(node_t *elemento, int valor)	/* Rotina que insere novo número logo em seguida 	*/
{											/* do elemento selecionado. 						*/
	node_t *novo_node;			/* Ponteiro para novo elemento. */
	node_t *aux;				/* Ponteiro auxiliar. 			*/
	novo_node 		= malloc(sizeof(node_t));	/* Alocação de memória para novo elemento. 	*/
	novo_node->num 	= valor;					/* Atribuição de valor para novo elemento. 	*/
	if (NULL != elemento->prox){				/* Se não for o último elemento: 			*/
		aux 			= elemento->prox;		/* Atribui as ligações entre os nós em ambas a pontas. */
		aux->ante 		= novo_node;
		elemento->prox 	= novo_node;
		novo_node->ante	= elemento;
		novo_node->prox	= aux;
	}
	else {										/* Caso seja o último: */
		novo_node->prox = NULL;					/* Adiciona o novo elemento ao final da lista. */
		novo_node->ante = elemento;
		elemento->prox 	= novo_node;
	}
}

void excluir (node_t *elemento)	/* Rotina que exclui o elemento selecionado da lista. */
{
	node_t *aux;				/* Ponteiros auxiliares para a exclusão. */
	node_t *aux_ante;
	node_t *aux_prox;
	if ((NULL == elemento->ante) && (NULL == elemento->prox)) {
		elemento->num 	= 0;	/* Se for o último elemento, atribui valor ZERO (vazio) para o elemento. */
	}
	else if (NULL == elemento->ante) {		/* Se for o primeiro elemento: 					*/
		aux 			= elemento->prox;	/* Passa o valor do segundo para o primeiro 	*/
		elemento->num 	= aux->num;
		excluir(aux);						/* e exclui o segundo elemento.					*/
	}
	else if (NULL == elemento->prox) {		/* Se for o último elemento: 					*/
		aux_ante 		= elemento->ante;	/* Remove a ligação para último elemento 		*/
		aux_ante->prox 	= NULL;				/* da lista.									*/
		elemento 		= aux_ante;
	}
	else {									/* Caso não seja o primeiro nem o último: 		*/
		aux_ante 		= elemento->ante;	/* Remove todas as ligações para o elemento.	*/
		aux_prox 		= elemento->prox;
		aux_ante->prox 	= aux_prox;
		aux_prox->ante 	= aux_ante;
		elemento 		= aux_prox;
	}
}

node_t *mover_registro(node_t *elemento, char dir)	/* Função que realiza a movimentação	*/
{													/* entre os elementos da navegação.		*/
	switch(dir)	
	{
		case ('E'):				/* Move para a esquerda (volta). */
			if (NULL != elemento->ante) {
				elemento = elemento->ante;
			}
		break;
		case ('D'):				/* Move para a direita (avança). */
			if (NULL != elemento->prox) {
				elemento = elemento->prox;
			}
		break;
	}
	return elemento;
}

node_t *selecionar_primeiro(node_t *lista) 	/* Função que retorna o primeiro elemento da lista. */
{
	while (NULL != lista->ante) {
		lista = lista->ante;
	}
	return lista;
}

node_t *selecionar_ultimo(node_t *lista)	/* Função que retorna o último elemento da lista. */
{
	while (NULL != lista->prox) {
		lista = lista->prox;
	}
	return lista;
}

node_t *selecionar_posicao(node_t *lista, int pos)	/* Função que retorna o elemento em 	*/
{													/* uma posição específica da lista.  	*/
	int x;
	lista = selecionar_primeiro(lista);
	for (x = 0; x < pos; x++) {
		if (NULL != lista->prox)
			lista = lista->prox;
	}
	return lista;
}

int retornar_posicao(node_t *lista) 	/* Função que retorna a posição de um elemento selecionado. */
{
	int contador = 0;
	while (NULL != lista->ante) {
		lista = lista->ante;
		contador++;
	}
	return contador;	
}

bool verificar_lista_vazia (node_t *lista)	/* Função que verifica se a lista 	*/
{											/* contém apenas o elemento vazio.	*/
	bool lista_vazia = false;
	if (NULL == lista->ante && NULL == lista->prox && lista->num == 0)
		lista_vazia = true;

	return lista_vazia;
}

int contar(node_t *lista)			/* Função que conta os elementos da lista. 	*/
{
	int contador = 0;
	while (NULL != lista) {
		lista 	 = lista->prox;
		contador++;
	}
	return contador;
}

bool verificar_numero(char *num)	/* Função que verifica se uma cadeia de 	*/	
{									/* caracteres representa um número.  		*/
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