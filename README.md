# Estudo_C

Repositório de códigos de códigos realizados na prática do aprendizado, com intenção de absorver conceitos e utilizações de técnicas da linguagem C.

Códigos são separados em pastas Aulas e Extras, sendo as primeiras os conteúdos lecionados pelo curso de Linguagem C da UNITEN/Anhanguera, enquanto os últimos são experimentos frutos de pesquisas em livros, apostilas e páginas da internet.

## Matéria das Aulas

- [Conteúdo explicado nas aulas.](aulas/ConteudoAulas.md)

## Atividades

Uma simples descrição de progresso e visão sobre as atividades.

## Análises de Exercícios

[Lista geral de analise de exercícios.](menuAnalise.md)

### Dia 1 (28/08/2018)

- Repositório Criado.
- Arquivo de estudo _001-var.c_ criado.
- Criação do repositório e criação de um simples arquivo inicial de estudos, apesar dos conceitos simples envolvendo o conteúdo trabalhado, me vi surpreendido e impelido a pesquisas adicionais ao descobrir que comando trivialmente utilizados em estudos de minha antiga faculdade (_scanf()_ e _system("PAUSE")_), na verdade, eram contraindicados em situações na qual os utilizava corriqueiramente no passado.
- O maior tempo gasto foi descrição em comentários, porém isso se mostra proveitoso dado o auxílio à absorção do aprendizado, assim como para futuras consultas.

- Arquivo de estudo _002-type.c_ criado.
- Um bom exercício sobre os tipos e utilizações de bibliotecas, não é nada fácil manter na memória os limites e tamanhos dos tipos, mas, sem dúvidas, brincar com eles assim ajuda. **Warnings realmente me incomodam**, no primeiro programa consegui escapar deles, mas não tive a mesma "sorte" neste.

- Arquivo de estudo _003-oper_cond_loop.c_ criado.
- Exercício multitécnico idealizado inicialmente para a prática das operações matemáticas e estruturas condicionais, porém, novas ideias adicionaram o uso de estruturas de repetição e criação de funções.

### Dia 2 (29/08/2018)

- Término do arquivo _003-oper_cond_loop.c_. Vários erros pequenos (e warnings) no caminho, mas nada realmente prejudicial. Pesquisas neste exercício me colocaram a intensão investigar mais os padrões de codificação multiplataforma para C, até o momento não vi algo claro, mas terei mente, a partir de agora, a questão de disponibilidade de comandos em plataformas diferentes.

- Primeira aula sobre a linguagem C do curso. Explicações sobre o básico, como esperado, sobre comandos e algumas particularidades da linguagem. Foi uma aula extensa e totalmente expositiva, talvez tivesse mais efetividade ao abordar várias pequenas práticas, mesmo que alcançando menos conteúdo explicado. Observação de código já pronto também me parece pouco interessante, sendo uma alternativa melhor a criação durante a aula.
- Arquivo de estudo _Aula02-ex01-mensagem_ criado durante a aula. Exercício simples criado nos últimos minutos de aula para ilustrar a criação, compilação e execução de um programa.

### Dia 3 (30/08/2018)

- Arquivo de estudo _004-operandos.c_ criado.
- Um exercício idealizado para operações, mas que rapidamente me instigou a dar o melhor trato estético que atualmente sou capaz, gerando preocupações com posicionamentos e caracteres. Fiquei satisfeito com o desempenho da validação de entrada de dados, apesar de simples está com boas restrições de segurança.
- Pesquisas e comentários sobre comandos novos utilizados. Reparos de pequenos problemas. No geral, processo mais demorado que difícil.

- Arquivo de estudo _005-ponteiros.c_ criado.
- Este exercício era para ser simples, apenas passar ponteiros entre funções, mas a empolgação me levou e passei a escaloná-lo sucessivamente enquanto escrevia o código. Agora é mais como um protótipo de um jogo utilizando caracteres especiais que formam um labirinto pela tela. O código ainda não está refinado, mas está funcionando razoavelmente, **é realmente um resultado bonito de se ver**.

### Dia 4 (31/08/2018)

