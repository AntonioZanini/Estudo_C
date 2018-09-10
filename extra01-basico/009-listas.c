#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

/* Programa: CADASTRO DE ASSOCIADOS */
/* Descrição: */
/* Exercício com o objetivo de recordar e aprimorar os conhecimentos sobre a criação de listas na linguagem C.  */
/* Em sua execução, este programa registra dados de pessoas na memória e permite navegação entre registros,     */
/* alteração, exclusão e geração de relatório. */

							/* Constantes de apresentação de caracteres especiais. */
#define ccedil '\x87' /* ç */
#define atilde '\xC6' /* ã */
#define oacute '\xA2' /* ó */
#define otilde '\xE4' /* õ */
#define eacute '\x82' /* é */
#define uacute '\xA3' /* ú */
#define iacute '\xA1' /* í */
#define aacute '\xA0' /* á */

typedef struct reg 			/* Definição de um struct para os elementos da lista e a criação de alias para sua utilização como um tipo. */
{
	struct reg * ante;
	char nome[30];
	char cidade[20];
	char fone[15];
	struct reg * prox;
} elemento;
							/* Protótipos das funções. */
int contar(elemento *);
void navegar(elemento *);
void cadastrar (elemento *);
void inserir(char *, char *, char *, elemento *);
void imprimir(elemento *);

int main()					/* Função principal que configura os dados básicos da lista e apresenta as opções no menu principal.*/
{
	elemento *lista;		/* declara um ponteiro para o tipo elemento, o primeiro nó da lista. */
	char tecla;
	char nomedigitado[30], telefonedigitado[15], cidadedigitada[20];
	lista = malloc(sizeof(elemento));		/* a função malloc() realiza a alocação de memória para o ponteiro retornando um endereço*/
	lista->ante = NULL;						/* de memória que possua uma quantidade de bytes consecutivos disponíveis definidos    */
	lista->prox = NULL;						/* pelo operador sizeof. */
	printf("-----------------------------------------\n\n");
	printf("CADASTRO DE ASSOCIADOS: \n\n");
	printf("-----------------------------------------\n\n");

							/* Atribui registros pré-cadastrados */
	strcpy(lista->nome, "Roberto Ribeiro");
	strcpy(lista->cidade, "Araras-SP");
	strcpy(lista->fone, "4651-5481");
	strcpy(nomedigitado, "Isis Fontana");
	strcpy(cidadedigitada, "Santos-SP");
	strcpy(telefonedigitado, "4125-9666");
	inserir(nomedigitado, cidadedigitada, telefonedigitado, lista);
	strcpy(nomedigitado, "Jorge Wilson");
	strcpy(cidadedigitada, "Sorocaba-SP");
	strcpy(telefonedigitado, "6951-6442");
	inserir(nomedigitado, cidadedigitada, telefonedigitado, lista);
	strcpy(nomedigitado, "Marcos Marinho");
	strcpy(cidadedigitada, "Osasco-SP");
	strcpy(telefonedigitado, "7511-8831");
	inserir(nomedigitado, cidadedigitada, telefonedigitado, lista);
	/* Cadastro obrigatório do primeiro registro.
	printf("Efetue seu cadastro inicial! \n\n");
	printf("-----------------------------------------\n\n");
	
	printf("Nome: ");
	fgets(lista->nome, sizeof(lista->nome), stdin);
	printf("Cidade: ");
	fgets(lista->cidade, sizeof(lista->cidade), stdin);
	printf("Telefone: ");
	fgets(lista->fone, sizeof(lista->fone), stdin);

	printf("\nCadastro efetuado com sucesso!\n");
	getch();
	*/
	do {
		system("cls");
		printf("-----------------------------------------\n\n");
		printf("CADASTRO DE ASSOCIADOS: \n\n");
		printf("-----------------------------------------\n\n");
		printf(" %i  Associados cadastrados. \n\n", contar(lista));
		printf("-----------------------------------------\n\n");
		printf("Selecione a op%c%co desejada: \n\n", ccedil, atilde);
		printf("1 - Cadastrar novos associados. \n");
		printf("2 - Navegar pelos associados. \n");
		printf("3 - Gerar relat%crio de associados. \n", oacute);
		printf("4 - Sair. \n\n");
		printf("Selecionar: ");
		tecla = getche();

		switch(tecla)
		{
			case ('1'):
				cadastrar(lista);
			break;
			case ('2'):
				navegar(lista);
			break;
			case ('3'):
				imprimir(lista);
			break;
			case ('4'):
			break;
			default:
				printf("\nOp%c%co n%co reconhecida, tente novamente.", ccedil, atilde, atilde);
				getch();
		}

	} while (tecla != '4');	
	return 0;
}

