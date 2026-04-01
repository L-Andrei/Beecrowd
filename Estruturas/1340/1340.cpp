#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


struct Hipoteses {
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;

    bool ehPilha = true, ehFila = true, ehFilaPri = true;

    void inserir(int x) {
        if (ehPilha) s.push(x);
        if (ehFila) q.push(x);
        if (ehFilaPri) pq.push(x);
    }

    void removerEValidar(int x) {

        if (ehPilha) {
            if (s.empty() || s.top() != x) ehPilha = false;
            else s.pop();
        }

        if (ehFila) {
            if (q.empty() || q.front() != x) ehFila = false;
            else q.pop();
        }

        if (ehFilaPri) {
            if (pq.empty() || pq.top() != x) ehFilaPri = false;
            else pq.pop();
        }
    }

    string resultado() {
        int total = ehPilha + ehFila + ehFilaPri;
        if (total == 0) return "impossible";
        if (total > 1) return "not sure";
        if (ehPilha) return "stack";
        if (ehFila) return "queue";
        return "priority queue";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        Hipoteses h;
        for (int i = 0; i < n; i++) {
            int comando, valor;
            cin >> comando >> valor;
            if (comando == 1) h.inserir(valor);
            else h.removerEValidar(valor);
        }
        cout << h.resultado() << "\n";
    }
    return 0;
}