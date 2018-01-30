#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char data[4];
	struct node *next;
}*top=NULL,*post=NULL,*equation,*current,*new,*temp,*temp1,*temp2,*prev;

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
				in_to_post();
				printf("the post order equation is : \n");
				reverse();
				break;
		}
		
	}while(ch!=3);
}
void En_eqn(){
	equation=NULL;
	current=NULL;
	do{
		new=(struct node*)malloc(sizeof(struct node));
		printf("enter -1 at the end of the equation...\n");
		printf("enter the data : ");
		fflush(stdin);
		scanf("%s",new->data);
		new->next=NULL;
		
		if(strcmp(new->data,"-1")==1||strcmp(new->data,"+")==0||strcmp(new->data,"-")==0||strcmp(new->data,"*")==0||strcmp(new->data,"%")==0||strcmp(new->data,"(")==0||strcmp(new->data,")")==0){
			equation=new;
			equation->next=current;
			current=equation;
		}
		
	}while(strcmp(new->data,"-1")!=0);
}

void reverse(){
	for(temp=equation;temp!=NULL;temp=temp->next){
		new=(struct node*)malloc(sizeof(struct node));
		strcpy(new->data,temp->data);
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
		printf("%s",temp->data);
	}
	printf("\n");
}

void in_to_post(){
	
	post=NULL;
	current=NULL;
	prev=NULL;
	for(temp=equation;temp!=NULL;temp=temp->next){
		printf("%s",temp->data);
	}
	for(temp=equation;temp!=NULL;temp=temp->next){
			printf("%s",temp->data);
		if(strcmp(temp->data,"(")==0||strcmp(temp->data,"+")==0||strcmp(temp->data,"-")==0){
			printf("braces\n");
			top=temp;
			top->next=prev;
			prev=top;
		}
		else if(strcmp(temp->data,")")==0){
			printf("closebraces\n");
			for(temp1=top;strcmp(temp1->data,"(")!=0;temp1=temp1->next){
				printf("inclosebraces\n");
				post=temp1;
				post->next=current;
				current=post;
				pop();
			}
			pop();
		}
		//check the below
		else if(strcmp(temp->data,"*")==0||strcmp(temp->data,"/")==0||strcmp(temp->data,"%")==0){
			
			if(strcmp(top->data,"+")==0||strcmp(top->data,"-")==0){
				
				for(temp1=top;strcmp(temp1->data,"(")!=0||strcmp(temp1->data,"*")!=0||strcmp(temp1->data,"%")!=0||strcmp(temp1->data,"/")!=0;temp1=temp1->next){
					post=temp1;
					post->next=current;
					current=post;
					pop();
				}
				
			}
			
		}
		
		else{
			printf("alpha\n");
			post=temp;
			post->next=current;
			current=post;
			
				printf("alpha\n");
		}
		printf("loop");
		
		
	}
	for(temp1=top;temp1->next!=NULL;){
		printf("remaining\n");
		post=temp1;
		post->next=current;
		current=post;
		temp1=temp1->next;
		pop();
	}
	for(temp=post;temp!=NULL;temp=temp->next){
		printf("%s",temp->data);
	}
}

void push(){
	
	top=temp;
	top->next=prev;
	prev=top;
	
}

void pop(){
	if(top==NULL){
		printf("stack is empty...\n");
	}
	else{
		temp2=top;
		top=top->next;
		free(temp2);
	}
}
