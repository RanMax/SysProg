#include <stdio.h>
//int max(int,int); //прототип функции
void main()
{
	int x,y,z;
	printf("Enter x,y(огрр)\n");
	scanf("%d%d",&x,&y);
	z=max(x,y);
	printf("Hello world\n");
	printf("x=%d y=%d z=%d\n",x,y,z);
}
int max(int a, int b)
{
	if (a>b)
		return a;
	else 
		return b;
}