- Múltiplos pequenos ajustes no exercício de ponteiros, como o potencial do programa, é possível que eu o mantenha como objeto de estudo por mais alguns dias. Por enquanto é um simples jogo de sorte em um labirinto aleatória. Pretendo inserir uma tela inicial e sistema de fases com algum tipo pontuação.

- Uma aula com o primeiro programa efetivo da classe, um programa sobre variáveis, entrada e exibição de dados. Apesar de também ter sido excessivamente expositiva, teve algum tempo para a programação em si, talvez um programa mais simples tivesse sido mais efetivo para aqueles com menos experiência, mesmo com minha bagagem e pesquisa acabei me enrolando um pouco, mas reaprendi as limitações do _printf()_, ou seja, mais um motivo para ter cuidado ao utilizá-lo.

### Dia 5 (01/09/2018)

- Maiores modificações no exercício de ponteiros, agora intitulado **Labirinto Dimensional**, iniciei a modulação do código e separei claramente os módulos de execução através do controle de estados durante a execução do jogo. Ainda existem as fases e a pontuação a serem implementadas, além de ajustes na movimentação, mas o jogo já está com uma boa aparência.
- Pontuação e sistema de fases implementadas, é praticamente um incompleto jogo completo, falta polir bastante e otimizar o código (bastante), mas como parte do exercício farei apenas o suficiente para o seu propósito. Ao concluir irei criar um repositório apenas para este jogo, para aprimorá-lo futuramente.

### Dia 6 (02/09/2018)

- Múltiplos ajustes no exercício de ponteiros: limites, interface, pontuação e controle. Coisas simples, mas que fizeram uma boa diferença na UX. Já estou perto do ponto em que o programa pode ser considerado completo.
- Exercício implementado totalmente, para a conclusão faltam apenas o código comentado e a análise.

### Dia 7 (03/09/2018)

- O curso da UNITEN falhou comigo novamente, mais uma vez não tivemos aula e nem explicações sobre o ocorrido. Depois disso não tenho certeza da continuidade das aulas.

- Exercício _005-ponteiros.c_ completo, depois de cinco dias trabalhando neste exercício já é hora de seguir em frente. Foi um grande aprendizado, principalmente no aspecto central, ponteiros. Consegui utilizá-los à exaustão! Agora estou mais acostumado com eles.

### Dia 8 (04/09/2018)

- Arquivo de estudo _006-recursividade-fatorial.c_ criado.
- Exercício lógico de recursividade, foi bem rápido e preciso.

- Arquivo de estudo _007-strings-criptografia.c_ criado.
- Exercício um pouco ambicioso que cria uma chave de encriptação aleatória e faz substituições simples porém duplicando a quantidade de caracteres. A criptografia está funcionando, agora falta o processo reverso.

### Dia 9 (05/09/2018)

- Exercício _007-strings-criptografia.c_ completo, a descriptografia foi adicionada e a apresentação foi levemente melhorada. Um interessante exercício que exigiu bastante manipulação de strings.

### Dia 10 (06/09/2018)

- Arquivo de estudo _008-ordenacao.c_ criado.
- Exercício envolvendo mais lógica que programação, revendo métodos de ordenação e criando seus algoritmos e programas. Até agora foram implementadas as ordenações por _Bolha_, _Seleção_ e _Inserção_.

### Dia 11 (07/09/2018)

- Adicionado o método de ordenação Quick Sort ao exercício extra 08. Algoritmo criado e passado sem erros aparentes em C (pelo menos na versão do compilador por browser).

### Dia 12 (09/09/2018)

- Arquivo de estudo _009-listas.c_ criado.
- Exercício com listas e as funcionalidades necessárias para a sua utilização. Será um exercício simples, porém deve ter uma abrangência considerável para abordar os tópicos necessários.

- Exercício _008-ordenacao.c_ completo.

### Dia 13 (10/09/2018)

- Exercício _009-listas.c_ completo.
- Terminadas a funcionalidades, comentários e análises. Foi um exercício rápido, porém, muito educativo.

- Com a troca de instrutor, a aula de hoje se tornou reintrodutória mas, ainda assim, teve bastante prática e um ritmo acelerado.
- Abordados desde ideias e conceitos iniciais da programação à estruturas condicionais na linguagem C, uma boa aula.

