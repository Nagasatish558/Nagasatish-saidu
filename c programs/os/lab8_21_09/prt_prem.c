#include<stdio.h>
main(){
	int n,smallest;
	printf("Enter the no of processes: ");
	scanf("%d",&n);
	int at[n],et[n],rt[20],wt[n],ft[n],prt[n],tat[n],flg[n],completed=0,i,time,high,alt,cc;
	printf("Enter arrival times and execution timesfor Processes:\n");
	for(i=0;i<n;i++){
		scanf("%d%d%d",&at[i],&et[i],&prt[i]);
		rt[i]=et[i];
		flg[i]=1;
	}
	high=0;
	for(i=0;i<n;i++){
		if(prt[i]>prt[high]){
			high=i;
		}
	}
	alt=high;
	printf("\nPid\tAt\tEt\tWt\tFt\tTat");
	for(time=0;completed<n;time++){
		high=alt;
		cc=0;
		for(i=0;i<n;i++)
			if(time>=at[i] && prt[i]<=prt[high] && flg[i]==1 ){
				high=i;
				cc=1;
			}
			if(cc){
				rt[high]--;
				if(rt[high]==0 && flg[high]==1){
						completed++;
						ft[high]=time+1;
						wt[high]=ft[high]-(et[high]+at[high]);
						tat[high]=ft[high]-at[high];
						printf("\nP%d\t%d\t%d\t%d\t%d\t%d",high+1,at[high],et[high],wt[high],ft[high],tat[high]);
						flg[high]=0;
				}
			}
	}
}
