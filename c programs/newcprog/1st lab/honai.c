#include<stdio.h>
main()
{
	char A,B,C;
	int n;
	printf("Enter the number of discs: \n");
	scanf("%d",&n);
	honai(n,'A','C','B');
	return 0;
}
void honai(int n,char source,char dest,char spare)
{
	if(n==1)
		printf("\n Move from %c to %c",source,dest);
	else
	{
		honai(n-1,source,spare,dest);
		honai(1,source,dest,spare);
		honai(n-1,spare,dest,source);
	}
}
