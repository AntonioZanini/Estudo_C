#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
/* Programa: PILHA DE NUMEROS 
   Descrição: 
   Exercício que captura números e os coloca em uma pilha e, ao fim do 
   programa, os exibe ao usuário na correspondente ordem.
 */

#define U_MI_AGUDO '\xA3' /* ú */
#define U_MA_AGUDO '\xE9' /* Ú */

typedef struct node_t		/* Estrutura dos nós da pilha. 		*/
{
	int 			num;	/* Número armazenado. 				*/
	struct node_t	*prox;	/* Ponteiro para próximo elemento. 	*/
} node_t;

void adicionar(node_t *, int);
int remover(node_t *);
void exibir(node_t *, int);
int contar(node_t *);
bool valor_zero(int);

int main()
{
	int num_entrada;			/* Número recebi e enviado à pilha.  		*/
	char tecla_digitada = 'S';	/* Valor da tecla que controla o loop. 		*/
	node_t *pilha;				/* Declaração e inicialização da pilha. 	*/
	pilha 		= malloc(sizeof(node_t));
	pilha->num 	= 0;			/* 0 é o numero que representa o nó vazio. 	*/
	pilha->prox = NULL;
	do {						/* Loop de entrada de números. 				*/
		system("cls");
		printf("------------------------------------------------------\n\n");
		printf("                    PILHA DE N%cMEROS                  \n\n", U_MA_AGUDO);
		printf("------------------------------------------------------\n\n");
		printf(" Digite um n%cmero diferente de zero para a pilha: ", U_MI_AGUDO);
		scanf("%i", &num_entrada);
		if (valor_zero(num_entrada))	/* Verificação se a entrada é o número zero. */
		{
			printf("\n N%cmero zero! Digite um novo n%cmuro.", U_MI_AGUDO, U_MI_AGUDO);
			getch();
		}
		else {
			adicionar(pilha, num_entrada); 
			printf("\n Adicionar novo n%cmero? (s): ", U_MI_AGUDO);
			tecla_digitada = toupper(getche());
		}
	} while ('S' == tecla_digitada);
	system("cls");
	printf("------------------------------------------------------\n\n");
	printf("                    PILHA DE N%cMEROS                  \n\n", U_MA_AGUDO);
	printf("------------------------------------------------------\n\n");
	printf(" N%cmeros na pilha: \n", U_MI_AGUDO);
	exibir(pilha, contar(pilha));
	return (0);
}

void adicionar(node_t * pilha, int num_add)	/* Função que adiciona um número a pilha. */
{
	node_t *novo_node;	/* Variável para a criação de um novo nó da pilha. 	*/

	if (0 != pilha->num) {					/* Se não é o nó inicial vazio. 	   */
		novo_node = malloc(sizeof(node_t));	/* Cria e adiciona um novo nó à pilha. */
		novo_node->num  = pilha->num;
		novo_node->prox = pilha->prox;
		pilha->num = num_add;
		pilha->prox	= novo_node;
	}
	else {									/* Se for o nó inicial vazio.	*/
		pilha->num = num_add;				/* Altera seu valor. 			*/
	}
}
int remover(node_t * pilha)		/* Função que retorna número, removendo-o da pilha. */
{
	node_t *aux_del;				/* Variável auxiliar para a exclusão. */
	int num_node = pilha->num;		/* Número para o retorno. */
	if (NULL != pilha->prox){		/* Se não for o último nó, movimenta elementos. */
		aux_del = pilha->prox;
		pilha->num = aux_del->num;
		pilha->prox = aux_del->prox;
	}
	else {							/* Se for o último nó atribui valor ignorado. */
		pilha->num = 0;
	}
	return (num_node);
}

void exibir(node_t * pilha, int num_impressos)	/* Função que exibe números da pilha. */
{
	int elem_num;					/* Número de elementos exibidos*/
	int x;							/* Contador */
	int num_removido;				/* Número para a exibição */
	elem_num = contar(pilha);		
	if (num_impressos < elem_num) {elem_num = num_impressos;}
	/* numero exibições deve ser menos ou igual a contagem da pilha. */
	for (x = 0; x < elem_num; x++)	/* Loop de exibição */
	{
		num_removido = remover(pilha);
		if(!valor_zero(num_removido))	/* Ignora valores 0. */
			printf(" #%02i - %i\n", x+1, num_removido);	
	}
}

int contar(node_t * pilha)	/* Função que retorna contagem dos nós da pilha. */
{
	int 	contagem = 1;	/* Contador. */
	node_t 	*plh_cont;		/* Variável para manipular pilha para a contagem. */
	for (plh_cont = pilha; plh_cont->prox != NULL; plh_cont = plh_cont->prox)
		contagem++;			/* Loop que passa por todos os elementos e 	*/
							/* se auto incrementa. */
	return (contagem);
}

bool valor_zero(int num)	/* Função para verificar se o número é zero. */
{
	bool resultado = false;		/* Valor padrão de retorno. */
	if (0 == num) {resultado = true;}
	return resultado;
}