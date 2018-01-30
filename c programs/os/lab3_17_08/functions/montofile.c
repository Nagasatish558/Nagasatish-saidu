#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
main()
{
	FILE *fp1;
	char ch;
	fp1=fopen("file1.txt","r");
	while((ch=fgetc(fp1))!=EOF)
	{
		putchar(ch);
	}
	putchar('\n');
}