void cadastrar(elemento * lista)			/* Função responsável por receber o cadastro dos associados. */
{
	char tecla, nomedigitado[30], telefonedigitado[15], cidadedigitada[20];
	do 
	{
		system("cls");
		printf("-----------------------------------------\n\n");
		printf("CADASTRO DE ASSOCIADOS: \n\n");
		printf("-----------------------------------------\n\n");
		printf("Preencha as informa%c%ces cadastrais. \n\n", ccedil, otilde);
		printf("-----------------------------------------\n\n");
		printf("Nome: ");
		scanf("%[^\n]%*c", &nomedigitado);
		printf("Cidade: ");
		scanf("%[^\n]%*c", &cidadedigitada);
		printf("Telefone: ");
		scanf("%[^\n]%*c", &telefonedigitado);
		inserir(nomedigitado, cidadedigitada, telefonedigitado, lista);		/* chama função que insere os dados coletados em um */
		printf("\nCadastro efetuado com sucesso!\n");						/* novo nó da lista. */
		printf("Mais cadastros? (N%co = n)", '\xC6');
		tecla = toupper(getche());
	} while (tecla != 'N');
}

void inserir(char * nome, char * cidade, char * fone, elemento * lista)		/* Função responsável por criar um novo nó na lista com  */
{																			/* os dados recebidos. */
	elemento *novo;							/* Cria novo elemento. */
	novo = malloc(sizeof(elemento));		/* Aloca espaço na memória para sua utilização. */
	strcpy(novo->nome,nome);				/* Função que copia os valores string dos parametros para as variáveis do novo elemento. */
	strcpy(novo->cidade,cidade);
	strcpy(novo->fone,fone);
	novo->prox = NULL;
	do 										/* Verifica lista pelo seu último nó. */
	{	
		if (lista->prox != NULL)
			lista = lista->prox;
	} while (lista->prox != NULL);
	lista->prox = novo;						/* Adiciona o novo nó após o ultimo nó da lista. */
	novo->ante = lista;
}

void imprimir(elemento * lista)				/* Função que exibe todos os elementos em forma de relatório na tela. */
{
	elemento *listaImprimir;
	listaImprimir = malloc(sizeof(elemento));
	listaImprimir = lista;
	system("cls");
	printf("-----------------------------------------\n\n");
	printf("CADASTRO DE ASSOCIADOS: \n\n");
	printf("-----------------------------------------\n\n");
	printf("Relat%crio de associados. \n\n", oacute);
	printf("-----------------------------------------\n\n");
		printf("  %-30s %-20s %-15s\n", "Nome:", "Cidade:", "Telefone:");	
		printf("-----------------------------------------------------------------\n");
	do {			/* Formatação que exibe as strings deixando o excedente do espaço reservado como espaços em branco à direita. */
		printf("  %-30s %-20s %-15s\n", listaImprimir->nome, listaImprimir->cidade, listaImprimir->fone);
		listaImprimir = listaImprimir->prox;
	}
	while (listaImprimir !=NULL);
	getch();
}

