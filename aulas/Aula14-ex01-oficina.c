#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

enum servicos {ALINHAMENTO, BALANCEAMENTO, TROCA_OLEO, FILTRO_OLEO, FILTRO_COMBUS};

bool verificar_servico_executado(int *servicos_executados, int servico);

int main(int argc, char const *argv[])
{
	float precos_servicos[5] = {55.50, 60.99, 65.20, 75.10, 80.30};
	int servicos_executados[5] = {-1, -1, -1, -1, -1};
	int num_servico = 0;
	float preco_pedido = 0;
	int servico;
	char opcao;
	do {
	system("cls");
	printf("-------------------------------------------\n\n");
	printf("              Selecione o Servico:         \n\n");
	printf("-------------------------------------------\n\n");
	printf("  1 - Alinhamento\n\n");
	printf("  2 - Balanceamento\n\n");
	printf("  3 - Troca de Oleo\n\n");
	printf("  4 - Troca de Filtro de Oleo\n\n");
	printf("  5 - Troca de Filtro de Combustivel\n\n");
	printf("  0 - Concluir Pedido.\n\n");
	printf("-------------------------------------------\n\n");
	printf("  Opcao: ");
	scanf("%i", &servico);
	if (servico != 0) {
		
		if(verificar_servico_executado(servicos_executados, (servico -1)) == false) {
			if (ALINHAMENTO == (servico -1) || BALANCEAMENTO == (servico -1)) {
				preco_pedido += precos_servicos[ALINHAMENTO];
				preco_pedido += precos_servicos[BALANCEAMENTO];
				servicos_executados[num_servico] = ALINHAMENTO;
				num_servico++;
				servicos_executados[num_servico] = BALANCEAMENTO;
			}
			else if (TROCA_OLEO == (servico -1) || FILTRO_OLEO == (servico -1)) {
				preco_pedido += precos_servicos[FILTRO_OLEO];
				preco_pedido += precos_servicos[TROCA_OLEO];
				servicos_executados[num_servico] = TROCA_OLEO;
				num_servico++;
				servicos_executados[num_servico] = FILTRO_OLEO;
			}
			else {
				preco_pedido += precos_servicos[(servico -1)];
				servicos_executados[num_servico] = (servico -1);
			}
			num_servico++;
			printf("\n\n  Servico Executado!\n");
		}
		else
			printf("\n\n  Servico ja Executado! Por favor, escolha uma outra opcao.\n");
		getch();
	}
	else
		printf("  Valor total do Pedido: R$ %.2f.\n", preco_pedido );
	} while (servico != 0);
	getch();
	return 0;
}

bool verificar_servico_executado(int *servicos_executados, int servico)
{
	int i;
	bool encontrado = false;
	for (i = 0; i < 5; i++)
	{
		if (servicos_executados[i] == servico){
			encontrado = true;
		}
	}
	return encontrado;
}
