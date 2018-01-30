#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	int fd1,fd2,fd3,n;
	char ch[1];
	fd1=open("a.txt",O_RDONLY);
	fd2=open("b.txt",O_RDONLY);
	fd3=creat("merge.txt",777);
	while((n=read(fd1,ch,1))!=0)
	{
		write(fd3,ch,n);
		if(ch[0]=='\n')
		{
			while((n=read(fd2,ch,1))!=0)
			{
				write(fd3,ch,n);
				lseek(fd2,0,1);
				if(ch[0]=='\n')
				break;
			}
		}
		lseek(fd1,0,1);
	}
	while((n=read(fd2,ch,1))!=0)
	{
		write(fd3,ch,n);
		lseek(fd2,0,1);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}
