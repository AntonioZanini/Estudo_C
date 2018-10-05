#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

#define C_MI_CEDILHA '\x87' /* ç */
#define A_MI_TIL '\xC6' /* ã */
#define O_MI_AGUDO '\xA2' /* ó */
#define O_MI_TIL '\xE4' /* õ */
#define E_MI_AGUDO '\x82' /* é */
#define U_MI_AGUDO '\xA3' /* ú */
#define I_MI_AGUDO '\xA1' /* í */
#define A_MI_AGUDO '\xA0' /* á */
#define E_MI_CIRC 	'\x88' 	/* ê */
#define A_MA_AGUDO		'\xB5' /* Á */
#define ORDINAL_MASC	'\xA7' 	/* º */

typedef struct arvore_t
{
	char 			palavra[10];
	struct arvore_t *esquerda;
	struct arvore_t *direita;
} arvore_t;

arvore_t *adicionar(arvore_t *, char *);
arvore_t *procurar(arvore_t *, char *);
int obter_altura(arvore_t *, int);
int obter_profundidade(arvore_t *, arvore_t *);
int contar_nos(arvore_t *);
int contar_folhas(arvore_t *);
arvore_t *obter_menor_no(arvore_t *);
arvore_t *obter_maior_no(arvore_t *);
bool verificar_folha(arvore_t *);
char **obter_lista(arvore_t *);
void popular_lista_palavras(arvore_t *, char **, int *);
arvore_t *obter_pai(arvore_t *, arvore_t *);
bool verificar_paternidade(arvore_t *, arvore_t *);
int obter_capacidade_altura(int);
float obter_eficiencia(arvore_t *, int);
char **gerar_array_string(int, int);
arvore_t *popular_nova_arvore(arvore_t *, char **, int);
arvore_t *reorganizar(arvore_t *);
arvore_t *tela_adicionar(arvore_t *);
arvore_t *tela_procurar(arvore_t *);
arvore_t *tela_info(arvore_t *);
void goToXY(int, int);
void imprime_arvore(arvore_t *, arvore_t *, int, int);
arvore_t *excluir(arvore_t *, arvore_t *);


arvore_t *reorganizar(); 

int main(int argc, char const *argv[])
{
	arvore_t *arvore;
	char opcao;
	arvore = NULL;
/*
	arvore = adicionar(arvore, "pato");
	arvore = adicionar(arvore, "rato");
	arvore = adicionar(arvore, "zato");
	arvore = adicionar(arvore, "qato");
	arvore = adicionar(arvore, "zzzz");
	arvore = adicionar(arvore, "zzzzz");
	arvore = adicionar(arvore, "zzzz0");
*/
	arvore = adicionar(arvore, "A");
	arvore = adicionar(arvore, "B");
	arvore = adicionar(arvore, "C");
	arvore = adicionar(arvore, "D");
	arvore = adicionar(arvore, "E");
	arvore = adicionar(arvore, "F");
	arvore = adicionar(arvore, "G");
	arvore = adicionar(arvore, "H");
	arvore = adicionar(arvore, "I");
	arvore = adicionar(arvore, "J");
	arvore = adicionar(arvore, "K");
	arvore = adicionar(arvore, "L");
	arvore = adicionar(arvore, "M");
	arvore = adicionar(arvore, "N");
	arvore = adicionar(arvore, "O");

	do {
		system("cls");
		printf("----------------------------------------------\n\n");
		printf("           %cRVORE BIN%cRIA DE BUSCA                \n\n", A_MA_AGUDO, A_MA_AGUDO);
		printf("----------------------------------------------\n\n");
		printf("  1 - Adicionar. \n\n");
		printf("  2 - Procurar. \n\n");
		printf("  3 - Informa%c%ces sobre a %crvore. \n\n", C_MI_CEDILHA, O_MI_TIL, A_MI_AGUDO);
		printf("  4 - Sair. \n\n");
		printf("----------------------------------------------\n\n");
		printf("  Op%c%co: ", C_MI_CEDILHA, A_MI_TIL);
		opcao = getche();
		switch(opcao)
		{
			case ('1'):
				arvore = tela_adicionar(arvore);
			break;
			case ('2'):
				arvore = tela_procurar(arvore);
			break;
			case ('3'):
				arvore = tela_info(arvore);
			break;
			case ('4'):
				
			break;
			default:
				printf("\n\n  Op%c%co inv%clida! Escolha novamente. ", C_MI_CEDILHA, A_MI_TIL, A_MI_AGUDO);
				getch();
		}
	} while (opcao != '4');
	return 0;
}

