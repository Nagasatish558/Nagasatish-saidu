#include<stdio.h>
int div(int,int);
main(){
	int n,m,ans=0;
	printf("enter first number : ");
	scanf("%d",&n);
	printf("enter first number : ");
	scanf("%d",&m);
	ans=div(n,m);
	printf("division of two numbers is : %d",ans);
}
int div(int n,int m){
	static int count=0;
	if(n==0||n<m)
		return 0;
	else if(m==0)
		printf("ans is infinite....");
	else{
		if(n>=m){
			n=n-m;
			count++;
			div(n,m);
		}
	}
	return count;
}
