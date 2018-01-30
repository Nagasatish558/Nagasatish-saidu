#include<stdio.h>
int mul(int a,int b);
int main()
{
int a,b,res=0;
printf("enter a,b values:");
scanf("%d%d",&a,&b);
res=mul(a,b);
printf("%d is the value:",res);
}
int mul(int a,int b)
{
if(b==0)
return 0;
else
return (mul(a,b-1)+a);
}
