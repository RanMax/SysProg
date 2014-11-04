#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int* data, int size);
int main(int argc, char** argv)
{
    int mas[argc];
    int i;
        for(i=1; i<argc; i++)
    {
       mas[i-1]=atol(*(argv+i));
    }
    bubble_sort(mas, argc-1);
    for(i=0; i<argc-1; i++)
    {
        printf("%d\n",mas[i]);
    }
    return 0;
}
void bubble_sort(int* data, int size)
{
        int i,j;
        for (i=0; i<size; ++i)
        {
                for (j=size -1; j>i; --j)
                {
                        if (data[j]<data[j-1])
                        {
                                int t=data[j-1];
                                data[j-1]=data[j];
                                data[j]=t;
                        }
               }
        }
}