void navegar(elemento * lista)		/* Função que gera uma navegação entre os registros, permitindo alterações e exclusões. */
{
	char tecla, teclaDel;
	elemento *listaNavegar;
	elemento *aux1, *aux2;			/* Variáveis auxiliares. */
	aux1 = malloc(sizeof(elemento));
	aux2 = malloc(sizeof(elemento));
	listaNavegar = malloc(sizeof(elemento));
	listaNavegar = lista;
	do 
	{
		system("cls");
		printf("-----------------------------------------\n\n");
		printf(" CADASTRO DE ASSOCIADOS: \n\n");
		printf("-----------------------------------------\n\n");
		printf(" Navega%c%co pelos associados: \n\n", ccedil, atilde);
		printf("-----------------------------------------\n\n");
		printf(" %i  Associados cadastrados. \n\n", contar(lista));
		printf("-----------------------------------------\n\n");
		printf("Nome: %s \nCidade: %s \nTelefone: %s\n\n", listaNavegar->nome, listaNavegar->cidade, listaNavegar->fone);
		printf(" (a) Anterior | (p) Pr%cximo | (m) Modificar | (d) Deletar | (s) Sair ", oacute);
		tecla = toupper(getch());
		printf("\n");
		switch(tecla)
		{
			case ('A'):									/* Move para o nó anterior. */
				if (listaNavegar->ante != NULL)
				{
					listaNavegar = listaNavegar->ante;
				}
				else
				{
					printf("Este %c o primeiro registro de associados.", eacute);
					getch();
				}
			break;
			case ('P'):									/* Move para o nó posterior. */
				if (listaNavegar->prox != NULL)
				{
					listaNavegar = listaNavegar->prox;
				}
				else
				{
					printf("Este %c o %cltimo registro de associados.", eacute, uacute);
					getch();
				}
			break;
			case ('M'):									/* Altera os valores das variáveis do registro. */
				printf("\nNome: ");
				scanf("%[^\n]%*c", listaNavegar->nome);
				printf("Cidade: ");
				scanf("%[^\n]%*c", listaNavegar->cidade);
				printf("Telefone: ");
				scanf("%[^\n]%*c", listaNavegar->fone);
				printf("\nModifica%c%co efetuada com sucesso!\n", ccedil, atilde);
				getch();
			break;
			case ('D'):									/* Deleta registro. */
				printf("\nRealmente deseja excluir este registro? A exclus%co %c irrevers%cvel! (Sim = s)", atilde, eacute, iacute);
				teclaDel = toupper(getche());
				if (teclaDel == 'S')
				{
					if (listaNavegar->ante == NULL && listaNavegar->prox == NULL)	/* Se for o único registro na lista. */
					{
						printf("\nApenas um registro, acesso negado!");
					}
					else
					{
						if (listaNavegar->ante == NULL)								/* Se for o primeiro registro na lista. */
						{

							aux1 = listaNavegar->prox;
							strcpy(listaNavegar->nome, aux1->nome);
							strcpy(listaNavegar->cidade, aux1->cidade);
							strcpy(listaNavegar->fone, aux1->fone);
							if (aux1->prox != NULL)									/* Se houver dois ou mais registros além do deletado. */
							{
								aux2 = aux1->prox;
								listaNavegar->prox = aux2;
								aux2->ante = listaNavegar;
							}
							else 													/* Se houver apenas um registro além do deletado.*/
							{
								listaNavegar->prox = NULL;
							}
						}
						else
						{
							if (listaNavegar->prox == NULL)							/* Se for o último registro na lista. */
							{
								aux1 = listaNavegar->ante;
								aux1->prox = NULL;
								listaNavegar = aux1;
							}
							else 													/* Se for um registro entre dois registros. */
							{
								aux1 = listaNavegar->ante;
								aux2 = listaNavegar->prox;
								aux1->prox = aux2;
								aux2->ante = aux1;
								listaNavegar = aux1;
							}
						}
						printf("\nExclus%co efetuada com sucesso!\n", atilde);
					}
					
					getch();
				}

				
			break;
			case ('S'):
		
			break;
		}
		
	} while (tecla != 'S');
}

int contar(elemento * lista)			/* Função que retorna o número de nós na lista. */
{
	int contador = 0;
	elemento * listaContar;
	listaContar = malloc(sizeof(elemento));
	listaContar = lista;
	do
	 {
	 	contador ++;
	 	listaContar = listaContar->prox;
	 } while (listaContar != NULL); 
	 return contador;
}