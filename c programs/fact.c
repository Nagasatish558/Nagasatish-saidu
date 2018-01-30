#include<stdio.h>
main(){
	int n,i,temp=1;
	printf("Enter the number: ");
	scanf("%d",&n);
	printf("\n the value is: %d",fact(n));
	for(i=1;i<=n;i++){
		temp=temp*i;
	}
	printf("\n the value is: %d",temp);
}
int fact(int n){
	if(n==1)
		return 1;
	else
		return (n*fact(n-1));
}
