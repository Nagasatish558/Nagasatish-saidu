#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
	
FILE *fp;
	char str[100];
	fp=fopen("out.txt","O_RDWR");
	printf("enter text");
	gets(str);
	fputs(str,fp);
	fclose(fp);
}

