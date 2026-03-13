# include <iostream>

int main(){
    double x,y,z;
    std::cin >> x>>y>>z;

    double tri, cir,tra,quad,ret;

    tri = x*z/2;
    cir = z*z*3.14159;
    tra = (x+y)*z/2;
    quad = y*y;
    ret = x*y;

    printf("TRIANGULO: %.3f\n",tri);
    printf("CIRCULO: %.3f\n", cir);
    printf("TRAPEZIO: %.3f\n", tra);
    printf("QUADRADO: %.3f\n", quad);
    printf("RETANGULO: %.3f\n", ret);

    return 0;
}