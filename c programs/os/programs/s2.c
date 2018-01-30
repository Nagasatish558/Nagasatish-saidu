//it is a program for shortest job first scheduling
#include<stdio.h>
struct node
{
	int pid,at,et,wt,ft,rt,tat;
	float mtat;
};
int main()
{
	int count,i,j;
	printf("Enter number of processes:\n");
	scanf("%d",&count);
	//declaring structures
	struct node arr[count],temp;
	//taking times of processes
	printf("Enter arrival and execution times\n");
	for(i=0;i<count;i++)
	{
		scanf("%d%d",&arr[i].at,&arr[i].et);
		arr[i].pid=i+1;	
		arr[i].rt=arr[i].et;
	}
	//sorting
	for(i=0;i<count;i++)
		for(j=1;j<count;j++)
		{
			if (arr[j-1].at>arr[j].at){
				temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
			else if(arr[i].at==arr[j].at && arr[i].et>arr[j].et)
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
		}
	//alogrithm starts
	int completed=0,time=0,flag=1,min=arr[0].at;
	i=0;
	if(i==0)
	{
		time=arr[0].at+arr[0].et;
		arr[0].wt=0;
		arr[0].ft=time;
		arr[0].rt=0;
		arr[min].tat=arr[min].et+arr[min].wt;
		arr[min].mtat=(float)arr[min].tat/arr[min].et;
		completed=1;
	}
	
	int cc=0,bc=0;
	
	while(completed<count)
	{
		bc=0;
		cc=0;
		min=-1;
		for(j=1;j<count;j++)
		{
			if(time>=arr[j].at && arr[j].rt>0)	
			{
				if(bc==0)
				{
					min=j;
					bc++;	
				}
				else if(min!=-1)
				{
					if(arr[j].et<arr[min].et)
					{
						min=j;	
					}
					if(arr[j].et==arr[min].et && arr[min].at>arr[j].at)
					{
						min=j;
					}		
				}
			}
			else
			{
				cc++;	
			}
		}
		if(cc==count-1)
		{
			time++;
		}
		else
		{ 
			time=time+arr[min].et;
			arr[min].wt=time-(arr[min].at+arr[min].et);
			arr[min].ft=time;	
			arr[min].rt=0;
			arr[min].tat=arr[min].et+arr[min].wt;
			arr[min].mtat=(float)arr[min].tat/arr[min].et;
			completed++;
		}
	}
	
	for(i=0;i<count;i++)
	for(j=1;j<count;j++)
		if (arr[j-1].pid>arr[j].pid){
			temp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=temp;
		}
	
	//
	printf("\np\ta\te\tw\tf\tt\tmt\n");
	for(i=0;i<count;i++)
		printf("\np%d\t%d\t%d\t%d\t%d\t%d\t%f",arr[i].pid,arr[i].at,arr[i].et,arr[i].wt,arr[i].ft,arr[i].tat,arr[i].mtat);
	
	return  0;
}
