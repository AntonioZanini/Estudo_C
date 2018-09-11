# Linguagem C - UNITEN/ANHANGUERA - SOROCABA

## AULA 1 - 27/08/2018 (Prof. Luís)

- Explicação sobre Algoritmos e Fluxograma.

## AULA 2 - 29/08/2018 (Prof. Luís)

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

## AULA 3 - 31/08/2018 (Prof. Luís)

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

### AULA 4 - 10/09/2018 (Prof. Stark)

### Definições:

#### Variáveis

- Local na memória principal. Ex: n1, n2.
- Variáveis **não podem** começar com dígitos. Ex errado: 2w.
- Variáveis **não podem** ter espaços. Ex errado: peso do aluno.
- Variáveis **não podem** ter caracteres especiais (que sejam operadores). Ex errado: sala/aula, f-e.
- Dica **variáveis** → minúscula.
- 	   **Constantes** → Maiúscula.

### Comandos:

- math.h 		Biblioteca de operações matemáticas.
- If 			Estrutura Condicional.
- For 			Laço Repetitivo.
- While 		Laço Repetitivo.
- =				Operador de atribuição.
- ==			Operador de comparação.

### Código:

**Exemplo 1**

	#include <stdio.h>
	main ()
	{
		int n1, n2;
		printf("Introduza o primeiro inteiro\n");
		scanf("%d", &n1);
		printf("Introduza o segundo inteiro\n");
		scanf("%d", &n2);
		if (n1 == n2)
			printf("%d igual a %d\n", n1, n2 );
		if (n1 < n2)
			printf("%d maior do que a %d\n", n2, n1);
		else
			printf("%d maior do que a %d\n", n1, n2);
	}

**Exemplo 2**

	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	main ()
	{
		float n1, n2;
		char r;
		printf("Introduza o primeiro valor\n");
		scanf("%f", &n1);
		printf("Introduza o segundo valor\n");
		scanf("%f", &n2);
		if (n1 == n2)
			printf("%.2f igual a %.2f\n", n1, n2 );
		else if (n1 < n2)
			printf("%.2f maior do que %.2f\n", n2, n1);
		else
			printf("%.2f maior do que %.2f\n", n1, n2);			
		system("pause");
	}

**Exercício 1**
Grupo 1.1 - Fazer um programa em C que pergunta um valor em metros e imprime o correspondente em decímetros, centímetros e milímetros

_**Lógica:**_

	Pergunta um valor em metros
	Imprimir valor em decímetros  (1 metro =   10 decímetros)
	Imprimir valor em centímetros (1 metro =  100 centímetros)
	Imprimir valor em milímetros  (1 metro = 1000 milímetros)

_**Linguagem C:**_

	#include <stdio.h>
	#include <stdlib.h>
	main()
	{
		float metros, decimetros, centimetros, milimetros;
		printf("Insira um valor em metros: ");
		scanf("%f", &metros);
		decimetros = metros * 10;
		centimetros = metros * 100;
		milimetros = metros * 1000;
		printf(" %.2f metros equivale a %.2f decimetros.\n", metros, decimetros);
		printf(" %.2f metros equivale a %.2f centimetros.\n", metros, centimetros);
		printf(" %.2f metros equivale a %.2f milimetros.\n", metros, milimetros);
		system("pause");
	}
