#include<stdio.h>
main(){
	int n,i,q,j,at[10],et[10],rt[10],wt[10],tat[10],ft[10],time,total=0,p[10],flg[10],tmp;
	printf("Enter the no of processes: ");
	scanf("%d",&n);
	printf("\nEnter the arrival and execution times: ");
	for(i=0;i<n;i++){
		scanf("%d%d",&at[i],&et[i]);
		rt[i]=et[i];
		p[i]=i+1;
		flg[i]=1;
	}
	printf("\nEnter the quantum: ");
	scanf("%d",&q);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(at[i]<at[j]){
				tmp=at[i];
				at[i]=at[j];
				at[j]=tmp;
				tmp=et[i];
				et[i]=et[j];
				et[j]=tmp;
				tmp=rt[i];
				rt[i]=rt[j];
				rt[j]=tmp;				
				tmp=p[i];
				p[i]=p[j];
				p[j]=tmp;
			}
	time=at[0];
	while(total<n){
		for(i=0;i<n;i++){
				if(rt[i]>q && at[i]<=time){
					rt[i]=rt[i]-q;
					time=time+q;
					printf("P%d->%d\t",p[i],q);
				}
				else if(rt[i]<=q && flg[i]!=0 && at[i]<=time){
					time=time+rt[i];
					printf("P%d->%d\t",p[i],rt[i],time);
					ft[i]=time;
					wt[i]=time-(at[i]+et[i]);
					tat[i]=time-at[i];
					total++;
					flg[i]=0;
				
				}
				else if(flg[i]!=0 && at[i]>time){
				
					time++;
					i--;
				}
			
		}
		
	}
			printf("\nprocess\tAT\tET\tWT\tFT\tTAT");
			for(i=0;i<n;i++){
					printf("\np%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],et[i],wt[i],ft[i],tat[i]);
			}
	
}
