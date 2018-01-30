#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *ptr,*newnode=NULL,*start=NULL,*ptr1;
	printf("To exit the taking values please enter: %d\n",-1);
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		
		newnode=(struct node*)malloc(sizeof(struct node*));
		ptr=newnode;
		printf("enter the node value:");
		scanf("%d",&newnode->data);
		if(start==NULL)
		{
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
			newnode->next=NULL;
		}
		printf("enter a value continue in the linked list else to exit  enter :-1:\n");
		scanf("%d",&n);
	}
	printf("node values before reverse:\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	ptr=start->next;
	while(ptr->next!=NULL)
	{
	 if(ptr==start->next)
		{	
			start->next=NULL;	
			ptr1=ptr->next;
		}
	else
		{
			ptr->next=start;					
			start=ptr;	
			ptr=ptr1;
			ptr1=ptr1->next;
		}
	}
	ptr->next=start;
	start=ptr;
	printf("node values after reverse:\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	ptr=start->next;
	return 0;
}
