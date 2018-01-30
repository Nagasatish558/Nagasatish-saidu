#include<stdio.h>
main()
{
	int i,j,k,c=0;
	printf("ENTER RANGE OF THE PRIME NUMBER");
	scanf("%d",&j);
	for(i=2;i<=j;i++)
	{
		for(k=1;k<=i;k++)
		{
			if(i%k==0)
			c++;
		}
		if(c==2)
		printf("hi frnd %d",c);
	}
}
