#include<stdio.h>
main()
{
	int at[10],et[10],ft[10],tat[10],flg[10],i,wt[10],smallest;
	int completed=0,n,time=0;
	printf("Enter no of Processes : ");
	scanf("%d",&n);
	printf("Enter arrival time & execution times for Processes: ");
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&at[i],&et[i]);
		flg[i]=1;
	}
	printf("\nPid\tAt\tEt\tWt\tFt\tTat");
	et[9]=9999;
	while(completed<n)
	{
		smallest=9;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && et[i]<et[smallest] && flg[i]==1)
			{	
				smallest=i;
			}
		}
		if(flg[smallest]==1 && smallest!=9){
			time=time+et[smallest];
			ft[smallest]=time;
			wt[smallest]=time-(at[smallest]+et[smallest]);
			tat[smallest]=time-at[smallest];
			flg[smallest]=0;
			completed++;
			printf("\nP%d\t%d\t%d\t%d\t%d\t%d",smallest+1,at[smallest],et[smallest],wt[smallest],ft[smallest],tat[smallest]);	
		}
		else if(smallest==9)
			time++;
	}
}

