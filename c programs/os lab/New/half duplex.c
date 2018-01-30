#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd[2],n,pid;
	char buf[30];
	pipe(fd);
	pid=fork();
	if(pid==0)
	{
		close(fd[1]);
		n=read(fd[0],buf,30);
		write(1,buf,n);
		close(fd[0]);
	}
	else if(pid>0)
	{
		close(fd[0]);
		read(fd[1],buf,30);
		n=read(0,buf,30);
		write(fd[1],buf,n);
		close(fd[1]);
	}
	return 0;
}
