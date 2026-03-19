#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

struct grafos_h{
    int **matrizGrafo;
    int numVertices;
};

GRAFO *criar_grafo(int numVertices){
    GRAFO *grafo = (GRAFO *)calloc(1, sizeof(GRAFO));
    if(grafo != NULL){
        grafo->numVertices = numVertices;
        
        grafo->matrizGrafo = (int **)calloc(numVertices, sizeof(int *));
        for(int i = 0; i < numVertices; i++){
            grafo->matrizGrafo[i] = (int *)calloc(numVertices, sizeof(int));

            for(int j = 0; j < numVertices; j++){ // Preenche toda a matriz com -1
                grafo->matrizGrafo[i][j] = -1;
            }
        }

        return grafo;
    }
    return NULL;
}

int existe_aresta(GRAFO *G, int vertice1, int vertice2){
    if(G == NULL || vertice1 < 0 || vertice1 >= G->numVertices || vertice2 < 0 || vertice2 >= G->numVertices){ //Verifica se o grafo existe OU se qualquer um dos vértices não pertence ao grafo
        return 0;
    }
    if(G->matrizGrafo[vertice1][vertice2] > -1){ //Verifica se há aresta ligando eles
        return 1; //
    }
    return 0;
}

void print_info_grafo(GRAFO *G){
    printf("V = [");
    for(int i = 0; i < G->numVertices; i++){
        if(i == G->numVertices - 1){
            printf("%d]\n", i);
            break;
        }
        printf("%d, ", i);
    }

    printf("E = [");
    for(int i = 0; i < G->numVertices; i++){
        for (int j = 0; j < G->numVertices; j++)
        {
            if(G->matrizGrafo[i][j] > -1)
                printf("(%d, %d)", i, j);
            if(i == G->numVertices - 1 && j == G->numVertices - 1){
                printf("]");
                break;
            }
            printf(", ");
        }
    }
}

void print_matriz_adjacencia(GRAFO *G){
    for(int i = 0; i < G->numVertices; i++){
        for(int j = 0; j < G->numVertices; j++)
            printf("%d ", G->matrizGrafo[i][j]);
        printf("\n");
    }
}

void free_grafo(GRAFO **G){
    for(int i = 0; i < (*G)->numVertices; i++){
        free((*G)->matrizGrafo[i]);
    }
    free((*G)->matrizGrafo);
    free((*G));
    *G = NULL;
}
