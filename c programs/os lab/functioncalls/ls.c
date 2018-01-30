#include<stdio.h>
#include<dirent.h>
main()
{
	struct dirent *p;
	DIR *dp;
	dp=opendir("CSE");
	while((p=readdir(dp))!=NULL)
	printf("%s",p->d-name);
	closedir(dp);
}
