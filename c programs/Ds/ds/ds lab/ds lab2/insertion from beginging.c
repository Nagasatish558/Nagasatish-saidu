#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *ptr,*newnode=NULL,*start=NULL;
	printf("To exit the taking values please enter: %d\n",-1);
	int n;
	printf("enter the value into -1 to exit:\n");
	scanf("%d",&n);
	while(n!=-1)
	{
		
		newnode=(struct node*)malloc(sizeof(struct node*));
		ptr=newnode;
		printf("\nenter the value into node:");
		scanf("%d",&newnode->data);
		if(start==NULL)
		{
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
			newnode->next=start;
			start=newnode;
		}
		printf("\nenter a value into node -1 to exit:");
		scanf("%d",&n);
	}
	printf("node values :\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	return 0;
}
