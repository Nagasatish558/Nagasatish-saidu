#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd,n,c,t,r=1,count=0;
	char ch[1],m[1];
	printf("enter number lines u want:");
	scanf("%d",&n);
	fd=open("m.txt",O_RDONLY);
	while((t=read(fd,ch,1))!=0)
	{
		if(ch[0]=='\n')
		count=count+1;
	}
	close(fd);
	c=count;
	printf("no of line %d",c);
	int s,cd;
	s=c-n;
	cd=open("m.txt",O_RDONLY);
	while((t=read(cd,m,1))!=0)
	{
		if(m[0]=='\n')
		r=r+1;
		if(r>s)
		{
			printf("%c",m[0]);
		}
	}
}
		
		
