#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
main()
{
	int fd,n;
	char ch[100];
	printf("enter data");
	n=read(0,ch,100);
write(1,ch,n);
}
	
