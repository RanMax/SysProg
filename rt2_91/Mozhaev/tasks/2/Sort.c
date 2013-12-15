#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(int argc, char *argv[]) 
{
        int mas[argc-1];
        int i;
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
   }
   int j=0, l=0;
   for (i=0; i<argc; i++)
           for (j=0; j<argc-i-1; j++)
                   if(mas[j]>mas[j+1])
                   {
                           l=mas[j];
                           mas[j]=mas[j+1];
                           mas[j+1]=l;
                   }
           for(i=0; i<argc-1; i++)
            printf("%d\n", *(mas+i));
        getch();
        return 0;
}
