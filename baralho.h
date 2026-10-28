#ifndef BARALHO_H
#define BARALHO_H

#include "deque.h"

typedef deque baralho;

void novoBaralho (baralho *b, int qtde);
void corta (baralho *b, int x);
void sobe (baralho *b, int x);
void vira (baralho *b);
void mostra (baralho baralho);

#endif