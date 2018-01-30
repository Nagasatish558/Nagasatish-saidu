#include<stdio.h>
void dec_bin(int n);
main(){
	int n;
	printf("enter the decimal number : ");
	scanf("%d",&n);
	dec_bin(n);

}
void dec_bin(int n){
	static int r,temp,sum=0,j=0,bin[20]={};
	if(n!=0){
		r=n%2;
		bin[j]=r;
		n=n/2;
		j++;
		dec_bin(n);
	}
	else{
		if(j-1>=0){
			printf("%d",bin[j-1]);
			j--;
			dec_bin(n);
		}
	}
}
