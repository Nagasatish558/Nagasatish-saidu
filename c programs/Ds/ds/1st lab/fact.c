#include<stdio.h>
main()
{
	int n;
	printf("enter the number: ");
	scanf("%d",&n);
	printf("Factorial of the given number is %d",fact(n));
}
fact(int a)
{
	if(a<1)
	return 1;
	else
	return (fact(a-1)*a);
}
