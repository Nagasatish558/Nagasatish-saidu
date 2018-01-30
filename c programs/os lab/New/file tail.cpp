#include<stdio.h>
main()
{
	FILE *fp;
	char ch[1];
	int c=0;
	fp=fopen("3.txt","r");
	while((ch[0]=fgetc(fp))!=EOF)
	{
		printf("%c",ch[0]);
		if(ch[0]=='\n')
		c=c+1;
		if(c==3)
		break;
	}
	fclose(fp);
}
