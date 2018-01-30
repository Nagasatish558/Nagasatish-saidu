#include<fcntl.h>
#include<unistd.h>
main()
{
	int n,fd;
	char buf[100];
	fd=open("1.txt",O_RDONLY);
	n=read(fd,buf,100);
	fd=creat("2.txt",O_WRONLY);
	write(fd,buf,n);
	return 0;
}
