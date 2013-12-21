#include <stdio.h>
int main(int argc, char* argv[]) {

    int n, i, j;

    int a[argc-1];

    for(i = 0; i < argc-1; i++) {

        a[i]=atoi(argv[i+1]);

    }

    for(i = 0; i < argc-1; i++) {

       // сравниваем два соседних элемента.

       for(j = 0 ; j < argc - i - 2 ; j++) {

           if(a[j] > a[j+1]) {

              // если они идут в неправильном порядке, то

              //  меняем их местами.

              int tmp = a[j]; a[j] = a[j+1] ; a[j+1] = tmp;

           }

       }

    }

    //printf("\n");

    for (i=0; i < argc-1; i++){

        printf("%d",a[i]);

        printf("\n");

    }

 }



