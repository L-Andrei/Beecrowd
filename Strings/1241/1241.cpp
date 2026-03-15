#include <vector>
#include <iostream>
#include <string> 
using namespace std;

int main()
{
    int count;
    cin >> count;
    vector<string> saida;

    
    for(int i = 0; i < count ; i++){
        string x,y;
        cin >> x>>y;
        
        if(y.length() <= x.length()){
        for (int j = 0; j < y.length(); j++){
            if (y[y.length()-1-j] != x[x.length()-j-1]){
                saida.push_back("nao encaixa");
                break;
            } else if(j == y.length()-1){
                saida.push_back("encaixa");
                break;
            }
        }
        }else{
            saida.push_back("nao encaixa");
        }
    }

    for(int i = 0; i < count; i++){
        cout << saida[i] << endl;
    }
    
    return 0;
}