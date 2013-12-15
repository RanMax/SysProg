#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int* data, int size);
int main(void)
{
	int mas[10];
	int i;
	mas[0]=4;
	mas[1]=5;
	mas[2]=1;
	mas[3]=9;
	mas[4]=10;
	mas[5]=3;
	mas[6]=4;
	mas[7]=2;
	mas[8]=34;
	mas[9]=55;
	bubble_sort(mas, 10);
	for(i=0; i<10; i++)
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


