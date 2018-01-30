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
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_node(struct node *);
struct node *sorting(struct node *);
struct node *delete_list(struct node *);

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
        printf("\n 5:insert a node before a given node");
	printf("\n 6:insert a node after a given node");
        printf("\n 7:delete a node from beginning");
        printf("\n 8:delete a node from ending ");
        printf("\n9:delete a node before a given node");
        printf("\n10:delete a node after a given node");
        printf("\n11:delete a given node");
        printf("\n12:sorting the list");
        printf("\n13:delete entire list\n\n\n");
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
            case 5 :    start=insert_before(start);
                             break;
	 
           case 6 :	start=insert_after(start);
                          break;
           case 7 :      start=delete_beg(start);
                           break;
           case 8 :    start=delete_end(start);
                         break;
           case 9 :   start=delete_before(start);
                        break;
            case 10 :   start=delete_after(start);
                              break;
    
            case 11 :     start=delete_node(start);
                                  break;
            case 12 :   start=sorting(start);
                                  break;
           case 13 :     start=delete_list(start);
                             break; 
       }
}while(ch<=13);
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
        if(start!=NULL)
        {
	ptr=start;
	printf("\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
		}
         }
          else
               printf("\n linked list is empty\n");
		return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int n;
         if(start!=NULL)
          {
	printf("enter the data in the new node\n");
	scanf("%d",&n);
	new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=n;
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
	printf("enter no to insert at end\n");
	scanf("%d",&n);
	new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=n;
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=NULL;
        }
        else
          printf("\noverflow\n");
	return start;
}

struct node *insert_after(struct node *start)
{
	struct node *new_node,*ptr;
	int n,num;
         if(start!=NULL)
          {
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
        }    
        else
            printf("\n overflow\n"); 
		return start;
}
struct node *insert_before(struct node *start)
{
	struct node *new_node,*ptr,*pt;
	int n,num;
          if(start!=NULL)
          {
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
        }
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
	start=start->next;
	free(ptr);
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
	while(ptr->next!=NULL)
	{
		pt=ptr;
		ptr=ptr->next;
		}
		pt->next=NULL;
		free(ptr);
          }
          else
           printf("\nunderflow\n");
		return start;
}
struct node *delete_node(struct node *start)
{
	struct node *ptr,*pt;
	int n;
         if(start!=NULL)
        {
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
         }
		
}
         else
          printf("\nunderflow\n");
       return start;
}
struct node *delete_before(struct node *start)
{
	struct node *ptr,*pt,*p;
	int n;
         if(start!=NULL)
        {
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
       }
        else
           printf("\nunderflow\n");
		return start;	
}
struct node *delete_after(struct node *start)
{
	struct node *ptr,*pt;
	int n;
        if(start!=NULL)
        {
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
         }	
        }
        else
            printf("\nunderflow\n");
            return start;
}
struct node *delete_list(struct node *start){
           struct node *ptr;
           if(start!=NULL)
           {
           ptr=start;
           while(ptr->next!=NULL)
          {
            printf("\n %d is to be deleted next",ptr->data);
             start=delete_beg(ptr);
             ptr=ptr->next;
          }
           printf("\n %d is the last node to be deleted\n",ptr->data);
          start=NULL;
          }
          else
              printf("\nunderflow\n");
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
   
