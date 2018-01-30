#include<stdio.h>
int main(){
	long long int i=0,sum=0,j=1,n,temp=0;
	printf("enter the no of terms in series:");
	scanf("%d",&n);
	while(n){
		printf("%lld\t",sum);
		sum=i+j;
		temp=j;
		j=sum;
		i=temp;
		n--;
	}

	return 0;
}
