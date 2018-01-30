#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
main()
{
	FILE *fp1;
	char ch;
	int n;
	printf("Enter the number of lines:");
	scanf("%d",&n);
	fp1=fopen("file1.txt","r");
	while((((ch=fgetc(fp1))!=EOF)&&n!=0))
	{
		if(ch=='\n')
		{
			putchar(ch);
			n--;
		}
		else
		{
			putchar(ch);		
		}
	}
	

}
