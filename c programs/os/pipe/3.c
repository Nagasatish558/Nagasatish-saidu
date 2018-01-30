//full duplex for pipe
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
main(){
	int n,m,pid,fd1[2],fd2[2];
	char buf[100],buff[100];
	pipe(fd1);
	pipe(fd2);
	pid=fork():
	if(pid==0)
	{
		close(fd1[1];//close read for fd1[
		n=read(0,buf,100);
		write(fd1[0],buf,n);
		write(fd2[1],fd1[0]);
	}
	else if(pid>0)
	{
		
		close(fd1[1]);
		n=read(fd2[0],buf,100);
		write(1,buf,n);
		close(fd2[0]);
		m=read(0,buf,100);
		write(fd1[0],buf,m);
		close(fd1[0]);
	}
