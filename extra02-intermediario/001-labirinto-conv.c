#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE_MAZE_X 90
#define SIZE_MAZE_Y 26

enum estados_jogo {SAIR, INICIO, JOGANDO, GAME_OVER, LEVEL_UP}; 

void goToXY(int, int);
int *moveToRandom(int **, int);
void carregarTelaJogo(int **, int);
bool moveToLocation(int **, int, int *, int, int, int *, int *, int);
void atualiza_header(int *, int *);
void jogar_fase(enum estados_jogo *, int, int *, int);
void game_over(enum estados_jogo *);
void tela_inicial(enum estados_jogo *);

int main(int argc, char const *argv[])
{
	enum estados_jogo estado = INICIO;
	int recorde = 0;
	int placar = 5;
	int fase = 1;
	srand(time(NULL));
	do {
		switch(estado)
		{
			case (JOGANDO):
				jogar_fase(&estado, fase, &placar, recorde);
			break;
			case (GAME_OVER):
				game_over(&estado);
				recorde = max(placar, recorde);
				placar = 0;
			break;
			case (INICIO):
				tela_inicial(&estado);
			break;
			case (LEVEL_UP):
			break;
			case (SAIR):
			break;
		}
	} while (estado != SAIR);
	/*getch();*/
	return 0;
}

void tela_inicial(enum estados_jogo *estado)
{
	int x, y;
	printf("%c", 201);
	for (x = 0; x < (SIZE_MAZE_X); x++)
		printf("%c", 205);
	printf("%c\n", 187);
	printf("%c", 186);
	goToXY(SIZE_MAZE_X + 1, 1);
	printf("%c\n", 186);

	goToXY((SIZE_MAZE_X / 2) - 4, 1);
	printf("LABIRINTO");
	
	

	goToXY(0, 2);
	printf("%c", 204);
	for (x = 0; x < (SIZE_MAZE_X); x++)
		printf("%c", 205);
	printf("%c\n", 185);
	for (y = 0; y < (SIZE_MAZE_Y); y++){
		printf("%c", 186);
		goToXY(SIZE_MAZE_X+1, y+3);
		printf("%c\n", 186);
	}
	printf("%c", 200);
	for (x = 0; x < (SIZE_MAZE_X); x++)
		printf("%c", 205);
	printf("%c", 188);

	getch();
	(*estado) = JOGANDO;
}

void jogar_fase(enum estados_jogo *estado, int fase, int *pontuacao, int recorde)
{
	int **labirinto;
	int *playerPos;
	int passos = 100;
	int x, y;
	char key;
	
	labirinto = malloc(sizeof(int *) * SIZE_MAZE_X);
	playerPos = malloc(sizeof(int) * 2);

	for (x = 0; x < SIZE_MAZE_X; x++)
		labirinto[x] = malloc(sizeof(int *) * SIZE_MAZE_Y);

	for (y = 0; y < SIZE_MAZE_Y; y++)
		for (x = 0; x < SIZE_MAZE_X; x++){
			if (rand() % 5 == 1)
				labirinto[x][y] = 1;
			else
				labirinto[x][y] = 0;
		}

	carregarTelaJogo(labirinto, recorde);

	atualiza_header(pontuacao, &passos);

	playerPos = moveToRandom(labirinto, 184);
	goToXY(playerPos[0], playerPos[1]);
	
	do
	{
		key = toupper(getch());
		switch(key)
		{
			case ('W'):
				moveToLocation(labirinto, 184, playerPos, 0, -1, pontuacao, &passos, fase);
			break;
			case ('A'):
				moveToLocation(labirinto, 184, playerPos, -1, 0, pontuacao, &passos, fase);
			break;
			case ('S'):
				moveToLocation(labirinto, 184, playerPos, 0, 1, pontuacao, &passos, fase);
			break;
			case ('D'):
				moveToLocation(labirinto, 184, playerPos, 1, 0, pontuacao, &passos, fase);
			break;
			
		}
		if (passos < 1)
		{
			break;
			
		}
	} while (key != 'Q');
	(*estado) = GAME_OVER;

}

