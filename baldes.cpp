//Pedro Emanuel Santana

#include <iostream>
#include <set>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<pair<pair<int, int>, int>> sequencia;
int target_id = -1;

class Balde {
private:
    int volume;
    int volume_max;
public:
    Balde(int volume_max) {
        this->volume_max = volume_max;
        volume = 0;
    }

    static void despejar_a_em_b(Balde& balde_a, Balde& balde_b) {
        int dif_volume = balde_b.get_volume_max() - balde_b.get_volume();
        for(int i = 0; (i < dif_volume) && (balde_a.volume > 0); i++) {
            balde_a.volume--;
            balde_b.volume++;
        }
    }

    void encher() {
        volume = volume_max;
    }

    void derramar_tudo() {
        volume = 0;
    }

    int get_volume() {
        return volume;
    }

    int get_volume_max() {
        return volume_max;
    }
};

pair<int, int> resolver_balde(Balde balde_a, Balde balde_b, set<pair<int, int>>& resolvidos, const int& target, bool& achou, int tipo) {
    if(achou)
        return {};
    
    int volume_a = balde_a.get_volume();
    int volume_b = balde_b.get_volume();

    if(volume_a == target || volume_b == target) {
        sequencia.push_back({{volume_a, volume_b}, tipo});
        achou = true;
        return {volume_a, volume_b};
    }

    auto result_busca = resolvidos.find({volume_a, volume_b});
    if(result_busca != resolvidos.end()) {
        return (*result_busca);
    } else {
        resolvidos.insert({volume_a, volume_b});
        Balde copia_balde_a = balde_a;
        Balde copia_balde_b = balde_b;

        /*Parte A (ramificação do balde A)*/
        //Caso Derramar
        copia_balde_a.derramar_tudo();
        resolvidos.insert(resolver_balde(copia_balde_a, copia_balde_b, resolvidos, target, achou, 1)); //{0, b}
        //Caso Encher
        copia_balde_a.encher();
        resolvidos.insert(resolver_balde(copia_balde_a, copia_balde_b, resolvidos, target, achou, 2)); //{Max, b}
        //Caso Despejar
        copia_balde_a = balde_a;
        Balde::despejar_a_em_b(copia_balde_a, copia_balde_b);
        resolvidos.insert(resolver_balde(copia_balde_a, copia_balde_b, resolvidos, target, achou, 3)); //{*a, *b}

        /*Parte B (ramificação do balde B)*/
        //Caso Derramar
        copia_balde_a = balde_a;
        copia_balde_b.derramar_tudo();
        resolvidos.insert(resolver_balde(copia_balde_a, copia_balde_b, resolvidos, target, achou, 4)); //{a, 0}
        //Caso Encher
        copia_balde_b.encher();
        resolvidos.insert(resolver_balde(copia_balde_a, copia_balde_b, resolvidos, target, achou, 5)); //{a, Max}
        //Caso Despejar
        copia_balde_b = balde_b;
        Balde::despejar_a_em_b(copia_balde_b, copia_balde_a);
        resolvidos.insert(resolver_balde(copia_balde_a, copia_balde_b, resolvidos, target, achou, 6)); //{*a, *b}
    }
    if(achou)
        sequencia.push_back({{volume_a, volume_b}, tipo});

    return {volume_a, volume_b};
}

int main() {
    bool achou = false;

    int input;
    cin >> input;
    Balde balde_a(input);
    cin >> input;
    Balde balde_b(input);

    int target;
    cin >> input;
    target = input;

    set<pair<int, int>> resolvidos;

    auto start = steady_clock::now();

    //Início do código
    cout << "\nEntrando\n";
    resolver_balde(balde_a, balde_b, resolvidos, target, achou, 0);
    cout << "Saindo\n\nCombinações resolvidas:\n\n";

    auto end = steady_clock::now();
    auto elapsed = end - start;
    cout << "Duração: " << duration_cast<milliseconds>(elapsed).count() << " milisegundos\n\n";

    cout << "Sequência até o target:\n\n";
    for(auto it = sequencia.rbegin(); it != sequencia.rend(); it++) {
        if(it->second == 0)
            cout << "{" << it->first.first << ", " << it->first.second << "} - Iniciando\n";
        else if(it->second == 1)
            cout << "{" << it->first.first << ", " << it->first.second << "}" << " - Balde A esvaziado\n";
        else if(it->second == 2)
            cout << "{" << it->first.first << ", " << it->first.second << "}" << " - Balde A preenchido\n";
        else if(it->second == 3)
            cout << "{" << it->first.first << ", " << it->first.second << "}" << " - Água do balde A despejada no balde B\n";
        else if(it->second == 4)
            cout << "{" << it->first.first << ", " << it->first.second << "}" << " - Balde B esvaziado\n";
        else if(it->second == 5)
            cout << "{" << it->first.first << ", " << it->first.second << "}" << " - Balde B preenchido\n";
        else if(it->second == 6)
            cout << "{" << it->first.first << ", " << it->first.second << "}" << " - Água do balde B despejada no balde A\n";
    }

    return 0;
}