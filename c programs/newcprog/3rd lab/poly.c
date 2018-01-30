#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
	int coef;
	int expo;
	struct node *next;
};
struct node *start1=NULL,*start2=NULL,*start3=NULL,*start4=NULL;
struct node * create(struct node *);
struct node * display(struct node *);
struct node * addition(struct node *,struct node *,struct node *);
struct node * subtraction(struct node *,struct node *,struct node *);
struct node * add(struct node *);
struct node * sort(struct node *);
struct node * addnoede(struct node *,int ,int );
int main()
{
int option;
	printf("-1 to exit\n1:create 1st polynomial\n2:create 2nd polynomial\n3:display1 st polynomial\n4:display 2 nd polynomial\n");
	printf("5:addition \n6:Subtraction\n7:sort\n");
	scanf("%d",&option);
	do
	{
		switch(option)
		{
			case 1:start1=create(start1);
			break;
			case 2:start2=create(start2);
			break;
			case 3:start1=display(start1);
			break;
			case 4:start2=display(start2);
			break;
			case 5:addition(start1,start2,start3);
			break;
			case 6:subtraction(start1,start2,start3);
			break;

		}
	printf("\n1:create 1st polynomial\n2:create 2nd polynomial\n3:display1 st polynomial\n4:display 2 nd polynomial\n");
	printf("5:addition \n6:Subtraction\n\n");
	scanf("%d",&option);
	}while(option!=-1);
	return 0;
}

struct node * create(struct node *start)
{
	int coef,expo,option;
	struct node *ptr=start,*newnode;
	printf("Enter -1 to exit:\n");
	scanf("%d",&option);
	while(option!=-1)
	{
		printf("Enter coef,expo\n");
		scanf("%d%d",&coef,&expo);
		newnode=(struct node *)malloc(sizeof(struct node *));
		newnode->coef=coef;
		newnode->expo=expo;
		newnode->next=NULL;
		if(start==NULL)
		{
		start=newnode;
		ptr=start;
		}
		else
		{
		while(ptr->next!=NULL)
				ptr=ptr->next;	
			ptr->next=newnode;
		}
		printf("Enter the data and -1 to exit::\n");
		scanf("%d",&option);
	}
add(start);
return start;
}
struct node * addnode(struct node *start,int co,int ex)
{
	struct node *ptr=start,*newnode;
	newnode=(struct node *)malloc(sizeof(struct node *));
	newnode->coef=co;
	newnode->expo=ex;
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
		ptr=start;
	}else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
		ptr=ptr->next;
		}
		ptr->next=newnode;
		ptr=newnode;
	}
return start;
}
struct node * display(struct node *start)
{
	struct node *ptr=start;
	printf("\nList is::\n\n");
	while(ptr!=NULL)
	{
		printf("%dx.%d",ptr->coef,ptr->expo);
		if(ptr->next!=NULL)
			printf("+");
		ptr=ptr->next;
	}
	printf("\n");
return start;
}
struct node * addition(struct node *start1,struct node *start2,struct node *start3)
{
	struct node *ptr=start1,*newptr=start2;
	int co,ex,flag=0;
	for(ptr=start1;ptr!=NULL;ptr=ptr->next)
	{
		while(newptr!=NULL)
		{
			if(ptr->expo == newptr->expo)
			{
			flag=1;
			co=ptr->coef+newptr->coef;
			ex=ptr->expo;
			start3=addnode(start3,co,ex);
			break;
			}
			newptr=newptr->next;
			if(newptr==NULL)
				break;
		}
		if(flag==0)
			start3=addnode(start3,ptr->coef,ptr->expo);
		flag=0;
		newptr=start2;
	}
	for(ptr=start2;ptr!=NULL;ptr=ptr->next)
		{
		flag=0;
			for(newptr=start1;newptr!=NULL;newptr=newptr->next)
			{
			if(ptr->expo==newptr->expo)
			{
				flag=1;
				break;
			}
			}
		if(flag==0)
			start3=addnode(start3,ptr->coef,ptr->expo);
		}
start3=sort(start3);
return start3;
}
	struct node * subtraction(struct node *start1,struct node *start2,struct node *start3)
	{
	struct node *ptr=start1,*newptr=start2;
	int co,ex,flag=0;
for(ptr=start1;ptr!=NULL;ptr=ptr->next)
	{
	while(newptr!=NULL)
	{
	if(ptr->expo == newptr->expo)
		{
		flag=1;
		co=ptr->coef-newptr->coef;
		ex=ptr->expo;
		start3=addnode(start3,co,ex);
		break;
		}
	newptr=newptr->next;
	if(newptr==NULL)
	break;
	}
if(flag==0)
{

	start3=addnode(start3,ptr->coef,ptr->expo);
}
flag=0;
newptr=start2;

}
for(ptr=start2;ptr!=NULL;ptr=ptr->next)
{
flag=0;
	for(newptr=start1;newptr!=NULL;newptr=newptr->next)
	{
		if(ptr->expo==newptr->expo)
		{
		flag=1;
		break;
		}
	}
	if(flag==0)
	{
		start3=addnode(start3,-ptr->coef,ptr->expo);
	}
}
start3=sort(start3);
return start3;
}
struct node * add(struct node *start)
{
	struct node *ptr,*newptr,*preptr;
	for(ptr=start;ptr!=NULL;ptr=ptr->next)
	{
	preptr=ptr;
	newptr=ptr->next;
		while(newptr!=NULL)
		{
			if(ptr->expo == newptr->expo)
			{
				ptr->coef=ptr->coef+newptr->coef;
				preptr->next=newptr->next;
				free(newptr);
				newptr=preptr->next;
			}
			else{
				preptr=preptr->next;
				newptr=newptr->next;
			}
		}
	}
display(start);
return start;
}
struct node * sort(struct node *start)
{
struct node *ptr,*newptr=start;
int temp1,temp2;
	for(ptr=start;ptr!=NULL;ptr=ptr->next)
	{
		for(newptr=ptr->next;newptr!=NULL;newptr=newptr->next)
		{
			if(ptr->expo<newptr->expo)
			{
				//swapping
				temp1=ptr->coef;
				temp2=ptr->expo;
				ptr->coef=newptr->coef;
				ptr->expo=newptr->expo;
				newptr->coef=temp1;
				newptr->expo=temp2;
			}
		}
	}
display(start);
return start;
}
