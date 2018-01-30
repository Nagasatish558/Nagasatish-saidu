#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node *next;
}*post=NULL,*top=NULL,*new,*temp,*current,*previous;

int flag;
void postfix();
void infix();
void reverse();

main(){
	int ch;
	do{
		printf("1.enter postfix equation \n2.convert into infix \n3.exit \n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				postfix();
				break;
			case 2:
				if(flag==1)
					infix();
				else
					printf("given equation is not valid...enter new valid equation...\n");
				break;
			case 3:
				break;
		}
	}while(ch!=3);
}
void postfix(){
	post=NULL;
	int count,count1;
	do{
		new=(struct node*)malloc(sizeof(struct node));
		printf("enter data or ! to end :");
		fflush(stdin);
		scanf("%c",&new->data);
		new->next=NULL;
		if(new->data!='!'){
			if(post==NULL){
				post=new;
			}
			else{
				new->next=post;
				post=new;
			}
		}	
	}while(new->data!='!');
	count=count1=0;
	for(temp=post;temp!=NULL;temp=temp->next){
		if(temp->data>='a'&&temp->data<='z')
			count++;
		else
			count1++;
	}
	flag=0;
	if(count==count1+1)
		flag=1;
	else
		printf("given equation is not valid...enter new valid equation...\n");
	reverse();
	
}
void infix(){
	top=NULL;
	current=post;
	
	for(temp=current;temp!=NULL;temp=temp->next){
		printf("%c",temp->data);
	}
	printf("\n");
	
	while(current!=NULL){
		
		new=(struct node*)malloc(sizeof(struct node));
		new=current;
		if(new->data>='a'&&new->data<='z'){
			if(top==NULL){
				top=new;
				top->next=NULL;
			}
			else{
				
				new->data=',';
				new->next=top;
				top=new;
				new=(struct node*)malloc(sizeof(struct node));
				new=current;
				new->next=top;
				top=new;
				
			}
		}
		else{
			for(temp=top;;temp=temp->next){
				if(temp->data==','){
					temp->data=current->data;
					break;
				}
			}
		}
		current=current->next;
		
	}
	for(temp=top;temp!=NULL;temp=temp->next){
		printf("%c",temp->data);
	}
	printf("\n");
	
}
void reverse(){
	previous=NULL;
	current=post;
	while(current!=NULL){
		temp=previous;
		previous=current;
		current=current->next;
		previous->next=temp;
	}
	post=previous;
	
	for(temp=post;temp!=NULL;temp=temp->next){
		printf("%c",temp->data);
	}
	printf("\n");
}

