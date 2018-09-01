# Estudo_C

Repositório de códigos de códigos realizados na prática do aprendizado, com intenção de absorver conceitos e utilizações de técnicas da linguagem C.

Códigos são separados em pastas Aulas e Extras, sendo as primeiras os conteúdos lecionados pelo curso de Linguagem C da UNITEN/Anhanguera, enquanto os últimos são experimentos frutos de pesquisas em livros, apostilas e páginas da internet.

## Matéria das Aulas

- [Conteúdo explicado nas aulas.](aulas/ConteudoAulas.md)

## Atividades

Uma simples descrição de progresso e visão sobre as atividades.

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