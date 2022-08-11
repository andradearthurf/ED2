#include <stdlib.h>
#include <stdio.h>

void printList(char v[], int tam){
    for (int i = 0; i < tam; i++){
        printf("%c ", v[i]);
    }
}

int buscaBinariaRecursiva(char vet[], int inicio, int fim, int num){
  int meio = (fim + inicio) / 2;

  if (inicio > fim){ 
    return meio;
  }
  else if (vet[meio] == num){ 
      return meio;
    }
  
  else{  
    if (vet[meio] > num){ 
      return buscaBinariaRecursiva(vet, inicio, meio-1, num); 
    }
    else if (vet[meio] < num){ 
      return buscaBinariaRecursiva(vet, meio+1, fim, num); 
    }
  }
}

void insertionSort(char v[], int tam){
  char ch;
  int j;
  for ( int i = 1; i < tam ; i++){
      ch = v[i];
      j = i - 1;

      int k = buscaBinariaRecursiva(v, 0, j, ch);
      while (j >= k){
          v[j + 1] = v[j];
          j--;
      }
      // for (int m = j; m >= k; m--){
      //   v[m + 1] = v[m];
      // }

      if (v[k] <= ch){
        v[k + 1] = ch;
      }
      else{
        v[k + 1] = v[k];
        v[k] = ch;
      }
  }
}

int main(){
    char vetor[18] = {'e', 'x', 'e', 'm', 'p', 'l', 'o', 'd', 'e', 'o', 'r', 'd', 'e', 'n', 'a', 'c', 'a', 'o'};
    printList(vetor, 18);
    printf("\n\n");
    insertionSort(vetor, 18);
    printList(vetor, 18);
}

