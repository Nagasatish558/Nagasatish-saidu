#include<stdio.h>
#include<stdlib.h>
struct node{
       int data;
       struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *count(struct node *);
struct node *search(struct node *);
int main()
{
          start=create_ll(start);
          start=display(start);
          start=count(start);
          start=search(start);
}
struct node *create_ll(struct node *start)
{
	struct node *new_node,*ptr;
	int n;
	printf("enter -1 to terminate\n");
	printf("enter a num\n");
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
struct node *count(struct node *start)
{
       struct node *ptr;
       int c=0;
       ptr=start;
       while(ptr!=NULL)
       {
           c=c+1;
           ptr=ptr->next;
       }
       printf("\n %d elements are in linked list\n",c);
       return start;
}
struct node *search(struct node *start)
{
  struct node *ptr;
  int n;
  printf("enter the data to search:\n");
  scanf("%d",&n);
  ptr=start;
  while(ptr!=NULL)
    {
     if(ptr->data==n)
         {
         printf("search is found\n");
          exit(0);
           }
     else
          ptr=ptr->next;
   }
   printf("search not found\n");
    return start;
}

