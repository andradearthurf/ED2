#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

typedef struct Registro{
  int chave;
  char info[100];
} Reg;

void lerSup(FILE **arqLEs, Reg *ultimoLido, int *ls, short *ondeLer){
  fseek(*arqLEs, (*ls ) *sizeof(Reg), SEEK_SET);
  fread(ultimoLido, sizeof(Reg), 1, *arqLEs);
  (*ls)--;
  *ondeLer = 0;
}

void lerInf(FILE **arqLi, Reg *ultimoLido, int *li, short *ondeLer){
  fseek(*arqLi, (*li ) *sizeof(Reg), SEEK_SET);
  fread(ultimoLido, sizeof(Reg), 1, *arqLi);
  (*li)++;
  *ondeLer = 1;
}

void inserirArea(Reg *area, Reg *ultimoLido, int *areaOcupada){
  int j = *areaOcupada;
  while(j > 0){
    if (area[j - 1].chave > ultimoLido->chave)
      memcpy(&(area[j]), &(area[j - 1]), sizeof(Reg));
    else
      break;
    j--;
  }
  memcpy(&(area[j]), ultimoLido, sizeof(Reg));
  (*areaOcupada)++;
}

void escreveMax(FILE **arqEs, Reg r, int *es){
  fseek(*arqEs, (*es) *sizeof(Reg), SEEK_SET);
  fwrite(&r, sizeof(Reg), 1, *arqEs);
  (*es)--;
}

void escreveMin(FILE **arqEi, Reg r, int *ei){
  fseek(*arqEi, (*ei) *sizeof(Reg), SEEK_SET);
  fwrite(&r, sizeof(Reg), 1, *arqEi);
  (*ei)++;
}

void retiraMax(Reg *area, Reg *r, int *nRArea){
  memcpy(r, &(area[(*nRArea) - 1]), sizeof(Reg));
  (*nRArea)--;
}

void retiraMin(Reg *area, Reg *r, int *nRArea){
  int i;
  memcpy(r, &(area[0]), sizeof(Reg));
  for(i = 0; i < (*nRArea - 1); i++) area[i] = area[i + 1];
  (*nRArea)--;
}

void ImprimeVetor(int tamanho, int inicio, int fim){
    Reg v[tamanho * 2];

    FILE *arq = fopen("arquivo.bin", "rb");

    fseek(arq, (inicio) * sizeof(Reg), SEEK_SET);
    fread(&v, sizeof(Reg), tamanho, arq);
    fclose(arq);

    for (int k = 0; k < fim - inicio + 1; k++)
    {
        printf("%d ", v[k].chave);
    }
    printf("\n");
}

void particao(int esq, int dir, int *i, int *j, int tam){
  FILE *arqLi = fopen("arquivo.bin", "rb+");
  FILE *arqEi = fopen("arquivo.bin", "rb+");
  FILE *arqEs = fopen("arquivo.bin", "rb+");
  FILE *arqLs = fopen("arquivo.bin", "rb+");
  int ei, li, ls, es;
  short ondeLer = 1;
  int nRArea = 0;
  int TAM_AREA = log(tam);
  int lInf = INT_MIN; 
  int lSup = INT_MAX;
  Reg ultimoLido;
  Reg r;
  Reg area[TAM_AREA];
  *i = esq - 1;
  *j = dir + 1;
  li = esq;
  ei = esq;
  ls = dir;
  es = dir;

  while (li <= ls){
    if (nRArea < TAM_AREA - 1){
      if (ondeLer){
        lerSup(&arqLs, &ultimoLido, &ls, &ondeLer);
      }
      else{
        lerInf(&arqLi, &ultimoLido, &li, &ondeLer);
      }
      inserirArea(area, &ultimoLido, &nRArea);
    }
    else{
      if (ls == es){
        lerSup(&arqLs, &ultimoLido, &ls, &ondeLer);
      }
      else if (li == ei){
        lerInf(&arqLi, &ultimoLido, &li, &ondeLer);
      }
      else{
        if (ondeLer){
          lerSup(&arqLs, &ultimoLido, &ls, &ondeLer);
        }  
        else{
          lerInf(&arqLi, &ultimoLido, &li, &ondeLer);
        }
      }
      if (ultimoLido.chave > lSup){
        *j = es;
        escreveMax(&arqEs, ultimoLido, &es);
      }
      else if (ultimoLido.chave < lInf){
        *i = ei;
        escreveMin(&arqEi, ultimoLido, &ei);
      }
      else{
        inserirArea(area, &ultimoLido, &nRArea);
        if ((ei - esq) < (dir - es)){
          retiraMin(area, &ultimoLido, &nRArea);
          escreveMin(&arqEi, ultimoLido, &ei);

          lInf = ultimoLido.chave;
        }
        else{
          retiraMax(area, &ultimoLido, &nRArea);
          escreveMax(&arqEs, ultimoLido, &es);

          lSup = ultimoLido.chave;
        }
      }
    }
  }
  while (ei <= es){
    retiraMin(area, &ultimoLido, &nRArea);
    escreveMin(&arqEi, ultimoLido, &ei);
  }

  fclose(arqLi);
  fclose(arqEi);
  fclose(arqLs);
  fclose(arqEs);

}

void quickSortExterno(int esq, int dir, int tam){
  int i, j;
  if (dir - esq >= 1){
    particao(esq, dir, &i, &j, tam);
    if ((i - esq) < (dir - j)){
      quickSortExterno(esq, i, tam);
      quickSortExterno(j, dir, tam);
    }
    else{
      quickSortExterno(j, dir, tam);
      quickSortExterno(esq, i, tam);
    }
  }
}

int main(){
  int tam = 7;
  int esq = 0;
  int dir = 6;


  Reg vetor[tam];

  for (int i = 0; i < tam; i++){
    printf("Digite o %d elementos: ", i + 1);
    scanf("%d", &(vetor[i].chave));
  } 

  FILE *arquivo = fopen("arquivo.bin", "wb");
  fwrite(vetor, sizeof(Reg), tam, arquivo);
  fclose(arquivo);

  ImprimeVetor(tam, esq, dir);

  quickSortExterno(esq, dir, tam);

  ImprimeVetor(tam, esq, dir);
  
}