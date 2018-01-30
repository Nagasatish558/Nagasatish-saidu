#include<stdio.h>
struct node{
	int pid,atime,etime,rtime,ftime;
};
int main()
{
	int count,i,j,time=0,wtime,ttime,completed=0,min_pid,min_rtime;
	float mttime;
	printf("Enter no.of processes: ");
	scanf("%d",&count);
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
	printf("\nPID\tAT\tET\tWT\tFT\tTAT\tMTAT");
	completed=0;
	while(completed<count)
	{
		min_pid=-1;min_rtime=1000;
		for(i=0;i<count;i++)
		{
			if(a[i].rtime>0&&a[i].atime<=time&&a[i].rtime<min_rtime)
			{
				min_pid=i;
				min_rtime=a[i].rtime;
			}
		}
		if(min_pid==-1)
		{
			time++;
			continue;
		}
		i=min_pid;
		time+=a[i].rtime;
		a[i].rtime=0;
		a[i].ftime=time;
		printf("\nP%d\t%d\t%d/%d",a[i].pid,a[i].atime,a[i].etime-a[i].rtime,a[i].etime);
		if(a[i].rtime==0)
		{
			completed++;
			wtime=a[i].ftime-(a[i].atime+a[i].etime);
			ttime=a[i].ftime-a[i].atime;
			mttime=(float)ttime/a[i].etime;
			printf("\t%d\t%d\t%d\t%.2f",wtime,a[i].ftime,ttime,mttime);
			time=a[i].ftime;
		}
	}
	printf("\nTotal execution time: %d",time);
	return 0;
}
