#include<stdio.h>
int main()
{
	FILE *fp;
	char str[100];
	fp=fopen("f1.txt","w");
	printf("Enter text: ");
	gets(str);
	fputs(str,fp);
	fclose(fp);
	return 0;
}
