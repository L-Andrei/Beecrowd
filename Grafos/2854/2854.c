#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Aresta {
    int d;
    struct Aresta* prox;
};

struct ListaAdj {
    struct Aresta* c; 
};

struct Grafo {
    int V; 
    struct ListaAdj* arr;
};

struct Aresta* criaAresta(int d){
    struct Aresta* nA = (struct Aresta*)malloc(sizeof(struct Aresta));
    nA->d = d;
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

// Grafo não-direcionado: adiciona a ligação nos dois sentidos
void adicionaAresta(struct Grafo* g, int o, int d) {
    struct Aresta* nA = criaAresta(d); 
    nA->prox = g->arr[o].c;
    g->arr[o].c = nA;
    
    nA = criaAresta(o);
    nA->prox = g->arr[d].c;
    g->arr[d].c = nA;
}

// Dicionário simples para converter strings em IDs inteiros
char nomes[305][50];
int numNomes = 0;

int pegaId(char* nome) {
    for (int i = 0; i < numNomes; i++) {
        if (strcmp(nomes[i], nome) == 0) {
            return i;
        }
    }
    strcpy(nomes[numNomes], nome);
    return numNomes++;
}

// Busca em Profundidade para visitar todos da mesma família
void dfs(struct Grafo* g, int v, bool visitados[]) {
    visitados[v] = true;
    
    struct Aresta* temp = g->arr[v].c;
    while (temp != NULL) {
        int vizinho = temp->d;
        if (!visitados[vizinho]) {
            dfs(g, vizinho, visitados);
        }
        temp = temp->prox;
    }
}

int main() {
    int m, n;
    
    if (scanf("%d %d", &m, &n) != 2) return 0;

    struct Grafo* g = criaGrafo(m);

    char nome1[50], relacao[50], nome2[50];
    
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", nome1, relacao, nome2);
        
        int u = pegaId(nome1);
        int v = pegaId(nome2);
        
        adicionaAresta(g, u, v);
    }

    bool visitados[305] = {false};
    int familias = 0;

    for (int i = 0; i < m; i++) {
        if (!visitados[i]) {
            dfs(g, i, visitados);
            familias++; 
        }
    }

    printf("%d\n", familias);

    return 0;
}
