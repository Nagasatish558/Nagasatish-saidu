#include<stdio.h>
int bin_dec(int);
int pow(int,int);
main(){
	int n,dec;
	printf("enter any number : ");
	scanf("%d",&n);
	dec=bin_dec(n);
	printf("decimal number is : %d",dec);
}
int bin_dec(int n){
	static int r,temp,sum=0,j=0;
	if(n!=0){
		r=n%10;
		sum=sum+(pow(2,j)*r);
		n=n/10;
		j++;
		bin_dec(n);
	}
	return sum;
}
int pow(int x,int y){
	static int i=1,sum=1;
	if(i<=y){
		sum=sum*x;
		i++;
		pow(x,y);
	}
	else
		return sum;
}
