#include<stdio.h>
int prime(int);
main(){
	int n,count;
	printf("enter any numebr : ");
	scanf("%d",&n);
	count=prime(n);
	if(count==2)
		printf("given number is prime...");
	else
		printf("given number is not prime....");
}
int prime(int n){
	static int i=1,coun=0;
	if(i<=n){
		if(n%i==0)
			coun++;
		i++;
		prime(n);
	}
	return coun;
}
