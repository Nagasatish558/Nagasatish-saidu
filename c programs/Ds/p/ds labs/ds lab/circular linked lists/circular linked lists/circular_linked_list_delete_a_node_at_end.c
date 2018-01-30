#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *ptr,*pre_ptr,*newnode,*start=NULL;
	newnode=(struct node*)malloc(sizeof(struct node*));
	int n,i;
	printf("\nenter count of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
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
	}
		printf("\nLINKED LIST NODE VALUES before deletion:\n");
		ptr=start;
		while(ptr->next!=start)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}		
		printf("%d\n",ptr->data);
		ptr=start;
		while(ptr->next!=start)
		{
			pre_ptr=ptr;
			ptr=ptr->next;
		}	
		pre_ptr->next=start;
		free(ptr);
		printf("\nLINKED LIST NODE VALUES after deletion of a node:\n");
		ptr=start;
		while(ptr->next!=start)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}		
		printf("%d\n",ptr->data);
	return 0;
}
