#include<fcntl.h>
#include<stdio.h>
main(){
	int fd,cd,rd;
	char ch[1];
	fd=open("m.txt",O_RDONLY);
	cd=open("sn.txt",O_RDONLY);
	rd=open("result.txt",O_WRONLY);
	while(read(fd,ch,1)!=0){
		write(rd,ch,1);
		if(ch[0]=='\n'){
			while(read(cd,ch,1)!=0){
				write(rd,ch,1);
				if(ch[0]=='\n')
					break;
			}
		}
	}
while(read(cd,ch,1)!=0){
		write(rd,ch,1);
	close(fd);
	close(rd);
	close(cd);
	return 0;
	}
}
