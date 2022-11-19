#include <iostream>
#include <map>

using namespace std;

int isCorrect(string& dAtual, string& dProx) {
    (void)dAtual;
    (void)dProx;
    if(stoi(dAtual) + 1 == stoi(dProx))
        return 1;
    else if(stoi(dAtual) > stoi(dProx))
        return 0;
    return -1;
}

int main() {
    int n, input;
    map<int, pair<string, string>> mapa;
    cin >> n;
    string digitos{};
    //cout << digitos.max_size();
    for(int i = 0; i < n; i++) {
        cin >> input;
        digitos += to_string(input);
    }
    string dAtual{}, dProx{}, aux{};
    for(int i = 1; i < n; i++) {
        int iBackup = i;
        for(int j = 0; j < n; j += i) {
            cout << "i: " << i << " j: " << j << '\n';
            bool flag = false;
            if((j + i + i) > n) continue;

            dAtual = digitos.substr(j, i);
            cout << dAtual << '\n';
            if((int) dAtual.size() > 8) break;
            aux = to_string(stoll(dAtual) + 1);

            if((j + i + i) > n) continue;
            
            if(aux.size() > dAtual.size()) {
                cout << "Entrou: " << i << ' ' << j << '\n';
                i++;
                flag = true;
            }

            if(flag)
                dProx = digitos.substr(j+i-1, i);
            else
                dProx = digitos.substr(j+i, i);

            cout << dAtual << " : " << dProx << " j: " << j << '\n';
            
            if(j == 0) {
                cout << "Foi pro mapa A\n";
                mapa[iBackup].first += dAtual;
                mapa[iBackup].second = dAtual;
            }
            int correct = isCorrect(dAtual, dProx);
            if(correct == 1) {
                cout << "Foi pro mapa B\n";
                mapa[iBackup].first += dProx;
            } else if(correct == 0 || correct == -1) break;
            if(flag) j--;
        }
        cout << '\n';
        i = iBackup;
        if(i > 8) break;
    }
    cout << '\n';
    for(auto elem : mapa) {
        cout << elem.first << ' ' << elem.second.first << ' ' << elem.second.second << '\n';
        if(digitos.compare(elem.second.first) == 0) {
            cout << elem.second.second << '\n';
            break;
        }
    }
}