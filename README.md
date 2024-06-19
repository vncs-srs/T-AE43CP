# Problema do Cavalo no Xadrez

Este projeto implementa uma solução para o **Problema do Cavalo no Xadrez**, que consiste em encontrar o menor número de passos que um cavalo precisa para percorrer de um ponto inicial ate chegar a uma posição específica.

## Arquivos

- `cavaloBacktracking.c`: Contém a implementação do algoritmo de busca em largura (BFS) para encontrar a menor quantidade de passos.
- `main.c`: Arquivo principal que lê as entradas (tamanho do tabuleiro, posição inicial e posição final) e chama a função de busca.
- `entrada.txt`: E o arquivo de entrada de dados onde o programa.


## Compilação e Execução

Para compilar o projeto, você pode usar um compilador C (como o GCC). Execute os seguintes comandos:

```bash
gcc -o cavalo_xadrez cavaloBacktracking.h cavaloBacktracking.c main.c
```
Para executar o programa deve-se inserir as entradas de dados no arquivo `entrada.txt` no seguinte formato:
#### Entrada
  - Tamanho do tabuleiro (N).
  - Coordenadas da posição inicial (x0, y0).
  - Coordenadas da posição final (xf, yf).
  
Em seguida executar o comando:
```bash 
./cavalo_xadrez < entrada.txt
```
#### Saída
- Se for possível alcançar a posição final a partir da posição inicial, o programa exibirá a quantidade mínima de passos e a matriz de passos atualizada.
- Caso contrário, informará que não é possível alcançar a posição final.
##### Exemplo de Uso
```bash
$ ./cavalo_xadrez < entrada.txt
8
2 2
7 7
Quantidade mínima de passos: 6
 0  3  2  3  2  3  4  5
 3  4  1  2  3  4  3  4
 2  1  4  3  2  3  4  5
 3  2  3  2  3  4  3  4
 2  3  2  3  4  3  4  5
 3  4  3  4  3  4  5  4
 4  3  4  3  4  5  4  5
 5  4  5  4  5  4  5  6

```
## Metodos Usados Para a solução do Problema
Há a utilização do `Backtracing` para rastrear os caminhos validos em conjunto de uma implementa de `busca em largura` (BFS) para encontrar a menor quantidade de passos necessários para o cavalo chegar à posição final.

## Contribuição
- [Caetano Chinarelli](https://github.com/Axiom03)
- [Guilheme Marcante](https://github.com/GuilhermeMarcante)
- [Kelvyn Augusto](https://github.com/kelvynnonato)
- [Luiz Eduardo](https://github.com/LupizI)
- [Vinicius Soares](https://github.com/vncs-srs)

## Licença
Este projeto está sob a licença MIT.