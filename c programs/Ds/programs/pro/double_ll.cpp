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
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *delete_node(struct node *);
int main()
{
	 int ch;
	 do
	 {
			printf("\n\n\nenter 13 to terminate\n");
			printf("1:createing double linked list\n");
			printf("2:displaying linked list\n");
			printf("3:insert at beginning of list\n");
			printf("4:insert at end of list\n");
			printf("5:insert before any given node\n");
			printf("6:insert after any given node\n");
			printf("7:deleting at beginning\n");
			printf("8:deleting at ending \n");
			printf("9:deleting before any given node\n");
			printf("10:deleting after any given node\n");
			printf("11:deleting entire list\n");
			printf("12:deleting given node\n");
		    printf("enter your choice\n");
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
           case 11 :     start=delete_list(start);
                             break; 
           case 12 :      start=delete_node(start);
                             break;
}
}while(ch<=12);
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
	  if(start!=NULL)
	  {
	 ptr=start;
	 while(ptr->next!=NULL)
	 { 
			printf("%d\t",ptr->data);
			ptr=ptr->next;
			}
			printf("%d\n",ptr->data);
	}
	else
	     printf("linked list is empty\n");
			return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	 if(start!=NULL)
	 {
	printf("enter data to newnode\n");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node*));
    new_node->data=num;
	start->prev=new_node;
	new_node->prev=NULL;
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
	int num;
	 if(start!=NULL)
	 {
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
   }
   else
      printf("\noverflow\n");
	return start;
}
struct node *insert_before(struct node *start)
{
	struct node *new_node,*ptr;
	int n,num;
	 if(start!=NULL)
	 {
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
	start->prev=NULL;
	free(ptr);
	}
	else
	 printf("\nunderflow\n");
	return start;
}
struct node *delete_end(struct node *start)
{
	struct node *ptr;
	 if(start!=NULL)
	 {
	ptr=start;
	while(ptr->next!= NULL)
	ptr=ptr->next;
	ptr->prev->next=NULL;
	free(ptr);
	}
	else
	  printf("\nunderflow\n");
	return start;
}
struct node *delete_before(struct node *start)
{
	struct node *ptr,*temp;
	int num;
	  if(start!=NULL)
	 {
	printf("before which node you want to delete\n");
	scanf("%d",&num);
	ptr=start;
	while(ptr->data != num)
	ptr=ptr->next;
	temp=ptr->prev;
	if(temp==start)
         start=delete_beg(start);
   else
   {
    ptr->prev=temp->prev;
	temp->prev->next=ptr;
   }
	free(temp);
   }
   else
     printf("\nunderflow\n");
	return start;
}
struct node *delete_after(struct node *start)
{
	struct node *ptr,*temp;
	int n;
	 if(start!=NULL)
	 {
	printf("after which node you wanna delete..?\n");
	scanf("%d",&n);
	ptr=start;
	while(ptr->data!=n)
	 ptr=ptr->next;
	 temp=ptr->next;
	 ptr->next=temp->next;
	 temp->next->prev=ptr;
	 free(temp);
	}
	else
	printf("\nunderflow\n");
	 return start; 
}
struct node *delete_list(struct node *start)
{
	 struct node *ptr;
	  if(start!=NULL)
	 {
	  ptr=start;
      while(ptr->next!=NULL)
          {
           start=delete_beg(start);
            ptr=ptr->next;
			}
			 free(ptr);
			 printf("listed is deleted\n");
	}
			 else
			  printf("\nunderflow\n");
       return start;
}
struct node *delete_node(struct node *start)
{
	struct node *ptr;
	int n;
	 if(start!=NULL)
	 {
	printf("enter which node u wanna delete?\n");
	scanf("%d",&n);
	ptr=start;
	while(ptr->data!=n)
	 ptr=ptr->next;
	 ptr->next->prev=ptr->prev;
	 ptr->prev->next=ptr->next;
	 free(ptr);
	}
	else
	  printf("\nunderflow\n");
	 return start;
}
      
