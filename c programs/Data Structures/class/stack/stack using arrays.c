#include<stdio.h>
#define MAX 5
int top=-1,stack[MAX];
void push();
void pop();
void peek();
main(){
	int ch;
	do{
		printf("1.Push \n2.Pop \n3.Peek \n4.Exit\n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				break;
		}
	}while(ch!=4);
	
}
void push(){
	if(top!=MAX-1){
		top++;
		printf("Enter the data :");
		scanf("%d",&stack[top]);
	}
	else{
		printf("stack is over flow...\n");
	}
}
void pop(){
	if(top==-1)
		printf("stack is under flow...\n");
	else{
		printf("Poped element is %d\n",stack[top]);
		top--;	
	}
}
void peek(){
	printf("Poped element is %d\n",stack[top]);
}
