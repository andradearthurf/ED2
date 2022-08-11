#include <stdlib.h>
#include <stdio.h>

void printList(char v[], int tam){
    for (int i = 0; i < tam; i++){
        printf("%c ", v[i]);
    }
} 

void insertionSort(char v[], int tam){
    for ( int i = 1; i < tam ; i++){
        int ch = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > ch){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = ch;   
    }
}

int main(){
    char vetor[18] = {'e', 'x', 'e', 'm', 'p', 'l', 'o', 'd', 'e', 'o', 'r', 'd', 'e', 'n', 'a', 'c', 'a', 'o'};
    printList(vetor, 18);
    printf("\n");
    insertionSort(vetor, 18);
    printList(vetor, 18);
}