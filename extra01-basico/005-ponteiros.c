#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

#define MINIMO_X 1
#define MINIMO_Y 3
#define LIMITE_Y 28
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
	MUDAFASE = 'F',
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
bool verificaMoverRegistrarRota(int rota[100][2], int * x, int * y, int direcaoMovimento, int * passoAtual);
bool dentroDaTela(int x, int y, int direcaoTela);
int aleatorio (int *x, int *y);
void telaTitulo (char * estadoTitulo);
void telaJogo (char * estadoJogo, int * pontuacao, int * fase);
void telaGameOver(char * estadoGameOver, int pontuacaoFinal, int faseFinal);
void telaMudaFase(int faseNova);
void verificarSaida(int rota[100][2], int pontasAtuais[4], int X, int Y, int passoAtual, int localSaida[2], int nivelSaida);
void atualizaPontuacao(int x, int y, int pontuacaoAtual);
void limparPortas(int saida[2], int x, int y);
void verificaFase(char * estadoFase, int portaFase[2], int X, int Y);
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
				telaGameOver(&estadoPrincipal, pontuacao, fase);
			break;
		}

		if (estadoPrincipal == MUDAFASE)
		{
			estadoPrincipal = JOGO;
			fase++;
			telaMudaFase(fase);
		}
		
	}	while (estadoPrincipal != SAIR);

	return 0;
}

void telaTitulo (char * estadoTitulo)
{
	char valorDigitado;

	system("COLOR 0F");
/*
	  HANDLE  hConsole;
    int k;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  	for(k = 1; k < 255; k++)
  	{
    SetConsoleTextAttribute(hConsole, k);
    printf("%3d  %s\n", k, "I want to be nice today!");
	}
	getch();
*/

	do 
	{
		system("cls");
		gotoxy(0, 0);
		printf("|====================================================================================================|\n");
		printf("|                                                                                                    |\n");
		printf("|                                        LABIRINTO DIMENSIONAL                                       |\n");
		printf("|                                                                                                    |\n");
		printf("|====================================================================================================|\n");
		printf("|                                                                                                    |\n");
		printf("|              FUJA! N%cO OLHE PARA TR%cS! PROCURE PELA SA%cDA! AQUILO EST%c TE PERSEGUINDO!             |\n", Atilde, Aacute, Iacute, Aacute);
		printf("|                                                                                                    |\n");
		printf("|====================================================================================================|\n");
		printf("|                                                                                                    |\n");
		printf("|  COMANDOS:                                   8 CIMA                                                |\n");
		printf("|                                                                                                    |\n");
		printf("|                                  ESQUERDA 4     6 DIREITA                                          |\n");
		printf("|                                                                                                    |\n");
		printf("|                                              2 BAIXO                                               |\n");
		printf("|  S SAIR                                                                                            |\n");
		printf("|                                                                                                    |\n");
		printf("|====================================================================================================|\n");
		printf("|                                                                                                    |\n");
		printf("|  (J/[ENTER]) JOGAR        (S) SAIR                                                                 |\n");
		printf("|                                                                                                    |\n");
		printf("|====================================================================================================|\n\n");
		printf("   ESCOLHA A OP%c%cO DESEJADA: ", Ccedil, Atilde);
		valorDigitado = toupper(getche());
		switch(valorDigitado)
		{
			case ('J'):
				*estadoTitulo = JOGO;
			break;
			case ('S'):
				*estadoTitulo = SAIR;
			break;
			case (13): /* Enter */
				*estadoTitulo = JOGO;
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
	bool semColisao;
	int direcaoProximo;
	int X, Y, i;
	int portaSaida[2] = {-1, -1};
	for (i = 0; i < 100; i++)
	{
		path[i][0] = 0;
		path[i][1] = 0;
	}

	carregarBlocos(blocos);
	system("cls");
	printf("|====================================================================================================|\n");
	printf("|   LABIRINTO DIMENSIONAL - FASE %02i                                   PONTUA%c%cO: %05i               |\n", *faseJogo, Ccedil, Atilde, *pontuacaoJogo);
	printf("|====================================================================================================|\n");
	for (i = 0; i < 26; ++i)
	{
		printf("|                                                                                                    |\n");
	}
	printf("|====================================================================================================|");
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
				}
			break;
			case ('2'):
				if (blocos[blocoAtual].pontasAbertas[BAIXO] == true)
				{
					direcaoLivre = true;
					direcaoProximo = BAIXO;
				}
			break;
			case ('6'):
				if (blocos[blocoAtual].pontasAbertas[DIREITA] == true)
				{
					direcaoLivre = true;
					direcaoProximo = DIREITA;
				}
			break;
			case ('4'):
				if (blocos[blocoAtual].pontasAbertas[ESQUERDA] == true)
				{
					direcaoLivre = true;
					direcaoProximo = ESQUERDA;
				}
			break;
			case ('S'):
				*estadoJogo = GAMEOVER;

			break;
		}
		if (!direcaoLivre)
		{
			printf("\a");
			if (*estadoJogo == GAMEOVER)
			{
				system("COLOR 4F");
				getch();	
			}
		}
		else
		{
			semColisao = verificaMoverRegistrarRota(path, &X, &Y, direcaoProximo, &numPasso);
			if (!semColisao || !dentroDaTela(X, Y, direcaoProximo))
			{
					
				*estadoJogo = GAMEOVER;
				system("COLOR 4F");
				printf("\a");
				getch();		
			}
			else
			{

				verificaFase(estadoJogo, portaSaida, X, Y);
				limparPortas(portaSaida, X, Y);
				gotoxy(X, Y);
				printf("%c", procuraBloco(blocos, direcaoProximo, &blocoAnterior, &blocoAtual));
				verificarSaida(path, blocos[blocoAtual].pontasAbertas, X, Y, numPasso, portaSaida, *faseJogo);
				*pontuacaoJogo += 1 + (1 * (*faseJogo));
				atualizaPontuacao(X, Y, *pontuacaoJogo);
			}
		}

	} while (*estadoJogo == JOGO);
}


