# Linguagem C - UNITEN/ANHANGUERA - SOROCABA

## Arquivos Relacionados

- Lista de exercícios adotada: [Curso de Extensão - Linguagem C / Universidade de Brasília](http://www.telecom.uff.br/~marcos/protocolos/www.cic.unb.br/docentes/jacobi/Extensao/ListaExerc.pdf).

## AULA 1 - 27/08/2018 (Prof. Luiz)

- Explicação sobre Algoritmos e Fluxograma.

## AULA 2 - 29/08/2018 (Prof. Luiz)

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

## AULA 3 - 31/08/2018 (Prof. Luiz)

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

- \+	Soma			Ex. a + b 			Obtém o valor da soma de dois números.
- \- 	Subtração		Ex. a - b 			Obtém o valor da subtração de dois números.
- \*	Multiplicação	Ex. a * b 			Obtém o valor da multiplicação de dois números.
- /		Divisão 		Ex. a / b 			Obtém o valor da divisão de dois números.
- %		Resto inteiro 	Ex. a % b 			Obtém o valor do resto da divisão inteira de dois números inteiros.

#### Operadores Relacionais

- ==	Igualdade		Ex. a == 10			Compara se dois valores são diferentes.
- !=	Diferte			Ex. a != 10			Compara se dois valores são diferentes.
- <		Menor			Ex. a  < 10			Compara se um valor é menor que outro.
- <=	Menor ou igual 	Ex. a <= 10			Compara se um valor é menor ou igual a outro.
- \>		Maior 			Ex. a  > 10			Compara se um valor é maior que outro.
- \>=	Maior ou igual 	Ex. a >= 10			Compara se um valor é maior ou igual a outro.

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

##### Operações Lógicos em C

Operações lógicas na linguagem C funcionam de forma em valores inteiros, sendo o valor 0 equivale à falsidade e todos os outros valores são tratados como verdade, apesar disso, em comparações e operações lógicas feitas pela linguagem ela utilizará o valor 1 para simbolizar a verdade. Os valores lógicos podem ser utilizados com a manipulação de variáveis e constantes inteiras, ou através da biblioteca _stdbool.h_ que adiciona o tipo _bool_ e a utilização de valores _true_ e _false_, porém, mesmo com essas adições o tipo bool (e seus valores) ainda age como "máscaras" para valores inteiros.

Exemplo:

	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	int main()
	{
		if (0)
			printf("Este valor logico nunca sera verdadeiro.\n");
		if (1)
			printf("Este valor logico sempre sera verdadeiro.\n");
		if (2)
			printf("Este tambem.\n");
		if (-1)
			printf("Este idem.\n");
		getchar();
		return 0;
	}

##### Negação / NÃO / NOT ( ~ )

Esta operação é definida como a negação de uma proposição p, quando a proposição p for falsa o valor lógico da negação de p, "não p", será verdade, e quando p tiver o valor verdadeiro, "não p" terá o valor falso. Sendo assim, _**a negação terá o valor lógico oposto daquele de sua proposição**_.
Em notação a negação se escreve "~p", que se lê: "não p".

Exemplo:

| p | ~p |
|:-:|----|
| V | F  |
| F | V  |

Proposições:

-  **a** : O céu é azul. 				→ V
- **~a** : O céu não é azul. 			→ F
-  **b** : 1 + 7 = 0					→ F
- **~b** : 1 + 7 ≠ 0					→ V
-  **c** : A terra não é redonda. 		→ F
- **~c** : A terra é redonda.			→ V

###### **Negação na programação**

Na programação, o operador NOT tem a incumbência de alterar um valor lógico utilizado para algum tipo de processo, geralmente verificações condicionais. Sua implementação nas linguagens possui diferentes formas:

| FORMA | LINGUAGENS                        |
|:-----:|-----------------------------------|
|  not  | Pascal, Visual Basic.             | 
|   !   | C, C++, C#, Java, Javascript, PHP.|

**Exemplo de negação em C**

	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <stdbool.h>
	int main()
	{
		char escolha;
		bool programa_ativo = true;
		do {
			printf("Deseja encerrar este programa? (s/n)");
			escolha = getche();
			programa_ativo = !(escolha == 's');
		} while (programa_ativo == true);
		return 0;
	}

##### Conjunção / E / AND ( ∧ )

Esta operação é definida como a conjunção de duas proposições p e q, sendo chamada de "p e q", e terá o valor lógico **verdadeiro apenas se todos suas proposições forem verdade**, e o mesmo será falso em todos os outros casos.
Em notação a conjunção se escreve "p ∧ q", que se lê: "p e q".

Exemplo:

| p | q | p ∧ q |
|:-:|:-:|:-----:|
| V | V |   V   |
| V | F |   F   |
| F | V |   F   |
| F | F |   F   |

Proposições:

- **a** : O sol é uma estrela. 		→ V
- **b** : O sol orbita a terra.  	→ F
- **c** : A lua orbita a terra.		→ V

Sendo:
- **a ∧ b**			→ F
- **c ∧ b**			→ F
- **a ∧ c**			→ V
- **(a ∧ b) ∧ c**	→ F
- **a ∧ ~b**		→ V

###### **Conjunção na programação**

A principal função da conjunção na programação é extrair valores lógicos de comparações e verificações. Estas são as suas implementações em diferentes linguagens de programação:

| FORMA | LINGUAGENS                        |
|:-----:|-----------------------------------|
|  and  | Pascal, Visual Basic, PHP.        | 
|  &&   | C, C++, C#, Java, Javascript, PHP.|

**Exemplo de conjunção em C**

	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <stdbool.h>
	int main()
	{
		bool carro_aspirado, carro_lavado, carro_encerado;
		carro_aspirado = true;
		carro_lavado   = true;
		carro_encerado = false;
		if (carro_aspirado && carro_lavado && carro_encerado)
			printf("A limpeza do carro terminou!\n");
		else 
			printf("A limpeza do carro ainda nao terminou.\n");
		getchar();
		return 0;
	}

##### Disjunção / OU / OR ( ∨ )

Esta operação é definida como a disjunção de duas proposições p e q, sendo chamada de "p ou q", e **terá o valor lógico verdadeiro quando ao menos uma de suas proposições possuir o valor verdade**, caso nenhuma o possua será uma falsidade.
Em notação a disjunção se escreve "p ∨ q", que se lê: "p e q".

Exemplo:

| p | q | p ∨ q |
|:-:|:-:|:-----:|
| V | V |   V   |
| V | F |   V   |
| F | V |   V   |
| F | F |   F   |

Proposições:

- **a** : Gelo é água sólida.  				→ V
- **b** : Combustão necessita de Oxigênio.	→ V
- **c** : Baleias são peixes.				→ F
- **d** : Tomate não é fruta.				→ F

Sendo:
- **a ∨ b**			→ V
- **b ∨ c**			→ V
- **c ∨ d**			→ F
- **(a ∨ b) ∨ c**	→ V
- **(a ∧ c) ∨ d**	→ F
- **a ∨ d**			→ V
- **~b ∨ d**		→ F

###### **Disjunção na programação**

A principal função da disjunção na programação é extrair valores lógicos de comparações e verificações. Estas são as suas implementações em diferentes linguagens de programação:

| FORMA | LINGUAGENS                        |
|:-----:|-----------------------------------|
|  or   | Pascal, Visual Basic, PHP.        | 
|  \|\|   | C, C++, C#, Java, Javascript, PHP.|

**Exemplo de disjunção em C**

	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <stdbool.h>
	int main()
	{
		bool carro_azul, carro_verde, carro_preto;
		carro_azul 	= true;
		carro_preto = false;
		carro_verde = false;
		if (carro_azul || carro_preto || carro_verde){
			printf("Na garagem estao:\n");
			carro_verde ? printf("Carro Verde\n")	:0;
			carro_preto ? printf("Carro Preto\n")	:0;
			carro_azul 	? printf("Carro Azul\n")	:0;
		}
		else 
			printf("Garagem Vazia.\n");

		getchar();
		return 0;
	}

##### Outros Operadores

###### **Disjunção Exclusiva / XOR (⊻)**

Este operador é uma variação da disjunção padrão onde as proposições **p e q necessitam ter valores lógicos diferentes para ser uma verdade**, em qualquer outro caso será uma falsidade.
Em notação a disjunção exclusiva se escreve "p ⊻ q", que se lê: "p ou q, mas não ambas".

Exemplo:

| p | q | p ⊻ q |
|:-:|:-:|:-----:|
| V | V |   F   |
| V | F |   V   |
| F | V |   V   |
| F | F |   F   |

Proposições:

- **a** : Hoje é segunda-feira.  			→ V
- **b** : Hoje é sábado.					→ F
- **c** : O meu único mascote é um gato.	→ V
- **d** : O meu único mascote é um peixe.	→ V

Sendo:
- **a ⊻ b**			→ V
- **c ⊻ d**			→ F

**Disjunção exclusiva na programação**

Comparado com os operadores anteriores, a disjunção exclusiva é utilizada em escala bem menor devido a sua utilização ser necessária apenas em casos específicos, por isso ela não é implementada em todas as linguagens.

###### **Condicional (→)**

Também chamada de proposição condicional, é representado com "se p então q", e terá o valor lógico **verdadeiro quando a proposição q tive o valor lógico verdade ou um valor lógico igual à proposição p**.
Em notação a condicional se escreve "p → q", que se lê: "se p então q".

Exemplo:

| p | q | p → q |
|:-:|:-:|:-----:|
| V | V |   V   |
| V | F |   F   |
| F | V |   V   |
| F | F |   V   |

**Condicional na programação**

No formato de operador lógico, condicional não se faz presente nas linguagens de programação.

###### **Bicondicional (↔)**

Este operador é também chamado de proposição bicondicional, representado com "p se e somente se q", e terá o valor lógico **verdadeiro apenas se ambas as proposições tiverem valores lógicos iguais**.
Em notação a bicondicional se escreve "p ↔ q", que se lê: "p se e somente se q".

Exemplo:

| p | q | p ↔ q |
|:-:|:-:|:-----:|
| V | V |   V   |
| V | F |   F   |
| F | V |   F   |
| F | F |   V   |

**Bicondicional na programação**

No formato de operador lógico, bicondicional não se faz presente nas linguagens de programação.

##### Bibliografia

- **ALENCAR FILHO, Edgar de**. _Iniciação à lógica matemática_. São Paulo. Nobel. 2003.
- **LAUREANO, Marcos**. _Programando em C para Linux, Unix e Windows_. Rio de Janeiro. Brasport. 2005.

## AULA 7 - 17/09/2018 (Prof. Stark)

### Comandos

- Operações

| Operador | Função                                                             |
|:--------:|:-------------------------------------------------------------------|
|    +     | Operador de soma.                                                  |
|    *     | Operador de multiplicação.                                         |
|  pow()   | Função de potenciação. _pow(3,2)_ equivale a 3². Biblioteca math.h.|
|  sqrt()  | Função de raiz quadrada. Biblioteca math.h.                        |
|  sin()   | Função de seno radiano. Biblioteca math.h.                         |
|  abs()   | Função de módulo inteiro. Biblioteca math.h.                       |
|  fabs()  | Função de módulo ponto flutuante. math.h.                          |

### Código

**Exercício 1**
Grupo 1.5 - Fazer um programa em "C" que solicite 2 números e informe: a) A soma dos números; b) O produto do primeiro número pelo quadrado do segundo; c) O quadrado do primeiro número; d) A raiz quadrada da soma dos quadrados; e) O seno da diferença do primeiro número pelo segundo; f) O módulo do primeiro número.

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	int main(int argc, char const *argv[])
	{
		float primeiro_numero, segundo_numero;
		printf("Insira primeiro numero: ");
		scanf("%f", &primeiro_numero);
		printf("Insira segundo numero: ");
		scanf("%f", &segundo_numero);
		printf("Soma: %.3f\n", (primeiro_numero + segundo_numero));
		printf("a*(b*b): %.3f\n", (primeiro_numero * pow(segundo_numero,2)));
		printf("a*a: %.3f\n", pow(primeiro_numero,2));
		printf("Raiz de ((a*a)+(b*b)): %.3f \n", sqrt(pow(primeiro_numero,2)+pow(segundo_numero,2)));
		printf("Seno de (a - b): %.3f\n", sin(primeiro_numero - segundo_numero));
		printf("Modulo de a: %.3f\n", fabs(primeiro_numero));
		return 0;
	}


