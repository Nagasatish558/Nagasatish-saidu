#include<stdio.h>
main()
{
	int a,b,c;
	printf("Enter the two values: ");
	scanf("%d%d",&a,&b);
	if(a<b)
	{
		c=a;a=b;b=c;
	}
	printf("Gcd of two nums is %d",gcd(a,b));
}
gcd(int a,int b)
{
	int c;
	if(b<1)
	return a;
	else
	{ 
	c=a%b;
	gcd(b,c);
}
}
