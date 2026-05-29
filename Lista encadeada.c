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

// Parte 3 - Inverter lista
void inverterLista(NoInt **head) {
    NoInt *anterior = NULL;
    NoInt *atual = *head;
    NoInt *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *head = anterior;
}

// Parte 4 - Dividir lista em duas
void dividirLista(NoInt *head, NoInt **lista1, NoInt **lista2) {
    if (head == NULL) {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    NoInt *lento = head;
    NoInt *rapido = head;

    while (rapido->prox != NULL && rapido->prox->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    *lista1 = head;
    *lista2 = lento->prox;
    lento->prox = NULL;
}

void liberarLista(NoInt *head) {
    NoInt *temp;
    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);
    }
}

// Parte 5 - Playlist circular duplamente encadeada
typedef struct No {
    char musica[100];
    struct No *prox;
    struct No *ant;
} No;

void adicionarMusica(No **head, char *nome) {
    No *novo = (No *)malloc(sizeof(No));
    strcpy(novo->musica, nome);
    novo->prox = NULL;
    novo->ant = NULL;

    if (*head == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        *head = novo;
        return;
    }

    No *ultimo = (*head)->ant;
    ultimo->prox = novo;
    novo->ant = ultimo;
    novo->prox = *head;
    (*head)->ant = novo;
}

void proximaMusica(No **atual) {
    if (*atual != NULL)
        *atual = (*atual)->prox;
}

void musicaAnterior(No **atual) {
    if (*atual != NULL)
        *atual = (*atual)->ant;
}

void exibirPlaylist(No *head) {
    if (head == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    No *temp = head;
    do {
        printf("[%s] <-> ", temp->musica);
        temp = temp->prox;
    } while (temp != head);
    printf("(volta ao inicio)\n");
}

int totalMusicas(No *head) {
    if (head == NULL) return 0;
    int total = 0;
    No *temp = head;
    do {
        total++;
        temp = temp->prox;
    } while (temp != head);
    return total;
}

void tocarPlaylistCompleta(No *head) {
    if (head == NULL) {
        printf("Playlist vazia!\n");
        return;
    }
No *atual = head;
    printf("\nTocando playlist:\n");
    do {
        printf("Tocando: %s\n", atual->musica);
        atual = atual->prox;
    } while (atual != head);
    printf("Todas as musicas foram tocadas.\n");
}

void liberarPlaylist(No **head) {
    if (*head == NULL) return;

    No *atual = (*head)->prox;
    while (atual != *head) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(*head);
    *head = NULL;
}

int main() {
    printf("===== LISTA ENCADEADA =====\n\n");

    NoInt *lista = NULL;

    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);

    printf("Lista original:\n");
    exibirLista(lista);

    inserirPosicao(&lista, 99, 1);
    printf("\nDepois de inserir 99 na posicao 1:\n");
    exibirLista(lista);

    int pos = buscarValor(lista, 20);
    printf("\nValor 20 encontrado na posicao: %d\n", pos);

    inverterLista(&lista);
    printf("\nLista invertida:\n");
    exibirLista(lista);

    NoInt *lista1 = NULL;
    NoInt *lista2 = NULL;
    dividirLista(lista, &lista1, &lista2);
    printf("\nLista 1:\n");
    exibirLista(lista1);
    printf("Lista 2:\n");
    exibirLista(lista2);

    liberarLista(lista1);
    liberarLista(lista2);

    printf("\n===== PLAYLIST =====\n");

    No *playlist = NULL;

    adicionarMusica(&playlist, "Rock");
    adicionarMusica(&playlist, "Jazz");
    adicionarMusica(&playlist, "Pop");

    printf("\nPlaylist:\n");
    exibirPlaylist(playlist);
    printf("\nTotal de musicas: %d\n", totalMusicas(playlist));

    No *atual = playlist;
    printf("\nMusica atual: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Proxima: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Proxima: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Proxima (circular): %s\n", atual->musica);

    musicaAnterior(&atual);
    printf("Anterior: %s\n", atual->musica);

    tocarPlaylistCompleta(playlist);

    liberarPlaylist(&playlist);

    return 0;
}
