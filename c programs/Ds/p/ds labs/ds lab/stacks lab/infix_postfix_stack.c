#include<stdio.h>
#include<string.h>
#define max 100
char st[max];
int top=-1;
void push(char [],char);
char pop(char []);
void infix_postfix(char [],char []);
int get_priority(char);
int main()
{
	char infix[50],postfix[30];
	printf("enter the expression:\n");
	scanf("%s",infix);
	infix_postfix(infix,postfix);
	printf("\ncorresponding postfix expression is:%s\n",postfix);
	return 0;
}
void infix_postfix(char source[],char target[])
{
	int i=0,j=0;
	char temp;
	while(source[i]!='\0')
	{
		if(source[i]=='(')
		{
			push(st,source[i]);
			i++;
		}
		else if(source[i]==')')
		{
			while((st[top]!='(') && (top!=-1))
			{
				target[j]=pop(st);
				j++;
			}
			if(top==-1)
			{
				printf("\n incorrect expression:\n");
			}
			temp=pop(st);
			i++;
		}
		else if(isdigit(source[i])||isalpha(source[i]))
		{
			target[j]=source[i];
			i++;
			j++;
		}
		else if(source[i]=='+' || source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%')
		{
			while((top!=-1) && (st[top]!='(') && get_priority(source[i])<=get_priority(st[top]))
			{
				target[j]=pop(st);
					j++;
			}
			push(st,source[i]);
            i++;
		}
		else
		{
		printf("INCORRECT EXPRESSION\n");
		}
	}
	while((top!=-1) && (st[top]!='('))
	{
		target[j]=pop(st);
		j++;
	}
	target[j]='\0';
}
void push(char st[],char val)
{
	if(top==max)
	printf("\nstack over flow:\n");
	else
	{
		top++;
		st[top]=val;
	}
}
char pop(char st[])
{
	char val=' ';
	if(top==-1)
	{
		printf("stack underflow:\n");
	}
	else
	{
		val=st[top];
		top--;
	}
	return val;
}
int get_priority(char a)
{

	if(a=='*' || a=='/' ||a=='%')
		return 1;
	else if(a=='+' || a=='-')
		return 0;

}
