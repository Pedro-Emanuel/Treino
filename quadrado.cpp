#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, cont = 1;
    cin >> n;

    if(n % 2 == 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << cont << ' ';
                cont++;
            }
            cout << '\n';
        }
    } else {
        int primeira[n], soma = 0;
        for(int i = 0; i < n - 1; i++) {
            primeira[i] = i + 1;
            soma += i + 1;
        }
        primeira[n] = (soma / (n - 1)) + n;
        for(int i = 0; i < n - 1; i++) {
            cout << (primeira[n] * i) - 
        }
    }
}