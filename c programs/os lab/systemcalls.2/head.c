#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd,line=0,t,n;
	char ch[1];
	fd=open("m.txt",O_RDONLY);
	printf("enter number of lines w want:");
	scanf("%d",&n);
	while((read(fd,ch,1))!=0)
	{
		printf("%c",ch[0]);
		if(ch[0]=='\n')
			line=line+1;
	//	lseek(fd,0,1);
		if(line==n){
			printf("%d\t",line);
				break;
		}
		
	}
}
	
