#include<stdio.h>
main(){
	int a,i,j,c,found,k,n,pf=0;
	printf("Enter the no of frames: ");
	scanf("%d",&n);
	printf("Enter the no of words in list: ");
	scanf("%d",&k);
	int frames[n],lru[n];
	printf("Enter the list: \n");
	/*for(i=0;i<k;i++){
			scanf("%d",&list[i]);
	}*/
	int list[]={0,1,2,3,2,4,5,1,6,5,2,3,0,1,8};
	for(i=0;i<n;i++){
		c=0;
		for(j=0;j<i;j++){
			if(list[i]==lru[j]){
					c=1;
					found=j;
			}
		}
		if(c==0){
			lru[j]=list[i];
			pf++;
		}
		else{
			for(j=found;j<i;j++){
					lru[j]=lru[j+1];		
			}
			j--;
		}
		lru[j]=list[i];
		printf("\n%d--->",list[i]);
		for(a=0;a<i;a++)
			printf("%d\t",lru[a]);
		printf("pf=%d",pf);
		
	}	
	while(i<k){
			c=0;
			for(j=0;j<n;j++){
				if(list[i]==lru[j]){
					c=1;
					found=j;
				}
			}
			if(c==1&&pf<n){
				for(j=found;j<pf;j++){
					lru[j]=lru[j+1];
				}
				lru[pf]=list[i];
				pf++;
			}
			else if(c==0&&pf<n){
				lru[pf]=list[i];
				pf++;
			}
			else if(c==1){
				for(j=found;j<n-1;j++){
					lru[j]=lru[j+1];
				}
				lru[j]=list[i];
	 		}
	 		else if(c==0){
				for(j=0;j<n;j++){
					lru[j]=lru[j+1];
				}
				j--;
				lru[j]=list[i];
				pf++;
			}
			printf("\n%d--->",list[i]);
			for(a=0;a<n;a++)
				printf("%d\t",lru[a]);
			printf("pf=%d",pf);
			i++;
	}
}
	
	 
	 	

