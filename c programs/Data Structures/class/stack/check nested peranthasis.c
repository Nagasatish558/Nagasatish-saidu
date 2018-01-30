#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char data[3];
	struct node *next;	
}*top=NULL,*start=NULL,*new,*current,*temp,*prev,*temp1,*temp2;
void push();
void pop();
void display();
void reverse();
main(){
	int ch;
	do{
		printf("1.push \n2.check \n3.exit \n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				push();
				break;
			case 2:
				if(top==NULL)
					printf("valid equation....\n");
				else
					printf("not valid equation....\n");
			case 3:
				break;
		}
	}while(ch!=3);
}
void push(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter your data : ");
	scanf("%s",new->data);
	new->next=NULL;
	if(strcmp("{",new->data)==0||strcmp(new->data,"(")==0||strcmp(new->data,"[")==0){
		printf("Given element is pushed into stack.....\n");
			if(top==NULL){
				top=current=new;	
			}
			else{
				top=new;
				top->next=current;
				current=top;
			}
			if(start==NULL)
				start=temp=new;
			else{
				start=new;
				start->next=temp;
				temp=start;
			}
	}
	else if(strcmp(")",new->data)==0||strcmp(new->data,"]")==0||strcmp(new->data,"}")==0){
		pop();
			if(start==NULL){
				start=temp=new;
			}
			else{
				printf("Given element is pushed into stack.....\n");
				start=new;
				start->next=temp;
				temp=start;
			}
	}
	else{
		printf("Given element is pushed into stack.....\n");
		if(start==NULL){
			start=temp=new;
		}
		else{
			start=new;
			start->next=temp;
			temp=start;
		}
	}
}
void pop(){
	if(top==NULL){
		printf("equation is not valid...\n");
		exit(1);
	}
	else{
		prev=top;
		top=top->next;
		free(prev);
	}
}

