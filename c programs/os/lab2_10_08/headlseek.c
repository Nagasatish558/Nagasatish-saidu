//lseek head
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
main(){
	int fd,c=0,n;
	char buf[1];	
	fd=open("sample.txt",O_RDONLY);
	lseek(fd,0,SEEK_SET);
	printf("enter the no of lines u want from the top fo the file: ");
	scanf("%d",&n);
	while((lseek(fd,0,1))!=-1){
		read(fd,buf,1);
		if(buf[0]=='\n'){
			c++;
		}
		if(c==n)
			break;
		printf("%c",buf[0]);
		
	}
	
}
	
