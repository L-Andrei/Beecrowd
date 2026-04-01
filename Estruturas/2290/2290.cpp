#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


void resolver() {
    long long n;
    while (std::cin >> n && n != 0) {
        std::map<long long, long long> frequencia;
        for (long long i = 0; i < n; ++i) {
            long long numero;
            std::cin >> numero;
            frequencia[numero]++;
        }

        std::vector<long long> apaixonados;
        for (auto const& [num, cont] : frequencia) {
            if (cont % 2 != 0) {
                apaixonados.push_back(num);
            }
        }

        for (size_t i = 0; i < apaixonados.size(); ++i) {
            std::cout << apaixonados[i] << (i == apaixonados.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    resolver();

    return 0;
}