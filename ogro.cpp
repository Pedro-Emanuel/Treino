#include <iostream>

int main() {
    char m_esquerda[5]{'*'};
    char m_direita[5]{'*'};
    int valor, i;
    std::cin >> valor;
    
    for(i = 0; i < valor; i++) 
        m_esquerda[i] = 'I';
    valor -= i;
    for(i = 0; i < valor; i++)
        m_direita[i] = 'I';

    for(auto elem : m_esquerda)
        std::cout << elem;
    std::cout << '\n';
    for(auto elem : m_direita)
        std::cout << elem;
    std::cout << '\n';
}