arvore_t *tela_adicionar(arvore_t *arvore)
{
	char nova_palavra[10];
	system("cls");
	printf("----------------------------------------------\n\n");
	printf("           %cRVORE BIN%cRIA DE BUSCA                \n\n", A_MA_AGUDO, A_MA_AGUDO);
	printf("----------------------------------------------\n\n");
	printf("  Digite uma palavra: ");
	scanf("%s", nova_palavra);
	arvore = adicionar(arvore, nova_palavra);
	printf("  Palavra adicionada!\n");
	getch();
	return arvore;
}

arvore_t *tela_procurar(arvore_t *arvore)
{
	char valor_busca[10];
	char tecla_digitada;
	arvore_t *resultado_pesquisa;
	do {
		system("cls");
		printf("----------------------------------------------\n\n");
		printf("           %cRVORE BIN%cRIA DE BUSCA                \n\n", A_MA_AGUDO, A_MA_AGUDO);
		printf("----------------------------------------------\n\n");
		printf("  Digite valor para a pesquisa: ");
		scanf("%s", valor_busca);
		resultado_pesquisa = procurar(arvore, valor_busca);
		if (NULL == resultado_pesquisa){
			printf("  Palavra n%co encontrada!\n", A_MI_TIL);
			printf("\n\n   P - Sair.");
		}
		else{
			printf("  Palavra encontrada:\n");
			printf("                          %s\n", resultado_pesquisa->palavra);
			printf("                     Pai: %s\n", obter_pai(arvore, resultado_pesquisa) );
			printf("                  Filhos: %s\n", (verificar_folha(resultado_pesquisa))? "N\xC6o": "Sim" );
			printf("                   N%cvel: %i\n", I_MI_AGUDO, obter_profundidade(arvore, resultado_pesquisa) );
			printf("\n\n   1 - Exclur.   4 - Sair.");
		}
		tecla_digitada = getche();
	} while (tecla_digitada != '4');
	return arvore;
}

arvore_t *tela_info(arvore_t *arvore)
{
	char tecla_digitada;
	char *test;
	test = malloc(sizeof(char)* 10);
	do {
		system("cls");
		imprime_arvore(arvore, arvore, 50, 2);
		goToXY(0, 22);
		printf("------------------------------------------------------------");
		printf("------------------------------------------------------------\n");
		printf("   Altura da %crvore: %i", A_MI_AGUDO, obter_altura(arvore, 1));
		printf("   N%c de n%cs: %i", ORDINAL_MASC, O_MI_AGUDO, contar_nos(arvore));
		printf("   N%c de folhas: %i", ORDINAL_MASC, contar_folhas(arvore));
		printf("   Menor: %s", obter_menor_no(arvore)->palavra);
		printf("   Maior: %s\n", obter_maior_no(arvore)->palavra);
		printf("   Capacidade: %i", obter_capacidade_altura(obter_altura(arvore, 1)));
		printf("   Efici%cncia: %.f%\n", E_MI_CIRC, 100 * obter_eficiencia(arvore, obter_altura(arvore, 1)));
		printf("   1 - Reorganizar.   4 - Sair.\n");
		printf("------------------------------------------------------------");
		printf("------------------------------------------------------------\n   ");
		tecla_digitada = getche();
		if (tecla_digitada == 'a')
			arvore = reorganizar(arvore);
		else{
			test[0] = tecla_digitada;
			test[1] = '\0';
			if (tecla_digitada != 'a' && tecla_digitada != 's')
				arvore = excluir(arvore, procurar(arvore, test));
		}
	} while (tecla_digitada != 's');
	return arvore;
}

void imprime_arvore(arvore_t *arvore, arvore_t *raiz, int x, int y)
{
	int nivel;
	if (NULL != arvore){
		nivel = obter_profundidade(raiz, arvore) + 1;
		goToXY(x, y);
		printf("%s\n", arvore->palavra);
		imprime_arvore(arvore->esquerda, raiz, x-(2*(10 / nivel)), y + 2);
		imprime_arvore(arvore->direita, raiz, x+(2*(10 / nivel)), y + 2);
	}
}

