#include<stdio.h>
main(){
	int n,smallest,max=0,j=0;
	printf("Enter the no of processes: ");
	scanf("%d",&n);
	int at[n],et[n],rt[20],wt[n],ft[n],tat[n],completed=0,i,time;
	printf("Enter arrival times and execution timesfor Processes:\n");
	for(i=0;i<n;i++){
		scanf("%d%d",&at[i],&et[i]);
		rt[i]=et[i];
	}
	for(i=0;i<n;i++)
		if(rt[max]<rt[i])
			max=i;
	rt[n]=rt[max]+1;
	max=n;
	printf("\nPid\tAt\tEt\tWt\tFt\tTat");
	for(time=0;completed<n;time++){
		smallest=max;
		j=0;
		for(i=0;i<n;i++)
			if(time>=at[i] && rt[i]>0 && rt[i]<rt[smallest])
				{
					smallest=i;
					j=1;
				}
		if(j==1){
			rt[smallest]--;
			if(rt[smallest]==0){
				completed++;
				ft[smallest]=time+1;
				wt[smallest]=ft[smallest]-(et[smallest]+at[smallest]);
				tat[smallest]=ft[smallest]-at[smallest];
				printf("\nP%d\t%d\t%d\t%d\t%d\t%d\n",smallest+1,at[smallest],et[smallest],wt[smallest],ft[smallest],tat[smallest]);
			}
		}
	}
}

