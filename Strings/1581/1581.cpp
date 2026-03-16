#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int x;
    vector<string> out;

    cin >> x;

    for (size_t i = 0; i < x; i++)
    {
        vector<string> id;
        int y;
        int c = 0;
        cin >> y;
        for (size_t j = 0; j < y; j++)
        {

            string e;
            cin >> e;
            if(c == 0){
            if(j == 0){
                id.push_back(e);
            } else if(id[0]!=e){
                out.push_back("ingles");
                c = 1;
            } else if(j == y-1){
                out.push_back(id[0]);
            }
            }
        }
        
    }
    
    for (size_t i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    }
    
    return 0;
}