arvore_t *adicionar(arvore_t *arvore, char *palavra)
{
	arvore_t *novo;
	novo = malloc(sizeof(arvore_t));
	strcpy(novo->palavra, palavra);
	novo->esquerda = NULL;
	novo->direita = NULL;
	if (NULL == arvore) {
		arvore = novo;
	}
	else {
		if (strcmp(palavra, arvore->palavra) < 0){
			arvore->esquerda = adicionar(arvore->esquerda, palavra);
		}
		else if (strcmp(palavra, arvore->palavra) >= 0){
			arvore->direita = adicionar(arvore->direita, palavra);
		}
	}
	return arvore;
}

arvore_t *procurar(arvore_t *arvore, char *palavra)
{
	arvore_t *elemento = NULL;
	if (NULL != arvore){
		if (strcmp(palavra, arvore->palavra) < 0)
			elemento = procurar(arvore->esquerda, palavra);
		else if (strcmp(palavra, arvore->palavra) > 0)
			elemento = procurar(arvore->direita, palavra);
		else
			elemento = arvore;
	}
	return elemento;
}

int obter_altura(arvore_t *arvore, int nivel_anterior)
{
	int soma = 0, soma_a, soma_b;
	if (NULL != arvore){
		nivel_anterior++;
		soma_a = obter_altura(arvore->esquerda, nivel_anterior);
		soma_b = obter_altura(arvore->direita, nivel_anterior);
		nivel_anterior--;
		soma = (soma_a > soma_b) ? soma_a : soma_b;
		soma = (soma < nivel_anterior) ? nivel_anterior : soma;
	}
	return soma;
}

int obter_profundidade(arvore_t *arvore, arvore_t *elemento)
{
	int soma = -1, soma_a, soma_b;
	if (arvore != elemento){
		if (NULL != arvore){
			soma_a = obter_profundidade(arvore->esquerda, elemento);
			soma_b = obter_profundidade(arvore->direita, elemento);
			soma = (soma_a > soma_b) ? soma_a : soma_b;
		}
		if (soma >= 0) {
			soma ++;
		}
	}
	else {
		soma++;
	}
	return soma;
}

int contar_nos(arvore_t *arvore)
{
	int soma = 0;
	if (NULL != arvore){
		soma += contar_nos(arvore->esquerda);
		soma += 1;
		soma += contar_nos(arvore->direita);
	}
	return soma;
}

int contar_folhas(arvore_t *arvore)
{
	int soma = 0;
	if (NULL != arvore){
		if (verificar_folha(arvore)){
			soma += 1;
		}
		else {
			soma += contar_folhas(arvore->esquerda);
			soma += contar_folhas(arvore->direita);
		}
	}
	return soma;
}

arvore_t *obter_menor_no(arvore_t *arvore)
{
	if (NULL != arvore->esquerda){
		arvore = obter_menor_no(arvore->esquerda);
	}
	return arvore;
}

arvore_t *obter_maior_no(arvore_t *arvore)
{
	if (NULL != arvore->direita){
		arvore = obter_maior_no(arvore->direita);
	}
	return arvore;	
}

bool verificar_folha(arvore_t *arvore)
{
	bool resultado = false;
	if (NULL == arvore->esquerda && NULL == arvore->direita){
		resultado = true;
	}
	return resultado;
}


bool verificar_paternidade(arvore_t *pai, arvore_t *filho)
{
	bool resultado = false;
	if (pai->esquerda == filho || pai->direita == filho)
		resultado = true;
	return resultado;
}

int obter_capacidade_altura(int h)
{
	return (int)(pow(2, h)-1);
}

float obter_eficiencia(arvore_t *arvore, int h)
{
	float total;
	total = contar_nos(arvore);
	return (total / ((float)obter_capacidade_altura(h)));
}

arvore_t *obter_pai(arvore_t *arvore, arvore_t *elemento)
{
	arvore_t *pai = NULL;
	if (!verificar_paternidade(arvore, elemento)){
		if (strcmp(elemento->palavra, arvore->palavra) < 0)
			if (arvore->esquerda == NULL)
				pai = NULL;
			else
				pai = obter_pai(arvore->esquerda, elemento);
		else
			if (arvore->direita == NULL)
				pai = NULL;
			else
				pai = obter_pai(arvore->direita, elemento);	
	}
	else {
		pai = arvore;
	}
	return pai;
}




