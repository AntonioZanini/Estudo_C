#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
 



enum direcoes 
{
	CIMA = 0,
	DIREITA,
	BAIXO,
	ESQUERDA
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
void gotoxy(int x, int y);
int main ()
{
	char caracterDir;
	
	bloco blocos[11];
	int blocoAnterior, blocoAtual = 5;
	int numDir;
	/*char path[100];*/
	bool direcaoLivre = false;
	int direcaoProximo;
	int X = 0, Y = 0;

	carregarBlocos(blocos);
	printf("%c", blocos[blocoAtual].caracter);
	srand(time(NULL));
	
	do
	{
		caracterDir = toupper(getch());

		switch(caracterDir)
		{
			case ('C'):
				numDir = CIMA;
				if (blocos[blocoAtual].pontasAbertas[CIMA] == true)
				{
					direcaoLivre = true;
					direcaoProximo = CIMA;
					Y--;
				}
			break;
			case ('B'):
				numDir = BAIXO;
				if (blocos[blocoAtual].pontasAbertas[BAIXO] == true)
				{
					direcaoLivre = true;
					direcaoProximo = BAIXO;
					Y++;
				}
			break;
			case ('D'):
				numDir = DIREITA;
				if (blocos[blocoAtual].pontasAbertas[DIREITA] == true)
				{
					direcaoLivre = true;
					direcaoProximo = DIREITA;
					X++;
				}
			break;
			case ('E'):
				numDir = ESQUERDA;
				if (blocos[blocoAtual].pontasAbertas[ESQUERDA] == true)
				{
					direcaoLivre = true;
					direcaoProximo = ESQUERDA;
					X--;
				}
			break;
			default:
				direcaoLivre = false;
		}
		if (direcaoLivre)
		{
			gotoxy(X, Y);
			printf("%c", procuraBloco(blocos, direcaoProximo, &blocoAnterior, &blocoAtual));

		}
		else 
		{
			printf("direcao invalida\n");
		}
	} while (caracterDir != 'S');
	
	return 0;
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