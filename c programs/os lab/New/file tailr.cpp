#include<stdio.h>
main()
{
	FILE *fp;
	char ch;
	int n;
	printf("enter no.of lines: ");
	scanf("%d",&n);
	fp=fopen("3.txt","r");
	fseek(fp,0,1);
	while(n!=0)
	{
		fseek(fp,0,1);
		ch=fgetc(fp);
		if(ch=='\n')
			n--;
	}
	while((ch=fgetc(fp))!=EOF)
	{
		putchar(ch);
		fseek(fp,0,1);
	}
}
