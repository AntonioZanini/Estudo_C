#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
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
arvore_t *obter_menor_folha(arvore_t *);
arvore_t *obter_maior_folha(arvore_t *);
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


arvore_t *reorganizar(); 

int main(int argc, char const *argv[])
{
	arvore_t *arvore, *busca;
	char **lista;
	int i;
	arvore = NULL;

	arvore = adicionar(arvore, "pato");
	arvore = adicionar(arvore, "rato");
	arvore = adicionar(arvore, "zato");
	arvore = adicionar(arvore, "qato");
	arvore = adicionar(arvore, "zzzz");
	arvore = adicionar(arvore, "zzzzz");
	arvore = adicionar(arvore, "zzzz0");


	printf("%s %s %s %s\n", arvore->palavra, arvore->direita->palavra, arvore->direita->esquerda->palavra, arvore->direita->direita->palavra);
	busca = procurar(arvore, "pato");
	printf("Achou : %s\n", busca->palavra);
	printf("Vazio: %s\n", (strcmp(busca->palavra,"") == 0)? "SIM" : "NAO");
	printf("Nulo ? %s\n", (busca == NULL)? "SIM" : "NAO");
	printf("Pai : %s\n", obter_pai(arvore, busca)->palavra);
	printf("Prof :  %i\n", obter_profundidade(arvore, busca));
	printf("Uma Folha? %s\n", (verificar_folha(busca))? "SIM" : "NAO");
	printf("H-Arvore :  %i\n", obter_altura(arvore, 1));
	printf("Nos na Arvore :  %i\n", contar_nos(arvore));
	printf("Capacidade :  %i\n", obter_capacidade_altura(obter_altura(arvore, 1)));
	printf("Eficiencia :  %.2f%\n", 100 * obter_eficiencia(arvore, obter_altura(arvore, 1)));
	printf("Folhas na Arvore :  %i\n", contar_folhas(arvore));
	printf("Menor Folha :  %s\n", obter_menor_folha(arvore)->palavra);
	printf("Maior Folha :  %s\n", obter_maior_folha(arvore)->palavra);
	lista = obter_lista(arvore);
	printf("\n\n");
	for (i = 0; i < contar_nos(arvore); i++)
	{
		printf("%s\n", lista[i]);
	}

	arvore = reorganizar(arvore);
	printf("%s %s %s \n", arvore->palavra, arvore->direita->palavra, arvore->esquerda->palavra);
	printf("H-Arvore :  %i\n", obter_altura(arvore, 1));
	printf("Nos na Arvore :  %i\n", contar_nos(arvore));
	printf("Capacidade :  %i\n", obter_capacidade_altura(obter_altura(arvore, 1)));
	printf("Eficiencia :  %.2f%\n", 100 * obter_eficiencia(arvore, obter_altura(arvore, 1)));
	/* code */
	return 0;
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

arvore_t *obter_menor_folha(arvore_t *arvore)
{
	if (NULL != arvore->esquerda){
		arvore = obter_menor_folha(arvore->esquerda);
	}
	return arvore;
}

arvore_t *obter_maior_folha(arvore_t *arvore)
{
	if (NULL != arvore->direita){
		arvore = obter_maior_folha(arvore->direita);
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
	if (!verificar_paternidade(arvore, elemento) && NULL != arvore->esquerda){	
			if (!verificar_folha(arvore->esquerda)){
				pai = obter_pai(arvore->esquerda, elemento);
			}
	}
	if (!verificar_paternidade(arvore, elemento) && NULL != arvore->direita){	
		if (!verificar_folha(arvore->direita) ) {
			pai = obter_pai(arvore->direita, elemento);	
		}	
	}
	if (verificar_paternidade(arvore, elemento)){
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
	metade_a = gerar_array_string(n_a, 5);

	for (i = 0; i < n_a; i++){
		strcpy(metade_a[i], palavras[i]);
	}
	metade_b = gerar_array_string(n_b, 5);
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
	lista = gerar_array_string(total_nos, 5);
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