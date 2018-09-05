#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

/* Programa: CRIPTOGRAFIA */
/* Descrição: */
/* Programa que recebe uma string e a criptografa e descriptografa segundo uma chave aleatória com a substituição de 1 por dois caracteres. */

#define ALFABETO "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"	/* Constante que agrega os caracteres do alfabeto para referência na criação da chave criptográfica. */

typedef struct 							/* Estrutura criada para servir como unidade para a chave de criptográfica. */
{
	char alfa;							/* alfa representa a letra encontrada para a ser substituida, seus falores são equivalentes à constante ALFABETO. */
	char cripto[3];						/* cripto representa o codigo a ser inserido no lugar da respectiva letra, será gerada uma string composta por duas letras aleatorias. */
} UnidadeCripto;

void CarregarChave(UnidadeCripto * chave);
bool jaExisteEm(char * unidade, UnidadeCripto * colecao);
void AppendString(char * principal, char caractere);
int ProcuraCaractere(char X);
void Criptografia(char * original, UnidadeCripto * chave, char * codigo);
void transfereString(char * fonte, char * destino, int dMax, int diferenca);
void limparChar(char * palavra);
void Descriptografar (char * codigo, UnidadeCripto * chave, char * original);
int ProcuraCripto(char letra1, char letra2, UnidadeCripto * chave);

int main()
{
	UnidadeCripto chave[52];			/* Cria a matriz para abrigar a chave equivalendo todos os 52 caracteres definidos. */
	int i;
	char palavra[50];					/* Variável que receberá a string a ser criptografada. */
	char codigo[100];					/* Variável que receberá criptografia da string palavra. */
	char decodificado[50];				/* Variável que receberá a descriptografia da string codigo. */

	srand(time(NULL)); 					/* Inicia a seed randômica baseada no tempo do sistema. */
	CarregarChave(chave);				/* Função que popula a matriz da chave criptográfica com valores aleatórios dentre os adequados. */
	printf("===================================================================\n");
	printf("                         CRIPTOGRAFIA\n");
	printf("===================================================================\n");
	printf("CHAVE DE CRIPTOGRAFIA GERADA:\n");

	for (i = 0; i < 13; ++i)			/* Exibe a chave de criptografia gerada para conferência. */
	{
		printf("%c - %s\t\t", chave[i].alfa, chave[i].cripto);
		printf("%c - %s\t\t", chave[i+13].alfa, chave[i+13].cripto);
		printf("%c - %s\t\t",  chave[i+26].alfa, chave[i+26].cripto);
		printf("%c - %s\n",  chave[i+39].alfa, chave[i+39].cripto);
	}
	printf("===================================================================\n");

	for (i = 0; i < 100; i++)			/* Loop Infinito de execução. */
	{
		limparChar(palavra);			/* Função que limpa os conteúdos de cadeias de caracteres para evitar problemas com resíduos de dados. */
		limparChar(codigo);
		limparChar(decodificado);
		printf("Insira uma sequência a ser criptografada (Max 49 caracteres): ");	
		fgets(palavra, sizeof(palavra), stdin);					/* Recebe apenas a quantidade caracteres que pode ser processada. */

		Criptografia(palavra, chave, codigo);					/* Executa a Função de criptografia. */

		printf("\nValor criptografado: %s", codigo);
		
		Descriptografar(codigo, chave, decodificado);			/* Executa a Função de descriptografia. */
		printf("Valor descriptografado: %s\n", decodificado);
		
		getch();
	}
	return 0;
}

