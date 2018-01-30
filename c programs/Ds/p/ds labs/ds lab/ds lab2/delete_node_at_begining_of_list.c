#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *ptr,*newnode=NULL,*start=NULL,*temp;
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
	printf("\nnode values before delete node at begining:\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d ",ptr->data);
		ptr=ptr->next;
	}
	temp=start;
	start=start->next;
	free(temp);
	printf("\nnode values  delete node at begining:\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d ",ptr->data);
		ptr=ptr->next;
	}
	return 0;
}
