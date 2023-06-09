#include <stdio.h>

struct No {
    int valor;
    No* prox;
};

struct Fila {
    No* cabeca;
    No* cauda;

    Fila() {
        cabeca = cauda = NULL;
    }

    bool vazia() {
        return (cabeca == NULL);
    }

    void inserir(int v) {
        No* novo = new No();
        novo->valor = v;
        novo->prox = NULL;
        if (vazia()) {
            cabeca = cauda = novo;
        } else {
            cauda->prox = novo;
            cauda = novo;
        }
    }

    void remover() {
        if (!vazia()) {
            No* aux = cabeca;
            cabeca = cabeca->prox;
            delete aux;
            if (vazia()) {
                cauda = NULL;
            }
        }
    }

    int frente() {
        if (vazia()) {
            return -1; // Valor inválido para indicar fila vazia
        }
        return cabeca->valor;
    }
};

struct Pilha {
    No* topo;

    Pilha() {
        topo = NULL;
    }

    bool vazia() {
        return (topo == NULL);
    }

    void inserir(int v) {
        No* novo = new No();
        novo->valor = v;
        novo->prox = topo;
        topo = novo;
    }

    void remover() {
        if (!vazia()) {
            No* aux = topo;
            topo = topo->prox;
            delete aux;
        }
    }

    int topoPilha() {
        if (vazia()) {
            return -1; // Valor inválido para indicar pilha vazia
        }
        return topo->valor;
    }
};

void inverterFila(Fila& fila, Pilha& pilha) {
    //O "&" permite que a função trabalhe diretamente com "pilha" e "fila", passados como parâmetro, sem precisar criar "cópias".
    // Passo 1: Remover elementos da fila e empilhar na pilha
    while (!fila.vazia()) {
        int elemento = fila.frente();
        fila.remover();
        pilha.inserir(elemento);
    }

    // Passo 2: Desempilhar elementos da pilha e inserir de volta na fila
    while (!pilha.vazia()) {
        int elemento = pilha.topoPilha();
        pilha.remover();
        fila.inserir(elemento);
    }
}

int main() {
    Fila f;
    Pilha p;

    f.inserir(10);
    f.inserir(20);
    f.inserir(30);
    f.inserir(40);
    f.inserir(50);
    f.inserir(60);

    No* aux = f.cabeca;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");

    inverterFila(f, p);

    aux = f.cabeca;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");

    return 0;
}
