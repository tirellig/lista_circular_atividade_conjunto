[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/unRkVsub)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=23893716)

# Atividade Prática: Troca de Nós em Lista Duplamente Encadeada Circular

## 🎯 Objetivo da Atividade

Desenvolver a lógica de manipulação de ponteiros em estruturas complexas, focando em:

* **Listas Duplamente Encadeadas:** Manipulação simultânea dos ponteiros `ant` e `prox`.
* **Listas Circulares:** Manutenção da propriedade onde o último nó aponta para o primeiro e vice-versa.
* **Lógica de Troca (Swap):** Reposicionamento de nós na memória sem a alteração dos valores contidos neles.

## 🏦 Contexto

Em muitas estruturas de dados, a eficiência é garantida pela movimentação de endereços de memória em vez da cópia de grandes volumes de dados. Nesta atividade, você deve implementar uma função que localiza o `id` em uma lista circular duplamente encadeada e o troca de posição com o seu sucessor (o elemento posterior).

## Estruturas e Inicialização

No arquivo `lista_duplamente_encadeada_circular.h`, defina a seguinte estrutura e o tipo da lista:

```c
typedef struct {
    int id;
    float valor;
} Transacao;

typedef struct Elemento {
    struct Elemento *ant;
    Transacao dados;
    struct Elemento *prox;
} Elemento;

typedef Elemento* Lista;

int troca(Lista* li, int id_busca); 
```

onde,
	
  `li`: é o ponteiro para a primeira posição da lista
	
  `id_busca`: é um id inteiro armazenado na lista

Considerando que `id` exista na lista, a função deverá trocar de posição esse elemento com o elemento posterior, como mostra a figura abaixo.

![Troca](ilustracao_troca.png)

## ✅ Critérios de Aceitação e Avaliação

Para que a atividade seja considerada correta, os seguintes pontos serão avaliados:

| Critério | Descrição |
| --- | --- |
| **Integridade da Lista** | A lista deve permanecer circular e duplamente encadeada após qualquer troca.|
| **Manipulação de Ponteiros** | É estritamente proibido trocar os valores (`id`) dos nós. A troca deve ser apenas de ponteiros.|
| **Tratamento de Cabeçalho** | Se o elemento `id` for o primeiro da lista (`*li`), o ponteiro de início deve ser atualizado corretamente.|
| **Caso Especial (Último)** | Se `id` for o último elemento, ele deve trocar de posição com o primeiro (comportamento circular).|
| **Estabilidade** | O código deve tratar listas com apenas 1 ou 2 elementos sem causar erros de memória. |

## 🧪 **Instruções de compilação**

Use um dos comandos abaixo:

    gcc -o main *.c

ou

    gcc -o main lista_duplamente_encadeada_circular.c main.c

Depois execute:

    ./lista

## 🧪 Sugestão de Teste (Arquivo Principal)

Seu arquivo `main.c` pode demonstrar a funcionalidade através dos seguintes passos:

2. Criar uma lista com pelo menos 5 elementos (ex: `9, 19, 27, 14, 6`).
3. Chamar a função `troca(li, 27)` e verificar se a ordem resultou em `9, 19, 14, 27, 6`.
4. Chamar a função `troca` passando o valor que está no final da lista para verificar a troca circular com o primeiro.
5. Chamar a função `troca` passando o valor que está no início da lista para verificar a consistência do cabeçalho.
6. Chamar a função `troca` considerando a lista vazia.
7. Chamar a função `troca` considerando a lista com apenas um elemento.
8. Chamar a função `troca` considerando a lista com dois elementos.
9. Exibir a lista (nos dois sentidos: usando `prox` e `ant`) para validar o encadeamento duplo.

## 📝 Observações Finais

* Certifique-se de que nenhum ponteiro fique órfão durante a troca.
* Lembre-se: em uma lista circular de dois elementos, o sucessor do primeiro é o último, e o sucessor do último é o primeiro. Além disso, o antecessor do primeiro é último, e o antecessor do último é primeiro.
* Imprima outputs claros que evidenciem a troca feita.
* Comente as principais partes do código para facilitar entendimento e correção.
