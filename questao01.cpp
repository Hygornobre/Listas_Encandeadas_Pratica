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
        cout << atual->valor << " -> ";
        atual = atual->prox;
    }

    cout << "nullptr" << endl;
}

int main() {
    No* inicio = nullptr;

    cout << "Teste com lista vazia:" << endl;
    exibir(inicio);

    No* primeiro = new No{10, nullptr};
    No* segundo = new No{20, nullptr};
    No* terceiro = new No{30, nullptr};

    inicio = primeiro;
    primeiro->prox = segundo;
    segundo->prox = terceiro;

    cout << "\nLista com tres nos:" << endl;
    exibir(inicio);

    delete primeiro;
    delete segundo;
    delete terceiro;

    inicio = nullptr;

    return 0;
}
