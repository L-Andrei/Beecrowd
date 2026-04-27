#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Aresta {
    int d;
    int p;
    struct Aresta* prox;
};

struct ListaAdj {
    struct Aresta* c; 
};

struct Grafo {
    int V; 
    struct ListaAdj* arr;
};

struct Aresta* criaAresta(int d, int p){
    struct Aresta* nA = (struct Aresta*)malloc(sizeof(struct Aresta));
    nA->d = d;
    nA->p = p;
    nA->prox = NULL;
    return nA;
}

struct Grafo* criaGrafo(int v){
    struct Grafo* g = (struct Grafo*)malloc(sizeof(struct Grafo));
    g->V = v;
    g->arr = (struct ListaAdj*)malloc(sizeof(struct ListaAdj)*v);
    
    for(int i = 0; i < v; i++){
        g->arr[i].c = NULL;
    }
    
    return g;
}

void adicionaAresta(struct Grafo* g, int o, int d) {
    struct Aresta* nA = criaAresta(d, 0); 
    nA->prox = g->arr[o].c;
    g->arr[o].c = nA;
}

int main() {
    int m, n;
    
    if (scanf("%d %d", &m, &n) != 2) return 0;

    char mapa[1005][1005];
    for (int i = 0; i < m; i++) {
        scanf("%s", mapa[i]);
    }

    int totalVertices = m * n;
    struct Grafo* g = criaGrafo(totalVertices);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int u = i * n + j;
            
            if (i > 0) adicionaAresta(g, u, (i - 1) * n + j);
            if (i < m - 1) adicionaAresta(g, u, (i + 1) * n + j);
            if (j > 0) adicionaAresta(g, u, i * n + (j - 1));
            if (j < n - 1) adicionaAresta(g, u, i * n + (j + 1));
        }
    }

    int costa = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mapa[i][j] == '#') {
                int u = i * n + j;
                int adj_count = 0;
                bool tocaAgua = false;
                
                struct Aresta* temp = g->arr[u].c;
                
                while (temp != NULL) {
                    adj_count++;
                    int v = temp->d;
                    int vi = v / n; 
                    int vj = v % n; 
                    
                    if (mapa[vi][vj] == '.') {
                        tocaAgua = true;
                    }
                    temp = temp->prox;
                }
                
                if (adj_count < 4 || tocaAgua) {
                    costa++;
                }
            }
        }
    }

    printf("%d\n", costa);

    return 0;
}
