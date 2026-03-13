#include <iostream>


int main(){
    unsigned int x,y,z;

    std::cin >> x >>y>>z;

    unsigned int sum = x + y;
    unsigned int r = 0,res = 0;

    while(sum/z>0){
        r+=sum / z;
        res= sum%z;
        sum= res+sum/z;

    }

    std::cout << r <<std::endl;


}