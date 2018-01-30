#include<stdio.h>
struct proces{
	int pid,wt,et,tat,flag,at,ft;
	float mtat;
};
int main()
{
	int time=0,i,j,b,c,count,completed=0;
	printf("Enter the number of processes:");
	scanf("%d",&count);
	struct proces sj[count];
	struct proces temp;
	for(i=0;i<count;i++){
		sj[i].pid=i+1;
		sj[i].flag=1;
		printf("Enter the Arrival time for the P%d:",i+1);
		scanf("%d",&sj[i].at);
		printf("Enter the Execution time for the P%d:",i+1);
		scanf("%d",&sj[i].et);
	} 
	for(i=0;i<count;i++)
		for(j=1;j<count;j++){
			if(sj[j-1].at>sj[j].at){
				temp=sj[j-1];
				sj[j-1]=sj[j];
				sj[j]=temp;
			}
			else if(sj[i].at==sj[j].at && sj[i].et>sj[j].et){
				temp=sj[i];
				sj[i]=sj[j];
				sj[j]=temp;
			}
		}
	i=0;
	sj[i].wt=0;
	sj[i].ft=sj[i].at+sj[i].et;
	time=sj[i].at+sj[i].et;
	sj[i].tat=sj[i].ft-sj[j].at;
	sj[i].mtat=(float)sj[i].tat/sj[i].et;
	completed++;
	sj[i].flag=0;
	int min;
	while(completed<count){
		c=0;
		b=0;
		min=-1;
		for(i=1;i<count;i++){
			if(time>=sj[i].at && sj[i].flag==1){
				if(b==0){
					min=i;
					b=1;
				}
				else if(min!=-1){
					if(sj[i].et<sj[min].et){
						min=j;
					}
					if(sj[i].et==sj[min].et && sj[min].at>sj[i].at)
						min=j;
				}
			}
			else
				c++;
		}
		if(c==count-1){
			time++;
		}
		else{
			time=time+sj[min].et;
			sj[min].wt=time-(sj[min].at+sj[min].et);
			sj[min].ft=time;	
			sj[min].flag=0;
			sj[min].tat=sj[min].et+sj[min].wt;
			sj[min].mtat=(float)sj[min].tat/sj[min].et;
			completed++;
		}
	}
		
	for(i=0;i<count;i++)
		for(j=1;j<count;j++)
			if (sj[j-1].pid>sj[j].pid){
				temp=sj[j-1];
				sj[j-1]=sj[j];
				sj[j]=temp;
			}
	printf("\np\ta\te\tw\tf\tt\tmt\n");
	for(i=0;i<count;i++)
		printf("\np%d\t%d\t%d\t%d\t%d\t%d\t%f",sj[i].pid,sj[i].at,sj[i].et,sj[i].wt,sj[i].ft,sj[i].tat,sj[i].mtat);		
}
