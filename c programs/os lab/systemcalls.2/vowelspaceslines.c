#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
main()
{
	int fd,t,l=0,v=0,s=0;
	char ch[1];
	fd=open("m.txt",O_RDONLY);
	while(t=read(fd,ch,1)!=0)
	{
		if(ch[0]=='a'||ch[0]=='e'||ch[0]=='i'||ch[0]=='o'||ch[0]=='u')
		{
			v++;
		}
		else if(ch[0]==' ')
		{
			s++;
		}
		else if(ch[0]=='\n')
		{
			l++;
		}
	}
	printf("the no of lines %d\n",l);
	printf("the no of vowels %d\n",v);
	printf("the no of spaces %d\n",s);
}
				
	
