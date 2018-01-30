#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *start=NULL,*newnode,*ptr,*end;
	int n,i;
	printf("enter the total nodes count:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node*));
		printf("\nenter the value into node:");
		scanf("%d",&newnode->data);
		if(start==NULL)
		{
			start=newnode;
			start->next=start;
			end=start;
		}
		else
		{
			newnode->next=start;
			end->next=newnode;
			start=newnode;
		}
	}
	printf("\nnode values before deletion:\n");
	ptr=start;
	while(ptr->next!=start)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n",ptr->data);
	
	return 0;
}
