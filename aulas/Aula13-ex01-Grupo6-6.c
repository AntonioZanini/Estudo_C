#include <stdio.h>

#define NUM_LINHAS 		5
#define NUM_COLUNAS 	3

#define ORDINAL_MASC	'\xA7' 	/* º */
#define ORDINAL_FEM		'\xA6' 	/* ª */
#define U_MI_AGUDO 		'\xA3' 	/* ú */
#define E_MI_AGUDO		'\x82' 	/* é */
#define C_MI_CEDILHA 	'\x87'	/* ç */

int main(int argc, char const *argv[])
{
	float valores[NUM_LINHAS][NUM_COLUNAS];
	float somatoria = 0.0f;
	float media_colunas_pares;
	float media_linhas_impares = 0;
	int x, y;

	for (x = 0; x < NUM_LINHAS; x++){
		printf(" Insira os 3 n%cmeros da %i%c linha (ex: '0 0 0'): ",  U_MI_AGUDO, x+1, ORDINAL_FEM );
		scanf("%f %f %f", &valores[x][0], &valores[x][1], &valores[x][2]);
	}
	for (y = 1; y < NUM_COLUNAS; y += 2) {
		for (x = 0; x < NUM_LINHAS; x++){
			somatoria += valores[x][y];
		}
	}
	media_colunas_pares = somatoria / (float)NUM_LINHAS;
	somatoria = 0;
	for (x = 0; x < NUM_LINHAS; x += 2){
		for (y = 0; y < NUM_COLUNAS; y++)
		{
			somatoria += valores[x][y];
		}
		media_linhas_impares += (somatoria / (float)NUM_COLUNAS);
		somatoria = 0;
	}
	media_linhas_impares = media_linhas_impares / 3.0f; 
	printf(" \n\n M%cdia das colunas PARES: %.2f\n", E_MI_AGUDO, media_colunas_pares);
	printf(" M%cdia das linhas IMPARES: %.2f\n\n", E_MI_AGUDO, media_linhas_impares);
	printf(" Diferen%ca entre as m%cdias: %.2f\n\n", C_MI_CEDILHA, E_MI_AGUDO, media_colunas_pares - media_linhas_impares);

	return 0;
}
