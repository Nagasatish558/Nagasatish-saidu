#include<stdio.h>
int fibnocci(int);
int main()
{
	int n,i,a,sum=0;
	printf("enter a value:\n");
	scanf("%d",&n);
	printf("fibnocci series:\n");  
	for(i=0;i<n;i++)
	{
		a=fibnocci(i);
		sum+=a;
		printf("%d\n",a);
	}
	printf("first %d fibanocci numbers sum is:%d",n,sum);
	return 0;
}
int fibnocci(int x)
{
	if(x==0)
		return x;
	else if(x==1)
		return x;
	else
	 	return fibnocci(x-1)+fibnocci(x-2);
}
