#include<stdio.h>
struct process{
	int pid,at,et;
};
main()
{
	int n,i,j,wt,ft,tt,time=0;
	float mtat;
	printf("enter number of process");
	scanf("%d",&n);
	struct process arr[n],temp;
	for(i=0;i<n;i++)
	{
		arr[i].pid=i+1;
		printf("enter %d atime and etime",arr[i].pid);
		scanf("%d %d",&arr[i].at,&arr[i].et);
		
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
	printf("execution order\n");
	printf("PID\t AT \tET\t WT \tFT \tTAT\tMTAT\n");
	for(i=0;i<n;i++)
	{
		if(time<arr[i].at)
		time=arr[i].at;
		wt=time-arr[i].at;
		ft=time+arr[i].et;
		tt=ft-arr[i].at;
		mtat=(float)tt/arr[i].et;
		time=ft;
		printf("p%d \t %d \t %d \t%d \t %d \t %d \t %.2f\n",arr[i].pid,arr[i].at,arr[i].et,wt,ft,tt,mtat);
		
}
}
