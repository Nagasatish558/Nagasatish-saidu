#include<stdio.h>
main()
{
	int a,i=2;
	printf("Enter the number: ");
	scanf("%d",&a);
	prime(a,i);
}
prime(int a,int i)
{
	if(i<a|| a==1||a==0)
	{
		if(a%i==0||a==1||a==0)
		return (printf("not prime"));
		else
		return (prime(a,i+1));
	}
	return (printf("prime"));
}
