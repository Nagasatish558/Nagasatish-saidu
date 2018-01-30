#include<stdio.h>
main()
{
	FILE *fp1,*fp2;
	char str[100],f1name[20],f2name[20];
	printf("enter input filename");
	gets(f1name);
fp1=fopen("f1name","r");
printf("enter output filenaem");
gets(f2name);
fp2=fopen("f2name","w");
while(fgets(str,100,fp1)!=NULL)
fprintf(str,"%s",fp2);
close(fp1);
close(fp2);
}
