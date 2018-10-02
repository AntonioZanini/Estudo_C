# Linguagem C - UNITEN/ANHANGUERA - SOROCABA

## Arquivos Relacionados

- Lista de exercícios adotada: [Curso de Extensão - Linguagem C / Universidade de Brasília](http://www.telecom.uff.br/~marcos/protocolos/www.cic.unb.br/docentes/jacobi/Extensao/ListaExerc.pdf).

## AULA 1 - 27/08/2018 (Prof. Luiz)

- Explicação sobre Algoritmos e Fluxograma.

## AULA 2 - 29/08/2018 (Prof. Luiz)

- Breve descrição da história da linguagem C.

### Tipos de Variáveis:

|Tipos          |Conteúdo        |
|:-------------:|:--------------:|
|int            |Números inteiros|
|float, double  |Ponto flutuante |
|char           |Caracteres      |

### Comandos:

|Código de Comando |Função                                                                                                   |
|:----------------:|:--------------------------------------------------------------------------------------------------------|
|#include          |Inclusão de bibliotecas.                                                                                 |
|stdio.h           |Biblioteca de tratamento de entrada e saída de dados.                                                    |
|stdlib.h          |Biblioteca com funções de cálculo.                                                                       |
|printf            |Função de impressão.                                                                                     |
|""                |Delimitador de texto.                                                                                    |
|\n                |Marcador de quebra de texto.                                                                             |
|for               |Estrutura Repetitiva: for(variável = [início]; variável [limite lógico]; incremento ou decremento){}.    |
|scanf             |Captura de texto do teclado: scanf(tipo de dado, &variável).                                             |
|while             |Estrutura Repetitiva: while (condição lógica){}.                                                         |
|\|\|              |Operador lógico OU.                                                                                      |
|switch            |Estrura Condicional: switch (variável) { case (caso1): [código]; break; case (caso2): [código]; break;}. |
|system("pause")   |Pausa da tela.                                                                                           |

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
- Dica:

|Nomes          |Uso de Caracteres  |
|:-------------:|:-----------------:|
|**Variáveis**  |Sempre minúsculas. |
|**Constantes** |Sempre MAIÚSCULAS. |

### Comandos:

|Código de Comando |Função                               |
|:----------------:|:------------------------------------|
|math.h            |Biblioteca de operações matemáticas. |
|if                |Estrutura Condicional.               |
|for               |Laço Repetitivo.                     |
|while             |Laço Repetitivo.                     |
|=                 |Operador de atribuição.              |
|==                |Operador de comparação.              |

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

|Operador |Nome       |Função                             |Exemplo    |
|:-------:|:---------:|:----------------------------------|:----------|
|=        |Atribuição |Atribui um valor para um elemento. |Ex. a = 10 |

#### Operadores Aritméticos

|Operador |Nome          |Função                                                              |Exemplo   |
|:-------:|:------------:|:-------------------------------------------------------------------|:---------|
|\+       |Soma          |Obtém o valor da soma de dois números.                              |Ex. a + b |
|\-       |Subtração     |Obtém o valor da subtração de dois números.                         |Ex. a - b |
|\*       |Multiplicação |Obtém o valor da multiplicação de dois números.                     |Ex. a * b |
|/        |Divisão       |Obtém o valor da divisão de dois números.                           |Ex. a / b |
|%        |Resto Inteiro |Obtém o valor do resto da divisão inteira de dois números inteiros. |Ex. a % b |

#### Operadores Relacionais

|Operador |Nome           |Função                                        |Exemplo     |
|:-------:|:-------------:|:---------------------------------------------|:-----------|
|==       |Igualdade      |Compara se dois valores são iguais.           |Ex. a == 10 |
|!=	      |Diferença      |Compara se dois valores são diferentes.       |Ex. a != 10 |
|<        |Menor          |Compara se um valor é menor que outro.        |Ex. a  < 10 |
|<=       |Menor ou igual |Compara se um valor é menor ou igual a outro. |Ex. a <= 10 |
|\>       |Maior          |Compara se um valor é maior que outro.        |Ex. a  > 10 |
|\>=      |Maior ou igual |Compara se um valor é maior ou igual a outro. |Ex. a >= 10 |

#### Operadores Lógicos

|Operador |Nome          |Função                                                          |Exemplo     |
|:-------:|:------------:|:---------------------------------------------------------------|:-----------|
|&&       |E (AND)       |Retorna valor verdade de dois valores com o operador E.         |Ex. a && b   |
|\|\|     |OU (OR)       |Retorna valor verdade de dois valores com o operador OU.        |Ex. a \|\| b |
|!        |Negação (NOT) |Retorna valor verdade de um ou dois valores com o operador NÃO. |Ex. a  ! b   |

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

|Código de Comando |Função                                                   |
|:----------------:|:--------------------------------------------------------|
|%f                |Indicador de formato de captura para valores **float**.  |
|%lf               |Indicador de formato de captura para valores **double**. |

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

| FORMA   | LINGUAGENS                        |
|:-------:|-----------------------------------|
|  or     | Pascal, Visual Basic, PHP.        | 
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

## AULA 8 - 19/09/2018 (Prof. Stark)

### Código

**Exercício 1**
Grupo 2.5 - Escrever um programa em "C" que solicita as notas das duas provas feitas por cada um dos alunos de uma turma (as notas tem de estar no intervalo [0 10]) e imprime para cada um a média das notas. O programa deve parar imediatamente após ter sido digitado o valor 50 para a nota da primeira prova.

	#include <stdio.h>
	#include <stdlib.h>
	#define MAX_ALUNOS 5
	int main(int argc, char const *argv[])
	{
		int x = 0;
		float provas_turma[MAX_ALUNOS][2];
		float nota_1, nota_2;
		float media_aluno, media_classe = 0;
		int num_alunos;
		do {
			printf("\nINSIRA AS NOTAS DO %io ALUNO:\n", x+1);
			printf("-------------------------------");
			printf("\nNOTA DA PRIMEIRA PROVA: ");
			do {
				scanf("%f", &nota_1);
				if ((0 > nota_1) || ((10 < nota_1) && 50 != nota_1))
					printf("\nNOTA INVALIDA!\nINSIRA NOVO VALOR: ");
			} while ((0 > nota_1) || ((10 < nota_1) && 50 != nota_1));
			if (50 == nota_1) {
				break;
			}
			printf("\nNOTA DA SEGUNDA PROVA: ");
			do {
				scanf("%f", &nota_2);
				if ((0 > nota_2) || (10 < nota_2))
					printf("\nNOTA INVALIDA!\nINSIRA NOVO VALOR: ");
			} while ((0 > nota_2) || (10 < nota_2));
			provas_turma[x][0] = nota_1;
			provas_turma[x][1] = nota_2;
			x++;
		} while (MAX_ALUNOS > x);
		num_alunos = x;
		printf("\n\nMEDIAS:\n\n");
		for (x = 0; x < num_alunos; x++)
		{
			media_aluno = (provas_turma[x][0] + provas_turma[x][1]) / 2.0;
			printf("ALUNO %i P1: %.2f P2: %.2f M: %.2f\n", x +1, provas_turma[x][0], provas_turma[x][1],  media_aluno);
			media_classe += media_aluno;
		}
		media_classe = media_classe / num_alunos;
		printf("\nMEDIA DA CLASSE: %.2f\n\n", media_classe);
		system("pause");
		return 0;
	}

**Exercício 2**
Grupo 3.2 - Faca um programa em "C" que le dois números e utiliza uma função chamada "soma" e outra chamada "subtracao" para imprimir a soma e a diferenca entre os dois números. Ambas funções devem receber dois inteiros como parâmetro e retornar um inteiro como resultado.

	#include <stdio.h>
	#include <stdlib.h>
	float soma(float a, float b) 
	{
		return (a + b);
	}
	int main () 
	{
		float valor_a, valor_b;
		do {
			printf(" Insira o valor de A: ");
			scanf("%f", &valor_a);
			printf(" Insira o valor de B: ");
			scanf("%f", &valor_b);
			printf("\n %.2f + %.2f = %.2f\n\n", valor_a, valor_b, soma(valor_a, valor_b));
		} while ((0 != valor_a) || (0 != valor_a));
		system("pause");
		return 0;
	}

**Exercício 3**
Grupo 4.1 - Fazer uma função que cacula a enésima potência de uma variável real x: f(x, n) = x^n.

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	float potencia(float a, float b) 
	{
		return pow(a, b);
	}
	int main () 
	{
		float valor_a, valor_b;
		do {
			printf(" Insira o valor de A: ");
			scanf("%f", &valor_a);
			printf(" Insira o valor de B: ");
			scanf("%f", &valor_b);
			printf("\n %.2f ^ %.2f = %.2f\n\n", valor_a, valor_b, potencia(valor_a, valor_b));
		} while ((0 != valor_a) || (0 != valor_a));
		system("pause");
		return 0;
	}

## AULA 9 - 21/09/2018 (Prof. Luiz)

### Código

**Exercício 1**
Programa que atribui comandos para um processo encaixotador de latas.

_**Lógica:**_

	Algoritmo Contagem
	INÍCIO
		max_lata_cx		: INTEIRO;
		cont_caixa 		: INTEIRO;
		qtd_caixas		: INTEIRO;
		num_latas_cx	: INTEIRO;
		num_latas_lido	: INTEIRO;
		x				: INTEIRO;
		marca 			: CARACTERE;
		data			: CARACTERE;
		cont_caixa = 0;
		ESCREVA ("DIGITE A DATA: ");
		LEIA (data);
		ESCREVA ("DIGITE A MARCA: ");
		LEIA (marca);
		ESCREVA ("DIGITE A QUANTIDADE DE LATAS POR CAIXA: ");
		LEIA (max_lata_cx);
		ESCREVA ("INSIRA A QUANTIDADE DE CAIXAS: ");
		LEIA (qtd_caixas);
		FAÇA
			num_latas_cx = 0;
			FAÇA
				ESCREVA ("INSIRA A QUANTIDADE DE LATAS");
				LEIA (num_latas_lido);
				num_latas_cx = num_latas_cx + num_latas_lido;
				SE (num_latas_cx < max_lata_cx)
					ESCREVA("FALTAM " & (max_lata_cx - num_latas_cx) & " LATAS PARA FECHAR A CAIXA!");
				SENÃO SE (num_latas_cx = max_lata_cx)
					ESCREVA("CAIXA FECHADA!");
				SENÃO
					ESCREVA("CAIXA FECHADA! SOBRARAM " & (num_latas_cx - (max_lata_cx * (num_latas_cx /  max_lata_cx))) & "!");
					cont_caixa += (num_latas_cx /  max_lata_cx) -1;
				FIM SE
			ENQUANTO (num_latas_cx < max_lata_cx);
			cont_caixa ++;
			ESCREVA (cont_caixa & " CAIXA(S) FECHADA(S)")
		ENQUANTO (cont_caixa < qtd_caixas);
		ESCREVE ("TOTAL DE CAIXAS DE LATAS EMBALADAS EM " & data & ":" & cont_caixa);
	FIM

_**Linguagem C:**_

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

**Exercício 2**
Exercício que captura valores de bolsa de alguma ação e retorna as variações segundo os períodos informados.

	#include <stdio.h>
	#include <stdlib.h>
	int main(int argc, char const *argv[])
	{
		float bolsa[10], variacao_bolsa[9];
		int i;
		for (i = 0; i < 10; i++) {
			printf("Insira o valor da bolsa durante o periodo %2i : ", i + 1);
			scanf("%f", &bolsa[i]);
			if (i != 0) {
				variacao_bolsa[i-1] = (bolsa[i] - bolsa[i-1]);
			}
		}
		for (i = 0; i < 9; i++) {
			printf("A variacao %i : %.2f\n", i + 1, variacao_bolsa[i] );
		}
		system("pause");
		return 0;
	}

## AULA 10 - 26/09/2018 (Prof. Stark)

### Conceitos

- Revisão sobre funções.

### Código

**Exercício 1**
Grupo 4.3 - Dado que podemos calcular e^x por: 
**e^x = 1 + x + x^2/2! + x^3/3! + ...**
Fazer um trecho de programa em "C" que lê um valor para x e calcula o valor de e^x. O valor deve ser calculado enquanto o termo calculado for maior que 10E-6.

	#include <stdio.h>
	#include <stdio.h>
	#include <math.h>
	double		fatorial 	(int n);
	float 		euler		(int x);
	float 		e 			(int x, int i);
	int main(int argc, char const *argv[])
	{
		int valor;
			valor = 0;
			printf("\n\nDIGITE VALOR PARA A POTENCIA: ");
			scanf("%i", &valor);
			printf("RESULTADO DE E^%i: %.4f", valor, euler(valor));
	}
	float euler(int x)
	{
		float resultado;
		resultado = e(x, 1) + 1;
		return resultado;
	}
	float e(int x, int i)
	{
		float total = 0;
		total = (pow(x, i) / fatorial(i));
		if (fabs(total) >= 0.000001f)
			total += e(x, i + 1);
		return total;
	}
	double fatorial(int n)
	{
		double total = 1;
		if (n >= 1)
			total *= n * fatorial(n - 1); 
		return (total);
	}

**Variação B**
Resolver o mesmo exercício, porém sem a utilização de funções, apenas com a estrutura repetitiva.

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#define LIMITE 0.000001f
	int main(int argc, char const *argv[])
	{
		float termo, total, valor;
		int i;
		printf("DIGITE VALOR PARA A POTENCIA: ");
		scanf("%f", &valor);
		termo 	= 1.0f;
		total 	= 1.0f;
		i 		= 1;
		do
		{
			termo = termo * (valor / i);
			total = total + termo;
			i++;
		} while (fabs(termo) >= LIMITE);
		
		printf("\nRESULTADO: %f\n", total);
		system("pause");
		return 0;
	}

## AULA 11 - 28/09/2018 (Prof. Luiz)

### Conceitos

- Ponteiros.

### Código

- Ponteiro:

		int idade;
		int *pnt_idade;
		int ano;
		pnt_idade = &idade;
		ano = 2018 - *pnt_idade;

- Switch:

		switch (idade) {
			case 10:
				printf("Vai jogar bola");
				break;
		}

**Exercício 1**
Programa que recebe um número de carros e aplica um desconto à seu valor total de venda.

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
		float 	desconto;
		float	preco_carro = 70000.0f;
		bool	compra;
		do {
			compra = true;
			printf("\n Insira o n%cmero de carros a ser comprados: ", U_MI_AGUDO);
			scanf("%d", &num_carros);
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
			}
		} while (-1 != num_carros);
		return 0;
	}

