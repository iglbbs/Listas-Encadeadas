#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct NoInt {
    int valor;
    struct NoInt *prox;
} NoInt;
 
NoInt *criarNoInt(int valor) {
    NoInt *novo = (NoInt *)malloc(sizeof(NoInt));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}
 
void inserirFinal(NoInt **head, int valor) {
    NoInt *novo = criarNoInt(valor);
    if (*head == NULL) {
        *head = novo;
        return;
    }
    NoInt *temp = *head;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = novo;
}
 
void exibirLista(NoInt *head) {
    NoInt *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }
    printf("NULL\n");
}
 
// Parte 1 - Inserir em posicao especifica
void inserirPosicao(NoInt **head, int valor, int posicao) {
    if (posicao < 0) {
        printf("Posicao invalida!\n");
        return;
    }
 
    NoInt *novo = criarNoInt(valor);
 
    if (posicao == 0) {
        novo->prox = *head;
        *head = novo;
        return;
    }
 
    NoInt *temp = *head;
    int i = 0;
    while (temp != NULL && i < posicao - 1) {
        temp = temp->prox;
        i++;
    }
 
    if (temp == NULL) {
        printf("Posicao invalida!\n");
        free(novo);
        return;
    }
 
    novo->prox = temp->prox;
    temp->prox = novo;
}
 
// Parte 2 - Buscar valor
int buscarValor(NoInt *head, int valor) {
    int posicao = 0;
    while (head != NULL) {
        if (head->valor == valor)
            return posicao;
        head = head->prox;
        posicao++;
    }
    return -1;
}
