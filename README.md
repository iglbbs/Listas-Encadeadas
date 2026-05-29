# Atividade — Estruturas de Dados em C: Listas Encadeadas

Implementação das 5 partes da atividade avaliativa de Estruturas de Dados.

---

## Arquivos

| Arquivo | Conteúdo |
|---|---|
| `lista_encadeada.c` | Partes 1 a 5 |

---

## Como compilar e executar

```bash
gcc lista_encadeada.c -o lista && ./lista
```

---

## Parte 1 — Inserção em Posição Específica

```c
void inserirPosicao(NoInt **head, int valor, int posicao);
```

Percorre a lista até a posição `posicao - 1` e encadeia o novo nó. Casos tratados:
- Posição 0: novo nó vira o head.
- Meio/fim: ajusta os ponteiros `prox`.
- Posição inválida (negativa ou além do tamanho): exibe erro e não aloca.

**Saída:**
```
Lista original: 10 -> 20 -> 30 -> NULL
Após inserir 99 na posição 1: 10 -> 99 -> 20 -> 30 -> NULL
```

---

## Parte 2 — Busca por Valor

```c
int buscarValor(NoInt *head, int valor);
```

Percorre a lista com um contador de posição. Retorna a posição da primeira ocorrência ou `-1` se não encontrar. Sem uso de vetores.

**Saída:**
```
Posição do valor 20: 2
Posição do valor 77: -1
```

---

## Parte 3 — Inverter Lista

```c
void inverterLista(NoInt **head);
```

Usa três ponteiros (`anterior`, `atual`, `proximo`) para inverter os links um a um, sem alocar nova lista e sem vetor auxiliar.

**Saída:**
```
Antes:  10 -> 99 -> 20 -> 30 -> NULL
Depois: 30 -> 20 -> 99 -> 10 -> NULL
```

---

## Parte 4 — Dividir Lista em Duas

```c
void dividirLista(NoInt *head, NoInt **lista1, NoInt **lista2);
```

Técnica do ponteiro rápido/lento: `lento` avança 1 passo, `rapido` avança 2. Quando `rapido` chega ao fim, `lento` está no meio. A lista é cortada ali.

**Saída:**
```
Lista original: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
Lista 1: 10 -> 20 -> 30 -> NULL
Lista 2: 40 -> 50 -> NULL
```

---

## Parte 5 — Playlist Circular Duplamente Encadeada

```c
typedef struct No {
    char musica[100];
    struct No *prox;
    struct No *ant;
} No;
```

Funções implementadas:

- **`adicionarMusica`**: insere no final mantendo a circularidade.
- **`proximaMusica`**: avança para `atual->prox`.
- **`musicaAnterior`**: recua para `atual->ant`.
- **`exibirPlaylist`**: percorre com `do/while` até voltar ao head.
- **`totalMusicas`**: conta os nós percorrendo até voltar ao head.

**Saída:**
```
Playlist: [Rock] <-> [Jazz] <-> [Pop] <-> (volta ao inicio)
Total de musicas: 3
```

---

## Requisitos atendidos

- Apenas `stdio.h`, `stdlib.h` e `string.h`
- Sem vetores auxiliares
- Memória gerenciada com `malloc` e `free`
- Sem variáveis globais
