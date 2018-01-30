#include<stdio.h>
#define  MAX 10
int queue[MAX];
int front=-1,rear=-1;
void insert(void);
int delete_element(void);
int peek(void);
void display(void);
int main()
{
	int ch,val;
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
			case 1 : insert();
			          break;
			case 2 : val=delete_element();
			          if(val!=-1)
			               printf("\n the element to be deleted is  %d",val);
			               break;
	        case 3 : val=peek();
	                if(val!=-1)
			               printf("\n the element at top is  %d",val);
			               break;
			case 4 : display();
			         break;
			}
		}while(ch<=4);
}
void insert()
{
	int n;
	 printf("enter number to insert\n");
	 scanf("%d",&n);
	 if(front==0 && rear==MAX-1)
	   printf("overflow\n");
	      else if(front==-1 && rear==-1)
	      {
			
	        front=rear=0;
	         queue[rear]=n;
	     }
	      else if(rear==MAX-1 && front!=0)
	        {
		
		rear=0;
		queue[rear]=n;
		}
		else if(front==0 && rear>0)
	       {	 	 
		queue[++rear]=n;
	       }
	 else if(rear==0 && front==0)
	       {
			 
	             rear++;
	              queue[rear]=n;
	       }
	
 }
 int delete_element()
 {
		int val;
		if(front==-1 && rear==-1)
		 {
				printf("underflow\n");
				return -1;
				}
	
			val=queue[front];
			if(front==rear)
			      front=rear=-1;
				else
		{
			
			if(front==MAX-1)
			    front=0;
			else
			    front++;
	    }
			  return val;
}
int peek()
{
	if(front==-1 && rear==-1)
	{
		printf("\n queue is empty\n");
		return -1;
		}
	else
	   return queue[front];
}
void display()
{
	 int i;
	  printf("\n");
	if(front==-1 && rear==-1)
	   printf("\n queue is empty\n");
	else
	{
		if(front<rear)
		{
			for(i=front;i<=rear;i++)
			 printf("%d\t",queue[i]);
			}
		else
		{
			for(i=front;i<MAX;i++)
			  printf("\t%d",queue[i]);
			  for(i=0;i<=rear;i++)
			    printf("\t%d",queue[i]);
			}
		}
}
