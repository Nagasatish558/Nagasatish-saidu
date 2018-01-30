#include<stdio.h>
#include<unistd.h>
main()
{
	int c,cnt=0,t;
	char ch;
	FILE *fp,*fp1;
	printf("how many u want to print from down");
	scanf("%d",&t);
	fp=fopen("input.txt","r");
	fp1=fopen("input.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='\n')
		c++;
	}
		while((ch=fgetc(fp1))!=EOF)
		{
			if(cnt>=c-t)
			printf("%c",ch);
			if(ch=='\n')
				cnt++;
		}
		
}
