#include "../header/sucessor.hpp"
#include "../estruturas.hpp"
#include <iostream>

using namespace std;

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