arvore_t *reorganizar(arvore_t *arvore) /*cria nova arvore atraves de lista sequencial */
{
	int total_nos;
	char **lista_palavras;
	arvore_t *nova_arvore;
	nova_arvore = NULL;
	total_nos = contar_nos(arvore);
	lista_palavras = obter_lista(arvore);
	nova_arvore = popular_nova_arvore(nova_arvore, lista_palavras, total_nos);
	return nova_arvore;
}


arvore_t *popular_nova_arvore(arvore_t *arvore, char **palavras, int total)
{
	char **metade_a;
	char **metade_b;
	int i;
	int n_a;
	int n_b;
	int impar;
	impar = total % 2;
	n_a = total / 2;
	n_b = (total / 2) + (impar -1);
	arvore = adicionar(arvore, palavras[n_a]);
	metade_a = gerar_array_string(n_a, 10);

	for (i = 0; i < n_a; i++){
		strcpy(metade_a[i], palavras[i]);
	}
	metade_b = gerar_array_string(n_b, 10);
	for (i = 0; i < n_b; i++){
		strcpy(metade_b[i], palavras[i+n_a+1]);
	}

	if (n_a > 1)
		popular_nova_arvore(arvore, metade_a, n_a);
	else if (n_a != 0)
		arvore = adicionar(arvore, metade_a[0]);

	if (n_b > 1)
		popular_nova_arvore(arvore, metade_b, n_b);
	else if (n_b != 0)
		arvore = adicionar(arvore, metade_b[0]);

	return arvore;
}

char **obter_lista(arvore_t *arvore)
{
	int i = 0, total_nos;
	char **lista;
	total_nos =  contar_nos(arvore);
	lista = gerar_array_string(total_nos, 10);
	popular_lista_palavras(arvore, lista, &i);
	return lista;
}

void popular_lista_palavras(arvore_t *arvore, char **lista, int *ordem)
{
	if (NULL != arvore){
		popular_lista_palavras(arvore->esquerda, lista, ordem);
		strcpy(lista[*ordem], arvore->palavra);
		(*ordem)++;
		popular_lista_palavras(arvore->direita, lista, ordem);
	}
}

char **gerar_array_string(int posicoes, int caracteres) 
{
	int i;
	char **matriz;
	matriz = malloc(posicoes * sizeof(char *));
	for (i = 0; i < posicoes; i++)
	{
		matriz[i] = malloc(sizeof(char) * caracteres);
	}
	return matriz;
}

void goToXY(int x, int y)
{
  COORD coord; 									/* Estrutura que representa coordenadas em uma tela. */
  coord.X = x;									/* Valor da coluna. */
  coord.Y = y;									/* Valor da linha.  */
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  	/* Função que recebe o manipulador do stdout (saida de texto da tela)     */
  																		/* e um conjunto de coordenadas, com estes ele move o cursor de impressão */
}

arvore_t *excluir(arvore_t *arvore, arvore_t *elemento)
{
	arvore_t *substituto;
	arvore_t *pai_subs;
	arvore_t *pai;
	pai = obter_pai(arvore, elemento);
	substituto = NULL;
	if (elemento->esquerda != NULL){
		substituto = obter_maior_no(elemento->esquerda);
		pai_subs = obter_pai(arvore, substituto);
		if (pai_subs->direita == substituto)
				pai_subs->direita = substituto->esquerda;
		else
			pai_subs->esquerda = substituto->esquerda;
	}
	else if (elemento->direita != NULL){
		substituto = obter_menor_no(elemento->direita);
		pai_subs = obter_pai(arvore, substituto);
		if (pai_subs->direita == substituto)
			pai_subs->direita = substituto->direita;
		else
			pai_subs->esquerda = substituto->direita;
	}
	if (pai != NULL) {
		if (pai->direita == elemento)
			pai->direita = substituto;
		else
			pai->esquerda = substituto;
	}
	else {
		arvore = substituto;
	}
	if (substituto != NULL){
		substituto->direita = elemento->direita;
		substituto->esquerda = elemento->esquerda;
	}
	return arvore;
}