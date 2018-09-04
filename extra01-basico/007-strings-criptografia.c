#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

/* Programa: CRIPTOGRAFIA */
/* Descrição: */
/* Programa que recebe uma string e a criptografa segundo uma chave aleatória com a substituição de 1 por dois caracteres. */

#define ALFABETO "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef struct 
{
	char alfa;
	char cripto[3];
} UnidadeCripto;

void CarregarChave(UnidadeCripto * chave);
bool jaExisteEm(char * unidade, UnidadeCripto * colecao);
void AppendString(char * principal, char caractere);
int ProcuraCaractere(char X);
void Criptografia(char * original, UnidadeCripto * chave, char * codigo);
void transfereString(char * fonte, char * destino, int dMax, int diferenca);
void limparChar(char * palavra);

int main()
{
	UnidadeCripto chave[52];
	int i;
	char palavra[20];
	char codigo[40];



	srand(time(NULL)); 	
	CarregarChave(chave);
	
	for (i = 0; i < 26; ++i)
	{
		printf("%c - %s \t\t\t\t", chave[i].alfa, chave[i].cripto);
		printf("%c - %s\n",  chave[i+26].alfa, chave[i+26].cripto);
	}

	for (i = 0; i < 100; i++)
	{
		limparChar(palavra);
		limparChar(codigo);
		printf("Insira uma palavra a ser criptografada: ");
		scanf("%s", palavra);

		Criptografia(palavra, chave, codigo);

		printf("\nValor criptografado: %s\n", codigo);
		printf("\nTamanho: %i\n", strlen(codigo));


		/*printf("%c\n", ALFABETO[0]);*/
		getch();
	}
	return 0;
}

void Criptografia(char * original, UnidadeCripto * chave, char * codigo)
{
	int y, buscaIndice, tamanho = strlen(original);
	char strMontagem[40];
	for (y = 0; y < tamanho; y++)
	{
		buscaIndice = ProcuraCaractere(original[y]);
		if (buscaIndice == -1)
		{
			printf("***\n");
			AppendString(strMontagem, original[y]);
			AppendString(strMontagem, original[y]);
		}
		else
		{
			AppendString(strMontagem, chave[buscaIndice].cripto[0]);
			AppendString(strMontagem, chave[buscaIndice].cripto[1]);
		}
	}
	transfereString(strMontagem, codigo, 40, 0);
}

void CarregarChave(UnidadeCripto * chave)
{
	char valorNovo[3];
	int r1 = 0, r2 = 0, i;

	for (i = 0; i < 52; i++)
	{
		chave[i].alfa = ALFABETO[i];
		do
		{
			r1 = rand() % 52;
			r2 = rand() % 52;
			valorNovo[0] = ALFABETO[r1];
			valorNovo[1] = ALFABETO[r2];
			valorNovo[2] = '\0';
		} while (jaExisteEm(valorNovo, chave) || (r1 == r2));
		strcpy(chave[i].cripto, valorNovo);
	}
}

bool jaExisteEm(char * unidade, UnidadeCripto * colecao)
{
	bool encontrado = false;
	int x;

	for (x = 0; x < 52; x++)
		if (*unidade == *colecao[x].cripto)
			encontrado = true;
	
	return encontrado;
}

int ProcuraCaractere(char X)
{
	int a;
	int resultado = -1;
	
	for (a = 0; a < 52; a++)
	{
		if ((X == ALFABETO[a]))
		{
			resultado = a;
		}
	}
	return resultado;
}

void AppendString(char * principal, char caractere)
{
	int tamanho = strlen(principal);

	principal[tamanho] = caractere;
	principal[tamanho+1] = '\0';
}

void transfereString(char * fonte, char * destino, int dMax, int diferenca)
{
	int i, tamanho = strlen(fonte);
	for (i = 0; i < (tamanho - diferenca); i++)
	{
		destino[i] = fonte[i+diferenca];
	}
	for (i = i; i < dMax; i++)
	{
		destino[i] = 0;
	}
}

void limparChar(char * palavra)
{
	int tamanho = strlen(palavra);
	int i;
	for (i = 0; i < tamanho; i++)
	{
		palavra[i] = 0;
	}
}