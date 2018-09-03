#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>			/* Biblioteca que fornece acesso às funcionalidades de manipulação de datas e tempo. */
#include <windows.h>		/* Biblioteca que fornece acesso às funcionalidades da API do windows, com funções do S.O., porém limitando o código à plataforma Windows. */

/* Programa: LABIRINTO DIMENSIONAL */
/* Descrição: */
/* Jogo no qual o jogador controla um personagem abstraído em uma posição e deve guiá-lo até a saída através de um labirinto gerado aleatoriamente 
   sem voltar a caminhos préviamente visitados ou chegar pontos sem saída*/

							/* Constantes: */
#define MINIMO_X 1			/* Valor mínimo para a coordenada X do cursor de jogo. */
#define MINIMO_Y 3			/* Valor mínimo para a coordenada Y do cursor de jogo. */
#define LIMITE_Y 28			/* Valor máximo para a coordenada Y do cursor de jogo. */
#define LIMITE_X 100		/* Valor máximo para a coordenada X do cursor de jogo. */
/* CARACTERES ESPECIAIS */
#define Ccedil '\x80' /* Ç */
#define Aacute '\xB5' /* Á */
#define Agrave '\xB7' /* À */
#define Atilde '\xC7' /* Ã */
#define Iacute '\xD6' /* Í */
							
							/* enum é um tipo de dados defido pelo o usuário de modo a designar constantes para representar valores inteiros sob um contexto definido. */
enum direcoes 				/* Este enum representa os valores de 0-3, que são o valores índices de vetores que manipulam as quatro direções. A criação de enum deixa o */
{							/* código mais legível. */
	CIMA = 0,
	DIREITA,
	BAIXO,
	ESQUERDA
};

enum estadoFase				/* Este enum representa o agrupamento de estados da execução do jogo, utilizado para representar de forma mais clara e objetiva a sua transição. */
{
	TITULO = 'T',
	JOGO = 'J',
	GAMEOVER = 'O',
	MUDAFASE = 'F',
	SAIR = 'S'
};
							/* struct é um tipo especial de dados constituido pelo agrupamento de variáveis. Sua função é conceder a um único elemento */
typedef struct 				/* o uso de múltiplas variáveis.  */
{							/* Este struct agrupa um char e vetor inteiro para compor um dado que representa  */
	char caracter;			/* uma peça (o char com a imagem a ser exibida) */
	int pontasAbertas[4];	/* com suas direções que possuem ligações (o vetor inteiro com um valor, positivo ou negativo, para cada direção). */
} bloco;

/* PROTÓTIPOS DAS FUNÇÕES */
int direcaoOposta(int direcaoNormal);
void atribuirPontas(bloco * blocoAtual, int id, bool cima, bool direita, bool baixo, bool esquerda);
void carregarBlocos(bloco * blocos) ;
char procuraBloco(bloco * blocos, int direcaoLivre, int * blocoAtual);
bool verificaMoverRegistrarRota(int rota[100][2], int * x, int * y, int direcaoMovimento, int * passoAtual);
bool dentroDaTela(int x, int y, int direcaoTela);
int aleatorio (int *x, int *y);
void telaTitulo (char * estadoTitulo);
void telaJogo (char * estadoJogo, int * pontuacao, int * fase);
void telaGameOver(char * estadoGameOver, int pontuacaoFinal, int faseFinal);
void telaMudaFase(int faseNova);
bool novoNaRota(int rota[100][2], int x, int y);
void aparecerItem(int rota[100][2], int x, int y, int * saidaAtual, int * itemAtual);
void verificaItem(int itemLocal[2], int X, int Y, int * itemBonus, int * pontuacao, int faseAtual);
void aparecerSaida(int rota[100][2], int pontasAtuais[4], int X, int Y, int passoAtual, int localSaida[2], int itemLocal[2], int itemBonus, int nivelSaida);
void atualizaPontuacao(int x, int y, int pontuacaoAtual);
void limparPortas(int saida[2], int x, int y);
void verificaFase(char * estadoFase, int portaFase[2], int X, int Y);
void goToXY(int x, int y);

