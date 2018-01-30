#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
	int fd1,fd2,fd3,n;
	char ch[1];
	fd1=open("input1.txt",O_RDONLY);
	fd2=open("input2.txt",O_RDONLY);
	fd3=open("output1.txt",0_WRONLY|O_TRUNC);
	while(n=read(fd1,ch,1)!=0)
	{
		write(fd3,ch,n);
		if(ch[0]=='\n')
		{
			while((n=read(fd2,ch,1))!=0)
			{
			write(fd3,ch,n);
			if(ch=='\n')
			break;
			lseek(fd2,0,1);
			}
		
		}
		lseek(fd1,0,1);
	}
	while((n=read(fd2,ch,1))!=0)
			{
			write(fd3,ch,n);
			lseek(fd2,0,1);
		}
}
