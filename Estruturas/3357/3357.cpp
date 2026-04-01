#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    int x;
    float y,z;
    float resp;

    cin >> x >> y >> z;

    vector<string> v(x);

    for (size_t i = 0; i < x; i++)
    {
        cin>>v[i];
    }
    
    int atual = 0;

    while (y > z + 0.00001) {
        y -= z;
        atual = (atual + 1) % x; 
    }

    cout << v[atual] << " " << fixed << setprecision(1) << y << endl;


    return 0;
}