int main () 		/* Rotina principal que faz a transição entre os estados de execução do jogo. */
{
	char estadoPrincipal = TITULO;
	int pontuacao = 0, fase = 1;

	srand(time(NULL));									/* Cria uma seed para as funções random baseado na relogio do sistema. */
	do													/* Loop que controla a execução do programa. */
	{
		switch(estadoPrincipal)							/* Condicional que direciona os estados principais do programa. */
		{
			case (TITULO):
				telaTitulo(&estadoPrincipal);						/* Executa a Tela de Título. */
				pontuacao = 0;										/* o caractere & antes de uma variável significa que está sendo passado é seu ponteiro (seu */
				fase = 1;											/* endereço de memória) e não seu valor armazenado. */
			break;
			case (JOGO):
				telaJogo(&estadoPrincipal, &pontuacao, &fase);		/* Executa a Tela de Jogo. */
			break;
			case (GAMEOVER):
				telaGameOver(&estadoPrincipal, pontuacao, fase);	/* Executa a Tela de Game Over. */
			break;
		}

		if (estadoPrincipal == MUDAFASE)				/* Condicional para a execução transicional da Tela de Mudança de Fase. */
		{
			estadoPrincipal = JOGO;
			fase++;
			telaMudaFase(fase);
		}
		
	}	while (estadoPrincipal != SAIR);				/* Verifica o estado SAIR, que representa a saída do jogo. */

	return 0;
}

void telaTitulo (char * estadoTitulo)					/* Função que exibe a Tela de Título, responsável pela exibição da informações básicas e iniciar o jogo. */
{														/* O caractere * em um parâmetro significa que o parâmetro em questão deve ser um ponteiro. */
	char valorDigitado;

	system("COLOR 0F");						/* Comando do ambiente windows para alterar as cores do console para fundo preto e letras brancas, o visual padrão.  */

	do 										/* Loop que controla a execução da Tela de Título. */
	{
		system("cls");
		goToXY(0, 0);						/* Função para alterar a posição do cursor, neste caso, o colocando na posição inicial da tela. */
		/* INTERFACE DA TELA DE TÍTULO. */
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
		printf("|  %c - PORTA               %c - SUPRIMENTOS                                                           |\n", '\xDB', '\xDC');
		printf("|                                                                                                    |\n");
		printf("|====================================================================================================|\n");
		printf("|                                                                                                    |\n");
		printf("|  (J/[ENTER]) JOGAR        (S) SAIR                                                                 |\n");
		printf("|                                                                                                    |\n");
		printf("|====================================================================================================|\n\n");
		printf("   ESCOLHA A OP%c%cO DESEJADA: ", Ccedil, Atilde);
		valorDigitado = toupper(getche());
		switch(valorDigitado)								/* Condicional que encaminha as entradas a seus repectivos controles. */
		{
			case ('J'):
				*estadoTitulo = JOGO;						/* O caractere * antes de uma variável significa que o valor manipulado será o valor contido na */
			break;											/* variável destino (do ponteiro) e não o valor do endereço. */
			case ('S'):
				*estadoTitulo = SAIR;
			break;
			case (13): 										/* Valor em char para a tela Enter */
				*estadoTitulo = JOGO;
				break;
			default:
				printf("\n\nVALOR INV%cLIDO, ESCOLHA NOVAMENTE!", Aacute);
				getch();
		} 
	} while (*estadoTitulo == TITULO);						/* Ao alterar o valor do estado significa que esta tela deve se encerrar. */
}