**Exercício 2**
Grupo 2.3 - Fazer um programa em "C" que lê o preço de um produto e inflaciona esse preço em 10% se ele for menor que 100 e em 20% se ele for maior ou igual a 100. OBS: não use o comando "if" ou o operador de condição "?".

	#include <stdio.h>
	#include <stdlib.h>
	int main(int argc, char const *argv[])
	{
		float preco, inflacao, resultado;
		printf("Insira o valor do preco: ");
		scanf("%f", &preco);
		inflacao = 10 + (10 * (preco >= 100));
		resultado = preco * (1 + (inflacao/100.00));
		printf("Preco inflacionado: %.2f\n", resultado);
		return 0;
	}

**Exercício 3**
Grupo 2.4 - Fazer um programa que lê um valor, um operador (+,-,*,/) e outro valor e imprime o resultado da expressão: (valor 1) (operador) (valor 2).


	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	int main(int argc, char const *argv[])
	{
		int op1, op2, resultado;
		char opr;
		do {
		printf("Insira o operando 1: ");
		scanf("%i", &op1);
		printf("Insira o operador (+,-,*,/): ");
		opr = getche();
		printf("\nInsira o operando 2: ");
		scanf("%i", &op2);
		if (opr == '+')
			resultado = op1 + op2;
		else if (opr == '-') 
			resultado = op1 - op2;
		else if (opr == '*')
			resultado = op1 * op2;
		else if (opr == '/')
			resultado = op1 / op2;
		printf("\nResultado %d %c %d = %d \n\n", op1, opr, op2, resultado);
		} while (opr != 's');
		return 0;
	}

