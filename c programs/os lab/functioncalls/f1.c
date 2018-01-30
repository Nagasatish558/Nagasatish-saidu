#include<stdio.h>
main()
{
	int id;
	char sname[20];
	printf("enter student id");
	scanf("%d",&id);
	printf("enter student name");
	scanf("%s",sname);
	fprintf(stdout,"id=%d,name=%s",id,sname);
	
}