void carregarTelaJogo(int **labirinto, int recorde)
{
	int x, y, coordx, coordy;
	system("cls");
	printf("%c", 201);
	for (x = 0; x < (SIZE_MAZE_X); x++)
		printf("%c", 205);
	printf("%c\n", 187);
	printf("%c", 186);
	goToXY(SIZE_MAZE_X + 1, 1);
	printf("%c\n", 186);

	goToXY(SIZE_MAZE_X - 40, 1);
	printf("Recorde: ");
	printf("%08i  ", recorde);
	printf("Potuacao: ");
	

	goToXY(0, 2);
	printf("%c", 204);
	for (x = 0; x < (SIZE_MAZE_X); x++)
		printf("%c", 205);
	printf("%c\n", 185);
	for (y = 0; y < (SIZE_MAZE_Y); y++){
		printf("%c", 186);
		goToXY(SIZE_MAZE_X+1, y+3);
		printf("%c\n", 186);
	}
	printf("%c", 200);
	for (x = 0; x < (SIZE_MAZE_X); x++)
		printf("%c", 205);
	printf("%c", 188);

	coordx = 1;
	coordy = 3;
	
	for (y = 0; y < SIZE_MAZE_Y; y++){
	goToXY(coordx, coordy);
		for (x = 0; x < SIZE_MAZE_X; x++) {
			/*if (x != 0)
				printf("-" );*/
			if (labirinto[x][y] == 1 )
				printf("%c", 176);
			else
				printf(" ");
		}
		coordy++;
	}
}



void goToXY(int x, int y)
{
  COORD coord; 									/* Estrutura que representa coordenadas em uma tela. */
  coord.X = x;									/* Valor da coluna. */
  coord.Y = y;									/* Valor da linha.  */
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  	/* Função que recebe o manipulador do stdout (saida de texto da tela)     */
  																		/* e um conjunto de coordenadas, com estes ele move o cursor de impressão */
}																		/* de texto para a posição representada pelas coordenadas. */

int *moveToRandom(int** lab, int char_code)
{
	int x, y;
	int *ret;
	ret = malloc(sizeof(int) * 2);
	do{
		x = (rand() % (SIZE_MAZE_X)) + 1;
		y = (rand() % (SIZE_MAZE_Y)) + 3;
	} while (lab[x][y] != 0);
		
	lab[x][y] = char_code;
	goToXY(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);	/* Função que utiliza um manipulado do stdout para alterar as cores da impressão do cursor. */
    		/*	Fundo Preto com a cor da letra brilhante:
    			9 - Azul Es	10 - Verde	11 - Azul Cl	12 - Vermelho	13 - Purpura	14 - Amarelo	15 - Branco        */
	printf("%c", char_code);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	/* Restaura a coloração normal do cursor. */
	ret[0] = x;
	ret[1] = y;
	return ret;
}

bool moveToLocation(int **lab, int char_code, int *pos, int x, int y, int *pontos, int *passos, int fase)
{
	if (((pos[0] + x) > 0) && ((pos[0] + x) < (SIZE_MAZE_X + 1)))
	if (((pos[1] + y) > 2) && ((pos[1] + y) < (SIZE_MAZE_Y + 3)))
	if (lab[pos[0] + x - 1][pos[1] + y - 3] != 1)
	{
		printf(" ");
		pos[0] += x;
		pos[1] += y;
		goToXY(pos[0], pos[1]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);	/* Função que utiliza um manipulado do stdout para alterar as cores da impressão do cursor. */
        		/*	Fundo Preto com a cor da letra brilhante:
        			9 - Azul Es	10 - Verde	11 - Azul Cl	12 - Vermelho	13 - Purpura	14 - Amarelo	15 - Branco        */
		printf("%c", char_code);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	/* Restaura a coloração normal do cursor. */
		(*passos)--;
		(*pontos) += 1 * fase;
		atualiza_header(pontos, passos);
		goToXY(pos[0], pos[1]);
		
		return true;
	}
	return false;
}

void atualiza_header(int *pontos, int *passos)
{
	goToXY(3, 1);
	printf("Tempo restante: ");
	printf("%03i", *passos);
	goToXY(SIZE_MAZE_X - 10, 1);
	printf("%08i", *pontos);
}

void game_over(enum estados_jogo *estado)
{
	char continuar = 0;
	do
	{
		system("cls");
		goToXY(SIZE_MAZE_X / 2, SIZE_MAZE_Y / 2);
		system("color 47");
		printf("GAME OVER!");
		goToXY(SIZE_MAZE_X / 2, (SIZE_MAZE_Y / 2)+1);
		printf("Deseja reiniciar? (Y/N): ");
		continuar = getch();
	} while (toupper(continuar) != 'Y' && toupper(continuar) != 'N');
	system("color 07");
	system("cls");
	if (toupper(continuar) == 'Y')
		(*estado) = JOGANDO;
	else 
		(*estado) = SAIR;
}