#include<stdio.h>
struct process{
	int pid,at,et,pri;
};
main()
{
	int n,i,j,wt,ft,tt,time=0,highpri;
	float mt;
	printf("enter number of process");
	scanf("%d",&n);
	struct process arr[n],temp;
	for(i=0;i<n;i++)
	{
		arr[i].pid=i+1;
		printf("enter %d atime  etime,priority",arr[i].pid);
		scanf("%d %d %d",&arr[i].at,&arr[i].et,&arr[i].pri);
		
	}
	for(i=0;i<n;i++)
	{
	  for(j=i+1;j<n;j++)
	  {
			if(arr[i].at>arr[j].at)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}


	printf("enter which has highest priority either small or big:0/5:");
	scanf("%d",&highpri);
		time=arr[0].at;
			printf("execution order\n");
	printf("PID\t AT \tET\t PRI \t WT \tFT \tTAT\tMTAT\n");
	for(i=0;i<n;i++)
	{
		if(time<arr[i].at)
		time=arr[i].at;
		switch(highpri)
		{
			case 0:	for(j=i+1;j<n;j++)
				{
					if(arr[i].pri>arr[j].pri&&arr[j].at<=time)
					{
						temp=arr[i];
						arr[i]=arr[j];
						arr[j]=temp;
					}
					
				}
				break;
				case 5:	for(j=i+1;j<n;j++)
					{
						if(arr[i].pri<arr[j].pri&&arr[j].at<=time)
						{
							temp=arr[i];
							arr[i]=arr[j];
							arr[j]=temp;
						}
			       }
			       break;
			       
		}
		wt=time-arr[i].at;
		ft=arr[i].et+time;
   		tt=ft-arr[i].at;
		mt=(float)tt/arr[i].et;
		printf("P%d \t %d \t%d\t %d \t %d \t%d\t %d \t%.2f \n",arr[i].pid,arr[i].at,arr[i].et,arr[i].pri,wt,ft,tt,mt);
		time=ft;
}
}
