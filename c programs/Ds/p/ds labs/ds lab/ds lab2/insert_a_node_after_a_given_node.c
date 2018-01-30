#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *ptr,*newnode=NULL,*start=NULL,*temp;
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
	printf("\nenter a node to insert a node after that node:");
	scanf("%d",&x);
	newnode=(struct node *)malloc(sizeof(struct node *));
	ptr=start;
	printf("enter inserstion node value:");
	scanf("%d",&newnode->data);
	while(ptr->data!=x)
	{
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->next=newnode;
	newnode->next=temp;	
	printf("\nnode values after inserstion a node :\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d ",ptr->data);
		ptr=ptr->next;
	}
	return 0;
}
