#include <stdio.h>
#include <stdlib.h>


int ultimoDigitoNaoNulo(int n) {

    int digitos[] = {1, 1, 2, 6, 4};
    if (n < 5) return digitos[n];

    int a = n / 5;
    int b = n % 5;
    

    int pot2;
    if (a % 4 == 0) {
        pot2 = 6;
    } else {
        pot2 = (1 << (a % 4)) % 10;
    }

    return (pot2 * ultimoDigitoNaoNulo(a) * digitos[b]) % 10;
}

int main() {
    int n;
    int instancia = 1;

    while (scanf("%d", &n) != EOF) {
        int r = ultimoDigitoNaoNulo(n);
        
        printf("Instancia %d\n", instancia++);
        printf("%d\n\n", r);
    }

    return 0;
}