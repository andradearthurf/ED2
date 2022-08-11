#include <stdio.h>

int pegarMaximo(int vetor[], int tam){
    int max = vetor[0];
    for (int i = 0; i < tam; i++){
        if (vetor[i] > max)
            max = vetor[i];
    }
    return max;
}

void countingSort(int a[], int tam, int digito) {
    int b[tam + 1];

    int k = (a[0] / digito) % 10; 
    for (int i = 1; i < tam; i++) {
        if ((a[i] / digito) % 10 > k)
            k = a[i];
    }

    int c[k + 1];

    for (int i = 0; i <= k; ++i) {
        c[i] = 0;
    } 

    for (int i = 0; i < tam; i++) {
        c[(a[i] / digito) % 10]++;
    }

    for (int i = 1; i <= k; i++) {
        c[i] += c[i - 1];
    }

    for (int i = tam - 1; i >= 0; i--) {
        b[c[(a[i] / digito) % 10] - 1] = a[i];
        c[(a[i] / digito) % 10]--;
    }

    for (int i = 0; i < tam; i++) {
        a[i] = b[i];
    }
}

void radixSort(int vetor[], int tam){
    int max = pegarMaximo(vetor, tam);
    for (int i = 1; (max /i) > 0; i++){
        countingSort(vetor, tam, i);
    }
}

void printvetor(int vetor[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", vetor[i]);
    }
}

int main(){
    int vetor[7] = {145, 123, 123, 545, 723, 856, 550};
    radixSort(vetor, 7);
    printvetor(vetor, 7);
}