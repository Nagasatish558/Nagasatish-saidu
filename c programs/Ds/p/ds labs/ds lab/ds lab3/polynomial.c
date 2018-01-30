#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	int coefc;
	struct node *next;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *start4=NULL;
struct node *createpoly(struct node *);
struct node *display(struct node *);
struct node *addpoly(struct node *,struct node *,struct node *);
struct node *addnode(int,int,struct node *);
struct node *subtract_poly(struct node *,struct node *,struct node *);
int main()
{
	struct node *ptr,*newnode=NULL;	
	int ch;
	do 
	{
	printf("1.create first polynomial\n");
	printf("2.Display first polynomial\n");
	printf("3.create second polynomial\n");
	printf("4.Display second polynomial\n");
	printf("5.add two poly\n");
	printf("6.display added polynomial\n");
	printf("7.subtaract poly\n");
	printf("8.display subtaract poly\n");
	printf("9.EXIT\n");
	printf("enter ur choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:start1=NULL;
			start1=createpoly(start1);
			break;
		case 2:printf("\nFirst polynomial:");
			start1=display(start1);
			break;
		case 3:start2=NULL;
			start2=createpoly(start2);
			break;
		case 4:printf("\nsecond polynomial:");
			start2=display(start2);
			break;
		case 5:start3=NULL;
			start3=addpoly(start1,start2,start3);
			break;
		case 6:start3=display(start3);
			break;
		case 7:start4=NULL;
			start4=subtract_poly(start1,start2,start4);
			break;
		case 8:start4=display(start4);
			break;
		case 9:printf("*******THANK U*********\n");
			break;
		default:printf("invalid input\n");
	}
	}while(ch!=9);
	return 0;
}
struct node *createpoly(struct node *start)
{

	struct node *newnode=NULL,*ptr=NULL;
	printf("To exit the taking values please enter-1: \n");
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		
		newnode=(struct node*)malloc(sizeof(struct node));
		ptr=newnode;
		printf("enter the node value:");
		scanf("%d",&newnode->data);
		printf("\nenter coefficient value:");
		scanf("%d",&newnode->coefc);
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
		printf("enter a value continue in the linked list else to exit  enter :-1:\n");
		scanf("%d",&n);
	}
	return start;
}
struct node *display(struct node *start)
{
		printf("THIS IS DISPLAY\n");
	if(start==NULL)
	{
	printf("list is not created:\n");
	return start;
	}
	else
	{
		struct node *ptr;
		ptr=start;
		while(ptr->next!=NULL)
		{
			printf("(%dx",ptr->data);
			printf("^(%d))+",ptr->coefc);
			ptr=ptr->next;
		}
		printf("%dx",ptr->data);
		printf("^(%d)\n",ptr->coefc);
	}
	return start;
}
struct node *addpoly(struct node *start1,struct node *start2,struct node *start3)
{
	struct node *ptr1,*ptr2;
	int sum=0;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->coefc==ptr2->coefc)
		{
			sum=ptr1->data+ptr2->data;
			start3=addnode(sum,ptr1->coefc,start3);
			ptr1=ptr1->next;ptr2=ptr2->next;
		}
		else if(ptr1->coefc<ptr2->coefc)
		{
			start3=addnode(ptr1->data,ptr1->coefc,start3);
			ptr1=ptr1->next;
		}
		else if(ptr1->coefc>ptr2->coefc)
		{
			start3=addnode(ptr2->data,ptr2->coefc,start3);
				ptr2=ptr2->next;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			start3=addnode(ptr1->data,ptr1->coefc,start3);
			ptr1=ptr1->next;	
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			start3=addnode(ptr2->data,ptr2->coefc,start3);
			ptr2=ptr2->next;	
		}

	}
	return start3;
}
struct node *addnode(int data1,int coefc1,struct node *start3)
{
	struct node *newnode,*ptr=NULL;
	newnode=(struct node*)malloc(sizeof(struct node));
			newnode->data=data1;
			newnode->coefc=coefc1;
		if(start3==NULL)
		{
			newnode->next=NULL;
			start3=newnode;
		}
		else
		{
			ptr=start3;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
			newnode->next=NULL;
		}
		return start3;
}
struct node *subtract_poly(struct node *start1,struct node *start2,struct node *start4)
{
	struct node *ptr1,*ptr2;
	int dif=0;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->coefc==ptr2->coefc)
		{
			dif=ptr1->data-ptr2->data;
			start4=addnode(dif,ptr1->coefc,start4);
			ptr1=ptr1->next;ptr2=ptr2->next;
		}
		else if(ptr1->coefc<ptr2->coefc)
		{
			start4=addnode(ptr1->data,ptr1->coefc,start4);
			ptr1=ptr1->next;
		}
		else if(ptr1->coefc>ptr2->coefc)
		{
			start4=addnode(-(ptr2->data),ptr2->coefc,start4);
				ptr2=ptr2->next;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			start4=addnode(ptr1->data,ptr1->coefc,start4);
			ptr1=ptr1->next;	
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			start4=addnode(-(ptr2->data),ptr2->coefc,start4);
			ptr2=ptr2->next;	
		}

	}
	return start4;
}







