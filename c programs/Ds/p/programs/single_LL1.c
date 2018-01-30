// program to demonstrate defferent sigle linked list operations

#include<stdio.h>
#include<stdlib.h>

struct student
{
	int rno; 
	char name[50];
	struct student *link;
	
};

struct student *head=NULL, *prev, *next, *node;

char another;	int sno,find;

void create()
{
	do
	{
		if(head==NULL)
		{
			head = (struct student *)malloc(sizeof(struct student));	
			
			if(head==NULL) { printf("\nMemory allocation failed\n"); exit(1); }
		
			printf("\nEnter student R.No.: "); scanf("%d",&head->rno);
			
			printf("\nEnter student Name: "); scanf(" %s", head->name);
			
			head->link = NULL;
			
		}
			
			else
			{
				for(prev=head;prev->link!=NULL;prev=prev->link);
				
				next = (struct student *)malloc(sizeof(struct student));	
			
				if(next==NULL) { printf("\nMemory allocation failed\n"); exit(1); }
				
				prev->link = next;
				
				printf("\nEnter student R.No.: "); scanf("%d",&next->rno);
			
				printf("\nEnter student Name: "); scanf(" %s",next->name);
				
				next -> link = NULL;
			}
				
			printf("\nReuquired node is created\nDo you want to create another(y/n): "); scanf(" %c",&another);
		
		}while(another=='y' || another == 'Y');
}
	

void insert()
{
	if(head==NULL) printf("\nList is empty\n");
	
	else
	do
	{
		printf("\nWhere you want to insert?\nEnter R.No: "); scanf("%d",&sno);
		
		for(next=head;next!=NULL;next=next->link)
		{
			find = 0;
			if(next->rno==sno)
			{
				find=1;
				
				node = (struct student *)malloc(sizeof(struct student));
				
				printf("\nEnter student R.No.: "); scanf("%d",&node->rno);
			
				printf("\nEnter student Name: "); scanf("%s",node->name);
				
				if(next->link==NULL)
				{
					node->link=NULL;  next->link=node;
	
					}
				else
				{
					node->link = next->link;	next->link = node;
					}
				break;
				}
			}
			
		if (find == 0) printf("\nThere is no matching serial number\n");
		else printf("\nRequired node is inserted");
		printf("\nDo you want to insert another node(y/n): "); scanf(" %c",&another);
		
		}while(another=='y' || another=='Y');
	
	}
	

void delete()
{
	do
	{
		if(head==NULL) {printf("\nList is empty\n"); break;}
		else
		{
	
		printf("\nWhich you want to delete?\nEnter R.No: "); scanf("%d",&sno);
		
		for(next=head;next!=NULL;next=next->link)
		{
			find = 0;
					
			if(next->rno==sno)
			{
				find=1;
				
				if(next==head)	head=head->link;
	
				else if(next->link==NULL)		prev->link = NULL;
				
				else prev->link=next->link;
				
				break;
				}
				
			prev = next;
			
			}
			
		if (find == 0) printf("\nThere is no matching serial number\n");
		else printf("\nRequired node is delted");
		
		printf("\nDo you want to deletedt another node(y/n): "); scanf(" %c",&another);
		
		}
		}while(another=='y' || another=='Y');
	}
	
void update()
{
	if(head==NULL) printf("\nList is empty\n");
	else
	{
		do
		{
			printf("\nWhich node you want to update?\nEnter R.No: "); scanf("%d",&sno);
			
			for(next=head;next!=NULL;next=next->link)
			{
				find=0;
				if(next->rno==sno)
				{
					find=1;
					printf("\nEnter student R.No.: "); scanf("%d",&next->rno);
			
					printf("\nEnter student Name: "); scanf("%s",next->name);
					
					break;
					}
				}
			if (find == 0) printf("\nThere is no matching serial number\n");
			else printf("\nRequired node is updated");
			printf("\nDo you want to update another node(y/n): "); scanf(" %c",&another);
			
			}while(another=='y'||another=='Y');
	
		}
	}
	
void display()
{
	if(head == NULL ) printf("\nList is empty!\n");
	
	else
	{
		printf("\n%-10s%-50s\n","Roll.No","Student's Name");
		
		for(next=head;next!=NULL;next=next->link)
			printf("\n%-10d%-50s\n",next->rno,next->name);
			
		}
}

int main()
{
	int choice;
	
	do
	{
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\
		\n\n1 --> Create LL \t 2 --> Insert \t\t 3 --> Delete\n\n4 --> Update \t\t 5 --> Display \t\t 6 --> Exit\
		\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		
		printf("\nSelect your choice: "); scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: create(); break;	case 2: insert(); break;
			
			case 3: delete(); break;	case 4: update(); break;
			
			case 5: display(); break;	case 6: break;
			
			default: printf("\nInvalid input\n");  break;
			
			}
		
	}while(choice!=6);
		
	return 0;
	}
