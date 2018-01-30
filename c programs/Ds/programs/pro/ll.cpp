#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node*);
int main()
{
	start=create_ll(start);
    start=display(start);
	start=insert_beg(start);
    start=display(start);       
	start=insert_end(start);
	start=display(start);
	start=insert_before(start);
    start=display(start);
	start=insert_after(start);
    start=display(start);
    
}

struct node *create_ll(struct node *start)
{
	struct node *new_node,*ptr;
	int n;
	printf("enter -1 to terminate");
	printf("enter a num");
	scanf("%d",&n);
	while(n!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node*));
		new_node->data=n;
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
			}
			else
			{
				ptr=start;
				while(ptr->next!=NULL)
				ptr=ptr->next;
				ptr->next=new_node;
				new_node->next=NULL;
			}
				printf("enter data");
				scanf("%d",&n);
		}
		return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	printf("\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
		}
		return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int n;
	printf("enter the data in the new node\n");
	scanf("%d",&n);
	new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=n;
	new_node->next=start;
	start=new_node;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *new_node,*ptr;
	int n;
	printf("enter no to insert at end\n");
	scanf("%d",&n);
	new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=n;
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=NULL;
	return start;
}

struct node *insert_after(struct node *start)
{
	struct node *new_node,*ptr;
	int n,num;
	printf("enter the data");
	scanf("%d",&num);
	printf("after which node you want the number ?");
	scanf("%d",&n);
	new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=n)
	{
		ptr=ptr->next;
		
	}
	 new_node->next=ptr->next; 
	    ptr->next=new_node;	     
		return start;
}
struct node *insert_before(struct node *start)
{
	struct node *new_node,*ptr,*pt;
	int n,num;
	printf("enter data");
	scanf("%d",&num);
	printf("before which node you want number?");
	scanf("%d",&n);
	new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=num;
	ptr=start;
         if(ptr->data==n)
         {
           new_node->next=start;
           start=new_node;
           return start;
          }
          else
        {
	while(ptr->data!=n)
	{
			pt=ptr;
		ptr=ptr->next;
		}
	pt->next=new_node;
	new_node->next=ptr;

		return start;
}
}

