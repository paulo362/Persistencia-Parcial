#include "header/operacoes.hpp"
#include "header/estruturas.hpp"

#include <iostream>
using namespace std;

int versao_atual = 0;
Node* versoes[1001] = {nullptr};

int main(){
    string op;
    while(cin >> op){
        if(op == "INC"){
            int chave; cin >> chave;
            insercao(chave);
        }
        else if(op == "REM"){
            int chave; cin >> chave;
            remocao(chave);
        }
        else if(op == "SUC"){
            int chave, versao; cin >> chave >> versao;
            sucessor(chave, versao);
        }
        else if(op == "IMP"){
            int versao; cin >> versao;
            imprimir(versao);
        }
    }
    return 0;
}