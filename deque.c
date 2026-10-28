//Ao criar um deque, é necessário inicializa-lo em NULL
//LEMBRE-SE QUE UM PARÂMETRO **head REQUER O ENDEREÇO (&) DE UM PONTEIRO *head

#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

//Inserir no final
void push_front (int valor, node **head) {
    node *novo = malloc(sizeof(node));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    node *atual = *head;

    //Com esse if, tratamos o caso onde a lista está vazia
    if (*head == NULL) {
        *head = novo;
        return;
    }

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
    novo->ant = atual;
}

//
void push_back (int valor, node **head) {
    node *novo = malloc(sizeof(node));
    novo->valor = valor;

    if (*head == NULL) {
        *head = novo;
        novo->prox = NULL;
        novo->ant = NULL;

        return;
    }

    (*head)->ant = novo;

    novo->prox = *head;
    novo->ant = NULL;

    *head = novo;
}

//Remove um elemento do final do deque
void pop_front (node **head) {
    if (*head == NULL) {
        printf("Nao ha nada a ser removido!");
        return;
    }

    node *atual1 = *head;
    node *atual2 = *head;

    while (atual1->prox != NULL) {
        atual1 = atual1->prox;
    }

    while (atual2->prox->prox != NULL) {
        atual2 = atual2->prox;
    }

    free(atual1);
    atual2->prox = NULL;
}

//Remove um elemento do início do deque (REQUER PONTEIRO DUPLO)
void pop_back (node **head) {
    if (*head == NULL) {
        printf("Nao ha nada a ser removido!");
        return;
    }

    node *atual = (*head)->prox;
    free(*head);
    *head = atual;
    (*head)->ant = NULL;
}

//Imprime todos os elementos do deque
void imprimeDeque (node *head) {
    if (head == NULL) {
        printf("Vazio.");
        return;
    }

    node *atual = head;
    
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
}

//[!!!FUNÇÃO INUTILIZADA NO CONTEXTO DE LISTAS/PILHAS/FILAS SEM SENTINELA] 
//Cria um node sentinela no deque para inicializa-lo
node *inicializaDeque () {
    node *novo = malloc(sizeof(node));
    novo->valor = 0;
    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}