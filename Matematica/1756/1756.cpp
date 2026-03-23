#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void solve() {
    int n, y;
    double p;
    cin >> n >> y >> p;
    
    string a, b, t;
    cin >> a >> b >> t;
    
    string f1 = a.substr(0, y) + b.substr(y);
    string f2 = b.substr(0, y) + a.substr(y);
    
    auto calc_prob = [&](const string& f) {
        double prob = 1.0;
        for (int i = 0; i < n; ++i) {
            prob *= (f[i] == t[i]) ? (1.0 - p) : p;
        }
        return prob;
    };
    
    double p1 = calc_prob(f1);
    double p2 = calc_prob(f2);
    
    cout << fixed << setprecision(7) << (p1 + p2 - (p1 * p2)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testes;
    if (cin >> testes) {
        while (testes--) {
            solve();
        }
    }
    
    return 0;
}