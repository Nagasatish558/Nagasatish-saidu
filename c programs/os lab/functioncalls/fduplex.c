#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd1[2],fd2[2],n,pid;
	char buf[0];
	pipe(fd1[2]);
	pipe(fd2[2]);
	pid=fork();
	if(pid>0)
	{
		close(fd1[0]);
		n=read(0,buf,100);
		write(fd1[1],buf,n);
		close(fd1[1]);
		close(fd2[1]);
		n=read(fd2[0],buf,100);
		close(fd2[0]);
		write(1,buf,n);
		
		}
		else if(pid==0){
			close(fd1[1]);
			n=read(0,buf,100);
			close(fd1[0]);
			close(fd2[0]);
			write(fd2[1],buf,100);
			close(fd2[1]);
			
		}
	
	
}
