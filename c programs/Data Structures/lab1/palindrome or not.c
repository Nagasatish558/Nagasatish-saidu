#include<stdio.h>
int palindrome(int);
main(){
	int n,pal;
	printf("enter any number : ");
	scanf("%d",&n);
	pal=palindrome(n);
	if(pal==n)
		printf("given number is palindrome...");
	else
		printf("given number is not palindrome...");
}
int palindrome(int n){
	static int r,sum=0,temp;
	if(n!=0){
		r=n%10;
		sum=sum*10+r;
		n=n/10;
		palindrome(n);
	}
	else
		return sum;
}
