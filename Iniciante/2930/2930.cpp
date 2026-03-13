#include <iostream>

int main(){
    int x,y;
    std::cin >> x>>y;

    if (y < x){
        
        std::cout << "Eu odeio a professora!" << std::endl;
    }else if(x <= (y-3) && y < 25){
        std::cout << "Muito bem! Apresenta antes do Natal!" << std::endl;
    }else if((x+3)>=y){
        std::cout <<"Parece o trabalho do meu filho!"<<std::endl;
        if((x+2) < 24){
            std::cout<<"TCC Apresentado!"<<std::endl;
        }else{
            std::cout<<"Fail! Entao eh nataaaaal!"<<std::endl;
        }
    }


    return 0;
}