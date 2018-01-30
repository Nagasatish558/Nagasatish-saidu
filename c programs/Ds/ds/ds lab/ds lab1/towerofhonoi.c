#include<stdio.h>
int count=0;
int tower(int,char,char,char);
int main()
{
	int n,a;
	printf("enter a value:");
	scanf("%d",&n);
	a=tower(n,'a','b','c' );
	printf("\ntotal steps:%d",a);
	return 0;	
}
int tower(int n,char beg,char mid,char end)
{
	if(n==1)
	{
		printf("\n move from %c to %c",beg,end);
		count++;
		return count;
	}
	else
	{
		tower(n-1,beg,end,mid);
		tower(1,beg,mid,end);
		tower(n-1,mid,beg,end);
	}
}
