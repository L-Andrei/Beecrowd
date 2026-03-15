#include <iostream>
#include <string>
#include <cmath>

int main(){
    int x,y,z;
    std::cin >> x>>y>>z;
    
    int maiorxy =(x+y+std::abs(x-y))/2;
    int maioryz = (y+z+std::abs(y-z))/2;
    int maiorfinal = (maiorxy + maioryz + std::abs(maiorxy- maioryz))/2;
    
    std::cout << maiorfinal << " eh o maior" << std::endl;
    
    return 0;
}