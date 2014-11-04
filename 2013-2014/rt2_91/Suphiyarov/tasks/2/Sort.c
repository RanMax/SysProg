#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv, int* mas) {

  int i;
  for( i = 1 ; i < argc; i++) {
    mas[i-1]=atoi(*(argv+i));
  };
  
  if(argc == 1) printf("ОШИБКА! Укажите аргументы\n");

  
  int j;
  for (j = 0; j < (argc - 1); ++j){
    for (i = 0; i < (argc - 1) - j; ++i){
      if (mas[i] > mas[i+1]){
        int temp = mas[i];
        mas[i] = mas[i+1];
        mas[i+1] = temp;
      }
    }
  }

  
  
  for (i = 0; i < (argc - 1); i++)
     printf("%d\n",mas[i]);
     

    return 0;
}
