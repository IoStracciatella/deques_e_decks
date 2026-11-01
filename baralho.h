#ifndef BARALHO_H
#define BARALHO_H

#include "deque.h"

typedef deque baralho;

void novoBaralho (baralho *b, int qtde);
void corta (baralho *b, int x);
void sobe (baralho *b, int x);
void vira (baralho *b);
void viraTopo (baralho *b, int k);
void mostra (baralho baralho);
void carta (baralho *b, int p);
int posicao (baralho *b, int x);
void salva (baralho *b);

#endif