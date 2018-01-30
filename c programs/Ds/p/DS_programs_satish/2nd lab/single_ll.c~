#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display_ll(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *reverse(struct node *);
struct node *sorting(struct node *);
struct node *delete_before(struct node *);
main()
{	
	int n;
	do
	{
		printf ("\n *****MAIN MENU*****");
		printf ("\n 1:create a list");
		printf ("\n 2.Display the list ");
		printf ("\n 3.Add a node in the beginning");
		printf ("\n 4.Add a node at the end ");
		printf ("\n 5.Add a node after a given node");
		printf ("\n 6.Add a node before a given node  ");
		printf ("\n 7.Delete from the beginning ");
		printf ("\n 8.Delete from the end");
		printf ("\n 9.Delete a given node");
		printf ("\n 10.Delete after the given node");
		printf ("\n 11.Reverse of the given Linked list");
		printf ("\n 12.Sorting of the given Linked list");
		printf ("\n 13.Delete the node before given node");
		printf ("\n 14.EXIT");
		printf ("\n ****************************");
		printf ("\n Enter the option: ");
		scanf("%d",&n);
	 	switch(n)
	 	{
			case 1:
				start=create_ll(start);
				printf("\n LINKED LIST CREATED");
				break;
			case 2:
					start=display_ll(start);
					break;
			case 3:
					start=insert_beg(start);
					break;
			case 4:
					start=insert_end(start);
			break;
			case 7:
					start=delete_beg(start);
			break;

			case 5:
					start=insert_before(start);
			break;
  			case 6:
  					start=insert_after(start);
  			break;
			case 8:
					start=delete_end(start);
  			break;
			case 9:
					start=delete_node(start);
			break;
			case 10:
					start=delete_after(start);
			break;
			case 11:
					start=reverse(start);
			break;
			case 12:
					start=sorting(start);
			break;
			case 13:
					start=delete_before(start);
			break;
		}
	}while(n!=14);
}
struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf ("\n Enter -1 to end");
	printf ("\n Enter the data: ");
	scanf("%d",&num);
	start=NULL;
	while(num!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;	
		}		
		else
		{
			ptr=start;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("\n Enter the data: ");
		scanf("%d",&num);
	}
	return start;
}
struct node *display_ll(struct node *start)
{
	struct node *ptr;
	ptr=start;
	printf("\n");
	if(start==NULL)
	 {
			printf("\n\t\tUnderflow condition occured\n");
			
	 }
	 else{
	 
	while(ptr!=NULL)
	{
	printf("\t %d",ptr->data);
	ptr=ptr->next;
	}
	}
	
	return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	printf("\n Enter the data: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=start;
	start=new_node;
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
 	printf("\n Enter the data: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node *));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=NULL;
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
struct node *insert_before(struct node *start)
{
	struct node *ptr,*new_node,*preptr;
	int num,value;
	printf("Enter New node value:");
	scanf("%d",&num);
	printf("Enter  node value:");
	scanf("%d",&value);
	new_node=(struct new_node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=value)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	new_node->next=ptr;
	preptr->next=new_node;
	return start;
	
}
struct node *insert_after(struct node *start)
{
	struct node *ptr,*new_node,*preptr;
	int num,val;
	printf("Enter the new node value:");
	scanf("%d",&num);
	printf("Enter the desire node value");
	scanf("%d",&val);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	new_node->next=ptr;
	preptr->next=new_node;
	return start;
}
struct node *delete_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=NULL)
	{	
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;	
	free(ptr);
	return start;
}
struct node *delete_node(struct node *start)
{
	struct node *ptr,*preptr;
	int val;
	printf("enter the node value to be deleted");
	scanf("%d",&val);
	ptr=start;
	if(ptr->data==val)
	{
		start=delete_beg(start);
		return start;	
	}
	else
	{
	while(ptr->data!=val)
	{	
		preptr=ptr;
		ptr=ptr->next;
	}
		preptr->next=ptr->next;
		free(ptr);
	return start;
	}
}
struct node *delete_after(struct node *start)
{
	struct node *ptr,*preptr;
	int val;
	ptr=start;
	printf("Enter the value of node to delete after that node:");
	scanf("%d",&val);
	preptr=ptr->next;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
		printf("hi");
	}
	
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
struct node *reverse(struct node *start)
{
	struct node *ptr,*ptr1;
	ptr=start->next;
	while(ptr->next!=NULL)
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
	ptr1=ptr->next;
			ptr->next=start;
			start=ptr;
			ptr=ptr1;
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
			if(ptr->data>ptr1->data)	
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
struct node *delete_before(struct node *start)
{
	struct node *ptr,*preptr;
	int val;
	printf("\nEnter the node value to delete the node before it: ");
	scanf("%d",&val);
	ptr=start;
	while(ptr->next->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
