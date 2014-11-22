#include <stdio.h>
void getMass(int *mas, int argc, char **argv);
void printMas(int *mas, int argc);
void sort(int *mas, int start, int end);

int main(int argc, char **argv){
  int mas[argc - 1];
  getMass(mas, argc, argv);
  printMas(mas, argc - 1);
  sort(mas, 0, argc - 2);
  printMas(mas, argc - 1);
  
  getchar();
}

void getMass(int* mas, int argc, char** argv){
  int i;
  for(i=1; i<argc; i++){
    mas[i-1]=atol(*(argv+i));
  }
}

void printMas(int* mas, int argc){
  int i;
  printf("Elements:\n");
  for (i = 0; i < argc; i++){
    printf("%d",mas[i]);
    printf("\n");
  }
}

void sort(int* mas, int start, int end){
  if ((end - start) > 1) {
    int p = (end + start)/2 + start;
    sort(mas, start, p);
    sort(mas, p+1, end);
    
    int i = start;
    int j = p+1;
    
    int n = start;
    
    int sortMas[end-start+1];
    
    while (n <= end){
      if (mas[i] < mas[j]){
        sortMas[n] = mas[i];
        i++;
      } else {
        sortMas[n] = mas[j];
        j++;       
      }
      n++;
    }
    for (i = start; i <= end; i++){
      mas[i] = sortMas[i - start];
    }
  } else if ((end - start) == 1 && mas[start] > mas[end]){
    int val = mas[start];
    mas[start] = mas[end];
    mas[end] = val;
  } 

}


