#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *sorting(struct node *);
struct node *reverse(struct node *);
int main()
{
  start=create_ll(start);
  start=display(start);
  start=sorting(start);
  start=display(start);
  start=reverse(start);
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
struct node *sorting(struct node *start)
{
   struct node *ptr,*ptr1;
    int temp;
    ptr=start;
    while(ptr!=NULL)
      {
        ptr1=ptr->next;
        while(ptr1!=NULL)
           {
             if(ptr->data > ptr1->data)
              {
               temp=ptr->data;
                ptr->data=ptr1->data;
               ptr1->data=temp;
              }
              ptr1=ptr1->next;
            }
           ptr=ptr->next;
}
 return start;
}
struct node *reverse(struct node *start)
{
     struct node *ptr,*ptr1;
     ptr=start->next;
     while(ptr!=NULL)
     {
          if(ptr==start->next)
               start->next=NULL;
          else
          {
                 ptr1=ptr->next;
                  ptr->next=start;
                    start=ptr;
                    ptr=ptr1;
          }
      }
          return start;
}

