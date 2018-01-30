#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd,n,fd1;
	char ch[100];
	fd=open("input.txt",O_RDONLY);
	n=read(fd,ch,100);
	fd1=open("out.txt",O_RDWR);
	write(fd1,ch,n);
	return 0;
}
