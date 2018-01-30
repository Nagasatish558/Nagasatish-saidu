#include<stdio.h>
main()
{
	int n,c=0,i,j;
	start:
	printf("\nenter the num");
	scanf("%d",&n);
	for(i=1;i<=(n/2);i++)
	if(n%i==0)
	printf("\n%d is divisible by %d",n,i);
	goto start;
}
