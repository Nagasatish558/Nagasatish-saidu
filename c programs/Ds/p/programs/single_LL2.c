// program to demonstrate defferent sigle linked list operations

#include<stdio.h>
#include<stdlib.h>

struct student
{
	int rno;  char name[50];
	struct student *link;
	
	};

struct student *head=NULL, *prev, *next, *node, *prevprev, *temp;

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
		
				printf("\nEnter student R.No.: "); scanf("%d",&next->rno);
			
				printf("\nEnter student Name: "); scanf(" %s",next->name);
				
				prev->link=next;
				
				next -> link = NULL;
				}
				
			printf("\nReuquired node is created\nDo you want to create another(y/n): "); scanf(" %c",&another);
			
		}while(another=='y' || another == 'Y');
}
	

void insert_after()
{
	if(head==NULL) printf("\nList is empty\n");
	
	else
	do
	{
		printf("\nAfter which node you want to insert?\nEnter R.No: "); scanf("%d",&sno);
		
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
			
		if (find == 0) printf("\nThere is no matching roll number\n");
		else printf("\nRequired node is inserted");
		printf("\nDo you want to insert after another node(y/n): "); scanf(" %c",&another);
		
		}while(another=='y' || another=='Y');
	
	}
	

void insert_before()
{
	do
	{
		if(head==NULL) {printf("\nList is empty\n"); break;}
		else
		{
	
		printf("\nBefore which node you want to insert?\nEnter R.No: "); scanf("%d",&sno);
		
		for(next=head;next!=NULL;next=next->link)
		{
			find = 0;
					
			if(next->rno==sno)
			{
				find=1;
				
				if(next==head)
				{
					node=(struct student*)malloc(sizeof(struct student));
					
					printf("\nEnter student R.No.: "); scanf("%d",&node->rno);
					printf("\nEnter student Name: "); scanf("%s",node->name);
					
					node->link=head;	head=node;
										
					}
				else
				{
					node=(struct student*)malloc(sizeof(struct student));
					
					printf("\nEnter student R.No.: "); scanf("%d",&node->rno);
					printf("\nEnter student Name: "); scanf("%s",node->name);
					
					temp->link=node; node->link=next;
					}
				break;
				}
				
			temp = next;
			
			}
			
		if (find == 0) printf("\nThere is no matching serial number\n");
		else printf("\nRequired node is inserted");
		
		printf("\nDo you want to insert before another node(y/n): "); scanf(" %c",&another);
		
		}
		}while(another=='y' || another=='Y');
	}
	
void delete_before()
{
	if(head==NULL) printf("\nList is empty\n");
	else
	{
		do
		{
			printf("\nBefore which node you want to delete?\nEnter R.No: "); scanf("%d",&sno);
			
			if(head->rno==sno)	 {printf("\nYou can't delete before head node\n"); find=2;}
			
			else
			{
				for(next=head->link;next!=NULL;next=next->link)
				{
					find=0;
					
					if (next->rno==sno)
					{
						find = 1;
						
						if(head->link==next) head=next;
						
						else
						{
							for(prevprev=head;prevprev->link!=temp;prevprev=prevprev->link);
							
							prevprev->link=next;
							}
												
					break;
					}
				temp=next;
				}
			}
				
			if (find == 0) printf("\nThere is no matching roll number\n");
			else if (find!=2)printf("\nRequired node is deleted");
			
			printf("\nDo you want to delete before another node(y/n): "); scanf(" %c",&another);
			
			}while(another=='y'||another=='Y');
	
		}
	}
	
	
void delete_after()
{
	if(head==NULL) printf("\nList is empty\n");
	
	else
	{
		do
		{
			printf("\nAfter which node you want to delete?\nEnter R.No.: "); scanf("%d",&sno);
			
			for(next=head;next!=NULL;next=next->link)
			{
				find=0;
			
				if(next->rno==sno)
				{
					find=1;
					
					if(next->link==NULL)	{printf("\nYou can't delete after last node\n"); find=2; }
				
					else if(next->link->link==NULL) next->link=NULL;
				
					else	next->link=next->link->link;
					
					break;			
					}
				}
				
				if (find == 0) printf("\nThere is no matching roll number\n");
				else if (find!=2)printf("\nRequired node is deleted");
			
				printf("\nDo you want to delete after another node(y/n): "); scanf(" %c",&another);
				
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
		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\
		\n\n1 --> Create LL \t 2 --> Insert_before\t 3 --> Insert_after\
		\n\n4 --> Delete_before \t 5 --> Delete_after \t 6 --> Display \t 7 --> Exit \
		\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		
		printf("\nSelect your choice: "); scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: create(); break;	case 2: insert_before(); break;
			
			case 3: insert_after(); break;	case 4: delete_before(); break;
			
			case 5: delete_after(); break;	case 6: display(); break;	case 7: break;
			
			default: printf("\nInvalid input\n");  break;
			
			}
		
	}while(choice!=7);
		
	return 0;
	}
