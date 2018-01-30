#include<stdio.h>
int power(int,int);
int main()
{
	int num,pow,a;
	printf(" enter a number:");
	scanf("%d",&num);
	printf("\n enter the power value:");
	scanf("%d",&pow);
	a=power(num,pow);
	printf(" %d  to the power of %d is: %d",num,pow,a);	
}
int power(int x,int y)
{
	if(y==0)
	return 1;
	else
	{
		y--;
		return x*power(x,y);
	}
}

