#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *count(struct node *);
struct node *add(struct node *,struct node *,struct node *);
int main()
{
	start1=create_ll(start1);
    start1=display(start1);
        start1=count(start1);
	start2=create_ll(start2);
    start2=display(start2);
        start2=count(start2);
        start3=add(start1,start2,start3);
       start3=display(start3);
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
struct node *add(struct node *start1,struct node *start2,struct node *start3)
{
     struct node *ptr,*pt,*p;
     int sum=0,n1,n2;
     ptr=start1;
     pt=start2;
     p=start3;
     while((ptr!=NULL)&&(pt!=NULL))
     {
      n1=ptr->data;
      n2=pt->data;
      sum=n1+n2;
      p->data=sum;
      ptr=ptr->next;
      pt=pt->next;
      p=p->next;
     }
     return start3;
}
