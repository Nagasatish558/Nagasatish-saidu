#include <stdio.h>
int fibonacci(int ,int );
int main()
{
	int a,b,i=1;
	printf("How many number of finbonaaci series you want:\n");
	scanf("%d",&a);
	b=fibonacci(a,i);
	printf("\nfibonacci sum %d number is %d",a,b);
}
int fibonacci(int a,int i)
{
	static int b=0,c=1,d=1,sum=0;
	if(i==1)
		{
			printf("%d\t",b);
				++i;
		}
	if(i==2)
		{
			printf("%d\t",c);
			++i;
				sum=sum+c;
		}
	if(i<=a)
	{
			
			d=b+c;
			b=c;
			c=d;
			printf("%d\t",d);
			sum=sum+d;
			return (fibonacci(a,++i));
	}
	return sum;
}

