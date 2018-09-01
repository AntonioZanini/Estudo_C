#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

#define LIMITE_Y 30
#define LIMITE_X 100
/* CARACTERES ESPECIAIS */
#define Ccedil '\x80' /* Ç */
#define Aacute '\xB5' /* Á */
#define Agrave '\xB7' /* À */
#define Atilde '\xC7' /* Ã */
#define Iacute '\xD6' /* Í */

enum direcoes 
{
	CIMA = 0,
	DIREITA,
	BAIXO,
	ESQUERDA
};

enum estados
{
	TITULO = 'T',
	JOGO = 'J',
	GAMEOVER = 'O',
	SAIR = 'S'
};

typedef struct 
{
	char caracter;
	int pontasAbertas[4];
} bloco;

int direcaoOposta(int direcaoNormal);
int atribuirPontas(bloco * blocoAtual, int id, bool cima, bool direita, bool baixo, bool esquerda);
int carregarBlocos(bloco * blocos) ;
char procuraBloco(bloco * blocos, int direcaoLivre, int * blocoAnterior, int * blocoAtual);
bool verificaRota(int rota[100][2], int x, int y);
bool dentroDaTela(int x, int y);
int aleatorio (int *x, int *y);
void telaTitulo (char * estadoTitulo);
void telaJogo (char * estadoJogo, int * pontuacao, int * fase);
void telaGameOver(char * estadoGameOver, int pontuacaoFinal);
void gotoxy(int x, int y);

int main ()
{
	char estadoPrincipal = TITULO;
	int pontuacao = 0, fase = 1;

	srand(time(NULL));
	do
	{
		switch(estadoPrincipal)
		{
			case (TITULO):
				telaTitulo(&estadoPrincipal);
				pontuacao = 0;
				fase = 1;
			break;
			case (JOGO):
				telaJogo(&estadoPrincipal, &pontuacao, &fase);
			break;
			case (GAMEOVER):
				telaGameOver(&estadoPrincipal, pontuacao);
			break;
		}
		
	}	while (estadoPrincipal != SAIR);

	return 0;
}

void telaTitulo (char * estadoTitulo)
{
	char valorDigitado;

	do 
	{
		system("cls");
		gotoxy(0, 0);
		printf("=======================================================================\n");
		printf("\n\t\t\tLABIRINTO DIMENSIONAL\n\n");
		printf("=======================================================================\n\n");
		printf("\t\t(J) JOGAR\t\t\t(S) SAIR\n\n");
		printf("=======================================================================\n\n");
		printf("ESCOLHA A OP%c%cO DESEJADA: ", Ccedil, Atilde);
		valorDigitado = toupper(getche());
		switch(valorDigitado)
		{
			case ('J'):
				*estadoTitulo = JOGO;
			break;
			case ('S'):
				*estadoTitulo = SAIR;
			break;
			default:
				printf("\n\nVALOR INV%cLIDO, ESCOLHA NOVAMENTE!", Aacute);
				getch();
		} 
	} while (*estadoTitulo == TITULO);
}

void telaJogo (char * estadoJogo, int * pontuacaoJogo, int * faseJogo)
{
	char caracterDir;
	bloco blocos[11];
	int blocoAnterior, blocoAtual = 10;
	int numPasso = 0;
	int path[100][2];
	bool direcaoLivre = false;
	int direcaoProximo;
	int X, Y, i;
	for (i = 0; i < 100; i++)
	{
		path[i][0] = X;
		path[i][1] = Y;
	}

	carregarBlocos(blocos);
	system("cls");
	aleatorio(&X, &Y);
	gotoxy(X, Y);

	path[numPasso][0]= X;
	path[numPasso][1]= Y;

	printf("%c", blocos[blocoAtual].caracter);

	do
	{
		caracterDir = toupper(getch());
		direcaoLivre = false;
		switch(caracterDir)
		{
			case ('8'):
				if (blocos[blocoAtual].pontasAbertas[CIMA] == true)
				{
					direcaoLivre = true;
					direcaoProximo = CIMA;
					Y--;
				}
			break;
			case ('2'):
				if (blocos[blocoAtual].pontasAbertas[BAIXO] == true)
				{
					direcaoLivre = true;
					direcaoProximo = BAIXO;
					Y++;
				}
			break;
			case ('6'):
				if (blocos[blocoAtual].pontasAbertas[DIREITA] == true)
				{
					direcaoLivre = true;
					direcaoProximo = DIREITA;
					X++;
				}
			break;
			case ('4'):
				if (blocos[blocoAtual].pontasAbertas[ESQUERDA] == true)
				{
					direcaoLivre = true;
					direcaoProximo = ESQUERDA;
					X--;
				}
			break;
			case ('S'):
				/* IMPLEMENTAR GAME OVER */

			break;
		}
		if (direcaoLivre && verificaRota(path, X, Y) && dentroDaTela(X, Y))
		{

			gotoxy(X, Y);
			printf("%c", procuraBloco(blocos, direcaoProximo, &blocoAnterior, &blocoAtual));
			numPasso++;
			path[numPasso][0]= X;
			path[numPasso][1]= Y;

		}
		else {
			if (!direcaoLivre || !dentroDaTela(X, Y))
			{
				printf("\a");
			}
			else 
			{
				if (!verificaRota(path, X, Y))
				{
					
					*estadoJogo = GAMEOVER;
					printf("\a\a\a");
					getch();		
				}
			}
		}
	} while (*estadoJogo == JOGO);
}


