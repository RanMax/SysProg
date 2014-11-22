#include <stdio.h>

#include <stdlib.h>

#define N 2013 // arr[N]

int A[N],i,n=N,swapped,t;

int main(){

for(i=0;i<N;i++){

A[i]=rand()%100;

printf("%02d ",A[i]);

}

do{ swapped=0;

for(i=0;i<n-1;i++)

if(A[i]>A[i+1]){

t=A[i];A[i]=A[i+1];A[i+1]=t; //swap

swapped=1;

}

n--;

}while(swapped==1);

printf("\n\n");

for(i=0;i<N;i++)

printf("%02d ",A[i]);
getch();

return 0;

}
