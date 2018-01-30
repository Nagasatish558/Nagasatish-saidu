#include<stdio.h>
struct node{
	int at,et,wt,prt,tat,ft,flag,pid;
};
main(){
	int a,n,i,j,cmpltd=0,time,alt,small;
	printf("Enter the no of process: ");
	scanf("%d",&n);
	struct node p[n],temp;
	printf("Enter the values:\nAT\tEt\tPriority\n");
	for(i=0;i<n;i++){
		scanf("%d%d%d",&p[i].at,&p[i].et,&p[i].prt);
		p[i].pid=i+1;
		p[i].flag=1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(p[i].at<p[j].at){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	
	small=0;
	for(i=0;i<n;i++){
		if(p[i].prt>p[small].prt){
				small=i;
		}
	}
	alt=small;
	time=p[i].at;
	while(cmpltd<n){
		
		small=alt;
		a=0;
		for(i=0;i<n;i++){
			if(p[i].at<=time && p[i].prt<=p[small].prt && p[i].flag==1){
					small=i;
					a=1;
			}
		}
		if(a==1 && p[small].flag==1){
			time=time+p[small].et;
			p[small].ft=time;
			p[small].wt=p[small].ft-(p[small].et+p[small].at);
			p[small].tat=p[small].ft-p[small].at;
			p[small].flag=0;
			cmpltd++;
		}
		else if(a==0)
			time++;
	}
	printf("\nprocess\tAT\tET\tPriority WT\tFT\tTAT");
	for(i=0;i<n;i++){
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].et,p[i].prt,p[i].wt,p[i].ft,p[i].tat);
	}
}
