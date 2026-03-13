#include <iostream>
#include <vector>
#include <cmath>

void convet_to_bin(unsigned int x, std::vector<int> &v){

    unsigned int result = 0;
    for(int i = 0; x >0 || i < 32 ; i++){
        result = x % 2;
        x = x / 2;
        v[i] = result;
    }
}

unsigned int bin_to_dec(std::vector<int> &v){

    unsigned int resp = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == 1) {
            resp += (1U << i); 
        }
    }

    return resp;
}

void sum_bin(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &resp)
{
    unsigned int a,b;
    for (int i = 0; i < v1.size(); i++)
    {
        a = v1[i];
        b = v2[i];
        
        if(((a == 1 && b == 0)|| (a == 0 && b == 1))){
            resp[i] = 1;

        } else if( a == 1 && b == 1){
            resp[i] = 0;

        }else{
            resp[i] = 0;
        }

    }
    
}

int main(){
    
    unsigned int x,y;
    std::vector<unsigned int> out;
    
    while (std::cin >> x >> y)
    {

        std::vector<int> b1(32);
        std::vector<int> b2(32);
        std::vector<int> res(32);
        convet_to_bin(x,b1);
        convet_to_bin(y,b2);
        sum_bin(b1,b2,res);
        unsigned int r =  bin_to_dec(res);
        out.push_back(r);
    }

    for(int i = 0; i < out.size(); i++){

        std::cout << out[i] << std::endl;
    }
    return 0;
}
