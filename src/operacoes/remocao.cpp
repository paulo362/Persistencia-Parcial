#include "../header/operacoes.hpp"
#include "../header/estruturas.hpp"

void remocao(int chave){
    versoes[versao_atual + 1] = versoes[versao_atual];
    
    //achar onde vai remover
    Node* atual = versoes[versao_atual];
    Node* anterior = nullptr;
    while(atual != nullptr){
        if(atual->chave >= chave) break;
        anterior = atual;
        atual = ler_proximo(atual, versao_atual);
    }

    versao_atual++;
    
    // nada a ser removido
    if(atual == nullptr || atual->chave > chave)
        return;

    if(anterior == nullptr){ //remover o comeco
        Node* nova_raiz = ler_proximo(atual, versao_atual);
        if(nova_raiz != nullptr) nova_raiz->ponteiro_retorno = nullptr;
        versoes[versao_atual] = nova_raiz;
    }
    else{ //remover do meio
        Node* proximo = ler_proximo(atual, versao_atual);
        Node* novo_anterior = modif(anterior, proximo);
        if(proximo != nullptr)
            proximo->ponteiro_retorno = novo_anterior;
    }
}