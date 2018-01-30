#include<stdio.h>
int divide(int ,int );
int main()
{
int a,b,dd,div,res=0;
printf("enter a,b values:");
scanf("%d%d",&a,&b);
	if(a>b)
	{
	dd=a;
	div=b;
	}
	else
	{
	dd=b;
	div=a;
	}
res=divide(dd,div);
printf("%d is the value:",res);
}
int divide(int dd,int div)
{
int c;
c=(dd-div);
if(c<0)
return 0;
else
return(divide (c,div)+1);
}
