#include<stdio.h>
struct node{
	int pid,atime,etime,rtime,ftime;
};
int main()
{
	int count,i,j,time=0,wtime,ttime,completed,etime,tq;
	float mttime;
	printf("Enter no.of processes: ");
	scanf("%d",&count);
	printf("enter time quantum: ");
	scanf("%d",&tq);
	struct node a[count],temp;
	for(i=0;i<count;i++)
	{
		a[i].pid=i+1;
		printf("P%d ATime & ETime: ",a[i].pid);
		scanf("%d%d",&a[i].atime,&a[i].etime);
		a[i].rtime=a[i].etime;
	}
	for(i=0;i<count;i++)
	for(j=1;j<count;j++)
	if(a[j-1].atime>a[j].atime)
	{
		temp=a[j-1];
		a[j-1]=a[j];
		a[j]=temp;
	}
	printf("Execution order: \n");
	printf("PID\tAT\tET\tWT\tFT\tTAT\tMTAT\n");
	completed=0;
	while(completed<count)
	{
		j=1;
		for(i=0;i<count;i++)
		if(time>=a[i].atime&&a[i].rtime>0)
		{
			j=0;
			etime=a[i].rtime;
			if(etime>tq)
			{
				etime=tq;
			}
			a[i].rtime-=etime;
			time+=etime;
			a[i].ftime=time;
			printf("P%d\t%d\t%d/%d",a[i].pid,a[i].atime,a[i].etime-a[i].rtime,a[i].etime);
			if(a[i].rtime==0)
			{
				wtime=a[i].ftime-(a[i].atime+a[i].etime);
				ttime=a[i].ftime-a[i].atime;
				mttime=(float)ttime/a[i].etime;
				printf("\t%d\t%d\t%d\t%.2f\n",wtime,a[i].ftime,ttime,mttime);
				completed++;
			}
			printf("\n");
		}
		if(j)
		{
			time++;
		}
	}
	printf("Total execution time: %d",time);
	return 0;
}
