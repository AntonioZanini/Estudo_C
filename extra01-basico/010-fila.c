#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/* Programa FILA DE MENSAGENS */
/* Descrição: */
/* Recebe mensagens e as armazena em fila e, então, as exibe na tela.  */

							/* Constantes de apresentação de caracteres especiais. */
#define A_MI_TIL '\xC6' /* ã */

typedef struct mens 		/* Estrutura que representa os elementos da fila. */
{
	char texto[30] ;
	struct mens *prox;
} mensagem;

void adicionar_fila(mensagem *, char *);
void exibir_fila(mensagem *, int);
int conta_fila(mensagem *);
void remover_fila(mensagem *, char *);

int main(int argc, char const *argv[])		/* Função principal que capturas frases digitadas e as armazena em filas e, ao final, a exibe na ordem FIFO, */
{											/* primeiro a entrar, primeiro a sair. */
	mensagem *fila_mensagens;
	char msg[30];
	char tecla;
	fila_mensagens = malloc(sizeof(mensagem));
	strcpy(fila_mensagens->texto, "");		/* Atribui valores iniciais ao primeiro nó da fila. */
	fila_mensagens->prox = NULL;

	do 										/* Laço que controla as capturas das mensagens e as encaminha para o armazenamento na fila. */
	{
		system("cls");
		printf("-----------------------------------------\n\n");
		printf("            FILA DE MENSAGENS            \n\n");
		printf("-----------------------------------------\n\n");
		printf(" Digite uma mensagem para ser entregue: \n ");
		scanf("%[^\n]%*c", msg);
		adicionar_fila(fila_mensagens, msg);							/* Chama função que inclui a mensagem na última posição da fila. */
		printf("\n Deseja inserir mais uma mensagem? (n%co = n)\n\n", A_MI_TIL);
		tecla = getch();
	} while (tecla !='n');
	printf("-----------------------------------------\n\n");
	printf(" Exibindo %d mensagens armazenadas:\n\n", conta_fila(fila_mensagens));	/* Chama função que conta os elementos da fila. */
	exibir_fila(fila_mensagens, conta_fila(fila_mensagens));			/* Chama função que exibe as mensagens esvaziando a fila. */
	return 0;
}

void adicionar_fila(mensagem * fila_mensagens, char * msg_texto)	/* Função que cria um novo nó e o adiciona ao final da fila. */
{
	mensagem *fila, *novo;
	fila = fila_mensagens;
	while (fila->prox != NULL)				/* Loop para selecionar o último elemento. */
	{
		fila = fila->prox;
	};
	if (strcmp(fila->texto, "") == 0)		/* Condicional para saber se é um elemento vazio (inicial), caso seja, */
	{										/* ele adiciona a mensagem nele, em vez de criar novo nó. */
		strcpy(fila->texto, msg_texto);
	}
	else 									/* Caso contrário, cria o novo nó e adiciona ao fim da fila. */
	{
		novo = malloc(sizeof(mensagem));
		strcpy(novo->texto, msg_texto);
		novo->prox = NULL;
		fila->prox = novo;
	}
	
}

void remover_fila(mensagem * fila_mensagens, char * msg_texto)		/* Função responsável por remover o primeiro nó da fila enquanto retorna seu valor. */
{
	mensagem *aux;
	strcpy(msg_texto, fila_mensagens->texto);
	if (fila_mensagens->prox != NULL)					/* Passa o conteúdo do segundo elemento para o primeiro, fazendo a fila "andar". */
	{
		aux = fila_mensagens->prox;
		strcpy(fila_mensagens->texto, aux->texto);
		fila_mensagens->prox = aux->prox;
	}
	else 												/* Seja o último elemento, atribui o valor inicial. */
	{
		strcpy(fila_mensagens->texto, "");
	}
}

void exibir_fila(mensagem * fila_mensagens, int num_mensagens)		/* Função que exibe na tela o valor de um determinado número de elementos retirados da fila. */
{
	int x, num_exibe = 0;
	char msg[30];
	num_exibe = num_mensagens;
	if (num_exibe > conta_fila(fila_mensagens))						/* Se o número de elementos a serem exibidos for maior que o número */
	{																/* de elementos na fila, o número é limitado ao número de elementos */
		num_exibe = conta_fila(fila_mensagens);						/* na fila. */
	}
	for (x = 0; x < num_exibe; x++)
	{
		if (strcmp(fila_mensagens->texto, "") != 0)					/* Condicional que impede de exibir elementos com valores vazios (iniciais). */
		{
			remover_fila(fila_mensagens, msg);						/* Chama função para recuperar mensagem da fila. */
			printf(" #%02d - %s\n", x+1, msg);
		}
	}
}

int conta_fila(mensagem * fila_mensagens)					/* Função responsável por contar os elementos da fila. */
{
	mensagem *fila;
	int contador = 0;
	for (fila = fila_mensagens; fila != NULL; fila = fila->prox) {
		contador++;
	}
	return contador;
}