#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
main()
{
	FILE *fp1;
	char ch;
	fp1=fopen("file1.txt","w");
	while((ch=getchar())!='\n')
	{
		fputc(ch,fp1);
	}
}
