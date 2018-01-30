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
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
int main()
{
	start=create_ll(start);
    start=display(start);
	start=insert_beg(start);
    start=display(start); 
    start=insert_end(start);
    start=display(start);  
     start=delete_beg(start);
       start=display(start);  
  start=delete_end(start);
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
			new_node->next=new_node;
			start=new_node;
			}
			else
			{
				ptr=start;
				while(ptr->next!=start)
				ptr=ptr->next;
				ptr->next=new_node;
				new_node->next=start;
                                
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
	while(ptr->next!=start)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
		}
              printf("%d\n",ptr->data);
		return start;
}
struct node *insert_beg(struct node *start)
{
     struct node *new_node,*ptr;
	int n;
	printf("enter a num\n");
	scanf("%d",&n);
		new_node=(struct node*)malloc(sizeof(struct node*));
		new_node->data=n;
				ptr=start;
				while(ptr->next!=start)
				ptr=ptr->next;
				ptr->next=new_node;
				new_node->next=start;
                                 start=new_node;
		
		return start;
}
struct node *insert_end(struct node *start)
{
        struct node *new_node,*ptr;
        int n;
         printf("enter data to insert\n");
         scanf("%d",&n);
         new_node=(struct node*)malloc(sizeof(struct node*));
         new_node->data=n;
         ptr=start;
          while(ptr->next!=start)
                  ptr=ptr->next;
               ptr->next=new_node;
               new_node->next=start;
               return start;
}
struct node *delete_beg(struct node *start)
{
       struct node *ptr;
       ptr=start;
       while(ptr->next!=start)
         ptr=ptr->next;
        ptr->next=start->next;
        free(start);
        start=ptr->next;
         return start;
}
struct node *delete_end(struct node *start)
{
     struct node *ptr,*pt;
     ptr=start;
     while(ptr->next!=start)
     {
      pt=ptr;
      ptr=ptr->next;
      }
     pt->next=start;
     free(ptr);
      return start;
}
