#include <stdio.h>
#include <stdlib.h>

void printList(int v[], int tam){
    for (int i = 1; i < tam; i++){
        printf("%d ", v[i]);
    }
} 

int pai(int i){
    return i / 2;
}

int esquerdo(int i){
    return 2 * i;
}

int direito(int i){
    return 2 * i + 1;
}

void maxHeapfy(int a[], int i, int tam){
    int aux;
    int l, r, maior;
    l = esquerdo(i);
    r = direito(i);

    if (l <= tam && a[l] > a[i])
        maior = l;
    else
        maior = i;
    
    if (r <= tam && a[r] > a[maior])
        maior = r;
    if (maior != i){
        aux = a[maior];
        a[maior] = a[i];
        a[i] = aux;
        maxHeapfy(a, maior, tam);
    } 
}

void construirHeapMax(int a[], int tam){
    for (int i = (tam / 2); i >= 1; i--){
        maxHeapfy(a, i, tam);
    }
}

void heapSort(int a[], int tam){
    int aux;
    construirHeapMax(a, tam);
    for (int i = tam; i >= 2; i--){
        aux = a[i];
        a[i] = a[1];
        a[1] = aux;
        tam--;
        maxHeapfy(a, 1, tam);
    }
}

int main(){
    int vetor[5] = {0, 5, 6, 3, 1};
    heapSort(vetor, 5);
    printList(vetor, 5);
}