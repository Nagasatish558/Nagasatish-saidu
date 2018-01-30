#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	int fd,count=0,n=3;
	char ch[1];
	fd=open("3.txt",O_RDONLY);
	lseek(fd,0,SEEK_SET);
	while((lseek(fd,0,1))!=' ')
	{
		read(fd,ch,1);
		printf("%c",ch[0]);
		if(ch[0]=='\n')
		count++;
		if(count==n)
		break;
	}
	return 0;
}
