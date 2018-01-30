#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct queue{
	struct node *front;
	struct node *rear;
};
struct queue *q=NULL;
struct queue *create_queue(struct queue *);
struct queue *insert(struct queue *,int);
struct queue *delete_element(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);
int main()
{
		int ch,val;
		  q=create_queue(q);
	do
	{
		printf("\n\n MAIN MENU\n");
		printf("1.insert an element\n");
		printf("2.deleteing an element\n");
		printf("3.peek\n");
		printf("4.display the queue\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : 
				 printf("enter number to insert into queue:");
			           scanf("%d",&val);
			            q=insert(q,val);
			          break;
			case 2 : 
			          q=delete_element(q);
			               break;
	                  case 3 : val=peek(q);
	                           if(val!=-1)
			               printf("\n the element at top is  %d",val);
			               break;
			case 4 : q=display(q);
			         break;
			}
		}while(ch<=4);
}
struct queue *create_queue(struct queue *q)
{
      q=(struct queue *)malloc(sizeof(struct queue *));
	q->rear=NULL;
	q->front=NULL;
   return q;
}
struct queue *insert(struct queue *q,int val)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node*));
	ptr->data=val;
	if(q->front==NULL)
	{
		q->front=ptr;
		q->rear=ptr;
		q->front->next=q->rear->next=NULL;
    }
	else
	{
		q->rear->next=ptr;
		q->rear=ptr;
		q->rear->next=NULL;
    }
		return q;
}
struct queue *delete_element(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(q->front==NULL)
	     printf("underflow\n");
	else
	  {
			q->front=q->front->next;
			printf("%d is going to be deleted\n",ptr->data);
			free(ptr);
			}
			return q;
}
struct queue *display(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(ptr==NULL)
	 printf("queue is empty\n");
	 else
	 {
			printf("\n");
			while(ptr!=q->rear)
			  {
					printf("%d\t",ptr->data);
					ptr=ptr->next;
					}
					printf("%d\n",ptr->data);
			}
			return q;
}
int peek(struct queue *q)
{
	if(q->front==NULL)
	  {
			printf("queue is empty\n");
			return -1;
			}
    else
              return q->front->data;
}
