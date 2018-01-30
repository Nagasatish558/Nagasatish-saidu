#include<stdio.h>
int prime(int,int,int);
int main()
{
	int n,fact,temp;
	printf("enter a number:");
	scanf("%d",&n);
	temp=n;
	fact=prime(n,temp/2,0);
	if(fact==1)
	{
		printf("\n%d is prime",n);
		return 0;
	}
	printf("\n%d is not a prime",n);
	return 0;
}
int prime(int x,int div,int fac)
{
	if(div==0)
		return fac;
	else if(x%div==0)
	{
		div--;fac++;
		return prime(x,div,fac);
	}
	else
	{
		div--;
		return prime(x,div,fac);
	}
}
