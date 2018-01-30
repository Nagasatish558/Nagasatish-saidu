#include<stdio.h>
main()
{
	FILE *fp1,*fp2,*fp3;
	char ch;
	fp1=fopen("r1.c","r");
	fp2=fopen("r2.c","r");
	fp3=fopen("out1.txt","a+");
	while((ch=fgetc(fp1))!=EOF)
	{
		fprintf(fp3,"%c",ch);
		if(ch=='\n')
		{
		while((ch=fgetc(fp2))!=EOF)
		{
			fprintf(fp3,"%c",ch);
			if(ch=='\n')
			break;
		}
		}
	}
	while((ch=fgetc(fp2))!=EOF)
	{
		fprintf(fp3,"%c",ch);
		}
}
