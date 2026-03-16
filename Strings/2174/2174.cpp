#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int x;
    vector<string> p;
    cin >> x;
    int q=0;

    for(int i = 0; i < x; i++){
        string n;
        cin >> n; 
        for (size_t k = 0; k < p.size(); k++)
        {
            if(p[k] == n){
                q += 1;
                break;
            }
        }
        p.push_back(n);
 
    }

    int sum = 151 - (x - q);
    cout << "Falta(m) "<<sum << " pomekon(s)."<<endl;

    return 0;
}