void telaGameOver(char * estadoGameOver, int pontuacaoFinal, int faseFinal)
{
	char resposta;
	

	system("cls");
	gotoxy(0, 0);
	printf("|====================================================================================================|\n");
	printf("|                                                                                                    |\n");
	printf("|                                             GAME OVER!                                             |\n");
	printf("|                                                                                                    |\n");
	printf("|====================================================================================================|\n");
	printf("|                                                                                                    |\n");
	printf("|           FASE DA MORTE: %02d                            PONTUA%c%cO FINAL: %05d                      |\n", faseFinal, Ccedil, Atilde, pontuacaoFinal);
	printf("|                                                                                                    |\n");
	printf("|====================================================================================================|\n\n");
	printf("   RETORNAR %c TELA DE T%cTULO? (S/N) ", Agrave, Iacute);
	resposta = toupper(getch());
	if (resposta == 'S' || resposta == 13)
	{
		*estadoGameOver = TITULO;
	}
	else
	{
		*estadoGameOver = SAIR;
	}
}

void telaMudaFase(int faseNova)
{
	system("cls");
	gotoxy(50, 15);
	system("COLOR F0");
	printf("MUDAN%cA DE FASE! NIVEL %i!", Ccedil, faseNova);
	getch();
	system("COLOR 0F");
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

bool verificaMoverRegistrarRota(int rota[100][2], int * x, int * y, int direcaoMovimento, int * passoAtual) 
{
	int i, vX = * x, vY = * y;
	bool retorno = true;
	switch(direcaoMovimento)
	{
		case (CIMA):
			vY--;
		break;
		case (DIREITA):
			vX++;
		break;
		case (BAIXO):
			vY++;
		break;
		case (ESQUERDA):
			vX--;
		break;
	}
	for (i = 0; i < 100; i++)
	{
		if ((rota[i][0] == vX) && (rota[i][1] == vY))
		{
			retorno = false;
		}
	}
	if (retorno == true)
	{
		(*x) = vX;
		(*y) = vY;
		(*passoAtual) ++;
		rota[*passoAtual][0]= (*x);
		rota[*passoAtual][1]= (*y);
	}
	return retorno;
}

bool dentroDaTela(int x, int y, int direcaoTela)
{
	bool retorno = true;
/*
	switch(direcaoTela)
	{
		case (CIMA):
			y--;
		break;
		case (DIREITA):
			x++;
		break;
		case (BAIXO):
			y++;
		break;
		case (ESQUERDA):
			x--;
		break;
	}
*/
	if (x < MINIMO_X || x > LIMITE_X)
		retorno = false;
	if (y < MINIMO_Y || y > LIMITE_Y)
		retorno = false;

	return retorno;
}

int aleatorio (int *x, int *y)
{
	*x = (rand() % (LIMITE_X - MINIMO_X)) + MINIMO_X;
	*y = (rand() % (LIMITE_Y - MINIMO_Y)) + MINIMO_Y;
	return 0;
}

void verificarSaida(int rota[100][2], int pontasAtuais[4], int X, int Y, int passoAtual, int localSaida[2], int nivelSaida)
{
  HANDLE  hConsole;
  int chancesSaidaAparecer, direcao, i, x, y;
  int direcoesTestadas[4] = {CIMA, DIREITA,BAIXO, ESQUERDA};
  bool direcaoVazia;
  chancesSaidaAparecer = rand() % 100;
  if (chancesSaidaAparecer < ((passoAtual / 2) - (nivelSaida * 5)))
  {
    for (direcao = 0; direcao < 4; direcao++)
    {
      direcaoVazia = true;
      x = X;
      y = Y;
      if (pontasAtuais[direcao] == true)
      {
        switch(direcao)
        {
          case (CIMA):
            y--;
          break;
          case (DIREITA):
            x++;
          break;
          case (BAIXO):
            y++;
          break;
          case (ESQUERDA):
            x--;
          break;
        }
        for (i = 0; i < 100; i++)
        {
          if ((rota[i][0] == x) && (rota[i][1] == y))
          {
            direcaoVazia = false;
          }
        }
      }
      else
      {
        continue;
      }
      if (direcaoVazia)
      {
        gotoxy(x,y);
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        /*	Fundo Preto com a cor da letra brilhante:
        	9 - Azul Es	10 - Verde	11 - Azul Cl	12 - Vermelho	13 - Purpura	14 - Amarelo	15 - Branco        */
        printf("%c", '\xDB');
        SetConsoleTextAttribute(hConsole, 15);
        localSaida[0] = x;
        localSaida[1] = y;
        gotoxy(X, Y);
        break;
      }
    }
  }
}

void verificaFase(char * estadoFase, int portaFase[2], int X, int Y)
{
  if (portaFase[0] == X && portaFase[1] == Y)
  {
    (*estadoFase) = MUDAFASE;
    
  }
}

void limparPortas(int saida[2], int x, int y)
{
	if ((saida[0] != -1) && (saida[1] != -1))
	{
	  gotoxy(saida[0], saida[1]);
	  printf(" ");
	  gotoxy(x, y);
	  saida[0] = -1;
	  saida[1] = -1;
	}
}

void atualizaPontuacao(int x, int y, int pontuacaoAtual)
{
	int xPlacar = 81, yPlacar = 1;
	gotoxy(xPlacar, yPlacar);
	printf("%05i", pontuacaoAtual);
	gotoxy(x, y);
}