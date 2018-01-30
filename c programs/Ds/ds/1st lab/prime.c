#include <stdio.h>
int prime(int a, int i);
int main()
{
	int a,b,i;
	printf("Enter a number:\n");
	scanf("%d",&a);
	i=a;
	b=prime(a,i);
	if(b==2)
	{
			printf("%d is a prime number",a);
	}
	else{
		printf("%d not a prime number",a);
	}
}
int prime(int a, int i)
{
	static int c=0;
	if(i>=1)
	{
		if((a%i)==0)
		{
			c++;		
		}
		return prime(a,--i);
	}
	return c;
	
}
