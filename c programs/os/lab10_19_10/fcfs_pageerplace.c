#include<stdio.h>
mai(){
	int i,j,n,pf=0,c,;
	printf("Enter the no of frames:");
	scanf("%d",&n);
	printf("Enter the no of elements: ");
	scanf("%d",&c);
	int frame[n],word[c];
	printf("Enter the entries: \n");
	for(i=0;i<c;i++){
		scanf("%d",&word[i]);
	}
	for(i=0;i<n;i++){
		frame[i]=word[i];
		pf++;
	}
	while(i<c){
		cheak=0;
		for(j=0;j<n;j++){
			if(word[i]==frame[j]){
				cheak=1;
				break;
			}
		}
		if(cheak==1)
	}
	
}
