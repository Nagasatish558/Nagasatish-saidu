#include<stdio.h>
#define MAX 10
int st[MAX],top=-1;
void push(int [],int);
void disp(int []);
int pop(int []);
int main()
{
	int val,i,n;
	printf("enter length of the stack:");
	scanf("%d",&n);
	int st2[n];
	for(i=0;i<n;i++)
	{
		printf("\nenter a value to push into the stack:");
		scanf("%d",&val);
		push(st,val);
	}
	printf("\nstack values before reversing:\n");
	disp(st);
	for(i=0;i<n;i++)
	{
		if(val!=-999)	
		{
			val=pop(st);
			st2[i]=val;
		}
	}
	printf("\nstack values after reversing:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",st2[i]);
	}
	
    return 0;
}
void push(int st[],int val)
{
	if(top==MAX-1)
	{
		printf("stack overflow:\n");
	}
	else
	{
		top+=1;
		st[top]=val;
	}
}
void disp(int st[])
{
	if(top==-1)
		printf("stack underflow:\n");
	else
	{	
		int i;
		printf("\nstack values:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",st[i]);
		}	
	}				
}
 int pop(int st[])
{
	int val;
	if(top==-1)
	{
		printf("UNDER FLOW\n");
		val=-999;
	}
	else	
	{
		val=st[top];
		top-=1;		
	}	
	return val;
}