**Variação B**
Alteração do programa anterior para funcionar utilizando ponteiros e exibindo o endereço do ponteiro utilizado.

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
			switch (num_carros) {
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
			}
		} while (-1 != num_carros);
		return 0;
	}

## AULA 12 - 01/10/2018 (Prof. Stark)

### Código

**Exercício 1**
Grupo 5.1 - Procure determinar quais valores são impressos ao final deste programa. Confira sua resposta testando o programa no micro. Execute-o passo a passo conferindo o valor das variáveis em cada momento.

**a.** 

	void main()
	{
		int a,b,*c;
		a = 3;
		b = 4;
		c = &a;
		b++;
		*c = a+2;
		printf("%d %d",a,b);
	}

Saída: "5 5" CORRETO

**b.**

	void main()
	{
		int a,b,*c;
		a = 4;
		b = 3;
		c = &a;
		*c = *c +1;
		c = &b;
		b = b+4;
		printf("%d %d %d",a,b,*c);
	}

Saída: "5 7 7" CORRETO

**c.**

	void main()
	{
		int a,b,*c,*d,*f;
		a = 4;
		b = 3;
		c = &a;
		d = &b;
		*c /= 2;
		f = c;
		c = d;
		d = f;
		printf("%d %d",*c,*d);
	}

