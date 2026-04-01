#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define PI 3.1415926535897;

int main(){
    double a,b,c;
    vector<double> v;

    while(cin >> a >> b >> c){

        double p = (a+b+c)/2.0;
        double vio = sqrt(p*(p-a)*(p-b)*(p-c));
        double r_ros = vio/p;
        double roses = pow(r_ros,2)* PI;
        double r_sun = (a*b*c)/(4*vio);
        double sun = pow(r_sun,2) * PI;

        sun = sun -vio;
        vio = vio - roses;

        v.push_back(sun);
        v.push_back(vio);
        v.push_back(roses);
    }

    for(int i =0; i < v.size(); i+=3){
        printf("%.4f %.4f %.4f\n",v[i],v[i+1],v[i+2]);
    }

    return 0;
}