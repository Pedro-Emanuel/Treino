#include <iostream>

using namespace std;

int qCorridas, qParticipantes, qSistemas; //G, P

void iniciarCorridas(int *pontuacao) {
    for(int i = 0; i < qCorridas; i++) {
        for(int j = 0; j < qParticipantes; j++) {
            int p;
            cin >> p;
            pontuacao[i][j] += p;
        }
    }
}

void printar(int *pontuacao) {
    for(int i = 0; i < qCorridas; i++) {
        for(int j = 0; j < qParticipantes; j++) {
            cout << pontuacao[i][j] << " ";
        }
            cout << endl;
    }
}

void zerar(int *pontuacao) {
    for(int i = 0; i < qCorridas; i++) {
        for(int j = 0; j < qParticipantes; j++) {
            pontuacao[i][j] = 0;
        }
    }
}

int main() {
    cin >> qCorridas >> qParticipantes;

    int pontuacao[qCorridas][qParticipantes];
    zerar(pontuacao);

    while(qCorridas != 0 && qParticipantes != 0) {
        iniciarCorridas(pontuacao);

        cin >> qSistemas;
        printar(pontuacao);

        cin >> qCorridas >> qParticipantes;
    }
}