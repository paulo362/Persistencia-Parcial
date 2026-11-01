# Estruturas de Dados Avançadas - Trabalho 01
## Lista Encadeada Ordenada com Persistência Parcial

## Equipe
Paulo Eduardo Conrado Marinho (matrícula 567585) e Eric Rodrigues Gomes (matrícula 564971)

## Descrição
- **Linguagem de programação utilizada:** C++
- **Estruturas:**
  - **Node:**
    - Definida em `src/header/estruturas.hpp`
    - Estrutura do nó é `struct Node`
    - Guarda as informações de um nó da lista encadeada ordenada persistente
    - O campo `chave` corresponde ao valor atribuído àquele nó. Serve para determinar sua posição na lista
    - O campo `Node* prox` corresponde ao elemento cujo nó atual aponta (ponteiro para o próximo na lista)
    - O vetor `Modificacao mods[2]` guarda as modificações aplicadas naquele nó
    - O campo `Node* ponteiro_retorno` é o ponteiro para o elemento que aponta para o nó atual. Serve para "propagar" as modificações uma vez que o vetor `mods` está cheio
  
  - **Modificacao:**
    - Definida em `src/header/estruturas.hpp`
    - Estrutura da modificação é `struct Modificacao`
    - Guarda as informações necessárias para se aplicar uma modificação
    - O campo `versao` corresponde à versão em que aquela modificação foi aplicada
    - O campo `Node* novo_prox` corresponde ao novo elemento que aquele nó aponta em versões >= `versao`
    
  - **Node\* versoes[1001]:**
    - Guarda as raízes (primeiro elemento da lista) de cada versão
    
 - **Funções Auxiliares:**
    - Node\* ler_proximo:
      - Implementada em `src/navegacao.cpp`
      - Busca o elemento apontado por um dado nó considerando, nas modificações, aquela que tem maior versão que seja menor ou igual à procurada
    - Node\* modif:
      - Implementada em `src/navegacao.cpp`
      - Função recursiva que propaga as modificações em um dado nó
      - Se o número de modificações for igual a 2, cria uma cópia. As modificações são realizadas por meio da chamada recursiva no nó que apontava para o original. Assim, o ponteiro de retorno aponta para ele (ou para uma cópia, se necessário) e ele (ou a cópia) aponta para o novo nó criado
      
- **Operações:**
  - **Impressão:** Acessa a raíz daquela versão com o vetor `versoes` e percorre (com a função auxiliar `ler_proximo`) até chegar no fim da fila (elemento nullptr)
  - **Sucessor:** Semelhante à impressão, a diferença sendo a que imprime apenas o primeiro elemento com chave maior que a informada. Se não achar, imprime "inf"
  - **Inserção:** Percorre a lista até achar a posição correta para inserir o nó (primeiro elemento com chave maior ou igual à informada). Se a inserção for no começo, o novo nó vira a raíz daquela versão, bastando atualizar o próximo dele e o ponteiro de retorno do elemento que antes era a raíz. Se for no meio ou no fim, chama modif no nó anterior, que deve apontar para o que será inserido
  - **Remoção:** Percorre a lista para achar o elemento a ser removido. Se achar e foi a raíz daquela versão, a raíz vira o próximo do que será removido. Se tiver no meio, tem que chamar modif no anterior, que deve agora apontar para o próximo do removido
  

## Usando o Programa
O programa foi feito para sistemas Linux. Para rodar, basta utilizar o comando
```
make run INPUT=testes/testeX.in > saida.out
```
Para comparar com a saída esperada, basta fazer
```
diff saida.out testes/testeX.out > dif.txt
```