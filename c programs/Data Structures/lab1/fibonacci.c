#include<stdio.h>
int fib(int);
main(){
	int n,sum;
	printf("enter any number : ");
	scanf("%d",&n);
	sum=fib(n);
	printf("\nsum of numbers is : %d\n",sum);
}
int fib(int n){
	static int p=0,q=1,s=0,temp;
	if(q<=n){
		p=p+q;
		s=s+q;
		printf("%d\t",q);
		temp=p;
		p=q;
		q=temp;
		fib(n);
	}
	else 
		return s;
}
