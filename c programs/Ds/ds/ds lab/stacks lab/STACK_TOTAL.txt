#include<stdio.h>
#define MAX 10
int st[MAX],top=-1;
void push(int [],int);
void disp(int []);
int pop(int []);
int peak(int []);
int main()
{
    int ch,val;
    do
    {
        printf("*********THIS IS MENU********\n");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.peak");
        printf("\n4.display");
        printf("\n5.exit");
	printf("\nenter ur choice:");
        scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("enter a pushing value:");
			scanf("%d",&val);
			push(st,val);
			break;
		case 2:val=pop(st);
			if(val!=-999)
			printf("the value deleted from the stack is:%d\n",val);
			break;
		case 3:val=peak(st);
			if(val!=-999)
				printf("the top most value of the :%d\n",val);
			break;
		case 4:disp(st);
			break;
		case 5:printf("***********************this is end***************\n");
			break;
		default:printf("INVALID INPUT\n");
	}

    }while(ch!=5);
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
int peak(int st[])
{
	int val;
	if(top==-1)
	{
		printf("underflow\n");
		val=-999;
	}
	else
		val=st[top];
	return val;
}
