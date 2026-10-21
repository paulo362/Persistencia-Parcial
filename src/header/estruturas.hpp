#ifndef ESTRUTURAS_HPP
#define ESTRUTURAS_HPP

struct Node;

struct Modificacao{
    int versao;
    Node* novo_prox;

    Modificacao(){}
    Modificacao(int v, Node * prox) 
        : versao(v), novo_prox(prox){}
};

struct Node{
    int chave;
    Node* prox;
    int versao; //versao em que foi criado

    int num_mods;
    Modificacao mods[2]; //p = 1 -> 2 modificacoes

    Node* ponteiro_retorno; //aponta para quem aponta para esse no

    //construtor
    Node(int chave, int versao, Node* prox = nullptr)
        : chave(chave), versao(versao), prox(prox), num_mods(0), ponteiro_retorno(nullptr) {}
};

//vetor com as raizes de cada versao
// --- a priori, nao criei um struct pra versao pq n sei quais outras informacoes a gente pode precisar
//     mas se tu achar que precisa, pode criar
extern int versao_atual;
extern Node* versoes[1001];

Node* ler_proximo(Node* no, int versao);
void modif(Node* n, Node* prox);

#endif