//factorial
#include<stdio.h>
int main(){
	int n,i=1;
	printf("Enter the value: ");
	scanf("%d",&n);
	while(n){
		i=i*n;
		n--;
	}
	printf("The factorial value is %d",i);
	return 0;
}

