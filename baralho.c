#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include "baralho.h"

//Cria um novo baralho com uma dada quantidade de cartas
void novoBaralho (baralho *b, int qtde) {
    //Liberando a memória de todos os nodes caso já exista um baralho criado
    if (*b != NULL) {
        node *atual = *b, *aux;

        while (atual != NULL) {
            aux = atual->prox;
            free(atual);
            atual = aux;
        }
        
        *b = NULL;
    }

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

//Coloca a carta selecionada no topo do baralho
void sobe (baralho *b, int x) {
    node *atual = *b;
    int cont = 1;
    while (cont < x) {
        atual = atual->prox;
        cont++;
    }

    push_front(atual->valor, b);

    node *atual1, *atual2;
    atual1 = atual->ant;
    atual2 = atual->prox;

    atual1->prox = atual2;
    atual2->ant = atual1;

    free(atual);
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

//Inverte a ordem de todas as cartas acima de uma tal carta
void viraTopo (baralho *b, int k) {
    node *inicio = *b;
    node *fim = *b;
    int total = 1, aux;

    //Leva "inicio" até a carta escolhida
    int i;
    for (i = 0; i < k; i++) {
        inicio = inicio->prox;
    }

    //Leva "fim" até a o final do baralho e conta quantas cartas tem
    while (fim->prox != NULL) {
        fim = fim->prox;
        total++;
    }

    total = total/2;
    for (i = 0; i < total; i++) {
        aux = fim->valor;
        fim->valor = inicio->valor;
        inicio->valor = aux;

        inicio = inicio->prox;
        fim = fim->ant;
    }
}

void carta (baralho *b, int p) {
    node *atual = *b;
    
    int i;
    for (i = 1; i < p; i++) {
        atual = atual->prox;
    }

    printf("%d", atual->valor);
}

int posicao (baralho *b, int x) {
    int cont = 1;
    
    node *atual = *b;
    while (cont < x) {
        atual = atual->prox;
        cont++;
    }

    return cont;
}

void salva (baralho *b) {
    
}