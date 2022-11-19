#include <iostream>

using namespace std;

//Calcula a distância de um quadrado da fita até todos os zeros, retorna a menor opção
int calcularDistancia(int i, int * zero, int n) {
    int menorDistancia = (i - zero[n - 1] < 0) ? (i - zero[n - 1]) * -1 : i - zero[n - 1], distancia;
    for (int a = 0; a < n; a++) {
        distancia = (i - zero[a] < 0) ? (i - zero[a]) * -1 : i - zero[a];
        if (distancia <= menorDistancia) menorDistancia = distancia;
    }
    return (menorDistancia > 9) ? 9 : menorDistancia;
}

int main() {
    //Tamanho da fita
    int fita;
    cin >> fita;
    //Quadrados da fita, posição dos zeros, quantidate de zeros
    int quadrado[fita], zero[fita], n = 0;
    //Entrada dos valores da fita
    for (int i = 0; i < fita; i++) {
        cin >> quadrado[i];
        //Armazena a posição dos zeros
        if (quadrado[i] == 0) {
            zero[n] = i;
            n++;
        }
    }
    //Troca o -1 pela distância do quadrado até o zero mais próximo
    for (int i = 0; i < fita; i++) {
        if (quadrado[i] == -1) quadrado[i] = calcularDistancia(i, zero, n);
        cout << quadrado[i] << " ";
    }
}
