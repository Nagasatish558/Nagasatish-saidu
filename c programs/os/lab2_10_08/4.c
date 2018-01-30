#include<stdio.h>
#include<fcntl.h>
main(){
	int file1,file2,n;
	char buf[100];
	file1=open("1.txt",O_RDONLY);
	file2=open("2.txt",O_CREAT|O_EXCL|O_WRONLY,777);
	n=read(file1,buf,100);
	write(file2,buf,n);
	close(file1);
	close(file2);
}
