#include <iostream>
#include <vector>

using namespace std;

void printar(vector<vector<int>>& matriz) {
    for(int i = 0; i < (int) matriz.size(); i++) {
        for(int j = 0; j < (int) matriz[i].size(); j++) {
            cout << matriz[i][j] << ' ';
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matriz;
    matriz.reserve(n);
    matriz.push_back({});
    int soma = 0;
    for(int i = 0; i < n - 1; i++) {
        matriz[0].push_back(i + 1);
        soma += i + 1;
    }
    matriz[0].push_back(soma);
    printar(matriz);
}