void Descriptografar (char * codigo, UnidadeCripto * chave, char * original)		/* Função Principal que recebe um valor criptografado e a sua chave e, então, */
{																					/* retorna o valor descriptografado. */
	char strMontagem[50];													/* Cadeia de caracteres para a montagem da string descriptografada. */
	int buscaIndice, z, c1 = 0, c2 = 1, tamanho;
	limparChar(strMontagem);												/* Limpa possíveis resíduos de dados na cadeia de caracteres. */
	tamanho = strlen(codigo) / 2;											
	for (z = 0; z < tamanho; z++)											/* O processo roda pegando 2 em 2 dos caracteres do código e os envia para serem buscados na chave */
	{																		/* para adicionar o valor decodificado à string de montagem, caso não ache significa que é um caso */
		buscaIndice = ProcuraCripto(codigo[c1], codigo[c2], chave);			/* números ou caracteres especiais então simplesmente adiciona o primeiro e descarta o segundo. */
		if (buscaIndice == -1)
			AppendString(strMontagem, codigo[c1]);
		else
			AppendString(strMontagem, chave[buscaIndice].alfa);
		
		c1 += 2;															/* Variáveis auxiliares para obter caracteres de 2 em 2. */
		c2 = c1 +1;
	}

	transfereString(strMontagem, original, 50, 0);							/* Função que transfere o valor de uma cadeia de caracteres da string de montagem para o retorno. */
}

void Criptografia(char * original, UnidadeCripto * chave, char * codigo)			/* Função Principal que recebe uma sequência de caracteres e uma chave criptográfica e, */
{																					/* então, retorna o valor criptografado. */
	int y, buscaIndice, tamanho = strlen(original);
	char strMontagem[100];													/* Cadeia de caracteres para a montagem da string criptografada. */
	for (y = 0; y < tamanho; y++)
	{																		/* O processo pega cada caractere e o envia em busca da dupla de caracteres equivalente na */
		buscaIndice = ProcuraCaractere(original[y]);						/* chave criptográfica e adiciona estes à string de montagem, caso não ache significa que é um */
		if (buscaIndice == -1)												/* caso de números ou caracteres especiais então simplesmente tal caractere é inserido duplicado */
		{																	/* na string de montagem. */
			AppendString(strMontagem, original[y]);
			AppendString(strMontagem, original[y]);
		}
		else
		{
			AppendString(strMontagem, chave[buscaIndice].cripto[0]);
			AppendString(strMontagem, chave[buscaIndice].cripto[1]);
		}
	}
	transfereString(strMontagem, codigo, 100, 0);							/* Função que transfere o valor de uma cadeia de caracteres da string de montagem para o retorno. */
}

void CarregarChave(UnidadeCripto * chave)		/* Função que popula a chave criptográfica, gerando valores aleatório únicos para cada valor de ALFABETO. */
{
	char valorNovo[3];
	int r1 = 0, r2 = 0, i;

	for (i = 0; i < 52; i++)
	{
		chave[i].alfa = ALFABETO[i];
		do											/* Gera uma dupla de caracteres única e diferente entre si. */
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

bool jaExisteEm(char * unidade, UnidadeCripto * colecao)		/* Função para verificar se um valor criptográfico já existe na chave. */
{
	bool encontrado = false;
	int x;

	for (x = 0; x < 52; x++)
		if (*unidade == *colecao[x].cripto)
			encontrado = true;
	
	return encontrado;
}

int ProcuraCaractere(char X)							/* Função que retorna o índice da letra em ALFABETO e na chave, caso não seja encontrada retorna o valor de -1. */
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

int ProcuraCripto(char letra1, char letra2, UnidadeCripto * chave)		/* Função que procura valor criptográfico na chave para retornar o índice da respectiva letra, */
{																		/* caso não seja encontrada retorna o valor -1. */
	int x, resultado = -1;
	char busca[3];

	busca[0] = letra1;
	busca[1] = letra2;
	busca[2] = '\0';
	
	for (x = 0; x < 52; x++)	
		if (strcmp(busca, chave[x].cripto) == 0)
			resultado = x;
	
	
	return resultado;
}

void AppendString(char * principal, char caractere)						/* Função que anexa um caractere ao final de uma cadeia de caracteres */
{
	int tamanho = strlen(principal);

	principal[tamanho] = caractere;
	principal[tamanho+1] = '\0';										/* Caractere finalizador de cadeias de caracteres. */
}

void transfereString(char * fonte, char * destino, int dMax, int diferenca)		/* Função que transfere, um a um, cada caractere de uma cadeia para outra, */
{																				/* limpando posições excedentes. */
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

void limparChar(char * palavra)											/* Função que percorre uma cadeia de caracteres inteiramente limpando cada posição. */
{																		
	int tamanho = strlen(palavra);
	int i;
	for (i = 0; i < tamanho; i++)
	{
		palavra[i] = 0;
	}
}