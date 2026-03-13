#include <iostream>
#include <vector>


int main(){
    int a1,a2,a3,a4,a5,b1,b2,b3,b4,b5;
    
    std::cin >> a1>>a2>>a3>>a4>>a5;
    std::cin >> b1>>b2>>b3>>b4>>b5;

    if(a1 != b1 && a2 != b2 && a3 != b3 && a4 != b4 && a5 != b5){
        std::cout << "Y" << std::endl;

    }else{
        std::cout << "N"<<std::endl;
    }

    return 0;
}