### Dia 14 (11/09/2018)

- Arquivo de estudo _010-fila.c_ criado.
- Exercício mais simples que os anteriores, utilizando-se de uma lista encadeada para ilustrar a funcionalidade de uma fila. O programa recebe múltiplas frases e as armazena e uma fila, ao final do programa, ele as exibe pela ordem de entrada.

### Dia 15 (12/09/2018)

- Arquivo de estudo _011-pilha.c_ criado.
- Exercício simples envolto em erros que desejo evitar futuramente, a lista encadeada utilizada para representar uma pilha de números a serem exibidos ao final da execução do programa.

- Mais uma aula, a velocidade foi ainda mais impressionante, cinco exercícios realizados e solucionados em sala de forma plena, estou satisfeito com o progresso.

### Dia 16 (13/09/2018)

- Arquivo de estudo _012-lista-ordena.c_ criado.
- Exercício para reforçar o estudo de listas, utilizando em conjunto com ordenação.

### Dia 17 (14/09/2018)

- A 6ª aula do curso de linguagem C em um ritmo menos acelerado, mas com o tempo necessário para aqueles com dificuldade tirarem dúvidas.

### Dia 18 (15/09/2018)

- Pesquisa sobre operadores lógicos aconselhada na última aula, foi meio que uma visita ao passado relembrando aulas de lógica booleana.

### Dia 19 (16/09/2018)

- Realizadas as análises dos exercícios da aula 6.

### Dia 20 (17/09/2018)

- Diversos problemas com o exercício extra 12.

- Aula 7 do curso, uma aula resolvendo exercícios (e seus bugs).

### Dia 21 (18/09/2018)

- Recorri a pesquisa para conseguir superar meus problemas com o exercício extra 12, mas somente cheguei à conclusão que seria mais viável executar a ordenação de forma mais simples para poder realizá-la sem defeitos.
- Análises dos exercícios da aula 7.

### Dia 22 (19/09/2018)

- Em uma manhã sem muito tempo para programar, me concentrei no código das rotinas de navegação e menu principal. Na navegação fiz as ligações necessárias com a rotinas e funções que fazem as tarefas de alterar, inserir e excluir registros.
- No meio dos testes descobri que o processo de exclusão possui problemas, ele necessita que um registro seja excluído duas vezes para removê-lo da lista. Quando possível verificarei a rotina de exclusão (apesar dela aparentemente funcionar perfeitamente na função de ordenação) assim como a própria rotina de navegação.

- Aula com resolução de três exercícios, problemas com a lógica de um exercício atrasaram o progresso.
- Aprendi sobre um pouco sobre função exponencial natural, irei pesquisar mais para não ficar tão confuso ao me deparar novamente com isso no futuro.

### Dia 23 (20/09/2018)

- Apenas as análises dos exercícios da aula 8, dia cheio, mas não muito produtivo.

### Dia 24 (21/09/2018)

- Conclusão do exercício _012-lista-ordena.c_.
- Bastante tempo investido não remoção de todos os erros perseptíveis. Aparentemente está completo e livre de erros básicos.

- Aula 9 do curso, dois exercícios elaborados na hora.

### Dia 25 (22/09/2018)

- Organização dos arquivos da aula, e reprodução do exercício 2 que apenas foi feito pelo instrutor ao final da aula.

### Dia 26 (26/09/2018)

- Aula 10 do curso, um exercício da lista resolvido, pode parecer pouco, mas o tema justifica.

- Análises de exercícios das aulas 9 e 10.

### Dia 27 (28/09/2018)

- Aula 11 do curso, explicação sobre ponteiros e _switch_, um exercício e uma variação aplicando estes conceitos.

### Dia 28 (30/09/2018)

- Arquivo de estudo _013-arvore-binaria-1.c_ criado.
- Arquivo de estudo _014-merge-sort.c_ criado.

- Exercícios interessantes, achei que teria mais dificuldade, mas os únicos contratempos vieram de pequenos erros lógicos.

### Dia 29 (01/09/2018)

- Aula 12 do curso, muitos e muitos exercícios, esta foi uma aula em que avançamos muito na lista.