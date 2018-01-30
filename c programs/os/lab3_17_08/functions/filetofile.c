#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
main()
{
	FILE *fp1,*fp2;
	char ch;
	fp1=fopen("file1.txt","r");
	fp2=fopen("file2.txt","a");
	while((ch=fgetc(fp1))!=EOF)
	{
		fputc(ch,fp2);
	}
	fputc('\n',fp2);
}
