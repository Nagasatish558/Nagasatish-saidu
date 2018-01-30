#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
main(){
	int fd,t,spaces=0,lines=1;
	char ch[1];
	fd=open("3.txt",O_RDONLY);
	
	while((t=read(fd,ch,1))!=0){
		if(ch[0]==' ')
		{
			spaces=spaces+1;
		}
		if(ch[0]=='\n')
			lines++;
		lseek(fd,0,1);
			
	}
printf("No of spaces is=%d\n",spaces);
printf("No of lines is=%d",lines);
}
