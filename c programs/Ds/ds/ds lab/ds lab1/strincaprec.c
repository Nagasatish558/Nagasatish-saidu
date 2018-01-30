#include<stdio.h>
void printchar(char *);
int main()
{
	char str[10],x=0;
	printf("enter the string:");
	gets(str);
	printchar(str);
	//puts(str);
	return 0;
	
}
void printchar(char *string)
{
	if(*string!='\0')
	{
		if(*string>='A' && *string<='Z')
		{
			printf("%c",*string);
		}
			string++;
			printchar(string);
	}

}

