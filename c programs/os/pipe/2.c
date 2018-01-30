//create pipe read from keyboard,half duplex
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
main()
{
	int n,m,pid,fd[2];
	char buf[100],buf2[100];
	pipe(fd);
	pid=fork();
	if(pid==0){
		close(fd[0]);
		m=read(0,buf,100);
		write(fd[1],buf,m);
		close(fd[1]);		

	}
	else if(pid>0)
	{
		
		close(fd[1]);
		n=read(fd[0],buf,100);
		write(1,buf,n);
		close(fd[0]);
	}
}
