#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_before(struct node *);
struct node *delete_list(struct node *);
int main( )
{
		start=create_ll(start);
    start=display(start);
    start=delete_beg(start);
    printf("\nafter deleting at beginning\n");
    start=display(start);
    start=delete_end(start);
    printf("\n after deleting at ending\n");
    start=display(start);
    start=delete_node(start);
    start=display(start);
    start=delete_after(start);
    start=display(start);
   start=delete_before(start);
     start=display(start);
     start=delete_list(start);
   
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
struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	return start;
}
struct node *delete_end(struct node *start)
{
	struct node *ptr,*pt;
	ptr=start;
	while(ptr->next!=NULL)
	{
		pt=ptr;
		ptr=ptr->next;
		}
             
		pt->next=NULL;
		free(ptr);
		return start;
}
struct node *delete_node(struct node *start)
{
	struct node *ptr,*pt;
	int n;
	printf("which number you wanna delete?\n");
	scanf("%d",&n);
	ptr=start;
	if(ptr->data==n)
	{
		start=delete_beg(start);
		return start;
		}
		else
		{
	while(ptr->data!=n)
	{
		pt=ptr;
		ptr=ptr->next;
		}
		pt->next=ptr->next;
		free(ptr);
		return start;
}
}
struct node *delete_after(struct node *start)
{
	struct node *ptr,*pt;
	int n;
	printf("\nafter which  value you wanna delete? ");
	scanf("%d",&n);
	ptr=start;
        if(ptr->data==n)
        {
            pt=ptr->next;
            ptr->next=pt->next;
            free(pt);
             return start;
        }
          
         else 
         {
	pt=ptr;
	while(pt->data!=n)
	{
		pt=ptr;
		ptr=ptr->next;

        }
 
         pt->next=ptr->next;
		free(ptr);
         
		return start;
        }
}
struct node *delete_before(struct node *start)
{
	struct node *ptr,*pt,*p;
	int n;
	printf("before which you wanna delete?\n");
	scanf("%d",&n);
	ptr=start;
	pt=ptr;
      
	while(ptr->data!=n)
	{ 
		pt=ptr;
		ptr=ptr->next;
        }
         p=start;
       while(p->next!=pt)
                 p=p->next;
		p->next=pt->next;
		free(pt);
		return start;	
}
struct node *delete_list(struct node *start)
{
           struct node *ptr;
           ptr=start;
           while(ptr->next!=NULL)
          {
            printf("\n %d is to be deleted next",ptr->data);
             start=delete_beg(ptr);
             ptr=ptr->next;
          }
           printf("\n %d is the last node to be deleted\n",ptr->data);
          start=NULL;
          return start;
}
