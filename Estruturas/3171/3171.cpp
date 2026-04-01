#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<vector<int>>& v, int u, int i) {
    v[u].push_back(i);
    v[i].push_back(u);
}

int main() {
    int n, l;
    cin >> n >> l;

    vector<vector<int>> v(n + 1);
    for (int i = 0; i < l; i++) {
        int x, y;
        cin >> x >> y;
        addEdge(v, x, y);
    }

    vector<bool> visitado(n + 1, false);
    queue<int> fila;

    visitado[1] = true;
    fila.push(1);

    int contagemVisitados = 0;

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        contagemVisitados++;

        for (int vizinho : v[atual]) {
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                fila.push(vizinho);
            }
        }
    }

    if (contagemVisitados == n) {
        cout << "COMPLETO" << endl;
    } else {
        cout << "INCOMPLETO" << endl;
    }

    return 0;
}