#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*head=NULL,*prev,*newnode;
void create_sll();
void display();
void insert_beg();
void insert_mid();
void insert_end();
main()
{
	int choice;
	do
	{
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\
		\n\n1 --> Create LL \t 2 --> Insert at beginig\t 3 --> insert in middle\n\n4 --> insert at end \t 5 -->display \t\t\t 6 -->exit\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Enter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:create_sll();
		break;
		case 2:insert_beg();
		break;
		case 3:insert_mid();
		break;
		case 4:insert_end();
		break;
		case 5:display();
		break;
	}
	}while(choice<6&&choice>0);
	if(choice>6)
	printf("Invaid input");
}
void create_sll()
{
	int num;
	printf("\nEnter -1 to exit");
	printf("\nEnter data: "); 
	scanf("%d",&num);
	while(num!=-1)
	{
		if(head==NULL)
		{
			head = (struct node *)malloc(sizeof(struct node));	
			if(head==NULL)
			 { printf("\nMemory allocation failed\n"); exit(1); }
			head->data=num;
			head->link = NULL;
		}
		else
		{
			for(prev=head;prev->link!=NULL;prev=prev->link);//for traversing upto prev node of present node
			newnode = (struct node *)malloc(sizeof(struct node));	
			if(newnode==NULL) { printf("\nMemory allocation failed\n"); exit(1); }
			prev->link = newnode;
			newnode->data=num;
			newnode->link = NULL;
			}
			printf("\nEnter data: "); scanf("%d",&num);
	}
}
void display()
{
	if(head == NULL ) 
	printf("\nList is empty!\n");
	else
	{
		for(newnode=head;newnode!=NULL;newnode=newnode->link)
			printf("\n%d",newnode->data);
	}
}
void insert_beg()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter your number");
	scanf("%d",&newnode->data);
	newnode->link=head;
	head=newnode;
}
void insert_mid()
{
	int p,c=0;
	struct node *ptr,*preptr;
	printf("Enter the position in which you want to insert");
	scanf("%d",&p);
	ptr=head;
	while(ptr!=NULL)
	{
		c=c+1;
		preptr=ptr;
		ptr=ptr->link;
		if(c==p)
		{
			newnode=(struct node *)malloc(sizeof(struct node));
			printf("enter the number:");
			scanf("%d",&newnode->data);
			preptr->link=newnode;
			newnode->link=ptr;
		}
	}
}
void insert_end()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter your number");
	scanf("%d",&newnode->data);
	for(prev=head;prev->link!=NULL;prev=prev->link);
	prev->link=newnode;
	newnode->link=NULL;	
}
