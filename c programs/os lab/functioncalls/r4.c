#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
main()
{
	int n,fd;
	char ch[100];
	n=read(0,ch,100);
	fd=open("begum.txt",777);
	write(fd,ch,n);

}
