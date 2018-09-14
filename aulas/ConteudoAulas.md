# Linguagem C - UNITEN/ANHANGUERA - SOROCABA

## Arquivos Relacionados

- Lista de exercícios adotada: [Curso de Extensão - Linguagem C / Universidade de Brasília](http://www.telecom.uff.br/~marcos/protocolos/www.cic.unb.br/docentes/jacobi/Extensao/ListaExerc.pdf).

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

## AULA 4 - 10/09/2018 (Prof. Stark)

### Definições:

#### Variáveis

- Local na memória principal. Ex: n1, n2.
- Variáveis **não podem** começar com dígitos. Ex errado: 2w.
- Variáveis **não podem** ter espaços. Ex errado: peso do aluno.
- Variáveis **não podem** ter caracteres especiais (que sejam operadores). Ex errado: sala/aula, f-e.
- Dica **variáveis** → minúscula. **Constantes** → Maiúscula.

### Comandos:

- math.h 		→ Biblioteca de operações matemáticas.
- If 			→ Estrutura Condicional.
- For 			→ Laço Repetitivo.
- While 		→ Laço Repetitivo.
- =				→ Operador de atribuição.
- ==			→ Operador de comparação.

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
Grupo 1.1 - Fazer um programa em C que pergunta um valor em metros e imprime o correspondente em decímetros, centímetros e milímetros.

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

## AULA 5 - 12/09/2018 (Prof. Stark)

### Definições

#### Operador Atribuição

- =		Atribuição 		Ex. a = 10			Atribui um valor para um elemento.

#### Operadores Aritméticos

- +		Soma			Ex. a + b 			Obtém o valor da soma de dois números.
- - 	Subtração		Ex. a - b 			Obtém o valor da subtração de dois números.
- *		Multiplicação	Ex. a * b 			Obtém o valor da multiplicação de dois números.
- /		Divisão 		Ex. a / b 			Obtém o valor da divisão de dois números.
- %		Resto inteiro 	Ex. a % b 			Obtém o valor do resto da divisão inteira de dois números inteiros.

#### Operadores Relacionais

- ==	Igualdade		Ex. a == 10			Compara se dois valores são diferentes.
- !=	Diferte			Ex. a != 10			Compara se dois valores são diferentes.
- <		Menor			Ex. a  < 10			Compara se um valor é menor que outro.
- <=	Menor ou igual 	Ex. a <= 10			Compara se um valor é menor ou igual a outro.
- >		Maior 			Ex. a  > 10			Compara se um valor é maior que outro.
- >=	Maior ou igual 	Ex. a >= 10			Compara se um valor é maior ou igual a outro.

#### Operadores Lógicos

- &&	E (AND)			Ex. a && b 			Retorna valor verdade de dois valores com o operador E.
- ||	OU (OR)			Ex. a || b 			Retorna valor verdade de dois valores com o operador OU.
- !		Negação (NOT)	Ex. a  ! b 			Retorna valor verdade de um ou dois valores com o operador NÃO.

#### For

Comando de atribuição → Uso para controle de Loop (Laço).

					i = 0			i < 11		Contador, ex. i++
					↑				↑			↑
	Para (condição inicial; condição final; complemento)
	{
		Laço até a condição final.
	}

	for (i=0; i<11; i++){
		t = a1 * 1;
		printf("%d \n", i);
	}

### Comandos

- %f 			→ Indicador de formato de captura para valores **float**.
- %lf 			→ Indicador de formato de captura para valores **double**.

### Código

**Exercício 1**
Grupo 1.2 - Fazer um programa em C que imprime uma tabela com a tabuada de 1 a 9.

	#include <stdio.h>
	#include <stdlib.h>
	int main()
	{
		int i, t, a1;
		a1 = 9;
		printf("  TABUADA DO %i:\n", a1);
		printf("================\n");
		for (i = 0; i < 11; i++)
		{
			t = a1 * i;
			printf(" %2d x %2d = %3d\n", a1, i, t);
		}
		system("pause");
		return 0;
	}

**Variação B**
Utilizando vetor e recebendo o valor da tabuada.

	#include <stdio.h>
	#include <stdlib.h>
	int main()
	{
		int i, t[10], num;
		printf("DIGITE O VALOR PARA CALCULAR A TABUADA: ");
		scanf("%i", &num);
		printf("\n\n  TABUADA DO %i:\n", num);
		printf("================\n");
		for (i = 0; i < 11; i++)
		{
			t[i] = (num) * (i);
		}
		for (i = 0; i < 11; i++)
		{
			printf(" %2d x %2d = %3d\n", num, i, t[i]);
		}
		system("pause");
		return 0;
	}

**Exercício 2**
Grupo 1.3 - Fazer um programa que solicita um número decimal e imprime o correspondente em hexa e octal.

	#include <stdio.h>
	#include <stdlib.h>
	int main()
	{
		int decimal;
		printf("DIGITE UM VALOR DECIMAL PARA SER CONVERTIDO: ");
		scanf("%i", &decimal);
		
		printf("\n=====================================\n");
		printf("\n\n %i EQUIVALE:\n", decimal);
		printf("=====================================\n");
		printf(" Hexa  \tOcta \n", decimal, decimal);
		printf(" %4x \t%4o\n\n", decimal, decimal );
		system("pause");
		return 0;
	}

**Variação B**
Versão que imprime todos os valores de 0 a 255 de Decimal, Hex, Octal e Char.

	#include <stdio.h>
	#include <stdlib.h>
	int main()
	{
		int i;
		printf("     VALORES E CARACTERES\n");
		printf("================================\n");
		printf("  Dec\tHexa\tOcta\tChar\n");
		
		for (i = 0; i < 256; i++)
		{
			printf("  %3d\t%4x\t%4o\t%2c\n", i, i, i, i);
		}
		system("pause");
		return 0;
	}

**Exercício 3**
Grupo 1.4 - Fazer um programa em "C" que pergunte um valor em graus Fahrenheit e imprime no vídeo o correspondente em graus Celsius usando as fórmulas que seguem.
	A. Usar uma variável _double_ para ler o valor em Fahrenheit e a formula: **C = (f - 32.0) * (5.0/9.0)**.
	B. Usar uma variável _int_ para ler o valor em Fahrenheit e a formula: **C = (f - 32) * (5/9)**.

**A**

	#include <stdio.h>
	#include <stdlib.h>
	int main()
	{
		double c, f;
		printf("DIGITE O VALOR NA ESCALA FAHRENHEIT PARA CONVERTER EM CELSIUS:\n");
		scanf("%lf", &f);
		c = (f - 32.0) * (5.0/9.0);
		printf("O VALOR EM CELSIUS PARA %.2f GRAUS FAHRENHEIT EQUIVALE A %.2f.\n",  f, c);
		return 0;
	}

**B**

	#include <stdio.h>
	#include <stdlib.h>
	int main()
	{
		double c;
		int f;
		printf("DIGITE O VALOR NA ESCALA FAHRENHEIT PARA CONVERTER EM CELSIUS:\n");
		scanf("%i", &f);
		c = (f - 32) * (5/9);
		printf("O VALOR EM CELSIUS PARA %i GRAUS FAHRENHEIT EQUIVALE A %.2f.\n",  f, c);
		return 0;
	}

## AULA 6 - 14/09/2018 (Prof. Luiz)


### Código

**Exercício 1**
Grupo 2.1 - Faça um programa em "C" que lê dois valores e imprime: se o primeiro valor for menor que o segundo, a lista de valores do primeiro até o segundo; se o primeiro valor for menor que o segundo a lista de valores do segundo até o primeiro em ordem decrescente; se ambos forem iguais a mensagem "valores iguais".

_**Lógica**_

	INICIO
		LEIA(x1, x2);
		SE x1 > x2 ENTÃO
			IMPRIME x2;
			IMPRIME x1;
		SENÃO SE x2 > x1 ENTÃO
			IMPRIME x1;
			IMPRIME x2;
		SENÃO
			IMPRIME "Numeros Iguais";
		FIMSE
	FIM

_**Linguagem C:**_

	#include <stdio.h>
	#include <stdlib.h>
	int main()
	{
		float val1, val2;
		printf(" Insira o primeiro numero: ");
		scanf("%f", &val1);
		printf(" Insira o segundo numero: ");
		scanf("%f", &val2);
		if (val1 > val2) {
			printf(" \n\nNumeros: %.2f - %.2f\n\n", val2, val1);
		}
		else if (val1 < val2) {
			printf(" \n\nNumeros: %.2f - %.2f\n\n", val1, val2);
		}
		else if (val1 == val2) {
			printf(" \n\nNumeros iguais.\n\n");
		}
		system("pause");
		return 0;
	}

**Variação B**
Informa se números são diferentes ou iguais de forma infinita.

	#include <stdio.h>
	#include <stdlib.h>
	int main()
	{
		float val1, val2;
		for (;;){
			printf(" Insira o primeiro numero: ");
			scanf("%f", &val1);
			printf(" Insira o segundo numero: ");
			scanf("%f", &val2);
			if (val1 > val2 || val1 < val2) {
				printf(" \n\nNumeros diferentes\n\n");
			}
			else if (val1 == val2) {
				printf(" \n\nNumeros iguais.\n\n");
			}
		}
		return 0;
	}

**Exercício 2**
Criar exercício com operação matemática.

	#include <stdio.h>
	#include <stdlib.h>
	int main()
	{
		float c, f;
		printf(" Insira um n%cmero em graus Celsius: " , '\xA3');
		scanf("%f", &c);
		f = (c * (9.0/5.0)) + 32.0;
		printf("\n\n %.2f graus celsius equivale a %.2f graus fahrenheit.\n\n", c, f);
		system("pause");
		return 0;
	}

### Pesquisa
Operadores Lógicos (Para o dia 21/09).

#### Operadores Lógicos

Operadores lógicos são instrumentos para se extrair o **valor verdade** entre duas proposições. Tendo o funcionamento semelhante ao cálculo aritmético com números, as operações lógicas também são chamadas de **cálculo proposicional**.

##### Negação/NOT (~)

Esta operação é definida como a negação de uma proposição p, quando a proposição p for falsa o valor verdade da negação de p, "não p", será verdadeira, e quando p tiver o valor verdadeiro, "não p" terá o valor falso. Sendo assim, _**a negação terá o valor lógico oposto daquele de sua proposição**_.
Em notação a negação se escreve "~p" e é lida "não p".

Exemplo:

| p | ~p |
|:-:|----|
| V | F  |
| F | V  |

Proposições:
 **a** : O céu é azul. 				= V
**~a** : O céu não é azul. 			= F
 **b** : 1 + 7 = 0					= F
**~b** : 1 + 7 ≠ 0					= V
 **c** : A terra não é redonda. 	= F
**~c** : A terra é redonda.			= V

###### Negação na programação


##### Bibliografia

- **ALENCAR FILHO, Edgar de**. _Iniciação à lógica matemática_. São Paulo. Nobel. 2003.