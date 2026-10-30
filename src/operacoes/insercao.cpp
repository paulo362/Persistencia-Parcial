#include "../header/operacoes.hpp"
#include "../header/estruturas.hpp"

void insercao(int chave){
    versoes[versao_atual + 1] = versoes[versao_atual];
    
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
    if(anterior == nullptr){ //inserir no comeco
        versoes[versao_atual] = no;
        no->prox = atual;
        if(atual != nullptr){
            atual->ponteiro_retorno = no;
        }
    }
    else if (atual == nullptr){ //inserir no final
        no->ponteiro_retorno = modif(anterior, no);
    }
    else { //inserir no meio
        no->prox = atual;
        atual->ponteiro_retorno = no;
        no->ponteiro_retorno = modif(anterior, no);
    }
}