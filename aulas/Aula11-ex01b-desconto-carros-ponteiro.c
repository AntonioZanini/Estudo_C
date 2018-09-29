#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define U_MI_AGUDO 	'\xA3' 	/* ú */
#define E_MI_CIRC 	'\x88' 	/* ê */
#define A_MI_TIL 	'\xC6' 	/* ã */
#define CIFRAO 		'\x24' 	/* $ */

int main(int argc, char const *argv[])
{
	int 	num_carros;
	int		*carros_selecionados;
	float 	desconto;
	float	preco_carro = 70000.0f;
	bool	compra;
	do {
		compra = true;
		printf("\n Insira o n%cmero de carros a ser comprados: ", U_MI_AGUDO);
		scanf("%d", &num_carros);
		carros_selecionados = &num_carros;
		switch (*carros_selecionados) {
			case 0:
				printf("\n Olhe mais uma vez nossos carros!\n");
				compra = false;
				break;
			case 1:
				printf("\n Escolha mais um carro para ter um desconto!\n");
				desconto = 0;
				break;
			case 2:
				printf("\n Dois carros! Receba 15%% de desconto!\n");
				desconto = 15;
				break;
			case 3:
				printf("\n Tr%cs carros! Receba 20%% de desconto!\n", E_MI_CIRC);
				desconto = 20;
				break;
			case 4:
				printf("\n Quatro carros! Receba 25%% de desconto, ou seja, UM CARRO GRATUITO!\n");
				desconto = 25;
				break;
			default:
				printf("\n N%co trabalhamos com esta quantidade de carros!\n", A_MI_TIL);
				compra = false;
				break;
		}
	
		if (compra) {
			printf("\n Valor total a ser pago: R%c %.2f.\n", CIFRAO, num_carros * preco_carro * (1 - desconto / 100) );
			printf("\n Endereco: %x.\n", carros_selecionados);
		}
	} while (-1 != num_carros);
	return 0;
}