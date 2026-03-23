#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<long long> v;
    while(1){
    long long a,b,c;
    cin >> a >> b >> c;
    
    if(a == 0 && b == 0){
        break;
    }
    
    long long A = a - 7;
    long long B = b - 7;
    long long ab = A * B;
    
    if (c == 1){
        long long r = (ab + 1) / 2;
        v.push_back(r);
    }else{
        long long r = (ab)/2;
        v.push_back(r);
    }
    
    }
    
    for(int i = 0; i < v.size();i++){
        cout << v[i] << endl;
    }

    return 0;
}