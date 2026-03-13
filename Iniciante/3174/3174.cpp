#include <iostream>
#include <string>
#include <vector>

int main(){
    int g1, g2,g3,g4;
    int r1,r2,r3,r4;
    g1=g2=g3=g4=r1=r2=r3=r4=0;
    int x;
    std::cin >> x;

    int h;
    std::string n,g;

    for(int i = 0 ; i < x; i++){
        std::cin >> n >>g >> h;

        if( g == "bonecos"){
            g1 += (h+r1) / 8;
            r1 = (h+r1) % 8;
        }else if( g == "arquitetos"){
            g2 += (h+r2)/4;
            r2 = (h+r2)%4;
        }else if( g == "musicos"){
            g3 += (h + r3)/6;
            r3 = (h+r3)%6;
        }else{
            g4 += (h+r4)/12;
            r4 = (h+r4)%12;
        }

    }
    int sum = g1+g2+g3+g4;

    std::cout << sum << std::endl;

    return 0;
}