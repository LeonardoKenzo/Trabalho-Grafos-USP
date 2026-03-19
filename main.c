//Giovanna Maruyama - 16869489
//Leonardo Kenzo Tanaka- 16882154
//Pedro Teidi de Sá Yamacita - 16897290

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(void){
    int option, N, w, x, y;
    scanf(" %d", &N);
    GRAFO *G;

    scanf(" %d", &option);
    switch (option)
    {
    case 0:
        G = criar_grafo(N);
        break;
    
    default:
        printf("unrecognized option!\n");
    }

    print_info_grafo(G);
    free_grafo(&G);

    return 0;
}
