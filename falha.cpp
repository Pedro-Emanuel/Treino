#include <iostream>
#include <vector>

bool esta_contido(std::string a, std::string b) {
    for(int i = 0; i < (int) b.size(); i++)
        for(int j = 1; j < (int) b.size() + 1; j++) {
            if(a == b.substr(i, j)) {
                std::cout << a << ':' << b << ' ' << b.substr(i, j) << '\n';
                return true;
            }
        }
    return false;
}

int main() {
    int quant_senhas, quant_pares = 0;
    std::vector<std::string> vet;
    std::string senha;
    std::cin >> quant_senhas;

    for(int i = 0; i < quant_senhas; i++) {
        std::cin >> senha;
        vet.push_back(senha);
    }

    for(auto elem1 : vet) {
        for(auto elem2 : vet) {
            if(esta_contido(elem1, elem2)) {
                quant_pares++;
            }
        }
    }

    std::cout << quant_pares - quant_senhas << '\n';
}