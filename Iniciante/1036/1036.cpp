#include <iostream>
#include <cmath>

using namespace std;


int main(){
    double a,b,c;
    const double EPS = 1e-9;
    cin >> a >> b >> c;

    double delta = pow(b,2) - 4 * a * c;

    if(delta < 0 || a < EPS){
        cout << "Impossivel calcular" << endl;
    }else{
        double raiz = sqrt(delta);
        double x1 = (- b + raiz) / (2*a);
        double x2 = (- b - raiz) / (2*a);

        printf("R1 = %.5f\n",x1);
        printf("R2 = %.5f\n",x2);
    }

}