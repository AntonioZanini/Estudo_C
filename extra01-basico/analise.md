# Análise dos Exercícios Extras 01

Esta seção tem o intuito de servir tanto como um índice para os exercícios, os descrevendo e listando, como uma área para registrar pensamentos e ideia despertadas pela execução dos mesmos.

## Exercícios

1. [**001-var.c**](001-var.c).

Exercício simples de manipulação de variáveis. 
- A pesquisa envolvida em seu estudo me ensinou sobre a função **_fgets()_** e sua capacidade de limitar a entrada de caracteres, de modo a ser um recurso seguro em determinadas situações de coleta de dados. 
- Outro aprendizado foi sobre a função **_system()_**, em minhas experiências anteriores com C ela apenas era utilizada para pausar o programa para a visualização (desta maneira _system("pause")_), porém ao analisá-la um pouco pude ver que ela é muito mais que isso, sendo uma interação direta com ambiente de execução pedindo recursos externos para fins internos. Saber disto é ter a noção que nem sempre utilizar tais recursos pode ser uma boa ideia, _system(pause)_ pede ao ambiente de execução que pause todas as suas ações, e isso não parece a melhor maneira de se realizar uma simples pausa em um programa procedural.

2. [**002-type.c**](002-type.c).

Exercício sobre os tipos de variáveis. Abortando espaço utilizado na memória e os limites de valores que aos quais cada tipo suporta.
- Neste exercício não houveram complicações, mas a pesquisa me levou por conhecimentos que eu deduzia à primeira vista, como disponibilidades dos tipo de inteiro não-assinalados. Os tamanhos dos inteiros me deixou um pouco intrigado, os valores de tamanho retornados pelas funções foram iguais entre _int_ e _long_, inicialmente me causou confusão, mas a pesquisa revelou que a causa era uma questão de legado de arquitetura, sendo devido aos compiladores em sistemas modernos (x84 e x64) que utilizam o tamanho de 4 bytes (32 bits) ao invés de 2 bytes (16 bits) para o tamanho de _int_.
- Tentei incluir todos os tipos que vi descritos em múltiplas fontes, mas o tipo _long long_ me pareceu complicar excessivamente a premissa do exercício ao não ser facilmente adicionado utilizando as mesmas bibliotecas que seus companheiros inteiros.

3. [**003-oper_cond_loop.c**](003-oper_cond_loop.c).

Programa: **OPERAÇÕES COM TEMPERATURAS**. Exercício sobre operações aritméticas, estruturas condicionais e repetitivas e funções.
- Este foi o primeiro exercício com uma grande escalada de recursos utilizados durante o desenvolvimento, de algo simples como conversões com formulas definidas evoluiu para algo com interface e estruturas bem definidas. 
- Utilização de _enum_ é algo que começou de um modo promissor, deixando o código mais legível e estruturado. 

4. [**004-operandos.c**](004-operandos.c).

Programa: **OPERAÇÕES**. Exercício sobre operações aritméticas controladas pelo usuário, envolvendo coleta e validação de dados.
- O programa OPERAÇÕES foi um exercício para praticar mais as operações matemáticas e, ao começá-lo, procurei deixar o seu visual o mais interessante possível, não fiz nenhum milagre, mas o considero "elegante".
- A utilização de valores _ASCII_ para consertar a barreira do idioma em relação ao Unicode deu um trabalho considerável, mas valeu a pena, principalmente ao não ter que escrever **operacao** não tela!
- O nível de validação que fiz não era planejado inicialmente, mas a possibilidade se apresentou e me atirei nela, e ficou interessante. Eu poderia aprimorar ainda mais, porém não iria acrescentar muito ao resultado ou ao propósito do exercício.

5. [**005-ponteiros.c**](005-ponteiros.c).

