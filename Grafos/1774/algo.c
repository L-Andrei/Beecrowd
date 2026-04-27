#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

struct Aresta* criaAresta(int d,int p){
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
    
    for(int i=0; i<v;i++){
        g->arr[i].c = NULL;
    }
    
    return g;
}

void addAresta(struct Grafo* g, int o, int d, int p) {
    struct Aresta* check = criaAresta(d, p);
    check->prox = g->arr[o].c;
    g->arr[o].c = check;
}

long long calcularCustoMST(struct Grafo* g) {
    int v = g->V;
    int dist[v];      
    bool visitado[v];  
    int custoTotal = 0;

    for (int i = 0; i < v; i++) {
        dist[i] = INT_MAX;
        visitado[i] = false;
    }

    dist[0] = 0;

    for (int i = 0; i < v; i++) {
        int u = -1;

        for (int j = 0; j < v; j++) {
            if (!visitado[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INT_MAX) {
            break; 
        }
        visitado[u] = true;
        custoTotal += dist[u];
        struct Aresta* atual = g->arr[u].c;
        while (atual != NULL) {
            int destino = atual->d;
            int peso = atual->p;

            if (!visitado[destino] && peso < dist[destino]) {
                dist[destino] = peso;
            }
            atual = atual->prox;
        }
    }

    return custoTotal;
}



int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    struct Grafo* g = criaGrafo(r);
    for(int i = 0; i < c; i++){
        unsigned int a, b, peso; 
        scanf("%u %u %u",&a,&b,&peso);
        addAresta(g,a-1,b-1,peso);
        addAresta(g,b-1,a-1,peso);
    }
    
    long long cost = calcularCustoMST(g);
    
    printf("%lld\n",cost);
    return 0;
}
