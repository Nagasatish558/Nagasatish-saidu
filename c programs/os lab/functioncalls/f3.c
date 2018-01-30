#include<stdio.h>
#include<conio.h>
main()
{
	char str[100];
	FILE *fp;
	fp=fopen("input.txt","r");
	while(fgets(str,100,fp)!=NULL)
	fprintf(stdout,"%s",str);
	fcolse(fp);
}
