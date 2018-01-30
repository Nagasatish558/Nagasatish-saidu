#include<stdio.h>
#include<string.h>
#define MAX 100
int st[MAX];
int stk[MAX];
int top=-1;
void push(int st[],int val);
void pushi(int);
int popi();
int get_type(char);
int pop(int st[]);
int evaluatepre(char prefix[]);
int evaluatePostfixexp(char postfix[]);
int len,vali,i,opr1,opr2,res=0;
char prefix[100],postfix[100];
int main(){
	char prefix[100],postfix[100];
	int val;
	printf("\nEnter any postfix  expression:");
	gets(postfix);
	val=evaluatePostfixexp(postfix);
	printf("\nRESULT=%d",val);
	printf("\nEnter any prefix expression:");
	gets(prefix);
	res=evaluatepre(prefix);
	printf("\nRESULT=%d\n",res);
	return 0;
}

int evaluatepre(char prefix[]){
	len=strlen(prefix);
	for(i=len-1;i>=0;i--){
		switch(get_type(prefix[i])){
			case 0:
				vali=prefix[i]-'0';
				pushi(vali);
				break;
			case 1:
				opr1=popi();
				opr2=popi();
				switch(prefix[i]){
					case '+': 
						res=opr1+opr2;
						break;
					case '-':
						res=opr1-opr2;
						break;
					case '/':
						res=opr1/opr2;
						break;
					case '*':
						res=opr1*opr2;
						break;
					case '%':
						res=(int)opr1%(int)opr2;
						break;
				}
				pushi(res);
		}
	}
	return stk[0];
}


int evaluatePostfixexp(char postfix[]){
	int i=0,op1,op2,value;
	while(postfix[i]!='\0'){
		if(isdigit(postfix[i]))
			push(st,(int)(postfix[i]-'0'));
		else{
			op2=pop(st);
			op1=pop(st);
			switch(postfix[i]){
				case '+': 
					value=op1+op2;
					break;
				case '-':
					value=op1-op2;
					break;
				case '/':
					value=op1/op2;
					break;
				case '*':
					value=op1*op2;
					break;
				case '%':
					value=(int)op1%(int)op2;
					break;
			}
			push(st,value);
		}
		i++;
	}
	return(pop(st));
}

void push(int st[],int val){
	if(top==MAX-1)
		printf("\n Stack overflow");
	else{
		top++;
		st[top]=val;
	}
}

int pop(int st[]){
	int val=-1;
	if(top==-1)
		printf("\n Underflow");
	else{
		val=st[top];
		top--;
	}
	return val;
}

void pushi(int vali){
	stk[++top]=vali;
}

int popi(){
	return(stk[top--]);
}

int get_type(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return 1;
	else return 0;
}
