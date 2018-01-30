#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
main()
{
	int n,fd;
	char buf[100];
	fd=open("11.txt",O_CREAT|O_EXCL|O_RDWR,777);
	n=read(0,buf,100);
	write(fd,buf,n);
	
	
}
