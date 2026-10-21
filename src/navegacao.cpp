#include "header/estruturas.hpp"

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

// função auxiliar para dado um certo nó, ou adicionar uma nova versão dele ou modifica-lo.
void modif(Node* n, Node* prox){
    // estouro e novo nó
    if(n->num_mods == 2){
        Node* new_node = new Node(n->chave, versao_atual);
        if(n->ponteiro_retorno == nullptr){
            versoes[versao_atual] = new_node;
        } else {
            modif(n->ponteiro_retorno, new_node);
            new_node->ponteiro_retorno = n->ponteiro_retorno;
        }

        new_node->prox = prox;
    } // 
    else{
        Modificacao mod(versao_atual, prox);
        n->mods[n->num_mods] = mod;
    }
}
