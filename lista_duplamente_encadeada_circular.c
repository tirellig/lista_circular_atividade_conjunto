#include "lista_duplamente_encadeada_circular.h"

// Tarefa 1: Criar lista
Lista* criar_lista() {
    Lista *li = (Lista *) malloc(sizeof(Lista));
    if (li != NULL) {
        *li = NULL; // Inicializa a lista como vazia
    }
    return li;
}

int inserir_transacao_inicio(Lista *li, Transacao t) {
    if (li == NULL) return 0;
    
    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
    if (novo == NULL) return 0; // Proteção contra falha de memória
    
    novo->dados = t;
    if (*li == NULL){
        novo->ant   = novo;
        novo->prox  = novo;
    }
    else {
        Elemento *primeiro = *li;
        Elemento *ultimo = primeiro->ant;

        // 1. O "novo" entra no encadeamento
        novo->prox  = primeiro;
        novo->ant   = ultimo;

        // 2. Os vizinhos juntam-se ao "novo"
        primeiro->ant = novo;
        ultimo->prox = novo;
    }
    *li = novo;     // Cabeçalho atualiza para o novo

    return 1;
}

int inserir_transacao_final(Lista *li, Transacao t) {
    if(li == NULL) return 0;

    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
    if(novo == NULL) return 0;

    novo->dados = t;
    if(*li == NULL){
        novo->ant = novo;
        novo->prox = novo;
        *li = novo;
    } else{
    Elemento *primeiro = *li;
    Elemento *ultimo = primeiro->ant;

    novo->prox = primeiro;
    novo->ant = ultimo;

    primeiro->ant = novo;
    ultimo->prox = novo;
    }

    return 1;
}

int inserir_transacao_ordenado(Lista *li, Transacao t) {

    return 1;
}

// Tarefa 5: Remover por ID
int remover_transacao_id(Lista *li, int id_busca) {
    if (li == NULL || *li == NULL) return 0; // Lista não existe ou vazia
    
    Elemento *anterior = NULL;
    Elemento *atual = *li;

    // Busca pelo elemento
    while (atual != NULL && atual->dados.id != id_busca) {
        anterior    = atual;
        atual       = atual->prox;
    }
    
    if (atual == NULL) return 0; // Elemento não encontrado ou lista vazia
    
    // O elemento a ser removido é o primeiro da lista
    if (anterior == NULL) {
        // trata tanto a lista com um único elemento (vai ficar vazia) 
        *li = atual->prox; // vai ficar NULL se atual for o único
    } else {
        // O elemento a ser removido está no meio ou no fim
        anterior->prox = atual->prox;
    }
    
    free(atual); // Libera a memória do nó removido
    return 1;
}

int remover_transacao_inicio(Lista *li) {

    return 1;
}

int remover_transacao_final(Lista *li) {

    return 1;
}

int troca(Lista *li, int id_busca) {
    // Se a lista não existir, for vazia, ou tiver só 1 elemento, não faz nada
    if (li == NULL || *li == NULL || (*li)->prox == *li) return 0;
    
    Elemento *atual = *li;
    
    // Percorre até o final: usa do-while para garantir que ele entra pelo menos uma vez
    do {
        if (atual->dados.id == id_busca)
            break;
        atual = atual->prox;
    } while (atual != *li && atual->dados.id != id_busca);

    if (atual->dados.id != id_busca) return 0; // id não encontrado

    // 1. Identificando os 4 "Atores" da troca
    Elemento *proximo               = atual->prox;
    Elemento *anterior              = atual->ant;
    Elemento *proximo_do_proximo    = proximo->prox;

    //============================================
    //============================================

    // Conexões entre anterior e proximo
    anterior->prox  = proximo;
    proximo->ant    = anterior;

    // Conexões entre proximo e atual (eles trocam de lugar)
    proximo->prox   = atual;
    atual->ant      = proximo;

    // Conexões entre atual e proximo_do_proximo
    atual->prox             = proximo_do_proximo;
    proximo_do_proximo->ant = atual;

    //============================================
    //============================================

    // Ajuste do Cabeçalho (*li)
    // 1. E se o elemento buscado for o primeiro?
    if (atual == *li) {
        *li = proximo;
    }   
    // 2. E se o elemento buscado for o último?
    else if (proximo == *li) { //Usa proximo em vez de atual, e else if pra evitar comparação errada
        *li = atual;
    }

    return 1;
}

int troca_inversa(Lista *li, int id_busca) {

    return 1;
}

// --- Funções Auxiliares ---
void imprimir_lista(Lista *li) {
    if (li == NULL || *li == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    Elemento *atual = *li;
    Elemento *ultimo = (*li)->ant;

    printf("... [ID: %d | Valor: R$ %.2f] <-> ", ultimo->dados.id, ultimo->dados.valor);
    do {
        printf("[ID: %d | Valor: R$ %.2f] <-> ", atual->dados.id, atual->dados.valor);
        atual = atual->prox;
    } while (atual != *li);
    printf("[ID: %d | Valor: R$ %.2f] ...\n", (*li)->dados.id, (*li)->dados.valor);
}

int imprimir_lista_inversa(Lista *li){
    if (li == NULL || *li == NULL) {
        printf("Lista vazia.\n");
        return 0;
    }

    Elemento* referencia = (*li)->ant;

    while (referencia!=*li){
        printf("[ID: %d | Valor: R$ %.2f] \n", referencia->dados.id, referencia->dados.valor);
        referencia = referencia->ant;
    }

    return 1;
}

void liberar_lista(Lista *li) {
    if (li == NULL || *li == NULL) return;

    Elemento *atual = *li;

    while (atual != NULL) {
        free(atual);
        atual = atual->prox;
    }
    *li = NULL;
    free(li);
}