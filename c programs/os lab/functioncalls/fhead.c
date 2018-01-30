#include<stdio.h>
#include<string.h>
main()
{
	int c,h;
	char ch;
	FILE *fp;
	printf("enter number of lines u want to print from top");
	scanf("%d",&h);
	fp=fopen("f1.c","r");
	while((ch=getc(fp))!=EOF)
	{
	fprintf(stdout,"%c",ch);
	if(ch=='\n')
	{
		c++;
	}
		if(c==h)
		break;
	}
}