Saída: "3 2" CORRETO

**d.**

	int calcula(int);
	void main()
	{
		int a,b,c;
		char d;
		a=1;b=2;c=3;d='A';
		a+=b*c;
		d=(a>7)?d-1:d+1;
		b = calcula(b);
		c = calcula(calcula(a));
		a = c++;
		printf("%d - %d - %d - %c\n",a,b,c,d);
	}
	int calcula(int x)
	{
		int i;
		if ((x=x*2)>5) return(x+3);
		for(i=0;i<10;i++)
		{
			if (i<5) continue;
			if (x>8) break;
			x+=2;
		}
		return(x);
	}

Saída: "38 10 37 B" ERRADO "37 10 38 B" 
a = c++: Faz **a** receber o valor de c (37) e, após isso, incrementa c para 38.

**Exercício 2** 
Grupo 6.1 - Fazer um programa em "C" que lê 10 valores e imprime o maior e o menor valores lidos.

	#include <stdio.h>
	#include <stdlib.h>
	#define U_MI_AGUDO 		'\xA3' 	/* ú */
	#define ORDINAL_MASC	'\xA7' 	/* º */
	int main()
	{
		int i, num[10], maior, menor;
		for (i = 0; i < 10; i++) {
			printf(" Insira o %2i%c n%cmero: ", i+1, ORDINAL_MASC, U_MI_AGUDO);
			scanf("%i", &num[i]);
		}
		menor = num[0];
		maior = num[0];
		for (i = 1; i < 10; i++) {
			if (menor > num[i])
				menor = num[i];
			if (maior < num[i])
				maior = num[i];
		}
		printf("\n Menor: %i\n Maior: %i\n\n", menor, maior);
		system("pause");
		return 0;
	}

