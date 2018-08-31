# Análise dos Exercícios Extras 01

Esta seção tem o intuito de servir tanto como um índice para os exercícios, os descrevendo e listando, como uma área para registrar pensamentos e ideia despertadas pela execução dos mesmos.

## Exercícios

1. [**001-var.c**](001-var.c).
Exercício simples de manipulação de variáveis. 
- A pesquisa envolvida em seu estudo me ensinou sobre a função **_fgets()_** e sua capacidade de limitar a entrada de caracteres, de modo a ser um recurso seguro em determinadas situações de coleta de dados. 
- Outro aprendizado foi sobre a função **_system()_**, em minhas experiências anteriores com C ela apenas era utilizada para pausar o programa para a visualização (desta maneira _system("pause")_), porém ao analisá-la um pouco pude ver que ela é muito mais que isso, sendo uma interação direta com ambiente de execução pedindo recursos externos para fins internos. Saber disto é ter a noção que nem sempre utilizar tais recursos pode ser uma boa ideia, _system(pause)_ pede ao ambiente de execução que pause todas as suas ações, e isso não parece a melhor maneira de se realizar uma simples pausa em um programa procedural.