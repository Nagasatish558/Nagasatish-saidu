#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
main()
{
	int n=0,r,fd,s=0,co;
	printf("enter c");
	scanf("%d",&co);
	char ch[1],c[1];
	fd=open("3.txt",O_RDONLY);
	while((r=read(fd,ch,1))!=0)
	{
		if(ch[0]=='\n')
		{
			s++;
		}
	}
	close(fd);
	fd=open("3.txt",O_RDONLY);
	while((r=read(fd,c,1))!=0)
	{
		lseek(fd,0,1);
		if(c[0]=='\n')
		{
			n++;
		}
		if(n>s-co)
		{
			printf("%c",c[0]);
			lseek(fd,0,1);
		}
	}
	return 0;
}
