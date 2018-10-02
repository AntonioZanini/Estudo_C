#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Programa que cria uma árvore binária e a popula com número de forma ordenada. */

			/* Constantes para a exibição de caracteres especiais. 	*/
#define A_MA_AGUDO		'\xB5' /* Á */
#define QUADRADO		'\xFE' /* Caractere quadrado para tópico. 	*/
			/* Estrutura que compõe elementos da árvore. 			*/
typedef struct node_t
{
	struct node_t 	*pri;		/* Primeira folha do nó. 		*/
	struct node_t 	*seg;		/* Segunda folha do nó. 		*/
	int 			valor;		/* Valor numérico armazenado. 	*/
} node_t;

void 	adicionar				(node_t *, int);
void 	imprimir_sequencia		(node_t *, bool);
int 	contar_folhas			(node_t *, bool);

int main(int argc, char const *argv[])	/* Rotina principal que cria a raiz da árvore, */
{										/* e chama as funções que a manipulam. */
	node_t *arvore;				/* Raiz da árvore. */
	arvore 			= malloc(sizeof(node_t));
	arvore->pri 	= NULL;		/* Alocação da memória e inicialização de valores. */
	arvore->seg 	= NULL;
	arvore->valor	= 0;

	adicionar(arvore,  1);		/* Chamando a rotina que adiciona folhas passando 	*/
	adicionar(arvore, 10);		/* os números a serem armazenados. 					*/
	adicionar(arvore, -5);
	adicionar(arvore, -7);
	adicionar(arvore, -3);
	adicionar(arvore,  2);
	adicionar(arvore,  7);
	adicionar(arvore,  8);

	printf(" Valores da %crvore:\n\n", A_MA_AGUDO);

	imprimir_sequencia(arvore, true); 	/* Chama rotina que exibe as folhas em ordem crescente. */
										/* Chama função que conta as folhas da árvore. 			*/
	printf("\n Total de folhas: %i\n", contar_folhas(arvore, true));
	return 0;							/* O argumento lógico em ambas as faz ignorar a raiz.  	*/
}

void adicionar(node_t *arvore, int val)		/* Rotina que adiciona nova folha em 	*/
{											/* posição relativa à ordem numérica. 	*/
	node_t *folha;		/* Nova folha a ser adicionada. */

	if (arvore->valor > val) {	/* Condicional para o posicionamento da folha. */
		if (NULL == arvore->pri) {  /* Codicional para verificar se já não possui primeira folha. */
			folha 			= malloc(sizeof(node_t));
			folha->pri 		= NULL;			/* Alocação da memória e inicialização dos 	*/
			folha->seg 		= NULL;			/* valores da folha. 						*/
			folha->valor 	= val;
			arvore->pri 		= folha;
		}
		else
			adicionar(arvore->pri, val); 	/* Recursivamente, tenta adicionar o valor 	*/
	}										/* em um nível inferior. 					*/
	else { /* arvore->valor <= val */
		if (NULL == arvore->seg) { /* Condicional para verificar se já não possui segunda folha. */
			folha 			= malloc(sizeof(node_t));
			folha->pri 		= NULL;			/* Alocação da memória e inicialização dos 	*/
			folha->seg 		= NULL;			/* valores da folha. 						*/
			folha->valor 	= val;
			arvore->seg 		= folha;
		}
		else
			adicionar(arvore->seg, val);	/* Recursivamente, tenta adicionar o valor 	*/
	}										/* em um nível inferior. 					*/
}

void imprimir_sequencia(node_t *arvore, bool ocultar_raiz)	/* Rotina que exibe na tela os valores da árvore, 	 */
{															/* podendo ocultar o valor da raiz com um parâmetro. */
	bool ocultar = ocultar_raiz;		/* Variável auxiliar para executar a condição apenas na raiz. */
	ocultar_raiz = false;
	if (NULL != arvore->pri) {			/* Se houver uma primeira folha, mova para ela. 		*/
		imprimir_sequencia(arvore->pri, ocultar_raiz);
	}
	if (!ocultar) {						/* Condição logicamente possível apenas para a raiz. 	*/
		printf(" %c %3i\n", QUADRADO, arvore->valor);	/* Exibe valor da folha atual. 			*/
	}
	if (NULL != arvore->seg) {			/* Se houver uma segunda folha, mova para ela.	 		*/
		imprimir_sequencia(arvore->seg, ocultar_raiz);
	}
}

int contar_folhas(node_t * arvore, bool ocultar_raiz)	/* Função que conta o número de elementos na árvore, */
{														/* podendo ocultar o valor da raiz com um parâmetro. */
	bool ocultar = ocultar_raiz;		/* Variável auxiliar para executar a condição apenas na raiz. */
	int soma = 0;						/* Acumulador de contagem. */
	ocultar_raiz = false;
	if (NULL != arvore->pri) {			/* Se houver uma primeira folha, mova para ela. 		*/
		soma += contar_folhas(arvore->pri, ocultar_raiz);
	}
	if (!ocultar) {						/* Condição logicamente possível apenas para a raiz. 	*/
		soma ++;
	}
	if (NULL != arvore->seg) {			/* Se houver uma segunda folha, mova para ela.	 		*/
		soma += contar_folhas(arvore->seg, ocultar_raiz);
	}
	return (soma);
}