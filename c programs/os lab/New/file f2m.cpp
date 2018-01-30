#include<stdio.h>
int main()
{
	FILE *fp;
	char str[50];
	fp=fopen("f1.txt","r");
	while(fgets(str,50,fp)!=NULL)
	{
		printf("%s",str);
		fclose(fp);
	}
}
