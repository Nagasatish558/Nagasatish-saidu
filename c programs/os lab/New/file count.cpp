#include<stdio.h>
main()
{
	FILE *fp;
	int l=0,v=0,s=0;
	char ch;
	fp=fopen("3.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='\n')
			l++;
		else if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
			v++;
		else if(ch==' ')
			s++;
	}
	printf("%d\t%d\t%d",l,v,s);
}
