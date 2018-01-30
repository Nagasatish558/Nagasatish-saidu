#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
	int t,fd,cd,rd;
	char ch[1];
	fd=open("m.txt",O_RDONLY);
	cd=open("n.txt",O_RDONLY);
	rd=open("s.txt",O_WRONLY);
	while(t=read(fd,ch,1)!=0)
	{
		write(rd,ch,t);
		if(ch[0]=='/n')
		{
			while(t=read(cd,ch,1)!=0)
			{
				write(rd,ch,t);
				lseek(cd,0,1);
				if(ch[0]=='\n')
				break;
			}
		}
	}
	while(t=read(fd,ch,1)!=0)
	{
		write(rd,ch,t);
		lseek(fd,0,1);
	}
	close(fd);
	close(rd);
	close(cd);
	return 0;
}
		
