#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
main()
{
	int n,fd[2],pid;
	char buf[100];
	pipe(fd);
	pid=fork();
	if(pid>0)
	{
		close(fd[0]);
printf("enter data into buffer");
		n=read(0,buf,100);
		write(fd[1],buf,n);
		close(fd[1]);
n=read(fd[0],buf,100);
write(0,buf,n);
close(fd[0]);
	}
else if (pid==0)
	{
		close(fd[1]);
		n=read(fd[0],buf,100);
		write(1,buf,n);
		close(fd[0]);
printf("enter data into buffer");
n=read(0,buf,100);
write(fd[1],buf,n);
close(fd[1]);
	}
	
	
}
