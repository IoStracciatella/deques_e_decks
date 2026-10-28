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
        } else {
            printf("Insira uma entrada valida.");
        }
    }

    return 0;
}