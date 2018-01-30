#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after(struct node *);
struct node *insert_before(struct node *);
struct node *delete_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_after(struct node *);
struct node *delete_before(struct node *);
struct node *sort(struct node *);
struct node *reverse(struct node *);
int main()
{
	int option;
	do
	{
		printf("******* THIS IS MENU **********\n");
		printf("1.cration a singular linked list\n");
		printf("2.diplay the  singular linked list\n");
		printf("3.INSERT A NODE IN BEGINING\n");
		printf("4.INSERT A NODE AT END OF THE LIST\n");
		printf("5.INSERT A NODE AT AFTER A NODE OF THE LIST\n");
		printf("6.INSERT A NODE AT BEFORE A NODE OF THE LIST\n");
		printf("7.DELETE A NODE which was on the end A NODE OF THE LIST\n");
		printf("8.DELETE A NODE AT BEGINING OF THE singular\n");
		printf("9.DELETE A NODE AFTER A GIVEN NODE\n");
		printf("10.delete a node before a given node\n");
		printf("12.sort of given singular\n");
		printf("11.to exit\n");
		printf("13.reverse list\n");
		printf("**************************************\n");
		printf("enter ur option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:start=create(start);
				printf("%d", start->data);
				break;
			case 2:start=display(start);
				break;
			case 3:start=insert_beg(start);
				break;
			case 4:start=insert_end(start);
				break;
			case 5:start=insert_after(start);
				break;
			case 6:start=insert_before(start);
				break;
			case 7:start=delete_end(start);
				break;	
			case 8:start=delete_beg(start);
				break;
			case 9:start=delete_after(start);
				break;
			case 10:start=delete_before(start);
				break;
			case 12:start=sort(start);
				break;
			case 13:start=reverse(start);	
				break;
			case 11:printf("\n******** THANK YOU ******\n");
				break;
			default:printf("\n INVALID INPUT");
		}			
	}while(option!=11);
	return 0;
}	
struct node *create(struct node *start)
{
	free(start);
	struct node *newnode=NULL,*ptr=NULL;
	printf("to stop creation -1: \n");
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		
		newnode=(struct node*)malloc(sizeof(struct node));
		ptr=newnode;
		printf("enter the node value:");
		scanf("%d",&newnode->data);
		if(start==NULL)
		{
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
			newnode->next=NULL;
		}
		printf("to stop creation -1: \n");
		scanf("%d",&n);
	}
	return start;
}
struct node *display(struct node *start)
{
	printf("THIS IS DISPLAY\n");
	if(start==NULL)
	{
	printf("list is empty:\n");
	return start;
	}
	else
	{
		struct node *ptr;
		ptr=start;
		while(ptr!=NULL)
		{
			printf("%d \n",ptr->data);
			ptr=ptr->next;
		}
	}
	return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *ptr,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node*));
	printf("\nenter the data into newnode:");
	scanf("%d",&newnode->data);
	newnode->next=start;
	start=newnode;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *ptr,*newnode;
	if(start!=NULL)
	{
		newnode=(struct node*)malloc(sizeof(struct node*));
	printf("\nenter the data into newnode:");
	scanf("%d",&newnode->data);
	ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->next=NULL;
	}
	else
	{
		printf("\nUNDER FLOW\n");		
	}
	return start;
}
struct node *insert_after(struct node *start)
 {  

	if(start==NULL)
	{
	printf("list is not created:\n");
	return start;
	}
	else
	{
	struct node *ptr,*newnode,*temp;
	int x;
	printf("\nenter a node to insert a node after that node:");
	scanf("%d",&x);
	newnode=(struct node *)malloc(sizeof(struct node ));
	ptr=start;
	while(ptr->data!=x)
	{
		if(ptr->next==NULL)
		{
			printf("%d is not in the list\n",x);
			return start;
		}
		else
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->next=newnode;
	newnode->next=temp;
	printf("enter inserstion node value:");
	scanf("%d",&newnode->data);
	return start;
	}
}
struct node *insert_before(struct node *start)
{
	struct node *ptr,*pre_ptr,*newnode;
	int x;
	if(start==NULL)
		printf("list is empty,please create the list\n");	
	else
	{
		printf("\nenter a node to insert a node before that node:");
		scanf("%d",&x);
		newnode=(struct node *)malloc(sizeof(struct node *));
		ptr=start;
		pre_ptr=start;
		while(ptr->data!=x)
		{
			pre_ptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==pre_ptr)
		{
			start=insert_beg(start);
		}
		else
		{	
		printf("enter inserstion node value:");
		scanf("%d",&newnode->data);
		pre_ptr->next=newnode;
		newnode->next=ptr;
		}

	}
	return start;
}
struct node *delete_end(struct node *start)
{		
		struct node *ptr,*preptr;
	if(start==NULL)
		printf("list is empty,please create the list\n");
	else
	{
			ptr=start;
		preptr=ptr;
		while(ptr->next!=NULL)
		{
			preptr=ptr;		
			ptr=ptr->next;
		}
		if(ptr==preptr)
		{
			free(start);
			start=NULL;
		}
		else
		{
			preptr->next=NULL;
			free(ptr);
		}

	}
	return start;	
}
struct node *delete_beg(struct node *start)
{
	if(start==NULL)
		printf("list is empty,please create the list\n");
	else
	{
		struct node *ptr,*temp;
		temp=start;
		start=start->next;
		free(temp);			

	}
	return start;
}
struct node *delete_after(struct node *start)
{
	struct node *ptr,*temp;
	int x,k=0;
	if(start==NULL)
		printf("list is empty,please create the list\n");

	else
	{
		printf("\nenter a node to delete a node which was after that:\n");
		scanf("%d",&x);
		ptr=start;
		while(ptr->data!=x)
		{
			if(ptr->next==NULL)
			{
				printf("%d is not in the list\n",x);
				return start;
			}
			else
			ptr=ptr->next;
		}
		if(ptr->next==NULL)
			{
				printf("there was no node to delete after that node\n");
			}
			else 
			{
				temp=ptr->next;
				ptr->next=temp->next;
				free(temp);	
			}

	}
	return start;
}
struct node *delete_before(struct node *start)
{
	struct node *ptr,*pre_ptr,*temp;
	int x,k=0;
	if(start==NULL)
		printf("list is empty,please create the list\n");
	else
	{
			printf("\nenter a node value to delete a node before that node:");
			scanf("%d",&x);
			ptr=start;
			while(ptr!=NULL)
			{
				if(ptr->data==x)
					{	
						if(start->data==x)
						{
							printf("ther was no node before the node %d\n",x);
								return start;
						}
						else
						{k++;break;}
					}
					ptr=ptr->next;
			}
		if(k==0)
			printf("%d is not in the list\n",x);
		else
		{
			ptr=start;
			pre_ptr=start;		
			while(ptr->next->data!=x)
			{
				pre_ptr=ptr;
				ptr=ptr->next;
			}
			if(ptr==pre_ptr)
			{
				start=delete_beg(start);
			}
			else
			{	
				temp=ptr;
				pre_ptr->next=temp->next;
				free(temp);
			}
		
		}

	}
	return start;
}
struct node *sort(struct node *start)
{
	if(start==NULL)
		printf("list is empty,please create the list\n");
	else
	{
			struct node *ptr,*ptr1;
	int temp;
	ptr=start;
	while(ptr!=NULL)
	{
		ptr1=start;
		while(ptr1->next!=NULL)
		{
			if(ptr1->data > ptr1->next->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr1->next->data;
				ptr1->next->data=temp;
			}
			ptr1=ptr1->next;
		}
		ptr=ptr->next;
	}	
	}
	return start;
}
struct node *reverse(struct node *start)
{
	if(start==NULL)
		printf("list is empty,please create the list\n");
	else
	{
			struct node *ptr,*ptr1;
	ptr=start->next;
	while(ptr->next!=NULL)
	{
	 if(ptr==start->next)
		{	
			start->next=NULL;	
			ptr1=ptr->next;
		}
	else
		{
			ptr->next=start;					
			start=ptr;	
			ptr=ptr1;
			ptr1=ptr1->next;
		}
	}
	ptr->next=start;
	start=ptr;
	printf("node values after reverse:\n");
	ptr=start;
	}
	return start;
}
