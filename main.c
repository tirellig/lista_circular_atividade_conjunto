
#include "lista_duplamente_encadeada_circular.h"

int main() {
    // 1. Chame a inicialização da lista
    Lista *li = criar_lista();

    // 1. Inserir elementos no início
    Transacao transacao1, transacao2, transacao3, transacao4, transacao5;
    transacao1.id = 6; transacao1.valor = 100;
    inserir_transacao_inicio(li, transacao1);

    transacao2.id = 14; transacao2.valor = 200;
    inserir_transacao_inicio(li, transacao2);

    transacao3.id = 27; transacao3.valor = 300;
    inserir_transacao_inicio(li, transacao3);

    transacao4.id = 19; transacao4.valor = 400;
    inserir_transacao_inicio(li, transacao4);

    transacao5.id = 9; transacao5.valor = 500;
    inserir_transacao_inicio(li, transacao5);

    imprimir_lista(li);
    /*
    // 2. Trocar elementos
    if (troca(li, 27)){
        printf("\nTroca bem sucedida! \n");
        imprimir_lista(li);
    } else {
        printf("\nErro na troca! \n");
    }
    */
    // 3. E se o elemento buscado for o primeiro ou o ultimo? (Victor)
    if (troca(li, 9)){ //primeiro elemento
        printf("\nTroca bem sucedida! \n");
        imprimir_lista(li);
    } else {
        printf("\nErro na troca! \n");
    }     

    if (troca(li, 6)){ //ultimo elemento
        printf("\nTroca bem sucedida! \n");
        imprimir_lista(li);
    } else {
        printf("\nErro na troca! \n");
    }
    /*
    // 4. Removendo uma transação por id (Sabrinna)
    int id_alvo = 27;
    if (remover_transacao_id(li, id_alvo)){
        printf("\n--- Apos remover o (ID %d) ---\n", id_alvo);
        imprimir_lista(li);
    } else {
        printf("\nErro na remoçao! \n");
    }


    // 5. Removendo a primeira transação (Pedro)
    if (remover_transacao_inicio(li)){
        printf("\n--- Apos remover a primeira transacao ---\n");
        imprimir_lista(li);
    } else {
        printf("\nErro na remoçao! \n");
    }

    // 6. Removendo a ultima transação (Miguel)
    if (remover_transacao_inicio(li)){
        printf("\n--- Apos remover a ultima transacao ---\n");
        imprimir_lista(li);
    } else {
        printf("\nErro na remoçao! \n");
    }    

    // 7. Inserindo uma transacao no final da lista (Amanda)
    Transacao transacao6;
    transacao6.id = 9; transacao6.valor = 600;
    if (inserir_transacao_final(li, transacao6)){
        printf("\n--- Apos inserir uma transacao no final ---\n");
        imprimir_lista(li);
    } else {
        printf("\nErro na remoçao! \n");
    } 
    
    // 8. Inserindo uma transacao no meio (ordenado) (Rafael)
    Transacao transacao7;
    transacao7.id = 15; transacao6.valor = 700;
    if (inserir_transacao_final(li, transacao7)){
        printf("\n--- Apos inserir uma transacao ordenado ---\n");
        imprimir_lista(li);
    } else {
        printf("\nErro na remoçao! \n");
    }   

    // 9. Trocar inversa de elementos (Arthur)
    if (troca_inversa(li, 27)){
        printf("\nTroca bem sucedida! \n");
        imprimir_lista(li);
    } else {
        printf("\nErro na troca! \n");
    }

    // 10. Imprime lista inversa (Gabriel)
    printf("\n--- Lista Inversa --- \n");
    imprimir_lista_inversa(li);

    // 11. Libere toda a memória restante (Wendell)
    liberar_lista(li);
    li = NULL;

    printf("\n[ Programa finalizado e memoria liberada com sucesso. ]\n");
    
    return 0; // Verifica se o programa retorna 0 com sucesso (sem crash).

*/
    return 0;
}