void telaGameOver(char * estadoGameOver, int pontuacaoFinal)
{
	char resposta;
	
	system("cls");
	gotoxy(0, 0);
	printf("=======================================================================\n");
	printf("\n\t\t\tGAME OVER!\n\n");
	printf("=======================================================================\n\n");
	printf("\n\t\t\tPONTUA%c%cO FINAL: %d\n\n", Ccedil, Atilde, pontuacaoFinal);
	printf("=======================================================================\n\n");
	printf("\t\tRETORNAR %c TELA DE T%cTULO? (S/N) ", Agrave, Iacute);
	resposta = toupper(getch());
	if (resposta == 'S')
	{
		*estadoGameOver = TITULO;
	}
	else
	{
		*estadoGameOver = SAIR;
	}
}

int carregarBlocos(bloco * blocos) 
{
	blocos[0].caracter = '\xB9';
	atribuirPontas(blocos, 0, true, false, true, true);
	blocos[1].caracter = '\xBA';
	atribuirPontas(blocos, 1, true, false, true, false);
	blocos[2].caracter = '\xBB';
	atribuirPontas(blocos, 2, false, false, true, true);
	blocos[3].caracter = '\xBC';
	atribuirPontas(blocos, 3, true, false, false, true);
	blocos[4].caracter = '\xC8';
	atribuirPontas(blocos, 4, true, true, false, false);
	blocos[5].caracter = '\xC9';
	atribuirPontas(blocos, 5, false, true, true, false);
	blocos[6].caracter = '\xCA';
	atribuirPontas(blocos, 6, true, true, false, true);
	blocos[7].caracter = '\xCB';
	atribuirPontas(blocos, 7, false, true, true, true);
	blocos[8].caracter = '\xCC';
	atribuirPontas(blocos, 8, true, true, true, false);
	blocos[9].caracter = '\xCD';
	atribuirPontas(blocos, 9, false, true, false, true);
	blocos[10].caracter = '\xCE';
	atribuirPontas(blocos, 10, true, true, true, true);
	return 0;
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int atribuirPontas(bloco blocoAtual[], int id, bool cima, bool direita, bool baixo, bool esquerda)
{
	blocoAtual[id].pontasAbertas[CIMA] = cima;
	blocoAtual[id].pontasAbertas[DIREITA] = direita;
	blocoAtual[id].pontasAbertas[BAIXO] = baixo;
	blocoAtual[id].pontasAbertas[ESQUERDA] = esquerda;

	return 0;
}

char procuraBloco(bloco * blocos, int direcao, int * blocoAnterior, int * blocoAtual)
{
	int dirOposta = direcaoOposta(direcao);
	int r = 0;
	do{
		r = rand() % 11;
	} while (blocos[r].pontasAbertas[dirOposta] != true);
	blocoAnterior = blocoAtual;
	*blocoAtual = r;
	return blocos[r].caracter;
}

int direcaoOposta(int direcaoNormal) 
{
	int dirOposta = 0;
	switch(direcaoNormal)
	{
		case (CIMA):
			dirOposta = BAIXO;
		break;
		case (DIREITA):
			dirOposta = ESQUERDA;
		break;
		case (BAIXO):
			dirOposta = CIMA;
		break;
		case (ESQUERDA):
			dirOposta = DIREITA;
		break;
	}
	return dirOposta;

}

bool verificaRota(int rota[100][2], int x, int y) 
{
	int i;
	bool retorno = true;
	for (i = 0; i < 100; i++)
	{
		if ((rota[i][0] == x) && (rota[i][1] == y))
		{
			retorno = false;
		}
	}

	return retorno;
}

bool dentroDaTela(int x, int y)
{
	bool retorno = true;

	if (x < 0 || x > 100)
		retorno = false;
	if (y < 0 || y > 30)
		retorno = false;

	return retorno;
}

int aleatorio (int *x, int *y)
{
	*x = rand() % (LIMITE_X / 2);
	*y = rand() % (LIMITE_Y / 2);
	return 0;
}

