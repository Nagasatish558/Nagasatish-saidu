#include<stdio.h>
#include<fcntl.h>
main(){
	int fd,t;
	char ch[1];
	fd=open("1.txt",O_RDONLY);
	while((t=read(fd,ch,1))!=0){
		printf("%c",ch[0]);
		lseek(fd,0,1);
		
	}
}
