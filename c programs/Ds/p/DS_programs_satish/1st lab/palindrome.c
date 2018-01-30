#include<stdio.h>
main()
{
	int a,b;
	printf("Enter the value for a: \n");
	scanf("%d",&a);
	b=a;
	pal(a,b);
	
}
pal(int a,int b)
{
	static int c=0;
	int d;
	if(a<1)
	 {
			if(b==c)
			printf("palindrome");
			else
			printf("not a palindrome");}
	 
	else
	{	
	d=a%10;
	c=(c*10)+d;
	a=a/10;
	pal(a,b);
	 }
}
