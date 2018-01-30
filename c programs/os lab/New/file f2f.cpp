#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	char str[30];
	fp1=fopen("f1.txt","r");
	fp2=fopen("f2.txt","w");
	while(fgets(str,30,fp1)!=NULL)
	{
		fputs(str,fp2);
	}
	return 0;
}
