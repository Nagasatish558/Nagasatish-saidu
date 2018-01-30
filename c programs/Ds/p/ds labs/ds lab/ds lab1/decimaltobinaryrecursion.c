#include<stdio.h>
#include<math.h>
int binary(int,int);
int binarynum=0;
int main()
{
	int n,a;
	printf("enter a decimal value :");
	scanf("%d",&n);
	a=binary(n,0);
	printf("binary form for %d is :%d",n,a);
	return 0;	
}
int binary(int x,int i)
{
	if(x==0)
		return binarynum;
	else
	{
		binarynum+=(x%2)*pow(10,i);
		//x=x/2;
		i++;
		binary(x/2,i);
	}
}
