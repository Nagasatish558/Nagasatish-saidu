#include<stdio.h>
#include<string.h>
#define MAX 100
char st[MAX];
int top=-1;
void push(char st[],char);
char pop(char st[]);
void intopost(char source[],char target[]);
int getPriority(char);
void reverse(char str[]);
char infix[100],postfix[100],temp[100];
int main(){
	int option;
	printf("\n Enter any infix expression:");
	gets(infix);
	do{
		printf("\n1:Equivalent Postfix Expression");
		printf("\n2:Equivalent Prefix Expression");
		printf("\n3:Enter new expression");
		printf("\n4:EXIT");
		printf("\nEnter your option:");
		scanf("%d",&option);
		switch(option){
			case 1:
				strcpy(postfix, "");
				intopost(infix,postfix);
				printf("\nThe corresponding postfix expression is:");
				puts(postfix);
				break;
			case 2:
				reverse(infix);
				strcpy(postfix,"");
				intopost(temp,postfix);
				strcpy(temp,"");
				reverse(postfix);
				printf("\nThe prefix expression is:");
				puts(temp);
				break;
			case 3:
				printf("\n Enter any infix expression:");
				gets(infix);
				break;
			
		}
		
	}while(option!=4);
	return 0;
}

void reverse(char str[]){
	int len,i=0,j=0;
	len=strlen(str);
	j=len-1;
	while(j>=0){
		if(str[j]=='(')
			temp[i]=')';
		else if(str[j]==')')
			temp[i]='(';
		else
			temp[i]=str[j];
			i++;
			j--;
	}
	temp[i]='\0';
}


void intopost(char source[],char target[]){
	int i=0,j=0;
	char temp;
	strcpy(target, "");
	while(source[i]!='\0'){
		if(source[i]=='('){
			push(st,source[i]);
			i++;
		}
		else if(source[i]==')'){
			while((top!=-1)&&(st[top]!='(')){
				target[j]=pop(st);
				j++;
			}
			if(top==-1){
				printf("\n incorrect expression");
				exit(1);
			}
			temp=pop(st);
			i++;
		}
		else if(isdigit(source[i])||isalpha(source[i])){
			target[j]=source[i];
			j++;
			i++;
		}
		else if(source[i]=='+' || source[i]=='-' || source[i]=='*' || source[i]=='/' || source[i]=='%'){
			while((top!=-1)&&(st[top]!='(')&&(getPriority(st[top])>getPriority(source[i]))){
				target[j]=pop(st);
				j++;
			}
			push(st,source[i]);
			i++;
		}
		else{
			printf("\n Incorrect element in expression");
			exit(1);
		}
	}
	while((top!=-1) && (st[top]!='(')){
		target[j]=pop(st);
		j++;
	}
	target[j]='\0';
}

int getPriority(char op){
	if(op=='/' || op=='*' || op=='%')
		return 1;
	else if(op=='+' || op=='-')
		return 0;
}

void push(char st[],char val){
	if(top==MAX-1)
		printf("\n Stack overflow");
	else{
		top++;
		st[top]=val;
	}
}

char pop(char st[]){
	char val=' ';
	if(top==-1)
		printf("\n stack underflow");
	else{
		val=st[top];
		top--;
	}
	return val;
}
