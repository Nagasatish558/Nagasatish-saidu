//FCFS
#include<stdio.h>
main(){
	int n,opt,i,j,k,l,m,a;
	printf("Enter the no of process: ");
	scanf("%d",&n);
	char p[n],at[n],et[n],wt[n],ft[n],tat[n],mtat[n];
				for(i=0;i<n;i++){
						printf("Enter the Arrival time for the P%d: ",i+1);
						scanf("%d",&at[i]);
						printf("Enter the Execution time for the P%d: ",i+1);
						scanf("%d",&et[i]);
						p[i]=i+1;
				}
				for(i=0;i<n;i++){
						for(j=i;j<n;j++){
							if(at[i]>at[j]){
								k=at[i];
								l=et[i];
								m=p[i];
								p[i]=p[j];
								p[j]=m;
								et[i]=et[j];
								et[j]=l;
								at[i]=at[j];
								at[j]=k;
							}
								
						}
				}
					for(i=0;i<n;i++){
							if(at[i]>ft[i-1]){
								wt[i]=0;
								ft[i]=at[i]+et[i];
								tat[i]=wt[i]+et[i];
							}
							else{
								if(i==0)
									wt[i]=0;	
								else{
									wt[i]=ft[i-1]-at[i];
								}
								ft[i]=at[i]+et[i]+wt[i];
								tat[i]=et[i]+wt[i];
							}
				
					}
					printf("\nprocess\tAT\tET\tWT\tFT\tTAT");
					for(i=0;i<n;i++){
						printf("\np%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],et[i],wt[i],ft[i],tat[i]);
					}
}
					
