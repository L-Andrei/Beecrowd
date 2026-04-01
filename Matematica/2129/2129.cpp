#include <iostream>
#include <vector>

using namespace std;

int ultimoDigitoNaoNulo(int n) {
    static int digitos[] = {1, 1, 2, 6, 4};
    if (n < 5) return digitos[n];
    

    int a = n / 5;
    int b = n % 5;
    int pot2 = (a % 4 == 0) ? 6 : (1 << (a % 4)) % 10;
    
    return (pot2 * ultimoDigitoNaoNulo(a) * digitos[b]) % 10;
}


int main(){
    int n;
    vector<int> v;

    while(cin>>n){
        int r = ultimoDigitoNaoNulo(n);
        v.push_back(r);
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        cout << "Instancia " << (i+1) << endl;
        cout << v[i] << endl;
    }
    

    return 0;
}