#include<stdio.h>
main()
{
	int a,i;
	start:
	printf("Enter the number");
	scanf("%d",&a);
	for(i=2;i<=((a/2)+1);i++)
	if(a%i==0)
	printf("\n%d is divisible by %d",a,i);
	goto start;
}
