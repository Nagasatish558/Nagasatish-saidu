#include<stdio.h>
#include<math.h>
int decim(int,int);
int dval=0;
int main()
{
	int n,res;
	printf("enter a binary number:");
	scanf("%d",&n);
	res=decim(n,0);
	printf("decimal value of %d is:%d",n,res);
	return 0;
}
int decim(int m,int i)
{
	if(m==0)
		return dval;
	else
		{
			dval+=(m%10)*pow(2,i);
			i++;
		  	return decim(m/10,i);
		}
}
