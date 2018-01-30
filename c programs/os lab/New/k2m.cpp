#include<fcntl.h>
#include<unistd.h>
main()
{
	int n;
	char buf[100];
	n=read(0,buf,10);
	write(1,buf,n);
	return 0;
}
