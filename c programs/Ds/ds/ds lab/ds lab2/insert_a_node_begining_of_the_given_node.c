#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *ptr,*newnode=NULL,*start=NULL,*temp,*pre_ptr;
	printf("enter the count of the node:");
	int n,i,x;
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
	printf("\nnode values before inserstion newnode :\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d ",ptr->data);
		ptr=ptr->next;
	} 	
	printf("\nenter a node to insert a node before that node:");
	scanf("%d",&x);
	newnode=(struct node *)malloc(sizeof(struct node *));
	printf("enter inserstion node value:");
	scanf("%d",&newnode->data);
		ptr=start;
		pre_ptr=start;
		while(ptr->data!=x)
		{
			pre_ptr=ptr;
			ptr=ptr->next;
		}	
		pre_ptr->next=newnode;
		newnode->next=ptr;
	printf("\nnode values after inserstion a node :\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d ",ptr->data);
		ptr=ptr->next;
	}
	return 0;
}
