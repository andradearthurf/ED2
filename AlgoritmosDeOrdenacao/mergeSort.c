#include <stdlib.h>
#include <stdio.h>

void printList(char v[], int tam){
    for (int i = 0; i < tam; i++){
        printf("%c ", v[i]);
    }
    printf("\n");
} 

void merge(char vet[], int inicio, int meio, int fim, char aux[]){
    int a = inicio;
    int b = meio + 1;
    int c = 0;
    int j;
    while (a <= meio && b <=fim){
        if (vet[a] <= vet[b]) aux[c++] = vet[a++]; 
        else aux[c++] = vet[b++];
    }
    while (a <= meio) 
        aux[c++] = vet[a++];
    while (b <= fim)
        aux[c++] = vet[b++];
    for (int i = inicio,  j = 0; i <= fim; i++, j++){
       vet[i] = aux[j];
    }   
}

void mergeSemAuxiliar(char arr[], int start, int mid, int end){
    int start2 = mid + 1;
 
    // If the direct merge is already sorted
    if (arr[mid] <= arr[start2]) {
        return;
    }
 
    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && start2 <= end) {
 
        // If element 1 is in right place
        if (arr[start] <= arr[start2]) {
            start++;
        }
        else {
            char value = arr[start2];
            int index = start2;
 
            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != start) {
                arr[index] = arr[index - 1];
                index--;
            }
            // Coloco os dois 'sub arrays' (é o mesmo array mas em posições diferentes) 
            //ele ficam um do lado do outro ordenados, e vou trocando jogando pra 
            //frente para ordenar completamente o array.
            arr[start] = value;
 
            // Update all the pointers para ir para proxima iteração
            start++;
            mid++;
            start2++;
        }
    }
}

void mergeSort(char vet[], int inicio, int fim, char aux[]){
    int meio = (inicio + fim) / 2;
    if (inicio < fim){
        mergeSort(vet, inicio, meio, aux);
        mergeSort(vet, meio + 1, fim, aux);
        mergeSemAuxiliar(vet, inicio, meio, fim);
    }
}

int main(){
    char vetor[18] = {'e', 'x', 'e', 'm', 'p', 'l', 'o', 'd', 'e', 'o', 'r', 'd', 'e', 'n', 'a', 'c', 'a', 'o'};
    char aux[18];
    mergeSort(vetor, 0, 17, aux);
    printList(vetor, 18);
}
