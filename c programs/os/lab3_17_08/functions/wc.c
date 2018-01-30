#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
main()
{
	FILE *fp1;
	char ch;
	int l=0,v=0,w=0,c=0;
	fp1=fopen("file1.txt","r");
	while((ch=fgetc(fp1))!=EOF)
	{
		if(ch=='\n')
		{
			l++;		
		}
		else if()
		
	}

}
