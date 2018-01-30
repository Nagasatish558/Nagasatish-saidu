#include<stdio.h>
#include<string.h>
#define MAX 20
char st[MAX];int top=-1;
void push(char [],char);
char pop(char []);
int main()
{
	char eqn[20],parn;int i,n,flag=1;
	printf("ENTER EQUATION:\n");
	scanf("%s",eqn);
	n=strlen(eqn);
	for(i=0;i<n;i++)
	{
		if(eqn[i]=='(' || eqn[i]=='[' || eqn[i]=='{')
			push(st,eqn[i]);
		else if(eqn[i]==')' || eqn[i]==']' || eqn[i]=='}')
		{
			if(top==-1)
				flag=0;
			else
			{
				parn=pop(st);
				if(eqn[i]==')' && parn=='}' || parn==']')
					flag=0;
				else if(eqn[i]==']' && parn=='}' || parn==')')
					flag=0;	
				if(eqn[i]=='}' && parn==')' || parn==']')
					flag=0;
			}			
		}
	}
	if(top>=0)
		flag=0;
	if(flag==0)
		printf("%s is an unbalanced equation\n",eqn);
	else
		printf("%s is balanced equation\n",eqn);
    return 0;
}
void push(char st[],char val)
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
 char pop(char st[])
{
	char val;
	if(top==-1)
	{
		printf("UNDER FLOW\n");
		val='9';
	}
	else	
	{
		val=st[top];
		top-=1;		
	}	
	return val;
}

