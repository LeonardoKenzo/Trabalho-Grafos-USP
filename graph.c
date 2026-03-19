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

int *vertices_vizinhos(GRAFO *G, int vertice){
    if(G == NULL || vertice < 0 || vertice >= G->numVertices){
        return NULL;
    }
    int qtd_vizinhos = 0;
    for(int i = 0; i < G->numVertices; i++){ //Percorre a linha correspondente ao vértice na matriz de adjacência
        if(G->matrizGrafo[vertice][i] > -1){  //Se o valor for > -1 existe uma aresta entre o vertice e "i"
            qtd_vizinhos++;
        }
    }
    int *vizinhos = (int *)calloc(qtd_vizinhos + 1) * sizeof(int));  //Aloca memória para armazenar os vizinhos e +1 para colocar um marcador de fim (-1)
    if(vizinhos == NULL){
        return NULL;
    }
    int j = 0;
    for(int i = 0; i < G->numVertices; i++){ //Preenche o vetor com os índices dos vizinhos
        if(G->matrizGrafo[vertice][i] > -1){
            vizinhos[j] = i;
            j++;
        }
    }
    vizinhos[j] = -1; //Marca o fim do vetor
    return vizinhos;
}

int existe_aresta(GRAFO *G, int vertice1, int vertice2){
    if(G == NULL || vertice1 < 0 || vertice1 >= G->numVertices || vertice2 < 0 || vertice2 >= G->numVertices){ //Verifica se o grafo existe OU se qualquer um dos vértices não pertence ao grafo
        return 0;
    }
    if(G->matrizGrafo[vertice1][vertice2] > -1){ //Verifica se há aresta ligando eles(-1 seria se NÃO estivissem ligadas)
        return 1; //
    }
    return 0;
}

int vertice_mais_vizinhos(GRAFO *G){
    if(G == NULL || G->numVertices == 0){
        return -1;
    }
    int vertice_max = 0; //variável que guarda o vértice com mais vizinhos
    int max_vizinhos = -1; //variável para a maior quantidade encontrada até agora
    for(int i = 0; i < G->numVertices; i++){ //Percorre todos os vértices do grafo
        int quantidade = 0;
        for(int j = 0; j < G->numVertices; j++){ //Conta quantos vizinhos o vértice i possui
            if(G->matrizGrafo[i][j] > -1){
                quantidade++;
            }
        }
        if(quantidade > max_vizinhos){ //Atualiza o máximo encontrado
            max_vizinhos = quantidade;
            vertice_max = i;
        }
    }
    return vertice_max;
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