Programa: **LABIRINTO FANTASMA**. Exercício de um jogo sobre a movimentação em um labirinto, envolvendo múltiplas funções e fluxo de dados através de ponteiros.
- De início ele seria apenas algo como uma concatenação de caracteres de acordo com a direção de seu desenho, mas ao imaginar mais e descobrir como mover o cursor pela tela o objetivo subiu.
- Várias pequenas descobertas me moveram durante o desenvolvimento: _rand()_, _system("COLOR")_, _SetConsoleCursorPosition()_ e _SetConsoleTextAttribute()_. Elas possibilitaram pequenos detalhes e grandes funcionalidades, aquela que mais me interessei é a _SetConsoleCursorPosition()_ que permite personalizar o fluxo de texto da _stdout_ possibilitando maior controle na saída de texto.
- Este exercício me deu um grau de satisfação imenso, creio que nos próximos exercícios irei tentar me manter mais simples e objetivo.

6. [**006-recursividade-fatorial.c**](006-recursividade-fatorial.c).

Exercício extremamente simples, nenhum recurso novo da linguagem C, o maior benefício é exercitar conceitos da lógica de programação, nesse caso, a **recursividade**.
- Imaginei que fosse ter mais dificuldades na lógica, mas foi bem simples. Como é praticamente um enigma lógico fiz um [algoritmo](006-algoritmo.txt) deste exercício antes do programa para me preocupar apenas com a sua lógica.

7. [**007-strings-criptografia.c**](007-strings-criptografia.c).

Programa: **CRIPTOGRAFIA**. [Algoritmo](007-algoritmo.txt). Exercício composto pela captura de uma cadeia de caracteres e criptografá-la e descriptografá-la por substituição com uma chave dupla criada aleatoriamente no início de sua execução.
- Este exercício impôs boas horas manipulando as limitadas cadeias de caractere da linguagem C. Tive que contorná-las, mas não foram tão problemáticas assim.
- Com algoritmo construído de antemão, a parte de programação demorou apenas ao perceber alguns erros de digitação e implementar algumas funções auxiliares, comparado com o exercício de ponteiros este foi extremamente rápido.

8. [**008-ordenacao.c**](_008-ordenacao.c_).

Programa: **ORDENAÇÕES**. [Algoritmo](008-algoritmo.txt). Exercício composto por geração de valores inteiros aleatórios e a sua ordenação através de múltiplos métodos.
- Este exercício não impôs muitos desafios de programação ou lógica, mas sua prática custou bem mais tempo em algoritmo do que em implementação do código, provando que uma lógica bem trabalhada sempre facilita o trabalho na hora da criação do código.

9. [**009-listas.c**](009-listas.c).

Programa: **CADASTRO DE ASSOCIADOS**. Exercício que manipula uma lista encadeada de nós compostos por estruturas que abstraem registros de cadastro.
- Um exercício esclarecedor, com a manipulação de ponteiros para a criação de uma lista encadeada aprendi a utilização do _malloc()_, que faz a alocação de memória adequada ao tipo e fornece o endereço desse espaço na memória.
- Também entendi que _sizeof_ **não é uma função** e sim um operador que fornece o tamanho utilizado por tal variável, exemplo:

	elemento *lista;
	lista = malloc(sizeof (elemento));
	
Neste caso, _sizeof_ pega o tipo elemento como uma forma _casting_, e fornece o seu valor de espaço a _malloc()_. O operador poderia funcionar com a variável em si em vez do "_casting_":

  	elemento *lista;
	lista = malloc(sizeof *lista);

ou, também:

	int *i, x;
	i = malloc(sizeof x);

- Houve alguma complicação em operações de exclusão de nós, mas acho que consegui resolver sem que o resultado possa ser considerado uma gambiarra.
- A formatação de saída das strings no relatório teve uma boa aparência.
- A função _fgets()_ não foi adequada a este exercício, apesar dela ter vantagens em seu controle de entrada, a captura de _'\n'_ em suas strings cria uma complicação desnecessária, para a qual não achei um modo simples o suficiente para justificar seu uso.