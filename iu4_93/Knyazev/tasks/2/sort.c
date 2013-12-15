#include <stdio.h> 
#include <stdlib.h>
int main(int argc ,char** argv)
{
 int mas[argc];
  for(int i=1; i<argc; i++)
  {
	mas[i]=atol(*(argv+i));
}
 int i1,j,bufer;
  for(i1=0; i1<argc; i1++)
   for(j=argc-2; j>=i1; j--)
    if (mas[j]>mas[j+1])
     {
      bufer=mas[j]; mas[j]=mas[j+1];mas[j+1]=bufer; 
     }
   printf("\n Sorted Array:\n");
   for(i1=1; i1<argc; i1++)
   printf("%d\n",mas[i1]); 
	return 0;
}
