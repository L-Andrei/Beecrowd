#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std; 

 
int main() {
    int n;
    cin >> n;
    vector<string> out;
    for(int i = 0; i < n ;i++){
        int y;
        cin >>y;
        vector<int> p = {0,0,0};
        for (int j = 0; j < y; j++){
            char a,b;
            cin >> a >> b;
            
            if(a == 'R' && b == 'G'){
                p[0] += 2;
            }else if(a == 'R'){
                p[0] += 1;
            }else if(a == 'B' && b == 'R'){
                p[2]+=2;
            }else if(a == 'B'){
                p[2]+=1;
            }else if(a == 'G' && b == 'B'){
                p[1]+=2;
            }else{
                p[1]+=1;
            }
        }
        int maior = max(p[0],max(p[1],p[2]));

        int quantos_no_topo = 0;
        for (int pontos : p) {
            if (pontos == maior) quantos_no_topo++;
        }

        if (quantos_no_topo == 3) {
            out.push_back("trempate");
        } else if (quantos_no_topo == 2) {
            out.push_back("empate");
        } else {
            if (p[0] == maior) out.push_back("red");
            else if (p[1] == maior) out.push_back("green");
            else out.push_back("blue");
        }
        
        
    }
    
    for(string s:out){
        cout << s << endl;
    }
    
 
    return 0;
}