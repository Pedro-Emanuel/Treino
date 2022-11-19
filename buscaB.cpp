#include <iostream>
#include <set>
#include <vector>

using namespace std;

int busca_b(const vector<int>& numbers, const int& target) {
    int ini = 0, fim = numbers.size(), meio;
    while(ini <= fim) {
        meio = (ini + fim) / 2;
        cout << "V: " << numbers[meio] << '\n';
        if(numbers[meio] == target) return meio;
        if(numbers[meio] < target) ini = meio + 1;
        if(numbers[meio] > target) fim = meio - 1;
    }
    return -1;
}

int main() {
    int target, new_target, result_busca, num_anterior;
    cin >> target;
    vector<int> numbers{2,7,11,15};
    int size = (int) numbers.size();
    for(int i = 0; i < size; i++) {
        if(i > 0 && numbers[i] == num_anterior)
            continue;
        num_anterior = numbers[i];
        new_target = target - numbers[i];
        result_busca = busca_b(numbers, new_target);
        cout << result_busca << '\n';
        if(result_busca != -1) {
            cout << i << " < " << size - 1 << '\n';
            if(i == result_busca) {
                if((i < size - 1) && numbers[i + 1] == numbers[i]) {
                    cout << "entrou\n";
                    cout << i + 1 << " " << i + 2 << '\n';
                    break;
                } else {
                    cout << "Não achou outro igual\n";
                }
            } else {
                cout << "Achou diferente\n";
                cout << i + 1 << " " << result_busca + 1 << '\n';
                break;
            }
        }
    }
}

// 0
// V: 11
// V: 2
// -1

// 1
// V: 11
// V: 2
// -1

// 2
// V: 11
// V: 2
// -1

// 3
// V: 11
// V: 2
// -1
// 0 0

