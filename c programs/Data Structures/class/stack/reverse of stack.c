#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;	
}*top=NULL,*new,*current,*temp,*prev;
void push();
void pop();
void display();
void reverse();
main(){
	int ch;
	do{
		printf("1.push \n2.pop \n3.display \n4.reverse \n5.Exit \n");
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
			case 4:
				reverse();
				break;
			case 5:
				break;
		}
	}while(ch!=5);
}
void push(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter your number : ");
	scanf("%d",&new->data);
	new->next=NULL;
	printf("Given element is pushed into stack.....\n");
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
		printf("The poped element is : %d\n",top->data);
		temp=top;
		top=top->next;
		free(temp);
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

void reverse(){
	for(temp=top;temp!=NULL;temp=temp->next){
		new=(struct node*)malloc(sizeof(struct node));
		new->data=temp->data;
		new->next=NULL;
		if(temp==top){	
			top=new;
		}
		else{
			new->next=top;
			top=new;
		}
	}
	for(temp=top;temp!=NULL;temp=temp->next){
		printf("%d\t",temp->data);
	}
	printf("\n");
}
