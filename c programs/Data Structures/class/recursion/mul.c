#include<stdio.h>
int mul(int,int);
main(){
	int n,m,ans=0;
	printf("enter first number : ");
	scanf("%d",&n);
	printf("enter first number : ");
	scanf("%d",&m);
	ans=mul(n,m);
	printf("Multiplication of two numbers is : %d",ans);
}
int mul(int n,int m){
	static int i=1,sum=0;
	if(n!=0&&m!=0){
		if(i<=m){
			sum=sum+n;
			i++;
			mul(n,m);
		}
		return sum;
	}
}
