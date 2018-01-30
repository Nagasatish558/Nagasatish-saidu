//Round Robin
#include<stdio.h>
main(){
	int n,opt,i,j,k,l,m,a,t,finished=0,totaltime=0,z;
	printf("Enter the no of process: ");
	scanf("%d",&n);
	char p[n],f[n],at[n],et[n],wt[n],ft[n],ct[100],tat[n],mtat[n],cm[n];
	printf("\n 1.Arrival at same time\n 2.Arrival at different time\n Choose your option: ");
	scanf("%d",&opt);
	printf("\nEnter the time quantum: ");
	scanf("%d",&t);
	switch(opt){
		case 1:
			printf("\nEnter the Arrival time: ");
			scanf("%d",&z);
			for(i=0;i<n;i++){
				printf("Enter the Execution time for the P%d: ",i+1);
						scanf("%d",&et[i]);
						at[i]=z;
						p[i]=i+1;
			}
		for(i=0;i<n;i++){
			cm[i+1]=0;
			ct[i]=0;
		}
		totaltime=z;

			while(finished<n){
				for(i=0;i<n;i++){
					if((et[i]-ct[i])>t){
						ct[i]=ct[i]+t;
						totaltime=totaltime+t;
					}
					else{
						if(cm[i+1]!=p[i]){
								wt[i]=totaltime-ct[i]-at[i];
								totaltime=totaltime+(et[i]-ct[i]);
								ft[i]=totaltime;
								tat[i]=et[i]+wt[i];
								cm[i+1]=p[i];
								finished=finished+1;
								printf("ok");
						}
					}
				}

			}
			printf("\nprocess\tAT\tET\tWT\tFT\tTAT");
			for(i=0;i<n;i++){
				printf("\np%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],et[i],wt[i],ft[i],tat[i]);
			}
			break;
			case 2:
				for(i=0;i<n;i++){
					printf("Enter the Arrival time for the p%d: ",i+1);
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
			cm[i+1]=0;
			ct[i]=0;
			}
			while(finished<n){
				for(i=0;i<n;i++){
					if(cm[i+1]!=p[i]){
						if(at[i]<=totaltime){
							if((et[i]-ct[i])>t){
								ct[i]=ct[i]+t;
								totaltime=totaltime+t;
							}
							else{
								wt[i]=totaltime-at[i]-ct[i];
								totaltime=totaltime+(et[i]-ct[i]);
								ft[i]=totaltime;
								tat[i]=wt[i]+et[i];
								finished=finished+1;
								cm[i+1]=p[i];
							}
						}
					}
				}
			}
			printf("\nprocess\tAT\tET\tWT\tFT\tTAT");
			for(i=0;i<n;i++){
				printf("\np%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],et[i],wt[i],ft[i],tat[i]);
			}

	
	}
}
