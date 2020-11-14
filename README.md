# Compilador LiliTo
Desenvolvimento de um compilador em C++ para a gramática abaixo: 
<img alt="Gramática da linguagem" src="github/gramatica.png" />

## Analisador Léxico - Parte 1

Para o analisador Léxico, escolheu-se utilizar a modelagem por estado, na qual desenvolveu-se uma árvore de derivação que para a leitura de cada caracter, informa qual seria o próximo estado, ou se encontrou um token ou alguma espécie de erro.

Devido ao tamanho da gramático, a árvore ficou enorme, inviável de anexá-la aqui, por isso anexamos o exemplo de apenas uma parte e, caso tenham interesse, podem acessar integralmente através do [link do Drawio](https://drive.google.com/file/d/13-J8tpEmDeckLj1NGf_um_Rm7pPuR3NM/view?usp=sharing) e fazer comentários, para que o desenvolvimento seja contínuo.

### Compilação

Para compilar, basta ter o g++ instalado e executar o comando g++ main.cpp -o lilito. Isso irá gerar um executável na qual poderá utilizar para executar o compilador desenvolvido.

<img alt="Compilando o compilador" src="github/compilando.png" />

### Execução

O compilador desenvolvido, recebe como parâmetro o caminho do arquivo que se deseja compilar. Para isso, basta executar o comando: ./lilito caminho_do_programa. No exemplo abaixo, estamos analisando o arquivo que está dentro do diretório códigos e que possui o nome teste1, que corresponde ao código fornecido no enunciado do trabalho, disponível em:

<img alt="Executando o compilador Lilito" src="github/executando.png" />
