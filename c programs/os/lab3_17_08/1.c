//write a program to merge lines alternatively from two files into third file using sysstem calls
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
main()
{	
	int n,m,s,fd,fd1;
	char buf[100],buf1[100],file[100];
	fd=open("source1.txt",O_RDONLY);
	fd1=open("source2.txt",O_RDONLY);
	if(fd<0||fd<0)
	{
		printf("Source file doesnt exist");
	}
	else{	
		n=open("dest.txt",O_WRONLY|O_TRUNC);
		s=read(fd,buf,1);
		m=read(fd1,buf1,1);
		while(s!=0||m!=0){

			printf("%c",buf[0]);
			printf("%c",buf1[0]);
			write(n,buf,1);
			write(n,buf1,1);
			lseek(fd,0,1);
			lseek(fd1,0,1);
			s=read(fd,buf,1);
			m=read(fd1,buf1,1);

		}
	}
}
