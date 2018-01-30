#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *next;
	int data;
	struct node *prev;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_node(struct node *);
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
	 start=delete_node(start);
	 start=display(start);
}
struct node *create_ll(struct node *start)
{
	struct node *new_node,*ptr;
	int n;
	printf("enter -1 to terminate\n");
	printf("enter data\n");
	scanf("%d",&n);
	while(n!=-1)
	{
		if(start==NULL)
		{
			new_node=(struct node*)malloc(sizeof(struct node*));
			new_node->prev=NULL;
			new_node->data=n;
			new_node->next=NULL;
			start=new_node;
			}
			else
			{
				ptr=start;
			    new_node=(struct node*)malloc(sizeof(struct node*));
			    new_node->data=n;
			    while(ptr->next!=NULL)
			        ptr=ptr->next;
			        
			        ptr->next=new_node;
			        new_node->prev=ptr;
			        new_node->next=NULL;
				}
				printf("enter the data\n");
				scanf("%d",&n);
		}
		 return start;
}
struct node *display(struct node *start)
{
	 struct node *ptr;
	 ptr=start;
	 while(ptr->next!=NULL)
	 { 
			printf("%d\t",ptr->data);
			ptr=ptr->next;
			}
			printf("%d\n",ptr->data);
			return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	printf("enter data to newnode\n");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node*));
    new_node->data=num;
	start->prev=new_node;
	new_node->prev=NULL;
	new_node->next=start;
    start=new_node;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("enter the data\n");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=NULL;
	return start;
}
struct node *insert_before(struct node *start)
{
	struct node *new_node,*ptr;
	int n,num;
	printf("enter the newnode data\n");
	scanf("%d",&num);
	printf("before which node you want...?\n");
	scanf("%d",&n);
    new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=n)
	 ptr=ptr->next;
	  new_node->next=ptr;
	  new_node->prev=ptr->prev;
	  ptr->prev->next=new_node;
	  ptr->prev=new_node;
	  return start;
}
struct node *insert_after(struct node *start)
{
	struct node *new_node,*ptr;
	int n,num;
	printf("enter the newnode\n");
	scanf("%d",&num);
	printf("after which you want the no...?\n");
	scanf("%d",&n);
	new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=n)
	 ptr=ptr->next;
	 new_node->next=ptr->next;
	 ptr->next->prev=new_node;
	 new_node->prev=ptr->next->prev;
	 ptr->next=new_node;
	 return start;
}
struct node *delete_node(struct node *start)
{
	struct node *ptr;
	int n;
	printf("enter which node u wanna delete?\n");
	scanf("%d",&n);
	ptr=start;
	while(ptr->data!=n)
	 ptr=ptr->next;
	 ptr->next->prev=ptr->prev;
	 ptr->prev->next=ptr->next;
	 free(ptr);
	 return start;
}
      
