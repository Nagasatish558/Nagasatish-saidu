#include<stdio.h>
struct process_node{
	int pid; // Process Id
	int atime; // Arrival Time
	int etime; // Execution Time
	int rtime; // Remaining Time
	int ftime; // Final Time
};
int main(){
	int count,i,j,time=0,wtime,ttime,tquant,etime,completed;
	float mttime;
	printf("Enter number of processes: ");
	scanf("%d",&count);
	printf("Enter Time Quantum: ");
	scanf("%d",&tquant);
	struct process_node arr[count],temp;
	for(i=0;i<count;i++){
		arr[i].pid=i+1;
		printf("P%d Arriving Time: ",arr[i].pid);
		scanf("%d",&arr[i].atime);
		printf("P%d Execution Time: ",arr[i].pid);
		scanf("%d",&arr[i].etime);
		arr[i].rtime=arr[i].etime;
	}
	for(i=0;i<count;i++)
	for(j=1;j<count;j++)
		if (arr[j-1].atime>arr[j].atime){
			temp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=temp;
		}
	printf("Execution Order: \n");
	printf("PID\tAT\tET\tFT\tWT\tTAT\tMTAT\n");
	completed=0;
	while(completed<count){
		j=1;
		for(i=0;i<count;i++)
		if (time>=arr[i].atime && arr[i].rtime>0)
		{
			j=0;
			etime=arr[i].rtime;
			if (etime>tquant)
				etime=tquant;
			arr[i].rtime-=etime;
			time+=etime;		
			arr[i].ftime=time;
			
			// Printing		
			printf("P%d \t%d  \t%d/%d",arr[i].pid,arr[i].atime,arr[i].etime-arr[i].rtime,arr[i].etime);
			if (arr[i].rtime==0){
				wtime=arr[i].ftime-(arr[i].atime+arr[i].etime);
				ttime=arr[i].ftime-arr[i].atime;
				mttime=(float)ttime/arr[i].etime;
				printf("\t%d\t%d\t%d\t%.2f",arr[i].ftime,wtime,ttime,mttime);
				completed++;
			}
			printf("\n");
		}
		if (j)
			time++;
	}
	printf("Total Execution Time: %d\n",time);
	return 0;	
}
