#include "header/operacoes.hpp"
#include "header/estruturas.hpp"

#include <iostream>
using namespace std;

int versao_atual = 0;
Node* versoes[1001] = {nullptr};

int main(){
    insercao(3);
    insercao(4);
    insercao(6);
    imprimir(versao_atual);
    return 0;
}