#include<stdio.h>
int main(){
	int i,a,k;
	printf("Enter the number to check: ");
	scanf("%d",&k);
	while(k){
		a=k%2;
		if(a==0){
			k=k/2;
			printf("\t %d",k);
		}
		else
			break;
	}
	if(a==1&&k==1)
		printf("its a power of 2");
	else
		printf("its a not power of 2");		
}
