#include <iostream>

using namespace std;

int main() {
    int n, soma = 0, input;
    cin >> n;
    int camelos[n];

    for(int i = 0; i < n; i++) {
        cin >> input;
        camelos[i] = input;
        soma += input;
    }

    int media = soma / n;

    for(int i = 0; i < n; i++) {
        cout << media - camelos[i] << '\n';
    }
}