
#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

No* buscar(No* inicio, int alvo) {
    No* atual = inicio;

    while (atual != nullptr) {
        if (atual->valor == alvo)
            return atual;

        atual = atual->prox;
    }

    return nullptr;
}

int main() {
    No* inicio = nullptr;

    int valores[] = {3, 6, 3, 9};

    for (int valor : valores) {
        No* novo = new No{valor, nullptr};

        if (inicio == nullptr) {
            inicio = novo;
        } else {
            No* atual = inicio;

            while (atual->prox != nullptr)
                atual = atual->prox;

            atual->prox = novo;
        }
    }

    int alvos[] = {3, 9, 7};

    for (int alvo : alvos) {
        No* resultado = buscar(inicio, alvo);

        cout << alvo << ": "
             << (resultado != nullptr ? "encontrado" : "nao encontrado");

        if (alvo == 3 && resultado == inicio)
            cout << " (primeiro no)";

        cout << endl;
    }

    No* vazia = nullptr;

    cout << "Lista vazia: "
         << (buscar(vazia, 3) == nullptr
             ? "valor nao encontrado"
             : "valor encontrado") << endl;

    while (inicio != nullptr) {
        No* temporario = inicio;
        inicio = inicio->prox;
        delete temporario;
    }

    return 0;
}
