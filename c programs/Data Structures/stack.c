#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;	
}*top=NULL,*new,*current,*temp,*prev;
void push();
void pop();
void display();
main(){
	int ch;
	do{
		printf("1.push 2.pop 3.display 4.exit\n");
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
				display();
				break;
		}
	}while(ch!=4);
}
void push(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter your number : ");
	scanf("%d",&new->data);
	new->next=NULL;
	if(top==NULL){
		top=current=new;
	}
	else{
		top=new;
		top->next=current;
		current=top;
	}
}
void pop(){
	int del,a=1;
	if(top==NULL){
		printf("stack is empty...\n");
	}
	else{
		printf("enter which element you want to delete : ");
		scanf("%d",&del);
		if(top->data==del){
			printf("given number is deleted...\n");
			top=top->next;
		}
		else{
			for(temp=top;temp->next!=NULL;temp=temp->next){
				if(temp->data==del){
					a=0;
					break;
				}
				else{
					prev=temp;
				}
			}
			if(a==0){
				printf("given number is deleted...\n");
				prev->next=temp->next;
			}
			else if(temp->data==del){
				printf("given number is deleted...\n");
				prev->next=NULL;
			}
			else{
				printf("given element is not present in the stack...\n");
			}
		}
	}
}
void display(){
	if(top==NULL){
		printf("stack is empty...\n");
	}
	else{
		printf("the stack is : \n");
		for(temp=top;temp->next!=NULL;temp=temp->next){
			printf("%d\t",temp->data);
		}
		printf("%d\n",temp->data);
	}
}
