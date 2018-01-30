#include<stdio.h>
main()
{
	int x,y,z;
	printf("Enter the 1st number: ");
	scanf("%d",&x);
	printf("Enter the 2st number: ");
	scanf("%d",&y);
	z=div(x,y);
	printf("%d",z);

}
div(int a,int b)
{
	a=a-b;
	if(a<0)
		return 0;
	else
		return (div(a,b)+1);
}
