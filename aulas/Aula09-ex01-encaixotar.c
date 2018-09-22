#include <stdio.h>

int main()
{
	int max_lata_cx;
	int cont_caixa = 0;
	int qtd_caixas;
	int num_latas_cx;
	int num_latas_lido;
	int x;
	char marca[12];
	char data[10];

	printf(" DIGITE A DATA: ");
	scanf("%s", data);
	printf(" DIGITE A MARCA: ");
	scanf("%s", marca);
	printf(" DIGITE A QUANTIDADE DE LATAS POR CAIXA: ");
	scanf("%i", &max_lata_cx);
	printf(" INSIRA A QUANTIDADE DE CAIXAS: ");
	scanf("%i", &qtd_caixas);

	do
	{
		num_latas_cx = 0;
		do
		{
			printf(" INSIRA A QUANTIDADE DE LATAS");
			scanf("%i", &num_latas_lido);
			num_latas_cx += num_latas_lido;
			if (num_latas_cx < max_lata_cx)
				printf("\n FALTAM %i LATAS PARA FECHAR A CAIXA!\n", (max_lata_cx - num_latas_cx) );
			else if (num_latas_cx == max_lata_cx)
				printf("\n CAIXA FECHADA!\n");
			else {
				printf("\n CAIXA FECHADA! SOBRARAM %i!\n", (num_latas_cx - (max_lata_cx * (num_latas_cx /  max_lata_cx))));
				cont_caixa += (num_latas_cx /  max_lata_cx) -1;
			}

		} while (num_latas_cx < max_lata_cx);
		cont_caixa++;
		printf("\n CAIXAS EMBALADAS: %i\n", cont_caixa );
	} while (cont_caixa < qtd_caixas);
	printf("\n\n TOTAL DE CAIXAS DE LATAS EMBALADAS EM %s: %i\n", data, cont_caixa );
	return 0;
}
