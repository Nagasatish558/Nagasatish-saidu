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
     int ch;
        do
        {
        printf("\n\n\nenter ur choice\n ");
        printf(" \n 1:create a list");
        printf("\n 2: display a list");
        printf("\n 3: insert a node at beginning");
        printf("\n 4:insert a node at end");
        printf("\n 5:delete a node from beginning");
        printf("\n 6:delete a node from ending \n\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :     start=create_ll(start);
                          printf("\n linked list created");
                           break;
            case 2 :        start=display(start);
                                break;
            case 3 :       start=insert_beg(start);
                                 break;
  
            case 4 : 	start=insert_end(start);
                           break;
            case 5 :    start=delete_beg(start);
                             break;
	     case 6 :	start=delete_end(start);
                          break;              
       }
}while(ch<=6);
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
        if(start!=NULL)
        {
	ptr=start;
	printf("\n");
	while(ptr->next!=start)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
		}
              printf("%d\n",ptr->data);
        }
         else
           printf("\n linked list is empty\n");
		return start;
}
struct node *insert_beg(struct node *start)
{
     struct node *new_node,*ptr;
	int n;
       if(start!=NULL)
       {
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
		}
              else
                printf("\noverflow\n");
		return start;
}
struct node *insert_end(struct node *start)
{
        struct node *new_node,*ptr;
        int n;
           if(start!=NULL)
          {
         printf("enter data to insert\n");
         scanf("%d",&n);
         new_node=(struct node*)malloc(sizeof(struct node*));
         new_node->data=n;
         ptr=start;
          while(ptr->next!=start)
                  ptr=ptr->next;
               ptr->next=new_node;
               new_node->next=start;
           }
         else
                printf("\noverflow\n");
               return start;
}
struct node *delete_beg(struct node *start)
{
       struct node *ptr;
        if(start!=NULL)
       {
       ptr=start;
       while(ptr->next!=start)
         ptr=ptr->next;
        ptr->next=start->next;
        free(start);
        start=ptr->next;
        }
          else
               printf("\nunderflow\n");
         return start;
}
struct node *delete_end(struct node *start)
{
     struct node *ptr,*pt;
     if(start!=NULL)
     {
     ptr=start;
     while(ptr->next!=start)
     {
      pt=ptr;
      ptr=ptr->next;
      }
     pt->next=start;
     free(ptr);
    }
      else
               printf("\nunderflow\n");
      return start;
}
