#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char data;
	struct node *next;
}*top=NULL,*post=NULL,*equation=NULL,*current,*new,*temp,*temp1,*temp2,*prev;

void En_eqn();
void reverse();
void in_to_post();
void push();
void pop();

main(){
	
	int ch;
	do{
		printf("1.Enter equation \n2.postfix \n3.exit \n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				En_eqn();
				reverse();
				break;
			case 2:
					printf("the post order equation is : \n");
				in_to_post();
				break;
		}
		
	}while(ch!=3);
}
void En_eqn(){
	equation=NULL;
	current=NULL;
	do{
		new=(struct node*)malloc(sizeof(struct node));
		printf("enter ! at the end of the equation...\n");
		printf("enter the data : ");
		fflush(stdin);
		scanf("%c",&new->data);
		new->next=NULL;
		
		if(new->data!='!'){
			equation=new;
			equation->next=current;
			current=equation;
		}
		
	}while(new->data!='!');
}

void reverse(){
	for(temp=equation;temp!=NULL;temp=temp->next){
		new=(struct node*)malloc(sizeof(struct node));
		new->data=temp->data;
		new->next=NULL;
		if(temp==equation){	
			equation=new;
		}
		else{
			new->next=equation;
			equation=new;
		}
	}
	for(temp=equation;temp!=NULL;temp=temp->next){
		printf("%c",temp->data);
	}
	printf("\n");
}

void in_to_post(){
	
	prev=NULL;
	for(temp=equation;temp!=NULL;temp=temp->next){
		printf("%c",temp->data);
	}
	printf("\n");
	temp=equation;
	while(temp!=NULL){
		new=(struct node*)malloc(sizeof(struct node));
		if(temp->data=='('){
			new=temp;
			new->next=NULL;
			if(top==NULL){
				top=new;
			}
			else{
				new->next=top;
				top=new;
			}		
		}
		else if(temp->data==')'){
			
				for(temp1=top;temp1->data!='(';temp1=temp1->next){
					printf("%c",temp1->data);
					top=top->next;
				}
				top=top->next;
		}
		else if(strcmp(temp->data,"+")==0||strcmp(temp->data,"-")==0){
				
				new=temp;
				new->next=NULL;
				if(top==NULL){
					top=new;
				}
			
				else{
				if(top->data=='*'||top->data=='/'||top->data=='%'){
					
					for(temp1=top;temp1->data=='('||temp1->data!='+'||temp1->data!="-";temp1=temp1->next){
						printf("%c",temp1->data);
						top=top->next;
					}
					
					new->next=top;
					top=new;
					
				}
					else{
					
						new->next=top;
						top=new;
					}
				}
								
		}
		else{
			printf("%c",temp->data);
		}
		printf("%c",temp->data);
		temp=temp->next;
		
	}
	
	for(temp1=top;temp1!=NULL;){
		printf("%c",temp1->data);
		temp1=temp1->next;
		
	}
	
}

