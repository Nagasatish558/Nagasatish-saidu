#include<stdio.h>
//int div=0;
int divide(int,int);
int main()
{
	int m,n,res;
	printf("enter two values:\n");
	scanf("%d%d",&m,&n);
	res=divide(m,n);
	printf("\n%d/%d=%d",m,n,res);
	return 0;	
}
int divide(int x,int y)
{
	int div=0;
	if(x<y)
	{
		return div;
	}
	else
	{
		div++;
		x=x-y;
			return div+divide(x,y);
	}
}
