#include <stdio.h>
#include <limits.h>		/* Biblioteca que concede acesso aos valores que definem as capacidades mínimas e máximas de armazenamento dos tipos char, short, int e long.*/
#include <float.h>		/* Biblioteca que concede acesso, entres outras coisas, aos valores que definem as capacidades mínimas e máximas de armazenamento dos tipos float, double e long double.*/

int main()
{
	/* Variáveis declaradas com o único propósito de utilizar a função sizeof(), de forma a acessar o espaço que ocupa em memória. */
	char caracter;
	short inteiroCurto;
	int inteiroNormal;
	long inteiroLongo;
	float pontoFlutuante;
	double duplo;
	long double duploLongo;

	printf("<<<<<<<<<<CHAR>>>>>>>>>>\n");										/* Dados do tipo char. */
	printf("char\n");
	printf("Tamanho: %i bytes.\n", sizeof(caracter));
	printf("Minimo: %i, Maximo: %i.\n", CHAR_MIN, CHAR_MAX);					/* CHAR_MIN contém o valor mínimo de char. CHAR_MAX contém o valor máximo de char. */
	printf("Limites char nao-assinalado: 0-%u.\n", UCHAR_MAX);					/* UCHAR_MAX contém o valor máximo de unsigned char. */

	printf("\n<<<<<<<<<<INTEIRO>>>>>>>>>>\n");									/* Dados dos tipos inteiros. */
	printf("short\n");
	printf("Tamanho: %i bytes.\n", sizeof(inteiroCurto));
	printf("Minimo: %i, Maximo: %i.\n", SHRT_MIN, SHRT_MAX);					/* SHRT_MIN contém o valor mínimo de short. SHRT_MAX contém o valor máximo de short. */
	printf("Limites short nao-assinalado: 0-%u.\n", USHRT_MAX);					/* USHRT_MAX contém o valor máximo de unsigned short. */

	printf("\nint\n");
	printf("Tamanho: %i bytes.\n", sizeof(inteiroNormal));
	printf("Minimo: %i, Maximo: %i.\n", INT_MIN, INT_MAX);						/* INT_MIN contém o valor mínimo de int. INT_MAX contém o valor máximo de int. */
	printf("Limites inteiro nao-assinalado: 0-%u.\n", UINT_MAX);				/* UINT_MAX contém o valor máximo de unsigned int. */

	printf("\nlong\n");
	printf("Tamanho: %i bytes.\n", sizeof(inteiroLongo));
	printf("Minimo: %i, Maximo: %i.\n", LONG_MIN, LONG_MAX);					/* LONG_MIN contém o valor mínimo de long. LONG_MAX contém o valor máximo de long. */
	printf("Limites inteiro longo nao-assinalado: 0-%u.\n", ULONG_MAX);			/* ULONG_MAX contém o valor máximo de unsigned long. */

	printf("\n<<<<<<<<<<PONTO FLUTUANTE>>>>>>>>>>\n");							/* Dados dos tipos ponto flutuantes */
	printf("float\n");															/* Pontos Flutuante não possuem versões não-assinaladas. */
	printf("Tamanho: %i bytes.\n", sizeof(pontoFlutuante));
	printf("Minimo: %f, Maximo: %f.\n", -FLT_MAX, FLT_MAX);						/* -FLT_MAX contém o valor mínimo de float. FLT_MAX contém o valor máximo de float. */

	printf("\ndouble\n");
	printf("Tamanho: %i bytes.\n", sizeof(duplo));								/* -DBL_MAX contém o valor mínimo de double. DBL_MAX contém o valor máximo de double. */
	printf("Minimo: %e, Maximo: %e.\n", -DBL_MAX, DBL_MAX);						/* %e é um marcador para exibição em notação exponencial de um parâmetro ponto flutuante.  */

	printf("\nlong double\n");
	printf("Tamanho: %i bytes.\n", sizeof(duploLongo));
	printf("Minimo: %e, Maximo: %e.\n", -LDBL_MAX, LDBL_MAX);					/* -LDBL_MAX contém o valor mínimo de long double. LDBL_MAX contém o valor máximo de long double. */

	printf("Pressione qualquer tecla para finalizar . . .\a");					/* \a Aplica um aviso sonoro próprio do S.O. como um breve alerta, atual utilização puramente estética. */
	getchar();

	return 0;
}