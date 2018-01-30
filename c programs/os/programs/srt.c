#include<stdio.h>
struct node{
	int pid,at,et,wt,ft,tat,flag,rt;
	float mtat;
};
main(){
	int completed=0,i,j,k,n,count,a,b,c,time=0,tmp=0,min=0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	struct node srt[n];
	struct node temp;
	for(i=0;i<n;i++)
	{
		srt[i].pid=i+1;
		printf("\nEnter the Arrival time for the P%d:",i+1);
		scanf("%d",&srt[i].at);
		printf("\nEnter the Execution time for the P%d:",i+1);
		scanf("%d",&srt[i].et);
		srt[i].flag=1;
		srt[i].rt=srt[i].et;
	}
	for(i=0;i<n;i++)
		for(j=1;j<n;j++)
		{
			if(srt[j-1].at>srt[j].at)
			{
				temp=srt[j-1];
				srt[j-1]=srt[j];
				srt[j]=temp;
			}
			if(srt[j-1].at==srt[j].at && srt[j-1].et>srt[j].et)
			{
				temp=srt[j-1];
				srt[j-1]=srt[j];
				srt[j]=temp;	
			}
			
		}
	while(completed<n)
	{
	
		for(i=0;i<n;i++)
		{	
			if(srt[i].at<=time && srt[i].flag==1)
				for(j=0;j<n;j++)
					{
						if(srt[j].at==time && srt[i].rt>srt[j].rt && srt[j].flag==1)
						{
							i=j;
							printf("pid is %d\t%d\n",srt[i].pid,srt[i].at);		
						}
						else if(srt[i].rt==0 && srt[i].flag==0)
						{	
							for(k=0;k<n;k++)
								for(a=0;a<n;a++)
									if(time>=srt[k].at && srt[k].flag==1 && time>=srt[a].at && srt[a].flag==1){
										if(srt[k].rt>srt[a].rt && srt[a].flag==1&&srt[a].rt!=0)
											min=a;
								}
							i=min;
							printf("min is %d\n",srt[i].rt);
								
						}
						if(srt[i].rt>0){
							time++;
							srt[i].rt--;
						}
						if(srt[i].rt==0 && srt[i].flag==1){
							srt[i].ft=time;
							srt[i].wt=time-(srt[i].at+srt[i].et);
							srt[i].tat=time-srt[i].at;
							srt[i].flag=0;
							completed++;
						}
						
					}	
			
		}
	}
	printf("\np\ta\te\tw\tf\tt\tmt\n");
	for(i=0;i<n;i++)
		printf("\np%d\t%d\t%d\t%d\t%d\t%d",srt[i].pid,srt[i].at,srt[i].et,srt[i].wt,srt[i].ft,srt[i].tat);		
}
