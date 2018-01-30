#include<stdio.h>
int fact(int);
int main()
{
	int a;
	int n;
	scanf("%d",&n);
	a=fact(n);
	printf("factorial of %d is:%d\n",n,a);
}
int fact(int x)
	{
	if(x==0)
	return 1;
	if(x>0)
	{
		return x*fact(x-1);
	}
	}
