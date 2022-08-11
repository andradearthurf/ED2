#include <stdlib.h>
#include <stdio.h>

void printList(char v[], int tam){
    for (int i = 0; i < tam; i++){
        printf("%c ", v[i]);
    }
} 

void bubbleSort(char v[], int tam){
    int aux;
    for ( int i = 1; i < tam ; i++){
        for (int j = 0; j < tam - i ;j++){
            if (v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int main(){
    char vetor[18] = {'e', 'x', 'e', 'm', 'p', 'l', 'o', 'd', 'e', 'o', 'r', 'd', 'e', 'n', 'a', 'c', 'a', 'o'};
    printList(vetor, 18);
    printf("\n");
    bubbleSort(vetor, 18);
    printList(vetor, 18);
}