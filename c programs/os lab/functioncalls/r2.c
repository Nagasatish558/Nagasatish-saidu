#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
main()
{
	int n,fd;
	char ch[1000];
	fd=open("input1.txt",O_RDONLY);
	n=read (fd,ch,100);
	write(1,ch,n);

}
