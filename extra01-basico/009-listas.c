#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

/* Exercício com o objetivo de recordar e aprimorar os conhecimentos sobre a criação de listas na linguagem C */

#define ccedil '\x87' /* ç */
#define atilde '\xC6' /* ã */
#define oacute '\xA2' /* ó */
#define otilde '\xE4' /* õ */
#define eacute '\x82' /* é */
#define uacute '\xA3' /* ú */
#define iacute '\xA1' /* í */

typedef struct reg
{
	struct reg * ante;
	char nome[30];
	char cidade[20];
	char fone[15];
	struct reg * prox;
} elemento;

void navegar(elemento *);
void cadastrar (elemento *);
void inserir(char *, char *, char *, elemento *);
void imprimir(elemento *);

int main()
{
	elemento *lista;
	char tecla;
	lista = malloc(sizeof(elemento));
	lista->ante = NULL;
	lista->prox = NULL;
	printf("-----------------------------------------\n\n");
	printf("CADASTRO DE ASSOCIADOS: \n\n");
	printf("-----------------------------------------\n\n");
	printf("Efetue seu cadastro inicial! \n\n");
	printf("-----------------------------------------\n\n");
	getch();
	printf("Nome: ");
	fgets(lista->nome, sizeof(lista->nome), stdin);
	printf("Cidade: ");
	fgets(lista->cidade, sizeof(lista->cidade), stdin);
	printf("Telefone: ");
	fgets(lista->fone, sizeof(lista->fone), stdin);

	printf("\nCadastro efetuado com sucesso!\n");
	getch();
	do {
		system("cls");
		printf("-----------------------------------------\n\n");
		printf("CADASTRO DE ASSOCIADOS: \n\n");
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
		}

	} while (tecla != '4');

	
	
	return 0;
}

void cadastrar(elemento * lista)
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
		fgets(nomedigitado, sizeof(nomedigitado), stdin);
		printf("Cidade: ");
		fgets(cidadedigitada, sizeof(cidadedigitada), stdin);
		printf("Telefone: ");
		fgets(telefonedigitado, sizeof(telefonedigitado), stdin);
		inserir(nomedigitado, cidadedigitada, telefonedigitado, lista);
		printf("\nCadastro efetuado com sucesso!\n");
		printf("Mais cadastros? (N%co = n)", '\xC6');
		tecla = toupper(getche());
	} while (tecla != 'N');
/*  
	printf("\n\nNomes listados:\n");
	imprimirNomes(lista);
	*/
}

void inserir(char * nome, char * cidade, char * fone, elemento * lista)
{
	elemento *novo;
	novo = malloc(sizeof(elemento));
	strcpy(novo->nome,nome);
	strcpy(novo->cidade,cidade);
	strcpy(novo->fone,fone);
	novo->prox = NULL;
	do 
	{	
		if (lista->prox != NULL)
			lista = lista->prox;
	} while (lista->prox != NULL);
	lista->prox = novo;
	novo->ante = lista;
}

void imprimir(elemento * lista)
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
	do {
		printf("Nome: %s Cidade: %s Telefone: %s\n\n", listaImprimir->nome, listaImprimir->cidade, listaImprimir->fone);
		listaImprimir = listaImprimir->prox;
	}
	while (listaImprimir !=NULL);
	getch();
}

void navegar(elemento * lista)
{
	char tecla, teclaDel;
	elemento *listaNavegar;
	elemento *aux1, *aux2;
	aux1 = malloc(sizeof(elemento));
	aux2 = malloc(sizeof(elemento));
	listaNavegar = malloc(sizeof(elemento));
	listaNavegar = lista;
	do 
	{
		system("cls");
		printf("-----------------------------------------\n\n");
		printf("CADASTRO DE ASSOCIADOS: \n\n");
		printf("-----------------------------------------\n\n");
		printf("Associados cadastrados. \n\n");
		printf("-----------------------------------------\n\n");
		printf("Nome: %s \nCidade: %s \nTelefone: %s\n\n", listaNavegar->nome, listaNavegar->cidade, listaNavegar->fone);
		printf(" (a) Anterior | (p) Pr%cximo | (m) Modificar | (d) Deletar | (s) Sair ", oacute);
		tecla = toupper(getch());
		printf("\n");
		switch(tecla)
		{
			case ('A'):
				if (listaNavegar->ante != NULL)
				{
					listaNavegar = listaNavegar->ante;
				}
				else
				{
					printf("Este %c o primeiro registro de associados.", eacute);
				}
			break;
			case ('P'):
				if (listaNavegar->prox != NULL)
				{
					listaNavegar = listaNavegar->prox;
				}
				else
				{
					printf("Este %c o %cltimo registro de associados.", eacute, uacute);
				}
			break;
			case ('M'):
				printf("\nNome: ");
				fgets(listaNavegar->nome, sizeof(listaNavegar->nome), stdin);
				printf("Cidade: ");
				fgets(listaNavegar->cidade, sizeof(listaNavegar->cidade), stdin);
				printf("Telefone: ");
				fgets(listaNavegar->fone, sizeof(listaNavegar->fone), stdin);
				printf("\nModifica%c%co efetuada com sucesso!\n", ccedil, atilde);
				getch();
			break;
			case ('D'):
				printf("\nRealmente deseja excluir este registro? A exclus%co %c irrevers%cvel! (Sim = s)", atilde, eacute, iacute);
				teclaDel = toupper(getche());
				if (teclaDel == 'S')
				{
					if (listaNavegar->ante != NULL)
					{
						aux1 = listaNavegar->ante;
					} 
					if (listaNavegar->prox != NULL)
					{
						aux2 = listaNavegar->prox;
					} 
					aux1->prox = aux2;
					aux2->ante = aux1;
					listaNavegar = aux1;
				}
				printf("\nExclus%co efetuada com sucesso!\n", atilde);
				getch();
			break;
			case ('S'):
		
			break;
		}
		
	} while (tecla != 'S');
}