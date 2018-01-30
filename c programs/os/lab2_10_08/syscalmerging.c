#include<fcntl.h>
#include<unistd.h>
main(){
	int fd1,fd2,fd3,n;
	char buf[1];
	fd1=open("sample.txt",O_RDONLY);
	fd2=open("sample2.txt",O_RDONLY);
	fd3=creat("output.txt",777);
	while((n=read(fd1,buf,1)!=0)){
		write(fd3,buf,1);
		if(buf[0]=='\n'){
				while((n=read(fd2,buf,1))!=0){
					write
				}
		}
	}
}
