#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printList(char v[], int inicio, int fim){
    for (int i = inicio; i <= fim; i++){
        printf("%c ", v[i]);
    }
    printf("\n");
} 

int random(int inicio, int fim){
    time_t t;
    srand((unsigned)time(&t));
    int diferenca = fim - inicio + 1;
    int val = rand();
    return inicio + (val % diferenca);
}

int particao(int a[], int inicio, int fim){
    int x, i, j, aux1, aux2;
    x = a[fim];
    i = inicio - 1;
    for ( j = inicio; j <= fim - 1; j++){
        if (a[j] <= x){
            i++;
            aux1 = a[i];
            a[i] = a[j];
            a[j] = aux1;
        }
    }
    aux2 = a[i + 1];
    a[i + 1] = a[fim];
    a[fim] = aux2;
    return i + 1;
}

int particaoAleatorizado(int a[], int inicio, int fim){
    int i, aux;
    i = random(inicio, fim);
    aux = a[fim];
    a[fim] = a[i];
    a[i] = aux;
    return particao(a, inicio, fim);
}

int particaoAleatorizadoPlus(int a[], int inicio, int fim){
    int i, j, k, ch, aux;
    i = random(inicio, fim);
    j = random(inicio, fim);
    k = random(inicio, fim);

    if (i >= j && j >= k)
        ch = j;
    else if (j >= i && i >= j)
        ch = i;
    else
        ch = k;

    aux = a[fim];
    a[fim] = a[ch];
    a[ch] = aux;
    return particao(a, inicio, fim);
}

int particaoPlusPlus(char a[], int inicio, int fim, int *p){
    int x, i, j;
    char aux;
    x = a[fim];
    i = inicio - 1;
    int t = fim;
    int b = fim - 1;
    for (j = inicio; j <= b; j++){
        if (a[j] < x){
            i++;
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }
        else if (a[j] == x){
            aux = a[j];
            a[j] = a[b];
            a[b] = aux;
            b--;
            j--;
        }
        printList(a,inicio, fim);
    }
    int k;
    int y = i + 1;
    // fiz isso aqui pra nao considerar a parte que permanece a mesma, que nao muda
    // como nao considerei a parte que nao muda, eh so trocar o resto (que muda)
    for (k = y; k <= b; k++){
        aux = a[k];
        a[k] = a[t];
        a[t] = aux;
        t--;
    }
    printList(a,inicio, fim);
    *p = fim - b + y - 1; // parte da direita, conta pra achar isso 

    return i + 1;
}

void quickSort(int a[], int inicio, int fim){
    int aux, k;
    if (inicio < fim){
        aux = particaoPlusPlus(a, inicio, fim, &k);
        quickSort(a, inicio, aux - 1);
        quickSort(a, k + 1, fim);
    }
}

int main(){
    char vetor[105] = {'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y', 'a', 'a', 'g', 'w', 'h', 'h', 'p', 'j', 'k', 'i', 'j', 'k', 'g', 'u', 'y'};
    quickSort(vetor, 0, 104);
    printList(vetor, 0, 104);
}