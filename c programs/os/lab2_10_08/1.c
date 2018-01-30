#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
main(){
	int n,i;
	char buf[100];
	for(i=120001;i<121100;i++)
	{
		write(1,buf,n);
	}
}

