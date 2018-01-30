#include<stdio.h>
struct node{
	int pid,atime,etime,rtime,pri;
};
int main()
{
	int count,i,j,time=0,wtime,ttime,ftime,completed=0,p,min_pid,min_pri;
	float mttime;
	printf("Enter no.of processes: ");
	scanf("%d",&count);
	printf("enter value for preemptive or not(0/1): ");
	scanf("%d",&p);
	struct node a[count],temp;
	for(i=0;i<count;i++)
	{
		a[i].pid=i+1;
		printf("P%d ATime & ETime & Priority: ",a[i].pid);
		scanf("%d%d%d",&a[i].atime,&a[i].etime,&a[i].pri);
		a[i].rtime=a[i].etime;
	}
	for(i=0;i<count;i++)
	for(j=1;j<count;j++)
	if(a[j-1].atime>a[j].atime)
	{
		if(a[j-1].pri>a[j].pri)
		{
			temp=a[j-1];
			a[j-1]=a[j];
			a[j]=temp;
		}
	}
	printf("Execution order: \n");
	printf("\nPID\tAT\tET\tPRI\tWT\tFT\tTAT\tMTAT\n");
	while(completed<count)
	{
		min_pid=-1;min_pri=1000;
		for(i=0;i<count;i++)
		{
			if(a[i].rtime>0&&a[i].atime<=time&&a[i].pri<min_pri)
			{
				min_pid=i;
				min_pri=a[i].pri;
			}
		}
		if(min_pid==-1)
		{
			time++;
			continue;
		}
		i=min_pid;
		if(p)
		{
			a[i].rtime-=1;
			time++;
		}
		else
		{
			time+=a[i].rtime;
			a[i].rtime=0;
		}
		printf("\nP%d\t%d\t%d/%d\t%d",a[i].pid,a[i].atime,a[i].etime-a[i].rtime,a[i].etime,a[i].pri);
		if(a[i].rtime==0)
		{
			completed++;
			ftime=time;
			wtime=ftime-(a[i].atime+a[i].etime);
			ttime=ftime-a[i].atime;
			mttime=(float)ttime/a[i].etime;
			printf("\t%d\t%d\t%d\t%.2f\n",wtime,ftime,ttime,mttime);
			time=ftime;
		}
		else
		{
			printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f\n",a[i].pid,a[i].atime,a[i].etime,a[i].pri,wtime,ftime,ttime,mttime);
		}
	}
	printf("\nTotal execution time: %d",time);
	return 0;
}
