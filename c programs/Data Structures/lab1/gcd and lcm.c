#include<stdio.h>
int gcd_lcm(int,int);
main(){
	int m,n,gcd;
	printf("enter any numebr : ");
	scanf("%d",&m);
	printf("enter any numebr : ");
	scanf("%d",&n);
	gcd=gcd_lcm(m,n);
	printf("gcd is : %d\n",gcd);
	printf("lcm is : %d\n",(m*n)/gcd);
	
}
int gcd_lcm(int m,int n){
	static int r,temp;
	r=m%n;
	if(r!=0){
		temp=n;
		m=n;
		n=r;
		gcd_lcm(m,n);	
	}
	else
		return n;
}
