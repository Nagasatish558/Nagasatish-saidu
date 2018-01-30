#include<stdio.h>
main()
{
	int a,b,c;
	printf("Enter the values for a and b: ");
	scanf("%d%d",&a,&b);
	c=mul(a,b);
	printf("%d",c);
}
mul(int a,int b)
{	

	if(b<1)
	return 0
	;
	else
	{
		b--;
	return	(mul(a,b)+a);
	}
}
