#include "estruturas.hpp"
#include "operacoes/imprimir.hpp"
#include "operacoes/sucessor.hpp"
#include <iostream>
using namespace std;

int versao_atual = 0;
Node* versoes[1001] = {nullptr};

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