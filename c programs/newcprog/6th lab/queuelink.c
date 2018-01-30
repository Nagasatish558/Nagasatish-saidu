#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct queue{
	struct node *front;
	struct node *rear;
};
struct queue *q;
struct queue *create_queue(struct queue *);
struct queue *insert(struct queue *,int);
struct queue *delete(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);
int main()
{
	int val,option;
	q=create_queue(q);
	do{
		printf("\n****MAINMENU****\n1.Insert\n2.Delete\n4.Peek\n3.Display\n5.Exit");
		printf("\nEnter your option:");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter the number to be insert into queue:");
				scanf("%d",&val);
				q=insert(q,val);
				break;
			case 2:
				q=delete(q);
				break;
			case 3:
				q=display(q);
				break;
				case 4:
					peek(q);
					break;
		}
	}while(option!=5);
	return 0;	
}
struct queue * create_queue(struct queue *q){
	q=(struct node *)malloc(sizeof(struct node ));
	q->rear=NULL;
	q->front=NULL;
	return q;
}
struct queue *insert(struct queue *q,int val){
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	if(q->front==NULL){
		q->front=ptr;
		q->rear=ptr;
		q->front->next=q->rear->next=NULL;
	}
	else{
		q->rear->next=ptr;
		q->rear=ptr;
		q->rear->next=NULL;
	}
	return q;
}
struct  queue *display(struct queue *q){
	struct node *ptr;
	ptr=q->front;
	if(ptr==NULL)
		printf("\nQueue is EMPTY");
	else{
		printf("\n");
		while(ptr!=q->rear){
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
	return q;
}
struct queue *delete(struct queue *q){
	struct node *ptr;
	ptr=q->front;
	if(q->front==NULL)
		printf("\nUnderflow");
	else{
		q->front=q->front->next;
		printf("\n The value being deleted is %d",ptr->data);
		free(ptr);
	}
	return q;
}
int peek(struct queue *q){
	if(q->front==NULL){
		printf("\n Queue is emptly");
		return -1;
	}
	else{
		return (printf("front element is %d",q->front->data));
	}
}
