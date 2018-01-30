#include<stdio.h>
struct process{
	int pid,ft,at,et,tat,wt,flag;
	float mtat;
};
main(){
	int c=0,b=0,min,n,k,i,j,time=0,completed=0;
	printf("\nEnter the no of processes:");
	scanf("%d",&n);
	struct process sjf[n],temp;
	for(i=0;i<n;i++){
		sjf[i].pid=i+1;
		sjf[i].flag=1;
		printf("\nEnter the Arrival time for the P%d:",i+1);
		scanf("%d",&sjf[i].at);
		printf("\nEnter the Exection time for the P%d:",i+1);
		scanf("%d",&sjf[i].et);
	}
	for(i=0;i<n;i++)
		for(j=1;j<n;j++){
			if(sjf[j-1].at>sjf[j].at){
				temp=sjf[j-1];
				sjf[j-1]=sjf[j];
				sjf[j]=temp;		
			}
		}
	min=0;
	if(sjf[min].flag==1){
			sjf[min].wt=0;
			time=time+sjf[min].et;
			sjf[min].ft=time;
			sjf[min].tat=sjf[min].et+sjf[min].wt;
			sjf[min].flag=0;
			completed++;
		}
		
	while(completed<n){
		b=0;
		c=0;
		min=-1;
		for(i=1;i<n;i++){
			if(sjf[i].at<=time && sjf[i].flag==1){
				if(b==0){
					min=i;
					b++;
				}		
				else if(min!=-1){
					if(sjf[i].et<sjf[min].et)
					{
						min=j;	
					}
					if(sjf[j].et==sjf[min].et && sjf[min].at>sjf[j].at)
					{
						min=j;
					}	
				}
			}
			else
				c++;
			
		}
		if(c==n-1){
			time++;
		}			
		else
		{
			time=time+sjf[min].et;
			sjf[min].wt=time-(sjf[min].at+sjf[min].et);
			sjf[min].ft=time;	
			sjf[min].flag=0;
			sjf[min].tat=sjf[min].et+sjf[min].wt;
			sjf[min].mtat=(float)sjf[min].tat/sjf[min].et;
			completed++;
		}
		
	
	}

	printf("\nPID\tAT\tET\tFT\tWT\tTAT\tMTAT\n");
	for(i=0;i<n;i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",sjf[i].pid,sjf[i].at,sjf[i].et,sjf[i].ft,sjf[i].wt,sjf[i].tat);
	}
	
		
	
}
