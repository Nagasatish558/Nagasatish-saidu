#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
main(){
	int n,fd,cc=0,t;
	char buf[1];
	fd=open("sample.txt",O_RDONLY);
	printf("how many line you want to print form end");
	lseek(fd,0,SEEK_END);
	scanf("%d",&t);
	while(1){
		lseek(fd,-2,SEEK_CUR);
		n=read(fd,buf,1);
		if(buf[0]=='\n'){
			cc++;
			if(cc==t)
				break;
			else
				lseek(fd,-1,SEEK_CUR);
							
			}
				printf("%c",buf[0]);
		
	}
}

