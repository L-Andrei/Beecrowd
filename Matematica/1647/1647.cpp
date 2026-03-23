#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<long long> v;
    
    while (true) {
        int n;
        cin >> n;

        if (n == 0){
            break;
        }
        
        vector<long long> valores(n + 1); 

        for (int i = 1; i <= n; i++) {
            cin >> valores[i];
        }


        for (int i = n - 1; i >= 1; i--) {
            for (int j = n; j >= i + 1; j--) {
                valores[i] += valores[j];
            }
        }


        long long soma = 0;
        for (int i = 1; i <= n; i++) {
            soma += valores[i];
        }

        v.push_back(soma);
    }
    
    for(int i = 0 ; i < v.size(); i++){
        cout << v[i] << endl;
    }

    return 0;
}