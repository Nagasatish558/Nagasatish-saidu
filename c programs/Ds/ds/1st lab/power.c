#include<stdio.h>
main()
{
	int a,b,d;
	printf("Enter the values for a and b: ");
	scanf("%d%d",&a,&b);
	d=power(a,b);
	printf("%d",d);
}
power(int a,int b)
{
	if(b<1)
	return 1;
	else
	return (power(a,b-1)*a);
}
