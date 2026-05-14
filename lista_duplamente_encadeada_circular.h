
#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <stdio.h>
#include <stdlib.h>

// Definição das Estruturas
typedef struct {
    int id;
    float valor;
} Transacao;

typedef struct Elemento {
    struct Elemento *ant;
    Transacao dados;
    struct Elemento *prox;
} Elemento;

// Ponteiro para o primeiro elemento da lista
typedef Elemento* Lista;

// Protótipos das funções obrigatórias
Lista* criar_lista();
int inserir_transacao_inicio(Lista *li, Transacao t);
int inserir_transacao_final(Lista *li, Transacao t);
int inserir_transacao_ordenado(Lista *li, Transacao t);
int remover_transacao_id(Lista *li, int id_busca);
int remover_transacao_inicio(Lista *li);
int remover_transacao_final(Lista *li);
int troca(Lista* li, int id_busca);
int troca_inversa(Lista* li, int id_busca);

// Funções auxiliares (recomendadas para visualização e limpeza)
void imprimir_lista(Lista *li);
void imprimir_lista_inversa(Lista *li);
void liberar_lista(Lista *li);

#endif