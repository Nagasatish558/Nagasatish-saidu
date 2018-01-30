#include<stdio.h>
int prod(int,int);
int main()
{
	int m,n,a;
	printf("enter first number:");
	scanf("%d",&m);
	printf("\nenter second number:");
	scanf("%d",&n);
	a=prod(m,n);
	printf("%d*%d=%d",m,n,a);
	return 0;
}
int prod(int x,int y)
{
	if(y==0)
		return 0;
	else
		{
			y--;
			return x+prod(x,y);
		}
}
