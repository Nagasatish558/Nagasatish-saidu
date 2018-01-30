#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int st[MAX],top=-1;
void push(int st[],int val);
int pop(int st[]);
int peep(int st[]);
void display(int st[]);
void reverse(int st[]);
int main()
{
	int val,option;
	do{
		printf("\n***********MAIN MENU***********\n1.PUSH\n2.POP\n3.PEEP\n4.DISPLAY\n5.REVERSE\n6.EXIT*************************\n\nEnter your option:");
		scanf("%d",&option);
		switch (option){
			case 1:
				printf("\nEnter the number to be pushed on to the stack:");
				scanf("%d",&val);
				push(st,val);
				break;
			case 2:
				val=pop(st);
				printf("\n the value deleted from the stack is:%d",val);
				break;
			case 3:
				val=peep(st);
				printf("\n The value stored at the top of the stack is:%d",val);
				break;
			case 4:
				display(st);
				break;
			case 5:
				reverse(st);
				break;
		}
	}while(option!=6);
}
void push(int st[],int val){
	if(top==MAX-1)
		printf("\n STACK OVERFLOW");
	else{
		top++;
		st[top]=val;
	}
}
int pop(int st[]){
	int val;
	if(top==-1){
		printf("\n STACK UNDERFLOW");
		return -1;
	}
	else{
		
		val=st[top];
		top--;
		return val;
	}
}
void display(int st[])
{
	int i;
	if(top==-1)
		printf("\n STACK IS EMPTY");
	else{
		for(i=top;i>=0;i--){
			printf("\n%d",st[i]);
		}
	}
}
int peep(int st[]){
	if(top==-1){
		printf("\n STACK IS EMPTY");
		return -1;
	}
	else
		return (st[top]);
}
void reverse(int st[]){
	int i;
	for(i=top;i>=0;i--)
		printf("\t%d",st[i]);
	}

