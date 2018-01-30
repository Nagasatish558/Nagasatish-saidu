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
	printf("\nnode values before delete node :\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\nenter a node value to delete a node after that node:");
	scanf("%d",&x);
	ptr=start;
	while(ptr->data!=x)
	{
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->next=temp->next;
	free(temp);
	printf("\nnode values  delete node at after node:%d\n",x);
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d ",ptr->data);
		ptr=ptr->next;
	}
	return 0;
}
