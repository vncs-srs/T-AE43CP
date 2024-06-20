# Problema do Cavalo no Xadrez

Este projeto implementa uma solução para o **Problema do Cavalo no Xadrez**, que consiste em encontrar o menor número de passos que um cavalo precisa para percorrer de um ponto inicial ate chegar a uma posição específica.

## Arquivos

- `cavaloBacktracking.c`: Contém a implementação do algoritmo de busca em largura (BFS) para encontrar a menor quantidade de passos.
- `main.c`: Arquivo principal que lê as entradas (tamanho do tabuleiro, posição inicial e posição final) e chama a função de busca.
- `entrada.txt`: E o arquivo de entrada de dados onde o programa.


## Compilação e Execução

Para compilar o projeto, você pode usar um compilador C (como o GCC). Execute os seguintes comandos:

```bash
gcc -o cavalo_xadrez main.c
```
Para executar o programa deve-se inserir as entradas de dados no arquivo `entrada.txt` no seguinte formato:
#### Entrada
  - Tamanho do tabuleiro (N).
  - Coordenadas da posição inicial (x0, y0).
  - Coordenadas da posição final (xf, yf).
###### Exemplo de Entrada
```bash 
8
2 2
7 7
```
  
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
Menor caminho encontrado (passos): 4
    0: 1: 2: 3: 4: 5: 6: 7: 
0:  0  0  0  0  0  0  0  0 
1:  0  0  0  0  0  0  0  0 
2:  0  0  0* 0  0  0  0  0 
3:  0  0  0  0  0  0  0  0 
4:  0  0  0  1  0  0  0  0 
5:  0  0  0  0  0  0  3  0 
6:  0  0  0  0  2  0  0  0 
7:  0  0  0  0  0  0  0  4 

```
## Metodos Usados para a Solução do Problema
Há a utilização do `Backtracing` para rastrear os caminhos validos em conjunto de uma implementa de `busca em largura` (BFS) para encontrar o menor quantidade de passos necessários para o cavalo chegar à posição final.

## Contribuição
- [Caetano Chinarelli](https://github.com/Axiom03)
- [Guilheme Marcante](https://github.com/GuilhermeMarcante)
- [Kelvyn Augusto](https://github.com/kelvynnonato)
- [Luiz Eduardo](https://github.com/LupizI)
- [Vinicius Soares](https://github.com/vncs-srs)

## Licença
Este projeto está sob a licença MIT.