**Exercício 3**
Grupo 6.2 - Fazer um programa que lê um conjunto de 10 valores e os imprime ordenados.

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#define U_MI_AGUDO 		'\xA3' 	/* ú */
	#define ORDINAL_MASC	'\xA7' 	/* º */
	void ordenar(int *, int);
	int main()
	{
		int i, num[10];
		for (i = 0; i < 10; i++) {
			printf(" Insira o %2i%c n%cmero: ", i+1, ORDINAL_MASC, U_MI_AGUDO);
			scanf("%i", &num[i]);
		}
		ordenar(num, 10);
		printf("\n N%cmeros Ordenados: \n\n", U_MI_AGUDO);
		for (i = 0; i < 10; i++) {
			printf(" %i ", num[i]);
			if (i != 9)
				printf("-");
			else
				printf("\n\n");
		}
		system("pause");
		return 0;
	}
	void ordenar(int *lista, int tamanho)
	{
		int aux, final, i;
		bool ordenado;
		final = tamanho - 1;
		do {
			ordenado = true;
			for (i = 0; i < final; i++) {
				if (lista[i] > lista[i+1]) {
					aux = lista[i+1];
					lista[i+1] = lista[i];
					lista[i] = aux;
					ordenado = false;
				}
			}
			final--;
		} while (!ordenado);
	}

