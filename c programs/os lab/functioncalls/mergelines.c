#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
	int n,fd1,fd2,fd3;
	char ch[1];
	fd1=open("in1",O_RDONLY);
	fd2=open("in2",O_RDONLY);
	fd3=open("out",O_WRONLY|O_TRUNC);
	while((n=read(fd1,ch,1)!=0)
	{
		write(fd3,ch,n);
		if(buf[0]=='\n')
		{
			while((n=read(fd2,ch,1)!=0)
			{
				write(fd3,ch,n);
				if(buf[0]=='\n')
				break;
				lseek(fd2,0,1);
			}
		}
		lseek(fd1,0,10);
		
}
while((n=read(fd2,ch,1)!=0)
{
	write(fd3,ch,n);
	lseek(fd2,0,1);
}
}
