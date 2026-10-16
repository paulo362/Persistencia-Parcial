#include "estruturas.hpp"

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