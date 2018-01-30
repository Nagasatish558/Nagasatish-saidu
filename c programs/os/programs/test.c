#include<stdio.h>
main(){
	int a[10],i,j,k=0;
	for(i=0;i<7;i++)
		scanf("%d",&a[i]);
	for(i=0;i<7;i++)
		for(j=0;j<7;j++)
			if(a[i]>a[j]){
				k=i;				
		}
	printf("%d\thel",k);
}
