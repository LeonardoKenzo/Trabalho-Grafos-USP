//Giovanna Maruyama - 16869489
//Leonardo Kenzo Tanaka- 16882154
//Pedro Teidi de Sá Yamacita - 16897290

#include <stdio.h>
#include <stdlib.h>

typedef struct grafos_h{
    int **matrizGrafo;
    int numVertices;
}GRAFO;

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
    if(G == NULL || vertice < 1 || vertice > G->numVertices){
        return NULL;
    }
    int qtd_vizinhos = 0;
    // Primeiro, contamos quantos vizinhos existem
    for(int i = 0; i < G->numVertices; i++){
        if(G->matrizGrafo[vertice - 1][i] > -1) qtd_vizinhos++;
    }

    // Alocamos o tamanho exato + 1 para o marcador -1
    int *vizinhos = (int *)calloc((qtd_vizinhos + 1), sizeof(int));
    if(vizinhos == NULL) return NULL;

    int j = 0;
    for(int i = 0; i < G->numVertices; i++){
        if(G->matrizGrafo[vertice - 1][i] > -1){
            vizinhos[j++] = i + 1; // Guardamos o nome do vértice (1 a N)
        }
    }
    vizinhos[j] = -1; // Marcador de fim
    return vizinhos;
}

int existe_aresta(GRAFO *G, int vertice1, int vertice2){
    if(G == NULL || vertice1 < 1 || vertice1 > G->numVertices || vertice2 < 1 || vertice2 > G->numVertices){ //Verifica se o grafo existe OU se qualquer um dos vértices não pertence ao grafo
        return 0;
    }
    if(G->matrizGrafo[vertice1 - 1][vertice2 - 1] > -1){ //Verifica se há aresta ligando eles(-1 seria se NÃO estivissem ligadas)
        return 1;
    }
    return 0;
}

int vertice_mais_vizinhos(GRAFO *G){
    if(G == NULL || G->numVertices == 0){
        return -1;
    }
    int vertice_max = 1; //variável que guarda o vértice com mais vizinhos
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
            vertice_max = i+1;
        }
    }
    return vertice_max;
}

void add_aresta(GRAFO *G, int vertice1, int vertice2, int pesoAresta){
    if (G == NULL || vertice1 < 1 || vertice1 > G->numVertices || vertice2 < 1 || vertice2 > G->numVertices) 
        return;
    G->matrizGrafo[vertice1 - 1][vertice2 - 1] = pesoAresta;
    G->matrizGrafo[vertice2 - 1][vertice1 - 1] = pesoAresta;
}


int remove_aresta(GRAFO *G, int vertice1, int vertice2){
    if(existe_aresta(G, vertice1, vertice2)){
        G->matrizGrafo[vertice1 - 1][vertice2 - 1] = -1;
        G->matrizGrafo[vertice2 - 1][vertice1 - 1] = -1;
        return 1;
    }
    else {
        printf("-1\n");
        return 0;
    }
}


void print_info_grafo(GRAFO *G){
    printf("V = [");
    for(int i = 0; i < G->numVertices; i++){
        printf("%d%s", i + 1, (i == G->numVertices - 1) ? "" : ", ");
    }
    printf("]\nE = [");

    int first = 1;
    
    for(int j = 0; j < G->numVertices; j++){
        for(int i = 0; i <= j; i++){
            if (G->matrizGrafo[i][j] > -1) {
                if (!first) printf(", ");
                printf("(%d, %d)", i + 1, j + 1);
                first = 0;
            }
        }
    }
    printf("]\n");
}

void print_matriz_adjacencia(GRAFO *G){
    int max_v = 0;
    for (int i = 0; i < G->numVertices; i++) {
        for (int j = 0; j < G->numVertices; j++) {
            if (G->matrizGrafo[i][j] != -1) {
                if (i + 1 > max_v) max_v = i + 1;
                if (j + 1 > max_v) max_v = j + 1;
            }
        }
    }
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < max_v; i++) {
        for (int j = 0; j < max_v; j++) {
            printf("%3d ", (G->matrizGrafo[i][j] == -1) ? 0 : G->matrizGrafo[i][j]);
        }
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
                printf("%d\n", existe_aresta(G, x, y));
                print_status = 0;
                break;
            case 3: // vizinhos
                scanf(" %d", &x);
                int *vizi = vertices_vizinhos(G, x);
                if(vizi){
                    for(int i = 0; vizi[i] != -1; i++) {
                        printf("%d%s", vizi[i], (vizi[i+1] == -1) ? "" : " ");
                    }
                    printf("\n");
                    free(vizi);
                }
                print_status = 0;
                break;
                
            case 4: // remover
                scanf("%d %d", &x, &y);
                // Se a remoção falhar, desativamos o print final para o Caso 1
                if (!remove_aresta(G, x, y)){ 
                print_status = 0;
                }
                break;
            case 5: 
                print_matriz_adjacencia(G);
                print_status = 0;
                break;
                default:
                    printf("unrecognized option %d!\n", option);
        }
        scanf(" %d", &option);
    }

    if(option == -1){
        if(print_status && G != NULL)
            print_info_grafo(G);
    }
    if(G != NULL) free_grafo(&G);

    return 0;
}
