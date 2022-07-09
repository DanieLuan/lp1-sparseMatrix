# Matriz Esparsa

[Daniel Luan Lourenço de Lima](https://github.com/DanieLuan)

O objetivo desse projeto é criar uma implementação do TAD "Matriz Esparsa".

### Como compilar

Como foi feita uma implementação, foram criados algumas funções para demonstrar o funcionamento.
Esse passo-a-passo é para sistemas **unix-like**, portanto certifique-se de estar em um ambiente apropriado para executar os passos seguintes.
A forma mais fácil de executar os testes é compilando utilizando **Makefile**, porém é opcional. Lembrando que é necessário um compilador C/C++.

#### Com Makefile

1. Para executar os testes, na página principal do repositório, basta executar o comando
```
make all
```
e os testes iniciarão automaticamente.

#### Sem Makefile
1. Primeiramente, crie vergonha e instale o Makefile na sua máquina;
2. Já que insiste...
3. Você pode compilar os arquivos necessários utilizando esse comando no diretório principal do repositório;
```
g++ -Wall -o main src/main.cpp src/matrixEsp.cpp test/tests.cpp
```
4. Agora basta abrir o arquivo executável. Nesse caso, ele se chama `main`, então basta fazer;
```
./main
```

