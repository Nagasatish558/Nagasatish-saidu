#include<stdio.h>
main()
{
	FILE *fp,*fp1,*fp2;
	char ch;
	fp=fopen("a.txt","r");
	fp1=fopen("b.txt","r");
	fp2=fopen("merg.txt","w");
	while((ch=fgetc(fp))!=EOF)
	{
		fputc(ch,fp2);
		if(ch=='\n')
		{
			while(ch=fgetc(fp1)!=EOF)
			{
				fputc(ch,fp2);
				if(ch=='\n')
				break;
			}
		}
	}
	while((ch=fgetc(fp))!=EOF)
		fputc(ch,fp2);
	while((ch=fgetc(fp1))!=EOF)
		fputc(ch,fp2);
}
