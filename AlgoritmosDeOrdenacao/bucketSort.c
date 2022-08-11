#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int ch;
  struct Node *prox;
}No;


No *insertionSort(No *lista) {
  No *k, *aux;

  if (lista == 0 || lista->prox == 0) {
    return lista;
  }

  aux = lista;
  k = lista->prox;
  aux->prox = 0;
  while (k != 0) {
    No *p;
    if (aux->ch > k->ch) {
      No *tmp;
      tmp = k;
      k = k->prox;
      tmp->prox = aux;
      aux = tmp;
      continue;
    }

    for (p = aux; p->prox != 0; p = p->prox) {
      if (p->prox->ch > k->ch)
        break;
    }

    if (p->prox != 0) {
      No *tmp;
      tmp = k;
      k = k->prox;
      tmp->prox = p->prox;
      p->prox = tmp;
      continue;
    } 
    else {
      p->prox = k;
      k = k->prox;
      p->prox->prox = 0;
      continue;
    }
  }
  return aux;
}

int pegarIndex(int valor, int nBaldes) {
  int x =  valor / nBaldes;
  return x;
}

void bucketSort(int vet[], int tam, int nBaldes) {
  int i, j;
  No **baldes;

  baldes = (No **)malloc(sizeof(No *) * nBaldes);

  for (i = 0; i < nBaldes; ++i) {
    baldes[i] = NULL;
  }

  for (i = 0; i < tam; ++i) {
    No *atual;
    int pos = pegarIndex(vet[i], nBaldes);
    atual = (struct Node *)malloc(sizeof(struct Node));
    atual->ch = vet[i];
    atual->prox = baldes[pos];
    baldes[pos] = atual;
  }

  for (i = 0; i < nBaldes; ++i) {
    baldes[i] = insertionSort(baldes[i]);
  }


  for (j = 0, i = 0; i < nBaldes; ++i) {
    No *aux;
    aux = baldes[i];
    while (aux) {
      vet[j++] = aux->ch;
      aux = aux->prox;
    }
  }
  return;
}

void print(int vet[], int tam) {
  for (int i = 0; i < tam; ++i) {
    printf("%d ", vet[i]);
  }
  printf("\n");
}

int main() {
  int nBaldes = 10;
  int vetor[7] = {.78, .17, .39, .26, .72, .94, .21};

  print(vetor, 7);

  bucketSort(vetor, 7, nBaldes);

  print(vetor, 7);

  return 0;
}