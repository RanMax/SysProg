#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NL putchar('\n');
#define konec system("pause"); return 0; 

void bubblesort(int *mas, int n)
{     
    int i=0, j=0, t=0;
    for(i=n-1; i>=0; i--)
     for(j=0; j<i; j++)
      if (mas[j]>mas[j+1])
        {t=mas[j]; mas[j]=mas[j+1]; mas[j+1]=t; }
 }

int main(int argc, char *argv[])
{
   int mas[argc-1];
   int i;
   //printf("Array size:");
   //printf("%d", argc-1);
   //printf("\n");
  // printf("Elements:\n");
   for (i=1; i<argc; i++)
   {
	   mas[i-1]=0;
	   char* ch;
	   ch=&argv[i][0];
	   while (*ch != '\0')
	   {
		   if (*ch >= '0' && *ch <= '9') 
		   {
		   	  	   mas[i-1]=mas[i-1]*10 +(*ch -'0');
		   		   ch++;
		   }
		   else
		   {
		   		return -1;
		   }
	   }
	  // printf("%d", mas[i-1]);
	   //printf("\n");
   }
   
bubblesort(mas, argc-1) ;

for(i=0; i<argc-1; i++)
  printf("%d\n", *(mas+i));
  NL
return 0; 
}
