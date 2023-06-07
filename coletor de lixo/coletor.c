#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "coletorlixo.h"

typedef struct contador {
    void* endereco;
    int referencias;
    struct contador* proximo;
} Contador;

Contador* lista = NULL;

// Função para inserir um novo bloco de memória no contador
void* insereCont(size_t tamanho) {
    Contador* novo = (Contador*) malloc(sizeof(Contador));
    novo->endereco = malloc(tamanho);
    novo->referencias = 1;
    novo->proximo = NULL;
    
    if (lista == NULL)
        lista = novo;
    else {
        Contador* auxiliar = lista;
        while (auxiliar->proximo != NULL)
            auxiliar = auxiliar->proximo;
        auxiliar->proximo = novo;
    }

    return novo->endereco;
}

// Função para liberar memória do contador
Contador* liberaMem(Contador* l, Contador* auxiliar) {
    if (l->referencias == 0) {
        free(l);
        return auxiliar;
    } else {
        while (auxiliar != NULL) {
            if (auxiliar->referencias == 0) {
                l->proximo = auxiliar->proximo;
                free(auxiliar);
                return l;
            }
            l = l->proximo;
            auxiliar = auxiliar->proximo;
        }
    }
}

// Função para atualizar as referências de um endereço
void atualiza(void* x, int y) {
    Contador* auxiliar = lista;
    while (auxiliar != NULL) {
        if (auxiliar->endereco == x) {
            auxiliar->referencias += y;
            if (auxiliar->referencias == 0)
                lista = liberaMem(lista, lista->proximo);
            break;
        }
        auxiliar = auxiliar->proximo;
    }
}

// Função de alocação de memória com controle de referências
void* malloc2(size_t tamanho) {
    void* x = insereCont(tamanho);
    return x;
}

// Função para atribuição de valores a ponteiros com atualização das referências
void atrib2(int* x, int* y) {
    if (x != NULL) {
        atualiza(x, -1); // Diminui a referência do ponteiro x
        if (y != NULL)
            atualiza(y, 1); // Aumenta a referência do ponteiro y
    }

    if (y == NULL)
        x = NULL; // Se y for NULL, x também será NULL
    else
        *x = *y; // Atribui o valor de y a x
}

// Função para exibir a situação da memória
void dump() {
    setlocale(LC_ALL, "");
    printf("\nSituação da memória:\n");
    Contador* auxiliar = lista;
    int count = 1;
    while (auxiliar != NULL) {
        printf("Bloco %d - Endereço: %p  |  Referências: %d\n", count, auxiliar->endereco, auxiliar->referencias);
        auxiliar = auxiliar->proximo;
        count++;
    }
    printf("\n");
}
