#include "../header/operacoes.hpp"
#include "../header/estruturas.hpp"

void insercao(int chave){
    //achar onde vai inserir
    Node* atual = versoes[versao_atual];
    Node* anterior = nullptr;
    while(atual != nullptr){
        if(atual->chave >= chave) break;
        anterior = atual;
        atual = ler_proximo(atual, versao_atual);
    }

    versao_atual++;
    Node* no = new Node(chave, versao_atual);
    if(anterior == nullptr){
        versoes[versao_atual] = no;
        no->prox = atual;
        if(atual != nullptr){
            atual->ponteiro_retorno = no;
        }
    }
    else if (atual == nullptr){
        modif(anterior, no);
        no->ponteiro_retorno = anterior;
    }
    else {
        no->prox = atual;
        atual->ponteiro_retorno = no;
        modif(anterior, no);
        no->ponteiro_retorno = anterior;
    }
}