#include<stdio.h>
main(){
	int n,smallest;
	printf("Enter the no of processes: ");
	scanf("%d",&n);
	int at[n],et[n],rt[20],wt[n],ft[n],tat[n],completed=0,i,time;
	printf("Enter arrival times and execution timesfor Processes:\n");
	for(i=0;i<n;i++){
		scanf("%d%d",&at[i],&et[i]);
		rt[i]=et[i];
	}
	rt[9]=9999;
	printf("\nPid\tAt\tEt\tWt\tFt\tTat");
	for(time=0;completed<n;time++){
		smallest=9;
		for(i=0;i<n;i++)
			if(time>=at[i] && rt[i]>0 && rt[i]<rt[smallest])
				smallest=i;
			rt[smallest]--;
			if(rt[smallest]==0){
				completed++;
				ft[smallest]=time+1;
				wt[smallest]=ft[smallest]-(et[smallest]+at[smallest]);
				tat[smallest]=ft[smallest]-at[smallest];
				printf("\nP%d\t%d\t%d\t%d\t%d\t%d",smallest+1,at[smallest],et[smallest],wt[smallest],ft[smallest],tat[smallest]);
		}
	}
}
