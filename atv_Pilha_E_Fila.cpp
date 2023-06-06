#include <iostream>

struct No {
    int valor;
    No* prox;
};

struct Fila {
    No* cabeca;
    No* cauda;
    int tamanho;

    Fila() {
        cabeca = cauda = NULL;
        tamanho = 0;
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
        tamanho++;
    }

    void remover() {
        if (!vazia()) {
            No* aux = cabeca;
            cabeca = cabeca->prox;
            delete aux;
            tamanho--;
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

    void inverterFila() {
        No* atual = cabeca;
        No* anterior = NULL;
        No* proximo = NULL;

        while (atual != NULL) {
            proximo = atual->prox;
            atual->prox = anterior;
            anterior = atual;
            atual = proximo;
        }

        cabeca = anterior;
        cauda = atual;
    }
};

int main() {
    Fila f;

    f.inserir(10);
    f.inserir(20);
    f.inserir(30);
    f.inserir(40);
    f.inserir(50);
    f.inserir(60);
    

No* aux = f.cabeca;
while (aux != NULL) {
    aux = aux->prox;
}


f.inverterFila();

aux = f.cabeca;
while (aux != NULL) {
    printf("%d ", aux->valor);
    printf("\n");
    aux = aux->prox;
}

return 0;

}
