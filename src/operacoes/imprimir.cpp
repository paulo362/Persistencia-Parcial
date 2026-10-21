#include "../header/operacoes.hpp"
#include "../header/estruturas.hpp"
#include <iostream>

using namespace std;

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