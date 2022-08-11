#include <stdio.h>

void countingSort(int a[], int tam) {
    int b[10], c[10];

    int k = a[0]; 
    for (int i = 1; i < tam; i++) {
        if (a[i] > k)
            k = a[i];
    }

    for (int i = 0; i <= k; ++i) {
        c[i] = 0;
    } 

    for (int i = 0; i < tam; i++) {
        c[a[i]]++;
    }

    for (int i = 1; i <= k; i++) {
        c[i] += c[i - 1];
    }

    for (int i = tam - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    for (int i = 0; i < tam; i++) {
        a[i] = b[i];
    }
}

void printvetor(int vetor[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", vetor[i]);
    }
}

int main() {
    int vetor[7] = {7, 3, 9, 1, 3, 3, 8};
    countingSort(vetor, 7);
    printvetor(vetor, 7);
}