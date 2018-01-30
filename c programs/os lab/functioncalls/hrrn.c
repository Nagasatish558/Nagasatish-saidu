#include<stdio.h>
struct process
{
	int pid,et,at;
	float rr;
};
main()
{
	int count,i,j,time=0,wt,ft=0,tt,k;
	float mt;
	printf("ente no of process");
	scanf("%d",&count);
	struct process arr[count],temp;
	for(i=0;i<count;i++)
	{
		arr[i].pid=i+1;
		printf("enter process %d  atime and etime",arr[i].pid);
		scanf("%d %d",&arr[i].at,&arr[i].et);
		
	}
	for(i=0;i<count;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(arr[i].at>arr[j].at)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				
			}
		}
	}
	printf("EXECUTION ORDER");
	printf("\n PID \tAT \tET \tWT\t FT \tTAT\t MTAT");
	for(i=0;i<count;i++)
	{
		if(i!=0)
		{
			for(j=i;j<count;j++)
			{
				
				if(arr[j].at<=time)
			arr[j].rr=((time-arr[j].at)+arr[j].et)/(arr[j].et);
			}
		//sorting based on rr
				for(j=i;j<count;j++)
			{
			for(k=j+1;k<count;k++)
			{
				if(arr[j].rr<arr[k].rr)
				{
					temp=arr[j];
					arr[j]=arr[k];
					arr[k]=temp;
				}
			}
			}
	     }
		
	if(time<arr[i].at)
	time=arr[i].at;
	wt=time-arr[i].at;
	ft=arr[i].at+arr[i].et+wt;
	tt=ft-arr[i].at;
	mt=tt/arr[i].et;	
	printf("\n p%d \t %d \t %d \t %d \t%d \t%d \t%f \n",arr[i].pid,arr[i].at,arr[i].et,wt,ft,tt,mt);
	time=ft;	

}
}
