#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *ptr,*newnode,*start;
	start=NULL;
	newnode=(struct node*)malloc(sizeof(struct node*));
	int n,i,x;
	printf("\nenter -1 to stop linked list creation:");
	scanf("%d",&n);
	while(n!=-1)
	{
		newnode=(struct node*)malloc(sizeof(struct node*));
		printf("\nenter a value into newnode:");
		scanf("%d",&newnode->data);
		if(start==NULL)
		{
			start=newnode;
			start->next=start;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
			newnode->next=start;
		}
			printf("\nenter -1 to stop linked list creation:");
			scanf("%d",&n);
	}
		printf("\n BEFORE INSERTION LINKED LIST NODE VALUES :\n");
		ptr=start;
		while(ptr->next!=start)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}		
		printf("%d\n",ptr->data);
		printf("enter a node value to insert a node after that: ");
		scanf("%d",&x);
		printf("\nenter newnode data:");
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		ptr=start;
		while(ptr->data!=x)
		{
			ptr=ptr->next;
		}
		newnode->next=ptr->next;
		ptr->next=newnode;
		printf("\n AFTER INSERTION LINKED LIST NODE VALUES :\n");
		ptr=start;
		while(ptr->next!=start)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
	return 0;
}
