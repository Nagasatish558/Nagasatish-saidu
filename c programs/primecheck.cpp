#include<stdio.h>
main()
{
	int n,c=0,i,j;
	start:
	c=0;
	printf("enter the num");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	if(n%i==0)
	c++;
	}
	if(c==2)
	printf("\n%d is prime number",n);
	else
	printf("\n%d is not prime number",n);
	goto start;
}
