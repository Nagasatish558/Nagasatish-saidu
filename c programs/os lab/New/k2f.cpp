#include<fcntl.h>
#include<unistd.h>
main()
{
	int n,fd;
	char buf[100];
	n=read(0,buf,100);
	fd=creat("1.txt",777);
	write(fd,buf,n);
	return 0;
}
