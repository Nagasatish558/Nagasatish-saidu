#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main()
{
	char ch;
	while(ch=getchar()!=EOF)
	putc(ch,stdout);
	return 0;
}
