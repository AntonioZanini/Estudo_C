#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore_t
{
	char 			palavra[10];
	struct arvore_t *esquerda;
	struct arvore_t *direita;
} arvore_t;

arvore_t *adicionar(arvore_t *, char *);
arvore_t *procurar(arvore_t *, char *);

int main(int argc, char const *argv[])
{
	arvore_t *arvore, *busca;

	arvore = NULL;

	arvore = adicionar(arvore, "pato");
	arvore = adicionar(arvore, "rato");
	arvore = adicionar(arvore, "zato");
	arvore = adicionar(arvore, "qato");

	printf("%s %s %s %s\n", arvore->palavra, arvore->direita->palavra, arvore->direita->esquerda->palavra, arvore->direita->direita->palavra);
	busca = procurar(arvore, "rato");
	printf("Achou : %s\n", busca->palavra);
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
	arvore_t *elemento;
	if (strcmp(palavra, arvore->palavra) < 0)
		elemento = procurar(arvore->esquerda, palavra);
	else if (strcmp(palavra, arvore->palavra) > 0)
		elemento = procurar(arvore->direita, palavra);
	else
		elemento = arvore;

	return elemento;
}

int obter_altura()

int obter_profundidade()

