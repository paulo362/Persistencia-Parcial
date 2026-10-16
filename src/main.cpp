#include <iostream>
#include <algorithm>
using namespace std;

struct Node;

struct Modificacao{
    int versao;
    Node* novo_prox;
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
int versao_atual = 0;
Node* versoes[1001];

//funcao auxiliar para dado um no buscar o sucessor em uma versao
Node* ler_proximo(Node* no, int versao){
    //tem que ver nas modificacoes que tenham versao <= v e pegar a maior entre elas
    Node* resultado = no->prox;
    int maior_versao = -1;

    for(int i = 0 ; i < no->num_mods ; i++){
        int v_atual = no->mods[i].versao;
        if(v_atual <= versao && v_atual > maior_versao){
            resultado = no->mods[i].novo_prox;
            maior_versao = v_atual;
        }
    }
    return resultado;
}

void sucessor(int n, int versao){
    //como se trata de uma lista ordenada, basta ver o primeiro elemento que tem chave > n
    Node* raiz = versoes[versao];
    while(raiz != nullptr){
        if(raiz->chave > n){
            cout << raiz->chave << endl;
            return ;
        }
        raiz = ler_proximo(raiz, versao);
    }
    cout << "inf" << endl;
}

void imprimir(int versao){
    versao = min(versao, versao_atual); //se a versao nao existir pega a atual
    Node *raiz = versoes[versao];
    if(raiz == nullptr){
        cout << endl;
        return ;
    }
    while(true){
        cout << raiz->chave;
        raiz = ler_proximo(raiz, versao);
        if(raiz == nullptr){
            cout << endl;
            break;
        }
        else cout << ", ";
    }
}

int main(){
    Node* n1 = new Node(30, 0, nullptr);
    Node* n2 = new Node(10, 0, n1);
    versoes[0] = n2;

    //simulando insercao de um no com valor 20
    Node* n3 = new Node(20, 1, n1);
    n2->mods[0] = {1, n3};
    n2->num_mods++;
    versoes[1] = n2;
    versao_atual++;

    //inserir no com valor 5
    Node* n4 = new Node(5, 2, n2);
    versoes[2] = n4;
    versao_atual++;

    cout << "IMP 0: ";
    imprimir(0);
    cout << "IMP 1: ";
    imprimir(1);
    cout << "IMP 2: ";
    imprimir(2);

    cout << endl;
    cout << "SUC 15 0: ";
    sucessor(15, 0);
    cout << "SUC 15 1: ";
    sucessor(15, 1);
    cout << "SUC 15 2: ";
    sucessor(15, 2);
    cout << "SUC 40 2: ";
    sucessor(40, 2);
    return 0;
}