#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *ptr,*preptr,*newnode,*start,*ptr1;
	start=NULL;
	newnode=(struct node*)malloc(sizeof(struct node*));
	int n,i,x,temp;
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
		printf("\n NODE VALUES BEFORE SOTRTING  :\n");
		ptr=start;
		while(ptr->next!=start)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}		
		printf("%d\n",ptr->data);
		ptr=start;
		do
		{
			ptr1=start;
			while(ptr1->next!=start)
			{
				if(ptr1->data>ptr1->next->data)
				{
					temp=ptr1->data;
					ptr1->data=ptr1->next->data;
					ptr1->next->data=temp;
				}
				ptr1=ptr1->next;
			}
			ptr=ptr->next;
		}while(ptr!=start);
		printf("\n NODE VALUES BEFORE SOTRTIN  :\n");
		ptr=start;
		while(ptr->next!=start)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}		
		printf("%d\n",ptr->data);
	return 0;
}
