#include <stdlib.h>
#include <stdio.h>

void printList(char v[], int tam){
    for (int i = 0; i < tam; i++){
        printf("%c ", v[i]);
    }
} 

void selectionSort(char v[], int tam){
    for ( int i = 0; i < tam ; i++){
        int menor = i;
        for ( int j = i + 1 ; j < tam; j++){
            if (v[j] < v[menor]){
                menor = j;
            }
        }
        int temp = v[menor];
        v[menor] = v[i];
        v[i] = temp;
    }
}

int main(){
    char vetor[18] = {'e', 'x', 'e', 'm', 'p', 'l', 'o', 'd', 'e', 'o', 'r', 'd', 'e', 'n', 'a', 'c', 'a', 'o'};
    printList(vetor, 18);
    printf("\n");
    selectionSort(vetor, 18);
    printList(vetor, 18);
}