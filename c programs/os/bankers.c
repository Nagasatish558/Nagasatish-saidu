#include<stdio.h>
main(){
	int i,j,k,cheak,p,v,completed=0;
	printf("Enter the no of Resources & Processes: ");
	scanf("%d%d",&v,&p);
	int need[p][v],flag[p],maxins[v],allocation[p][v],max[p][v],available[v];
	printf("Enter the allocation matrix:\n\t");
	for(i=0;i<v;i++){
		printf("%c\t",97+i);
	}
	for(i=0;i<p;i++){
		flag[i]=0;
	}
	for(i=0;i<p;i++){
		printf("\n");
		printf("P[%d]\t",i);
		for(j=0;j<v;j++){
				scanf("%d",&allocation[i][j]);
		}
	}
	printf("Enter the max matrix:\n\t\t ");
	for(i=0;i<v;i++){
		printf("%c",97+i);
	}
	for(i=0;i<p;i++){
		printf("\n");
		printf("P[%d]\t",i);
		for(j=0;j<v;j++){
				scanf("%d",&max[i][j]);
		}
	}
	for(i=0;i<p;i++){
		for(j=0;j<v;j++){
				need[i][j]=max[i][j]-allocation[i][j];
		}
	}		
	printf("Enter the availability of each resources:\n");
	for(i=0;i<v;i++){
		printf("%c=",97+i);
		scanf("%d",&available[i]);
	}
	while(completed<p){
		
		for(i=0;i<p;i++){
			cheak=0;
			for(j=0;j<v;j++){
				if(available[j]>=need[i][j])
					cheak=1;
				else{
					cheak=0;
					break;
				}
			}
			if(cheak==1 && flag[i]==0){
				completed++;
				printf("P[%d]\t",i);
				for(k=0;k<v;k++)
					available[k]=available[k]+allocation[i][k];
				flag[i]=1;
			}
		}
	}
}
