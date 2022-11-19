#include <iostream>
#include <list>

int main() {
    int q_convidados;
    std::cin >> q_convidados;
    std::list<int> lista;

    for(int i = 0; i < q_convidados; i++)
        lista.push_back(i + 1);

    int q_ciclos;
    std::cin >> q_ciclos;
    int valor;

    for(int i = 0; i < q_ciclos; i++) {
        std::cin >> valor;
        int j = 1;
        for(auto it = lista.begin(); it != lista.end(); it++) {
            if((j % valor) == 0) {
                auto aux = it;
                it--;
                lista.erase(aux);
            }
            j++;
        }
    }

    for(auto elem : lista)
        std::cout << elem << ' ';
    std::cout << '\n';
}