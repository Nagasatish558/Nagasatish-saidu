//Program to implement circular queue

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL,*temp,*new,*current,*prev;

void enqueue();
void dequeue();
void display();

main(){
	int ch;
	do{
		printf("1.Enqueue \n2.Dequeue \n3.Display \n4.Exit \n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
		}
	}while(ch!=4);
}
void enqueue(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter the data : ");
	scanf("%d",&new->data);
	new->next=NULL;
	printf("given element is enqueued...\n");
	if(front==NULL&&rear==NULL){
		front=rear=new;
		rear->next=front;
	}
	else{
		rear->next=new;
		rear=new;
		rear->next=front;
	}
}
void dequeue(){
	if(front==NULL&&rear==NULL){
		printf("queue is empty...\n");
	}
	else{
		printf("the element is dequeued...\n");
		if(front==rear){
			front=rear=NULL;
		}
		else{
			temp=front;
			front=front->next;
			free(temp);
			rear->next=front;
			
		}
	}
}
void display(){
	if(front==NULL&&rear==NULL){
		printf("queue is empty...\n");
	}
	else{
		printf("the queue is : \n");
		for(temp=front;temp!=rear;temp=temp->next){
			printf("%d\t",temp->data);
		}
		printf("%d\n",temp->data);
	}
}