void telaJogo (char * estadoJogo, int * pontuacaoJogo, int * faseJogo)	/* Função que exibe e controla o jogo. */
{
	char caracterDir;					
	bloco blocos[11];					/* Matriz de objetos struct bloco para serem populados com dados das imagens utilizadas para os caminhos do labirinto. */
	int blocoAtual = 10;				/* Indice da imagem a ser impressa na tela. */
	int numPasso = 0;					/* Número que se incrementa a cada passo completo no labirinto. */
	int path[100][2];					/* Matriz que armazena as coordenadas do caminho (rota) que jogador fez. */
	bool direcaoLivre = false;			/* Variável para controlar se a direção escolhida possui uma saída disponível no bloco atual. */
	bool semColisao;					/* Variável para receber a verificação do movimento válido. */
	int direcaoProximo;					/* Variável para atribuir a direção do movimento sendo executado. */
	int X, Y, i;						/* X e Y são os valores para controlar as coordenadas do cursos do jogador. */
	int portaSaida[2] = {-1, -1};		/* Variável que armazena as coordenadas da porta de passagem de nível na tela, -1, -1 são valores para caso ela não exista no momento. */
	int itemLocal[2] = {-1, -1};		/* Variável que armazena as coordenadas para o item bonus, -1, -1 são valores para caso ela não exista no momento. */
	int itemBonus = 0;					/* Valor para bonificação nas chances de aparecer uma porta caso um item seja adquirido durante a fase. */
	for (i = 0; i < 100; i++)			/* Iniciando o caminho com valores 0. */
	{
		path[i][0] = 0;
		path[i][1] = 0;
	}

	carregarBlocos(blocos);				/* Chama função para atribuir os valores dos blocos disponíveis. */
	system("cls");
	/* TELA DO JOGO */
	printf("|====================================================================================================|\n");
	printf("|   LABIRINTO DIMENSIONAL - FASE %02i                                   PONTUA%c%cO: %05i               |\n", *faseJogo, Ccedil, Atilde, *pontuacaoJogo);
	printf("|====================================================================================================|\n");
	for (i = 0; i < 26; ++i)			/* %02i e %05i: o 2 e o 5 significam que sempre usarão, respectivamente, 2 e 5 espaços, o 0 significa que no lugar de espaço */
	{									/* em branco, as sobras desses números serão preenchidos com zeros à esquerda.  */
		printf("|                                                                                                    |\n");
	}
	printf("|====================================================================================================|");
	aleatorio(&X, &Y);					/* Envia os ponteiros de X e Y para terem os seus valores de variável atribuidos com valores iniciais aleatórios. */

	goToXY(X, Y);						/* Posiciona o cursor nas novas coordenada XY.*/

	path[numPasso][0]= X;				/* Registra a coordenada inicial. */
	path[numPasso][1]= Y;

	printf("%c", blocos[blocoAtual].caracter);		/* Exibe a imagem do primeiro bloco. */

	do 												/* Loop que controla a execução da Tela do Jogo. */
	{
		caracterDir = toupper(getch());
		direcaoLivre = false;
		switch(caracterDir)							/* Condicional que encaminha as entradas a seus repectivos controles. */
		{
			case ('8'):
				if (blocos[blocoAtual].pontasAbertas[CIMA] == true)		/* Verifica se o bloco tem uma ponta que conecta com a direção CIMA. */
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
				*estadoJogo = GAMEOVER;										/* Mudança para GAMEOVER impedindo o novo ciclo do loop e encaminhando o próximo estado. */

			break;
		}
		if (!direcaoLivre)													/* Se não receber uma tecla de movimento válida para uma direção disponível. */
		{
			printf("\a");													/* Aviso Sonoro. */
			if (*estadoJogo == GAMEOVER)
			{
				system("COLOR 4F");											/* Aplica cores tema do GAME OVER ao console, fundo vermelho e letras brancas. */
				getch();	
			}
			else
			{
				(*pontuacaoJogo) -= (1 * (*faseJogo));						/* Diminui a pontuação ao errar a tecla, valor aumenta conforme as fases avançam. */
				atualizaPontuacao(X, Y, *pontuacaoJogo);					/* Atualiza o placar exibido na Tela de Jogo. */
			}
		}
		else
		{
			semColisao = verificaMoverRegistrarRota(path, &X, &Y, direcaoProximo, &numPasso);	/* Chama função que verifica se o caminho ja foi percorrido e, */
																								/* caso não, altera coordenada XY e registra o movimento. */
			if (!semColisao || !dentroDaTela(X, Y, direcaoProximo))			/* Verifica se teve colisao com um caminho percorrido ou se ultrapassou limites da tela. */
			{
				*estadoJogo = GAMEOVER;
				system("COLOR 4F");
				printf("\a");
				getch();		
			}
			else
			{
				verificaFase(estadoJogo, portaSaida, X, Y);					/* Verifica se o personagem chegou à localização de uma porta do mudança de fase na tela. */
				aparecerItem(path, X, Y, portaSaida, itemLocal);			/* Verifica as chances e imprime o item na tela sempre que possível. */
				verificaItem(itemLocal, X, Y, &itemBonus, pontuacaoJogo, *faseJogo);	/* Verifica se o personagem chegou à localização de um item na tela. */
				limparPortas(portaSaida, X, Y);											/* Apaga portas não utilizadas. */
				goToXY(X, Y);															/* Move para novas coordenadas XY. */
				printf("%c", procuraBloco(blocos, direcaoProximo, &blocoAtual));		/* Imprime valor do char do bloco adequado ao bloco atual. */
				aparecerSaida(path, blocos[blocoAtual].pontasAbertas, X, Y, numPasso, portaSaida, itemLocal, itemBonus, *faseJogo); /* Verifica as chances e imprime   */
				*pontuacaoJogo += 1 + (1 * (*faseJogo));	/* Aumenta pontuação a cada movimento em função do numero da fase */	 /* a porta do nível na tela sempre */
				atualizaPontuacao(X, Y, *pontuacaoJogo);	/* Atualiza o placar exibido na Tela de Jogo. */						 /* que possível.                   */		
			}
		}

	} while (*estadoJogo == JOGO);							/* Ao alterar o valor do estado significa que esta tela deve se encerrar. */
}


