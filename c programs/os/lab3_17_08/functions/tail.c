#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
main()
{
	FILE *fp1;
	char ch;
	int n;
	printf("Enter the no.of lines:");
	scanf("%d",&n);
	fp1=fopen("file1.txt","r");
	fseek(fp1,0,2);
        while(n!=0)
	{	
	fseek(fp1,-2,1);		
	ch=fgetc(fp1);
                if(ch=='\n')
		{
		n--;	
		}
		
           
		
	}
	while((ch=fgetc(fp1))!=EOF)
		{
			putchar(ch);
			fseek(fp1,0,1);
		}
}
