# Linguagem C - UNITEN/ANHANGUERA - SOROCABA

## AULA 1 - 27/08/2018

- Explicação sobre Algoritmos e Fluxograma.

## AULA 2 - 29/08/2018

- Breve descrição da história da linguagem C.

### Tipos de Variáveis:

- Números inteiros	→ int
- Ponto flutuante 	→ float, double
- Caracteres		→ char

### Comandos:

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

### Código:

	#include <stdio.h>
	int main()
	{
		printf("Ola aluno.");
		system("PAUSE");
		return 0;
	}

## AULA 3 - 31/08/2018

### Algol. Cadastro em C

	Inicio
		var: nome (char), endereço (char), CPF (int), telefone (int), email, nascimento;
		escreva "Nome: ";
		ler nome;
		escreva "Endereço: ";
		ler endereço;
		escreva "Nascimento: ";
		ler nascimento;
		...

		escreva nome;
		escreva endereço;
		...

		escreva "Sucesso";
	Fim

### Código

	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>

	#define cedilm '\x87' /* constante para o código char do caractere 'ç' */

	int main()
	{
		char nome[20], endereco[30], email[25], nascimento[10];
		int cpf, telefone;

		printf("============================");
		printf("\nInsira seus dados cadastrais");
		printf("\n============================");
		printf("\nNome: ");
		scanf("%[^\n]%*c", &nome);			/* Mascara para suprimir a divisão de entrada através do espaço*/
		printf("Endere%co: ", cedilm);
		scanf("%[^\n]%*c", &endereco);
		printf("CPF: ");
		scanf("%i", &cpf);
		printf("Data de Nascimento: ");
		scanf("%s", &nascimento);
		printf("Telefone: ");
		scanf("%i", &telefone);
		printf("Email: ");
		scanf("%s", &email);

		printf("\n\n============================");
		printf("\nConfira seus Dados");
		printf("\n============================");
		printf("\nNome: %s", nome);
		printf("\nEndere%co: %s", cedilm, endereco);
		printf("\nCPF: %d", cpf);
		printf("\nData de Nascimento: %s", nascimento);
		printf("\nTelefone: %d", telefone);
		printf("\nEmail: %s\n\n", email);

		printf("Cadastro preenchido corretamente? ");
		getch();
	}
