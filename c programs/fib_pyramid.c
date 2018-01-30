#include<stdio.h>
main(){
	int a,b=0,c,i,j,m=0,n;
	printf("enter the no of lines in pyramid:\n");
	scanf("%d",&a);
	for(i=1;i<=a;i++){
		for(j=1;j<=(a-i);j++){
			printf(" ");
		}
		for(c=1;c<=i;c++){
			n=fib(m);
			m++;
			printf("%d ",n);
		}
		printf("\n");
	}
}
int fib(int m){
	int x=1,i=0,y=1,z;
		if(m==0)
			return 0;
		else if(m==1)
			return 1;
		else{
			for(i=3;i<=m;i++){
				z=y;
				y=y+x;
				x=z;
			}
		}
	return y;
}
