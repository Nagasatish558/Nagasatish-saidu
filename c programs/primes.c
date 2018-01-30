#include<stdio.h>
main()
{
	int a,b,c,n,i,j;
	printf("Enter the last number: ");
	scanf("%d",&n);
	for (a=1;a<=n;a++)
	{	
		c=0;
		for(b=1;b<=a;b++)
		{
			if(a%b==0)
			c++;
		}
		if(c==2)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=i;j++)
				{ 
					printf("%d",a);
				}
			}
			
		printf("%d\t",a);
	}
}
}
