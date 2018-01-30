#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
main(){
	int fd,count=0,n;
	char ch[1];
	fd=open("m.txt",O_RDONLY);
	lseek(fd,-2,2);
	printf("Enter the no of lines u want to print");
	scanf("%d",&n);
	//printf("hell");
	while(read(fd,ch,1)!=0){
		if(ch[0]=='\n')
			count++;
		if(count==n)
			break;
		lseek(fd,-2,1);
	}
	while(read(fd,ch,1)!=0)
		write(1,ch,1);
}
