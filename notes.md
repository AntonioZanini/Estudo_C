# Caderno de Anotações

Arquivo para anotações de informações e tópicos importantes encontrados durante pesquisas e estudos.

## Referências e Links

- [**Recommended C Style and Coding Standards** do _Departamento de Computação/Imperial College London_](https://www.doc.ic.ac.uk/lab/cplus/cstyle.html).

## Conteúdo

### Convenções na Linguagem C

#### Declarações

Os qualificadores dos **ponteiros**, o "\*", devem estar junto às variáveis e não aos tipos.

	int *r;
	/* no lugar de : */
	int* r; 

Declarações não relacionadas, mesmo que compartilhem do mesmo tipo, devem ser realizadas em linhas distintas. Um comentário descrevendo o papel de cada objeto deve ser incluído, com exceção da lista de constantes _#define_ que quando devidamente nomeadas já possuem documentação adequada. Declarações de variáveis devem ser tabuladas de modo a ficarem alinhadas verticalmente em sua exibição.
Declarações de _struct_ e _union_ devem ter seus elementos declarados em linhas separadas e com comentários os descrevendo. Os _struct_ devem ter sua chave de abertura ({) colocada na mesma linha do comando _struct_, a chave de fechamento (}) deve ser colocada na primeira coluna do nível em uma linha.

	struct carro {
		int ano; 	/* ano de produção do carro. */
		int cor;	/* cor do carro. */
		long km;    /* quilometragem do carro. */
	};
	/* constantes para a cor do carro. */
	#define AZUL (1)
	#define BRANCO (2)
	#define VERDE (3)
	#define AMARELO (4)
	#define VERMELHO (5)

Quando os valores das constantes não são individualmente importantes, _enum_ se torna uma opção mais adequada.

	enum cores {AZUL=1, BRANCO, VERDE, AMARELO, VERMELHO};
	struct carro {
		int ano; 	/* ano de produção do carro. */
		enum cores cor;	/* cor do carro. */
		long km;    /* quilometragem do carro. */
	};

Quando o valor inicial de uma variável for importante, ele deverá ser explicitamente atribuído na inicialização, ou pelo menos, comentado sobre o valor inicial 0 esperado. Inicializadores vazios ({}) não devem ser utilizados, as inicializações de _struct_ devem ser abertas e fechadas com chaves. Constantes literais numéricas utilizadas para representar valores como _long_ ou _float_ devem ter a letra especificada ao seu tipo, a letra deve ser maiúscula para não gerar confusão, sendo 54L melhor que 54l que, por sua vez, pode ser facilmente confundido com 541.

	int x = 1;
	char *endereco = "endereco";
	struct carro corrida[] = {
		{1987, AZUL, 20000L},
		{2010, VERMELHO, 9000L},
		{ 0 },	
	};

Em arquivos que não programas autônomos, mas partes de grandes programas, deve ser utilizada amplamente a palavra-chace _static_ para tornar variáveis e funções locais. Variáveis, em particular, devem ser acessadas por outros arquivos apenas em casos de necessidade que não podem ser resolvida de forma local. Tais usos devem ser comentados para deixar claramente documentado quais variáveis têm tais usos e quais arquivos as costumam as acessar.

Os tipos utilizados mais importantes devem ser destacados através de _typedef_, mesmo se forem apenas números inteiros, considerando que nomes únicos são mais fáceis de ler no código (enquanto forem poucos os tipos modificados com _typedef_). Os _struct_ podem ser definidos por _typedef_ aos serem declarados, neste caso, dê a ambos o mesmo nome. Nomes de tipos definidos recebem o sufixo "*\_t*".

	typedef struct cliente_t {
		int codigo;
		char *nome;
		char *endereco;
	} cliente_t;

Tipos de retornos de funções devem ser sempre declarados, protótipos devem ser utilizados quando disponíveis. Um exemplo de erro comum é omitir a declaração de tipos de funções matemáticas externas, o que poderia fazer uma função que normalmente retorna valores do tipo _double_ ter o compilador assumindo que seu retorno é do tipo inteiro e manipulando e convertendo a informação de modo a tornar aquele um valor inutilizado.
