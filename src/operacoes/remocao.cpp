#include "../header/operacoes.hpp"
#include "../header/estruturas.hpp"

void remocao(int chave){
    //achar onde vai remover
    Node* atual = versoes[versao_atual];
    Node* anterior = nullptr;
    while(atual != nullptr){
        if(atual->chave >= chave) break;
        anterior = atual;
        atual = ler_proximo(atual, versao_atual);
    }

    // nada a ser removido
    versao_atual++;
    if(atual == nullptr || atual->chave > chave)
        return;

    if(anterior == nullptr){
        versoes[versao_atual] = ler_proximo(atual, versao_atual);
        atual->ponteiro_retorno = nullptr;
    }
    else{
        Node* proximo = ler_proximo(atual, versao_atual);
        modif(anterior, proximo);
        proximo->ponteiro_retorno = anterior;
    }
}