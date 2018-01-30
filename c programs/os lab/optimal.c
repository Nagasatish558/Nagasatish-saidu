#include<stdio.h>
main(){
	int process,frames,i,j,remove,fault=0,k,min;
	printf("Enter process and frames  : ");
	scanf("%d%d",&process,&frames);
	int p[process],f[frames],flag=1,next[frames],check=1;
	for(i=0;i<process;i++){
		//printf("Enter pid  : ");
		scanf("%d",&p[i]);
	}
	for(i=0;i<frames;i++){
		f[i]=-1;
	}
	for(i=0;i<process;i++){
		if(flag){
			for(j=0;j<frames;j++){
				if(f[j]==p[i])
					break;
				if(f[j]==-1){
					fault++;
					f[j]=p[i];
					if(j==(frames-1))
						flag=0;
					break;
				}
			}
		}
		else{
			check=1;
			for(j=0;j<frames;j++){
				if(f[j]==p[i]){
					check=0;
				//	printf("same");
					break;
				}
				
			}
			if(check==1){
				for(j=0;j<frames;j++){
					next[j]=0;
					for(k=i;k<process;k++){
						if(f[j]==p[k]){	
							if(k>i)
								next[j]=next[j]+k-i;
							else
								next[j]=next[j]+i-k;
							break;
						}
						if(process==(k+1)){
							k=-1;
							next[j]=process;
						}
							
					}	
				}
				min=next[0];
				for(j=0;j<frames;j++){
					if(min<next[j]){
						min=next[j];
						remove=j;
					}	
				}
				f[remove]=p[i];
				fault++;
			}
		}
	}
	printf("page fault=%d",fault);
}