**Exercício 4**
Grupo 6.3 - Fazer uma rotina que recebe como parâmetro um array de 5 posições contendo as notas de um aluno ao longo do ano e devolve a média do aluno.

	#include <stdio.h>
	#include <stdlib.h>
	#define ORDINAL_FEM		'\xA6' 	/* ª */
	#define E_MI_AGUDO		'\x82' 	/* é */
	float media(int *, int);
	int main(int argc, char const *argv[])
	{
		int i, notas[5];
		for (i = 0; i < 5; i++) {
			printf(" Insira a %2i%c nota do aluno: ", i+1, ORDINAL_FEM);
			scanf("%i", &notas[i]);
		}
		printf("\n A m%cdia do aluno %c: %.2f", E_MI_AGUDO, E_MI_AGUDO, media(notas, 5));
		return 0;
	}
	float media(int *notas, int quantidade)
	{
		int i, total = 0;
		for (i = 0; i < quantidade; i++) {
			total += notas[i];
		}
		return (total / (quantidade * 1.0f));
	}

**Exercício 5**
Grupo 6.4 - Fazer uma rotina que recebe um array do tipo double e o número de valores que devem ser solicitados ao usuário e devolve o array preenchido com os valores digitados.

	#include <stdio.h>
	#include <stdlib.h>
	#define QUANTIDADE_MATERIAS 	6
	#define ORDINAL_FEM			'\xA6' 	/* ª */
	#define E_MI_AGUDO			'\x82' 	/* é */
	int main(int argc, char const *argv[])
	{
		int i;
		double medias[QUANTIDADE_MATERIAS];
		preencher_medias(medias);
		printf("\n\n M%cdias: \n\n", E_MI_AGUDO);
		for (i = 0; i < QUANTIDADE_MATERIAS; i++) {
			printf(" %.2lf ", medias[i]);
			if (i != (QUANTIDADE_MATERIAS - 1))
				printf("-");
			else
				printf("\n\n");
		}
		system("pause");
		return 0;
	}
	void preencher_medias(double *medias)
	{
		int i;
		for (i = 0; i < QUANTIDADE_MATERIAS; i++) {
			printf(" Insira a m%cdia da %2i%c mat%cria do aluno: ", E_MI_AGUDO, i+1, ORDINAL_FEM, E_MI_AGUDO);
			scanf("%lf", &medias[i]);
		}
	}

**Exercício 6**
Grupo 6.5 - Fazer um programa em "C" que lê um conjunto de 10 valores inteiros e verifica se algum dos valores é igual a média dos mesmos.

	#include <stdio.h>
	#include <stdlib.h>
	#define E_MI_AGUDO		'\x82' 	/* é */
	float media(int *);
	int main(int argc, char const *argv[])
	{
		int valores[10] = {2, 2, 2, 2, 3 , 3, 3, 1, 1 ,1};
		int i;
		float media_geral;
		media_geral = media(valores);
		printf("\n\n M%cdia: %.2f\n\n", E_MI_AGUDO, media_geral);
		for (i = 0; i < 10; i++) {
			if (valores[i] == media_geral)
				printf(" Valor mediano: %i \n", valores[i] );
		}
		return 0;
	}
	float media(int *valores)
	{
		int i, soma = 0;
		for (i = 0; i < 10; i++) {
			soma += valores[i];
		}
		return (soma / 10.0);
	}