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

        if (atual->prox != nullptr)
            cout << " -> ";

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

    while (atual->prox != nullptr)
        atual = atual->prox;

    atual->prox = novo;
}

bool remover(No*& inicio, int alvo) {
    if (inicio == nullptr)
        return false;

    if (inicio->valor == alvo) {
        No* temporario = inicio;
        inicio = inicio->prox;
        delete temporario;
        return true;
    }

    No* atual = inicio;

    while (atual->prox != nullptr) {
        if (atual->prox->valor == alvo) {
            No* temporario = atual->prox;
            atual->prox = temporario->prox;
            delete temporario;
            return true;
        }

        atual = atual->prox;
    }

    return false;
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

    inserirFim(inicio, 4);
    inserirFim(inicio, 7);
    inserirFim(inicio, 4);
    inserirFim(inicio, 9);

    cout << "Lista inicial: ";
    exibir(inicio);

    int valores[] = {4, 4, 9, 99};

    for (int valor : valores) {
        cout << "\nRemover " << valor << ": "
             << (remover(inicio, valor) ? "true" : "false")
             << endl;

        exibir(inicio);
    }

    cout << "\nTeste com um unico no:" << endl;

    inserirFim(inicio, 15);
    exibir(inicio);

    cout << "Remover 15: "
         << (remover(inicio, 15) ? "true" : "false")
         << endl;

    exibir(inicio);

    cout << "\nTeste com lista vazia:" << endl;

    cout << "Remover 15: "
         << (remover(inicio, 15) ? "true" : "false")
         << endl;

    cout << "\nLiberando a lista..." << endl;
    liberarLista(inicio);

    cout << "Inicio igual a nullptr: "
         << (inicio == nullptr ? "sim" : "nao") << endl;

    return 0;
}
