#include<stdio.h>
#include<fcntl.h>
main(){
	int f,n;
	char buf[100];
	f=open("1.txt",O_RDONLY);
	n=read(f,buf,100);
	write(1,buf,n);
}
