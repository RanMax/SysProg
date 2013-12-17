#include <stdio.h>

void getMass(int argc, char** argv, int* mas);
void bubbleSort(int *data, int n);
void printMas(int* mas, int argc);


int main(int argc, char** argv){
  int mas[argc - 1]; 
  
  getMass(argc, argv, mas);
  bubbleSort(mas, argc - 2);
  printMas(mas, argc-1);
}

void getMass(int argc, char** argv, int* mas){
  int i;
  for(i=1; i<argc; i++) mas[i-1]=atol(*(argv+i));
}

void printMas(int* mas, int argc){
  int i;
  for (i = 0; i < argc; i++){
     printf("%d",mas[i]);
     printf("\n");
  }
}

void bubbleSort(int *data, int n){
  int j;
  for (j = 0; j < n; ++j){
    int i;
    for (i = 0; i < n - j; ++i){
      if (data[i] > data[i+1]){
        int temp = data[i];
        data[i] = data[i+1];
        data[i+1] = temp;
      }
    }
  }
}
