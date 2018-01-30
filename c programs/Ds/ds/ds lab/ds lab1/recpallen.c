#include<stdio.h>
int rev=0;
int reverse(int);
int main()
{
	int n,a;
	printf("enter a value:");
	scanf("%d",&n);
	a=reverse(n);
	if(a==n)
		printf("%d is pallendrome",n);
	else
		printf("%d is not a pallendrom",n);
	return 0;
	
}
int reverse(int x)
{
	//static rev=0;
	if(x!=0)
	{
		rev=rev*10;
		rev=rev+(x%10);
		reverse(x/10);
	}
	else
	{
		return rev;
	}
}
