#include<stdio.h>
int main(){
	int t,n,i,j=0,min;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int a[n];
		scanf("%d",&a[0]);
		min=a[0];
		for(i=1;i<n;i++){
			scanf("%d",&a[i]);
			if(min>a[i])
				min=a[i];	
		}
		j=0;
		for(i=0;i<n;i++){
			if(min==a[i])
				j++;
		}
		if(j%2==1)
			printf("Lucky\n");
		else
			printf("Unlucky\n");
	}
	return 0;
}
