#include<stdio.h>
main(){
	 int i,j,k,n,pf=0,c;
	 printf("Enter the no of Frmes: ");
	 scanf("%d",&n);
	 printf("Enter the no of words in list: ");
	 scanf("%d",&k);
	 int frame[n];
	 printf("Enter the list: \n");
	 for(i=0;i<k;i++){
			scanf("%d",&list[i]);
	 }
	int list[]={0,1,2,3,2,4,5,1,6,5,2,3,0,1,8};
	 for(i=0;i<n;i++){
		c=0;
		for(j=0;j<i;j++){
			if(list[i]==frame[j]){
					c=1;
			}
		}
		if(c==0){
			frame[i]=list[i];
			pf++;
		}
	 }
	 while(i<k){
			c=0;
			for(j=0;j<n;j++){
				if(list[i]==frame[j]){
					c=1;
					i++;
				}
			}
			if(c==0){
				pf++;
				for(j=0;j<n-1;j++){
					frame[j]=frame[j+1];
				}
				frame[j]=list[i];
				i++;
			}
	 }
	 printf("page fault=%d",pf);
}
