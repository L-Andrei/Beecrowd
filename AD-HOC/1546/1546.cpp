#include <iostream>
#include <vector>
#include <string>

int main(){
    int x,y,z;
    std::vector<std::string> out;

    std::cin >> x;

    for(int i = 0; i < x;i++){
        std::cin>>y;
        for(int j = 0; j<y;j++){
            std::cin>>z;

            if(z==1){
                out.push_back("Rolien");
            }else if(z==2){
                out.push_back("Naej");
            }else if(z==3){
                out.push_back("Elehcim");
            } else{
                out.push_back("Odranoel");
            }

        }

    }

    for(int i = 0; i < out.size();i++){
        std::cout << out[i] << std::endl;

    }

    return 0;
}