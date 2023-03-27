//Algoritmo e Estrutura de Dados - MCC - UFJF
//Algoritmo de Ordenação - BucketSort

 #include <locale.h>
 #include <stdio.h>
 #include <iostream>
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

 #define tam_bucket 100
 #define num_bucket 10
 #define max 10
 #define tam_vet 20

 typedef struct {
         int topo;
         int balde[tam_bucket];
 }bucket;

 void bucket_sort(int v[],int tam);
 void bubble(int v[],int tam);
 void print(int v[], int tam);


int main (int argc, char *argv[]){
  setlocale(LC_ALL, _T("portuguese_brazil"));

  int vet[tam_vet];
     for(int i=0; i< tam_vet; i++){
             vet[i]=rand()%100 +1;
              }
     printf("Vetor que será ordenado:\n");
     print(vet, tam_vet);
     bucket_sort(vet,tam_vet);
     printf("\nResultado - Vetor Ordenado:\n");
     print(vet,tam_vet);
     system("pause");
     }

 void bucket_sort(int v[],int tam){
         bucket b[num_bucket];
         int i,j,k;
 /* 1 */ for(i=0;i<num_bucket;i++) //Inicializa o "topo"
                 b[i].topo=0;

 /* 2 */ for(i=0;i<tam;i++){ //Verifica em que balde o elemento do vetor deve ficar

                 int aux = (int) (v[i]/num_bucket);
                 b[aux].balde[b[aux].topo] = v[i];
                 (b[aux].topo)++;
         }

         printf("Condição dos Baldes\n");
         for(int k=0; k< num_bucket; k++){
                 printf("\n Balde %d: ", k);
                  for(int i =0; i<b[k].topo; i++){
                          printf("%d|",b[k].balde[i]);
                          }
                  }

 /* 3 */ for(i=0;i<num_bucket;i++) //Ordena os baldes utilizando o BubbleSort
                 if(b[i].topo)
                         bubble(b[i].balde,b[i].topo);

         printf("\n\nCondição dos Baldes após bubble sort\n");
         for(int k=0; k< num_bucket; k++){
                 printf("\n Balde %d: ", k);
                  for(int i =0; i<b[k].topo; i++){
                          printf("%d|",b[k].balde[i]);
                          }
                  }
         i=0;
 /* 4 */ for(j=0;j<num_bucket;j++){ //Coloca os elementos dos baldes de volta no vetor
                 for(k=0;k<b[j].topo;k++){
                         v[i]=b[j].balde[k];
                         i++;
                 }
         }
 }

 void bubble(int v[],int tam){
         int i,j,temp,flag;
         if(tam)
                 for(j=0;j<tam-1;j++){
                         flag=0;
                         for(i=0;i<tam-1;i++){
                                 if(v[i+1]<v[i]){
                                         temp=v[i];
                                         v[i]=v[i+1];
                                         v[i+1]=temp;
                                         flag=1;
                                 }
                         }
                         if(!flag)
                                 break;
                 }
 }

void print(int v[], int tam){
     for(int i=0; i<tam; i++){
             printf("%d|", v[i]);
             }
             printf("\n-----------------\n");
     }
