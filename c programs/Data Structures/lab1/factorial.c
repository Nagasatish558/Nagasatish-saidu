#include<stdio.h>
int factorial(int);
main(){
	int n,fact;
	printf("enter any number : ");
	scanf("%d",&n);
	fact=factorial(n);
	printf("factorial is : %d\n",fact);
}
int factorial(int n){
	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
}
