#include <iostream>
#include <vector>

int main(){
    unsigned int x,y,z;
    std::vector<unsigned int> v;
    std::cin >> x;

    for (size_t i = 0; i < x; i++)
    {
        unsigned int t;
        std::cin >> y>>z;
        t = 1;
        for (size_t j = 0; j < y; j++)
        {
            t *= 26;
        }
        for (size_t k = 0; k < z; k++){
            t*=10;
        }

        if(y == 0 && z == 0){
            t = 0;
        }
        v.push_back(t);
    }
    
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i]<<std::endl;
    }

    return 0;
}