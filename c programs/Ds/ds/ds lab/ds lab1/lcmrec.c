#include<stdio.h>
int i=1;
int lcmf(int,int);
int main()
{
	int m,n,lcm;
	printf("enter first value:");
	scanf("%d",&m);
	printf("\nenter second value:");
	scanf("%d",&n);
	lcm=lcmf(m,n);
	printf("lcm of %d,%d is:%d",m,n,lcm);
	return 0;
}
int lcmf(int x,int y)
{
	
		if(i%x==0 && i%y==0)
			{
				return i;
			}
		else if(x*y==i)
			{
				return i;
			}
		else
		{
			i++;
			lcmf(x,y);
		}
}
