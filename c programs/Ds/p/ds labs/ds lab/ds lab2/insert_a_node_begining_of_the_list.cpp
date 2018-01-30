#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *ptr,*newnode=NULL,*start=NULL,*temp;
	printf("enter count node values:");
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
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
	}
	printf("\nnode values before insert node at begining of list:\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d ",ptr->data);
		ptr=ptr->next;
	}
	newnode=(struct node*)malloc(sizeof(struct node*));
	printf("\nenter the data into newnode:");
	scanf("%d",&newnode->data);
	newnode->next=start;
	start=newnode;
	printf("\nnode values after insert node at begining list:\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d ",ptr->data);
		ptr=ptr->next;
	}
	return 0;
}
