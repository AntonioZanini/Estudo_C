#Conteúdo Aulas - Linguagem C - UNITEN/ANHANGUERA - SOROCABA

##AULA 1 - 27/08/2018

- Explicação sobre Algoritmos e Fluxograma.

##AULA 2 - 29/08/2018

- Breve descrição da história da linguagem C.

###Tipos de Variáveis:

- números inteiros	→ int
- ponto flutuante 	→ float, double
- caracteres		→ char

###Comandos:

- #include			→ Inclusão de biblioteca.
- stdio.h 			→ Biblioteca de tratamento de entrada e saída de dados.
- stdlib.h			→ Biblioteca com funções de cálculo.
- printf			→ Função de impressão.
- ""				→ Delimitador de texto.
- \n				→ Marcador de quebra de texto.
- for				→ Estrutura Repetitiva: for(variável = [início]; variável [limite lógico]; incremento ou decremento){}.
- scanf				→ Captura de texto do teclado: scanf(tipo de dado, &variável).
- while				→ Estrutura Repetitiva: while (condição lógica){}.
- ||				→ Modificador lógico OU.
- switch			→ Estrura Condicional: switch (variável) { case (caso1): [código]; break; case (caso2): [código]; break;}.
- system("pause")	→ Pausa da tela.

###Código:

	#include <stdio.h>
	int main()
	{
		printf("Ola aluno.");
		system("PAUSE");
		return 0;
	}
