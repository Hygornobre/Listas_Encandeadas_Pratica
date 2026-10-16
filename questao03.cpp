
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

void inserirFim(No*& inicio, int valor) {
    No* novo = new No{valor, nullptr};

    if (inicio == nullptr) {
        inicio = novo;
        return;
    }

    No* atual = inicio;

    while (atual->prox != nullptr) {
        atual = atual->prox;
    }

    atual->prox = novo;
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

    inserirFim(inicio, 8);
    exibir(inicio);

    inserirFim(inicio, 12);
    exibir(inicio);

    inserirFim(inicio, 16);
    exibir(inicio);

    liberarLista(inicio);

    return 0;
}