void telaGameOver(char * estadoGameOver, int pontuacaoFinal, int faseFinal)		/* Função que exibe a Tela de Game Over. */
{
	char resposta;
	

	system("cls");
	goToXY(0, 0);
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
		*estadoGameOver = TITULO;					/* Retorna para a Tela de Título; */
	}
	else
	{
		*estadoGameOver = SAIR;						/* Encerra o programa. */
	}
}

void telaMudaFase(int faseNova)						/* Função que exibe uma tela de transição entre os níveis. */
{
	system("cls");									/* Limpa a tela. */
	goToXY(50, 15);									/* Recoloca o cursor perto do centro da tela para escrever. */
	system("COLOR F0");								/* Altera cores do console, fundo branco e letras pretas. */
	printf("MUDAN%cA DE FASE! NIVEL %i!", Ccedil, faseNova);
	getch();
	system("COLOR 0F");								/* Altera cores do console para o padrão. */
}

void carregarBlocos(bloco * blocos) 				/* Função responsável por popular a lista disponíveis de blocos de caracteres e suas direções válidas. */
{
	blocos[0].caracter = '\xB9';							/* Atribuição do código Hex ASCII do char. */
	atribuirPontas(blocos, 0, true, false, true, true);		/* Chamada da função que atribui os valores à matriz das direções disponíveis. */
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
}

void goToXY(int x, int y)
{
  COORD coord; 									/* Estrutura que representa coordenadas em uma tela. */
  coord.X = x;									/* Valor da coluna. */
  coord.Y = y;									/* Valor da linha.  */
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  	/* Função que recebe o manipulador do stdout (saida de texto da tela)     */
  																		/* e um conjunto de coordenadas, com estes ele move o cursor de impressão */
}																		/* de texto para a posição representada pelas coordenadas. */

void atribuirPontas(bloco blocoAtual[], int id, bool cima, bool direita, bool baixo, bool esquerda) /* Função que popula a matriz de direções disponíveis de um bloco. */
{
	blocoAtual[id].pontasAbertas[CIMA] = cima;
	blocoAtual[id].pontasAbertas[DIREITA] = direita;
	blocoAtual[id].pontasAbertas[BAIXO] = baixo;
	blocoAtual[id].pontasAbertas[ESQUERDA] = esquerda;
}

char procuraBloco(bloco * blocos, int direcao, int * blocoAtual)		/* Função que procura um bloco na lista que tenha uma conexão com o bloco atual. */
{
	int dirOposta = direcaoOposta(direcao);								/* Converte a direção na direção oposta. */
	int r = 0;
	do{
		r = rand() % 11;												/* Índice de bloco aleatório. */
	} while (blocos[r].pontasAbertas[dirOposta] != true);				/* Repete se o bloco aleatório não possuir uma conexão oposta à saída do bloco anterior. */
	*blocoAtual = r;
	return blocos[r].caracter;											/* Retorna caractere para ser impresso na tela. */
}

