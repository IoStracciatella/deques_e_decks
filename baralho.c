#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include "baralho.h"

//Cria um novo baralho com uma dada quantidade de cartas
void novoBaralho (baralho *b, int qtde) {
    int i;
    for (i = 1; i <= qtde; i++) {
        push_front(i, b);
    }
}

//Faz todas as cartas acima de x irem para o fundo baralho
void corta (baralho *b, int x) {
    node *carta = *b;

    int qtde_cartas = 0;
    //Vai até o fim do baralho
    while (carta->prox != NULL) {
        carta = carta->prox;
        qtde_cartas++;
    }

    x = qtde_cartas - x;
    int contador = 0;
    while (contador <= x) {
        push_back(carta->valor, b);
        pop_front(b);
        contador++;

        carta = carta->ant;
    }
}

//Inverte a ordem de todas as cartas
void vira (baralho *b) {
    node *atual = *b;
    int qtde_cartas = 1, aux;
    while (atual->prox != NULL) {
        atual = atual->prox;
        qtde_cartas++;
    }

    aux = qtde_cartas;

    while (qtde_cartas > 0) {
        push_front(atual->valor, b);
        atual = atual->ant;
        qtde_cartas--;
    }

    qtde_cartas = aux;

    while (qtde_cartas > 0) {
        pop_back(b);
        qtde_cartas--;
    }
}

//Mostra todas as cartas do baralho. Do topo ao fundo
void mostra (baralho baralho) {
    node *atual = baralho;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->ant;
    }
}