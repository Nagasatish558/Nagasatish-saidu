#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void insert();
void delete();
void display();
void sort();
struct node *head=NULL,*current,*new,*temp,*prev;
main(){
	int ch;
	do{
		printf("1.insert \n2.delete \n3.disply \n4.sort \n5.Exit \n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				sort();
				break;
			case 5:
				break;
		}
	}while(ch!=5);
}
void insert(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter any number : ");
	scanf("%d",&new->data);
	new->next=NULL;
	if(head==NULL){
		head=current=new;
	}
	else{
		current->next=new;
		current=new;
	}
}
void delete(){
	int del,a=1;
	if(head==NULL){
		printf("list is empty...\n");
	}
	else{
		printf("enter which element you want to delete : ");
		scanf("%d",&del);
		if(head->data==del){
			printf("given number is deleted...\n");
			head=head->next;
		}
		else{
			for(temp=head;temp->next!=NULL;temp=temp->next){
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
				printf("given element is not present in the list ...\n");
			}
		}
	}
}
void display(){
	if(head==NULL){
		printf("list is empty...\n");
	}
	else{
		printf("the list is : \n");
		for(temp=head;temp->next!=NULL;temp=temp->next){
			printf("%d\t",temp->data);
		}
		printf("%d\n",temp->data);
	}
}
void sort(){
	int dat;
	for(temp=head;temp!=NULL;temp=temp->next){
		for(prev=temp;prev!=NULL;prev=prev->next){
			if(temp->data>prev->data){
				dat=temp->data;
				temp->data=prev->data;
				prev->data=dat;
			}
		}
		
	}
	printf("the LL is sorted......\n");
}
