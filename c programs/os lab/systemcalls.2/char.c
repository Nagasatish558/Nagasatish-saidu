#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd,t;
	char ch[100];
	fd=open("m.txt",O_RDONLY);
	t=read(0,ch,100);
	write(1,ch,t);
}

