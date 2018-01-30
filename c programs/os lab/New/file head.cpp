#include<stdio.h>
main()
{
	FILE *fp;
	char ch;
	int n;
	printf("enter no.of lines: ");
	scanf("%d",&n);
	fp=fopen("3.txt","r");
	while(((ch=fgetc(fp))!=EOF)&&n!=0)
	{
		if(ch=='\n')
		{
			putchar(ch);
			n--;
		}
		else
			putchar(ch);
	}
}
