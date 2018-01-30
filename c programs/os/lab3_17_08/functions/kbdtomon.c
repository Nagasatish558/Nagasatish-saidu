#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
main()
{
	char ch;
	while((ch=getchar())!='\n')
	{
		putchar(ch);
	}
}