int direcaoOposta(int direcaoNormal) 	/* Retorna direção oposta ao parâmetro. */
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
{																				/* Função que verifica se o movimento não invade áreas exploradas, */
	int vX = * x, vY = * y;													/* e atualiza as coordenadas e as registra, caso necessário. */
	bool retorno = true;
	switch(direcaoMovimento)									/* Simula movimento de acordo com a direção. */
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
	
	retorno = novoNaRota(rota, vX, vY);							/* Verifica a posição nas coordenadas armazenadas do caminho. */

	if (retorno == true)										/* Caso sejam novas coordenadas. */
	{
		(*x) = vX;												/* X e Y são atribuídas com estes valores. */
		(*y) = vY;
		(*passoAtual) ++;										/* A variável que controla movimentos é incrementada. */
		rota[*passoAtual][0]= (*x);								/* As coordenadas são registradas. */
		rota[*passoAtual][1]= (*y);
	}
	return retorno;
}

bool dentroDaTela(int x, int y, int direcaoTela)				/* Função que verifica se as coordenadas estão dentro dos limites válidos para o jogo. */
{
	bool retorno = true;

	if (x < MINIMO_X || x > LIMITE_X)
		retorno = false;
	if (y < MINIMO_Y || y > LIMITE_Y)
		retorno = false;

	return retorno;
}

int aleatorio (int *x, int *y)									/* Função que cria coordenadas aleatórias dentro dos limites válidos para o jogo. */
{
	*x = (rand() % (LIMITE_X - MINIMO_X)) + MINIMO_X;
	*y = (rand() % (LIMITE_Y - MINIMO_Y)) + MINIMO_Y;
	return 0;
}

void aparecerItem(int rota[100][2], int x, int y, int * saidaAtual, int * itemAtual) 	/* Função que controla o aparecimento de itens. */
{
	/* Valores para determinar a área em que o item pode aparecer. */
	int itemMinX = ((MINIMO_X + x) / 2) + 15;
	int itemMinY = (MINIMO_Y + y) / 2;
	int itemMaxX = ((LIMITE_X + x) / 2) - 15;
	int itemMaxY = (LIMITE_Y + y) / 2;
	int itemX = 0, itemY = 0;						/* Coordenadas do item. */
	int chanceAparecer;

	if (itemAtual[0] == -1 && itemAtual[1] == -1)	/* Verifica se o item já existe. */
	{
		chanceAparecer = rand() % 100;				/* Gera a probabilidade. */

		if (chanceAparecer < 10)					/* Compara com as Chances. */
		{
			itemX = (rand() % (itemMaxX - itemMinX)) + itemMinX;			/* Atribui coordenadas aleatórias de acordo com a diretrizes. */
			itemY = (rand() % (itemMaxY - itemMinY)) + itemMinY;
	
			if (novoNaRota(rota, itemX, itemY) && (saidaAtual[0] != itemX || saidaAtual[1] != itemY))	/* Verifica se a posição já está ocupada ou */
			{																							/* se existe uma porta ativa na fase. */
				goToXY(itemX, itemY);											/* Move o cursor para a posição determinada para o item. */
        		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);	/* Função que utiliza um manipulado do stdout para alterar as cores da impressão do cursor. */
        		/*	Fundo Preto com a cor da letra brilhante:
        			9 - Azul Es	10 - Verde	11 - Azul Cl	12 - Vermelho	13 - Purpura	14 - Amarelo	15 - Branco        */
        		printf("%c", '\xDC');											/* Imprime o caractere do item na coloração definida acima. */
        		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	/* Restaura a coloração normal do cursor. */
        		itemAtual[0] = itemX;					/* Registra as coordenadas do item. */
        		itemAtual[1] = itemY;
        		goToXY(x, y);							/* Retorna o cursor para a posição do jogador. */
			}
		}
	}
}

