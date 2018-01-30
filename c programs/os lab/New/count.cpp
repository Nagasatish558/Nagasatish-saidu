#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
main()
{
	int fd,t,vowels=0,space=0,lines=0;
	char ch[1];
	fd=open("b.txt",O_RDONLY);
	while((t=read(fd,ch,1))!=0)
	{
		if(ch[0]=='a'||ch[0]=='e'||ch[0]=='i'||ch[0]=='o'||ch[0]=='u')
		vowels=vowels+1;
		if(ch[0]==' ')
		space=space+1;
		if(ch[0]=='\n')
		lines=lines+1;
		lseek(fd,0,1)
	}
	printf("%d\t%d\t%d",vowels,space,lines);
	return 0;
}
