#include<stdio.h>
int main(){
	int i,j,k,l;
	printf("Enter the number of elements in an array");
	scanf("%d",&k);
	int a[k],b[k];
	for(i=0;i<k;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<k;i++){
		printf("%d",a[i]);
	}
	printf("\n");
	for(i=0;i<k;i++){
		scanf("%d",&b[i]);
	}
	printf("\n");
	for(i=0;i<k;i++){
		printf("%d",b[i]);
	}
	printf("\n");
	int c[k+k];
	l=0,j=0,i=0;
	while(l<(k+k)){
		if(a[i]>b[j]){
			c[l]=b[j];
			j++;
		}
		else{
			c[l]=a[i];
			i++;
		}
		l++;
	}
	for(i=0;i<(k+k);i++){
		printf("%d",c[i]);
	}
}
