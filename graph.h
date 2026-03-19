#ifndef GRAPH_H
    #define GRAPH_H
    
    typedef struct grafos_h GRAFO;

    GRAFO *criar_grafo(int numVertices);
    int *vertices_vizinhos(GRAFO *G, int vertice);
    int existe_aresta(GRAFO *G, int vertice1, int vertice2);
    int vertice_mais_vizinhos(GRAFO *G);
    void remove_aresta(GRAFO *G, int vertice1, int vertice2);
    void add_aresta(GRAFO *G, int vertice1, int vertice2, int pesoAresta);
    void print_info_grafo(GRAFO *G);
    void print_matriz_adjacencia(GRAFO *G);
    void free_grafo(GRAFO **G);

#endif
