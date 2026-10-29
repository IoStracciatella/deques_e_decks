/*
-----------------------------------------------------------------------------
DEQUES & DECKS: PROJETO DE BARALHO INTERATIVO FEITO COM ESTRUTURAS DE DADOS
-----------------------------------------------------------------------------
O projeto foi feito utilizando como principal estrutura de dados a lista dupla (Double ended queue)

Cada carta consiste de um tipo struct definido como "node"

O baralho é feito utilizando uma estrutura de deque, feito por sua vez por uma sequêcia de nodes
duplamente encadeados entre si
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "baralho.h"

int main () {
    int qtde_cartas, valor;
    bool rodando = true, existeBaralho = false;
    char entrada[20];

    baralho b = NULL;

    while (rodando == true) {
        scanf("%s", entrada);

        if (strcmp(entrada, "BARALHO") == 0) {
            printf("Quantas cartas voce quer inserir?\n");
            scanf("%d", &qtde_cartas);
            
            novoBaralho(&b, qtde_cartas);

            if (existeBaralho == false) {
                existeBaralho = true;
            }
        } else if (strcmp(entrada, "CORTA") == 0) {
            printf("Acima de qual carta voce deseja cortar?\n");
            scanf("%d", &valor);
            corta(&b, valor);
        } else if (strcmp(entrada, "FIM") == 0) {
            rodando = false;
        } else if (strcmp(entrada, "MOSTRA") == 0) {
            mostra(b);
        } else if (strcmp(entrada, "VIRA") == 0) {
            vira(&b);
        } else if (strcmp(entrada, "SOBE") == 0) {
            printf("Qual carta voce quer enviar ao topo?\n");
            scanf("%d", &valor);
            sobe(&b, valor);
        } else if (strcmp(entrada, "CARTA") == 0) {
            printf("Qual carta voce quer imprimir?\n");
            scanf("%d", &valor);
            carta(&b, valor);
        } else if (strcmp(entrada, "POSICAO") == 0) {
            printf("Voce quer saber a posicao de qual carta?\n");
            scanf("%d", &valor);
            printf("%d", posicao(&b, valor));
        } else if (strcmp(entrada, "VIRATOPO") == 0) {
            printf("Acima de qual carta voce quer virar?\n");
            scanf("%d", &valor);
            viraTopo(&b, valor);
        } else {
            printf("Insira uma entrada valida.");
        }
    }

    return 0;
}