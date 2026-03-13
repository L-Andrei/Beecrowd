#include <iostream>
#include <cmath>

int main(){
    double x1,y1,x2,y2;

    std::cin >>x1>>y1;
    std::cin >> x2>>y2;

    double res = sqrt(pow((x2-x1),2)+pow(y2-y1,2));

    printf("%.4lf\n", res);

    return 0;   
}