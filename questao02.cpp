
#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

void exibir(No* inicio) {
    if (inicio == nullptr) {
        cout << "Lista vazia." << endl;
        return;
    }

    No* atual = inicio;

    while (atual != nullptr) {
        cout << atual->valor;

        if (atual->prox != nullptr) {
            cout << " -> ";
        }

        atual = atual->prox;
    }

    cout << endl;
}

void inserirInicio(No*& inicio, int valor) {
    No* novo = new No{valor, inicio};
    inicio = novo;
}

void liberarLista(No*& inicio) {
    while (inicio != nullptr) {
        No* temporario = inicio;
        inicio = inicio->prox;
        delete temporario;
    }
}

int main() {
    No* inicio = nullptr;

    inserirInicio(inicio, 20);
    exibir(inicio);

    inserirInicio(inicio, 10);
    exibir(inicio);

    inserirInicio(inicio, 5);
    exibir(inicio);

    liberarLista(inicio);

    return 0;
}