void verificaItem(int itemLocal[2], int X, int Y, int * itemBonus, int * pontuacao, int faseAtual)	/* Função que verifica se o jogador se encontrou com um item. */
{
  if (itemLocal[0] == X && itemLocal[1] == Y)
  {
    (*pontuacao) += 10 * faseAtual; 		/* Recebe uma pontuação bonus. */
    (*itemBonus) = 30;						/* Recebe um bônus nas chances de aparecer uma porta para a próxima fase. */
    itemLocal[0] = -1;						/* Limpa o registro do item. */
    itemLocal[1] = -1;
  }
}

bool novoNaRota(int rota[100][2], int x, int y)	/* Função que verifica a posição nas coordenadas armazenadas do caminho. */
{
	int i;
	bool resultado = true;
	for (i = 0; i < 100; i++)
	{
  		if ((rota[i][0] == x) && (rota[i][1] == y))
  		{
    		resultado = false;
  		}
	}
	return resultado;
}

void aparecerSaida(int rota[100][2], int pontasAtuais[4], int X, int Y, int passoAtual, int localSaida[2], int itemLocal[2], int itemBonus, int nivelSaida)
{													/* Função que verifica as chances e, quando possível, imprime a porta de saída para próxima fase. */
  int chancesSaidaAparecer, direcao, x, y;
  bool direcaoVazia;
  chancesSaidaAparecer = rand() % 100;				/* Gera aleatoriedade. */
  if (chancesSaidaAparecer < ((passoAtual / 2) - (nivelSaida * 5) + itemBonus))	/* Compara aleatoriedade com chances (formada por passos e modificada por  */
  {																				/* fase e pelo bônus de obter um item na fase). */
    for (direcao = 0; direcao < 4; direcao++)			/* Roda as direções e verifica se o bloco possui uma direção para encaixa a porta.  */
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
        direcaoVazia = novoNaRota(rota, x, y);
        if (itemLocal[0] == x && itemLocal[1] == y)
        {
        	direcaoVazia = false;
        }
      }
      else
      {
        continue;
      }
      if (direcaoVazia)						/* Se tiver uma posição adequada para a porta. */
      {
        goToXY(x,y);						/* Move o cursor para a posição em que a porta será impressa. */
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  	/* Função que utiliza um manipulado do stdout para alterar as cores da impressão do cursor. */
        /*	Fundo Preto com a cor da letra brilhante:
        	9 - Azul Es	10 - Verde	11 - Azul Cl	12 - Vermelho	13 - Purpura	14 - Amarelo	15 - Branco        */
        printf("%c", '\xDB');											/* Imprime o caractere que representa a porta. */
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	/* Restaura a coloração normal do cursor. */
        localSaida[0] = x;				/* Registra a porta de saida. */
        localSaida[1] = y;
        goToXY(X, Y);					/* Retorna o cursor para a posição do jogador. */
        break;							/* Interrompe loop de direções.*/
      }
    }
  }
}

void verificaFase(char * estadoFase, int portaFase[2], int X, int Y)	/* Função que verifica se o jogador se encontrou com a porta de mudança de fase. */
{
  if (portaFase[0] == X && portaFase[1] == Y)
  {
    (*estadoFase) = MUDAFASE;
    
  }
}

void limparPortas(int saida[2], int x, int y)			/* Função que remove portas de mudança de fase não utilizadas. */
{
	if ((saida[0] != -1) && (saida[1] != -1))
	{
	  goToXY(saida[0], saida[1]);
	  printf(" ");
	  goToXY(x, y);
	  saida[0] = -1;
	  saida[1] = -1;
	}
}

void atualizaPontuacao(int x, int y, int pontuacaoAtual) /* Função que altera a pontuação exibida na tela de jogo. */
{
	int xPlacar = 81, yPlacar = 1;			/* Coordenadas do placar na tela de jogo. */
	goToXY(xPlacar, yPlacar);				/* Move o cursor para a posição do placar. */
	printf("%05i", pontuacaoAtual);			/* Altera o placar. */
	goToXY(x, y);							/* Retorna o cursor para a posição do jogador. */
}