#include<stdio.h>
main(){
	int max,n,i,j,time=0,temp,tmp,compltd=0;
	float rr,rr2;
	printf("Enter the no of processes: ");
	scanf("%d",&n);
	int at[n],et[n],wt[n],ft[n],tat[n],flg[n];
	printf("\nEnter the arrival and exection time for the processes: \n");
	for(i=0;i<n;i++){
		scanf("%d%d",&at[i],&et[i]);
		flg[i]=0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			if(at[i]<at[j]){
				tmp=at[i];
				at[i]=at[j];
				at[j]=tmp;
				tmp=et[i];
				et[i]=et[j];
				et[j]=tmp;
			}
	}
		printf("\nPID\tAT\tET\tFT\tWT\tTAT");
		i=0;
		time=at[i];
		ft[i]=at[i]+et[i];
		time=ft[i];
		wt[i]=0;
		tat[i]=ft[i]-wt[i];
		compltd++;
		flg[i]=1;
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d",temp+1,at[temp],et[temp],ft[temp],wt[temp],tat[temp]);
	while(compltd<n){
		tmp=0;
		temp=0;
		for(i=1;i<n;i++){
			if(flg[i]==0 && at[i]<=time && tmp==0){
				tmp=1;
				rr=(float)((time-at[i])+et[i])/(et[i]);
				max=i;
				temp=1;
			}
			else if(flg[i]==0 && at[i]<=time && tmp==1){
				rr2=(float)((time-at[i])+et[i])/(et[i]);
				if(rr2>rr){
					rr=rr2;
					max=i;
					temp=1;
					printf("\t%f",rr2);
				}	
			}
		}
		if(temp==1 && flg[max]==0){
			flg[max]=1;
			wt[max]=time-at[max];
			time=time+et[max];
			ft[max]=time;
			tat[max]=time-at[max];
			printf("\nP%d\t%d\t%d\t%d\t%d\t%d",max+1,at[max],et[max],ft[max],wt[max],tat[max]);
			compltd++;
		}
		if(temp==0)
			time++;
	}
}

