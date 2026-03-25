//Giovanna Maruyama - 16869489
//Leonardo Kenzo Tanaka- 16882154
//Pedro Teidi de Sá Yamacita - 16897290

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(void){
    int option, N, x, y, w, resposta, print_status = 1;
    GRAFO *G;
    
    scanf(" %d", &option);
    while (option != -1)
    {
        switch (option)
        {
            case 0:
                scanf(" %d", &N);
                G = criar_grafo(N);
                break;
            case 1:
                scanf(" %d %d %d", &x, &y, &w);
                add_aresta(G, x, y, w);
                break;
            case 2:
                scanf(" %d %d", &x, &y);
                resposta = existe_aresta(G, x, y);
                print_status = 0;
                break;
            default:
                printf("unrecognized option %d!\n", option);
        }
        scanf(" %d", &option);
    }

    if(option == -1){
        if(print_status)
            print_info_grafo(G);
        else
            printf("%d\n", resposta);
    }
    free_grafo(&G);

    return 0;
}
