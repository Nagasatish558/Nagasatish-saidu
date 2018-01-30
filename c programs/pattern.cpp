#include<stdio.h>
main()
{
	int a,b,c,n;
	printf("enter the number: ");
	scanf("%d",&n);
	for(a=1;a<=n;a++)
	{	
		for(c=(n-a);c>=0;c--)
		printf(" ");
		for(b=1;b<=2*a-1;b++)
		printf("*");
		printf("\n");
	}
	
}
