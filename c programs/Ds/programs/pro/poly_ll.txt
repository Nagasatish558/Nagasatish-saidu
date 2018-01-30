#include<stdio.h>
#include<stdlib.h>
struct node{
	int coff;
	int pow;
	struct node *next;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *start4=NULL;
struct node *start5=NULL;
struct node *create_poly(struct node *);
struct node *display_poly(struct node *);
struct node *add_poly(struct node *,struct node *,struct node *);
struct node *sub_poly(struct node *,struct node *,struct node *);
struct node *add_node(struct node *,int,int);
int main()
{
       int ch;
        do 
        {
         printf("\n\n\nenter 9 to exit\n");
         printf("1:creating 1st polynomial\n");
         printf("2.creating 2nd polynomial\n");
         printf("3.displaying 1st polynomial\n");
          printf("4.displaying 2nd polynomial\n");
         printf("5.addition of two polynomials\n");
         printf("6.subtraction of two polynomials\n");
          printf("7.displaying sum polynomial\n");
           printf("8.displaying subtraction polynomial\n");
         printf("enter your choice:\n");
         scanf("%d",&ch);
         switch(ch)
         {
           case 1 :       start1=create_poly(start1);
                            printf("\nfirst polynomial created\n");
                               break;
           case 2 :          start2=create_poly(start2);
                            printf("\nsecond polynomial created\n");
                               break;
 
            case 3 :         start1=display_poly(start1);
                                 break;
            case 4 :            start2=display_poly(start2);
                                 break;
	    case 5 :          start3=add_poly(start1,start2,start3);
	                             break;
	    case 6 :          start4=sub_poly(start1,start2,start4);
                                     break;
            case 7 :            start3=display_poly(start3);
                                 break;
            case 8 :            start4=display_poly(start4);
                                 break;
}
}while(ch<=8);
}
struct node *create_poly(struct node *start)
{
	struct node *new_node,*ptr;
	int p,c;
	printf("enter the power\n");
	scanf("%d",&p);
	printf("enter the coefficient\n");
	scanf("%d",&c);
	while(p!=-1)
	{
		if(start==NULL)
		{
			new_node=(struct node*)malloc(sizeof(struct node*));
			new_node->pow=p;
			new_node->coff=c;
			new_node->next=NULL;
			start=new_node;
			}
		else
		{
			ptr=start;
			while(ptr->next != NULL)
			  ptr=ptr->next;
			  	new_node=(struct node*)malloc(sizeof(struct node*));
			new_node->pow=p;
			new_node->coff=c;
			new_node->next=NULL;
			ptr->next=new_node;
		}
		printf("enter the power:\n");
		scanf("%d",&p);
		if(p==-1)
		      break;
		printf("enter the coefficient\n");
		scanf("%d",&c);
}
return start;
}
struct node *display_poly(struct node *start)
{
	struct node *ptr;
	ptr=start;
        if(start!=NULL)
        {
	printf("\n");
	while(ptr->next!=NULL)
	  {
			printf("(%d)^%d\t",ptr->coff,ptr->pow);
                        printf("+");
			ptr=ptr->next;
			}
				printf("(%d)^%d\t",ptr->coff,ptr->pow);
        }
        else
                printf("\npolynomial is not created\n");
			return start;
}
struct node *add_poly(struct node *start1,struct node *start2,struct node *start3)
{
	struct node *ptr1,*ptr2;
	int sum,c;
        if(start1!=NULL || start2!=NULL)
        {
	ptr1=start1;
	ptr2=start2;
	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(ptr1->pow == ptr2->pow)
		{
			sum=ptr1->coff + ptr2->coff;
			start3=add_node(start3,ptr1->pow,sum);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
			}
		else if(ptr1->pow > ptr2->pow)
		{
			start3=add_node(start3,ptr1->pow,ptr1->coff);
			ptr1=ptr1->next;
			}
	   else if(ptr1->pow < ptr2->pow)
	   {
			start3=add_node(start3,ptr2->pow,ptr2->coff);
			ptr2=ptr2->next;
			}		
		}
		if(ptr1==NULL)
		{
			while(ptr2!=NULL)
			 {
					start3=add_node(start3,ptr2->coff,ptr2->pow);
					ptr2=ptr2->next;
					}
	    }
			if(ptr2==NULL)
			{
				while(ptr1!=NULL)
				{
					start3=add_node(start3,ptr1->coff,ptr1->pow);
					ptr1=ptr1->next;
					}
				}
           }
          else
                   printf("\noverflow\n");
				return start3;
}
struct node *add_node(struct node *start5,int p,int c)
{
	 struct node *ptr,*new_node;
	 if(start5==NULL)
	 {
			new_node=(struct node*)malloc(sizeof(struct node*));
			new_node->pow=p;
			new_node->coff=c;
			new_node->next=NULL;
			start3=new_node;
			}
			else
			{
				ptr=start3;
				while(ptr->next != NULL)
				 ptr=ptr->next;
				 	new_node=(struct node*)malloc(sizeof(struct node*));
			new_node->pow=p;
			new_node->coff=c;
			new_node->next=NULL;
			ptr->next=new_node;
				}
				return start3;
				
}
struct node *sub_poly(struct node *start1,struct node *start2,struct node *start4)
{

	struct node *ptr1,*ptr2;
	int sub,c;
        if(start1!=NULL || start2!=NULL)
        {
	ptr1=start1;
	ptr2=start2;
	while(ptr1 != NULL  || ptr2 != NULL)
	{
	if(ptr1->pow == ptr2 ->pow)
	{
		sub=ptr1->coff - ptr2->coff;
		start4=add_node(start4,ptr1->pow,sub);
		ptr1=ptr1->next;
		ptr2=ptr2->next;
		}
		else if(ptr1->pow > ptr2->pow)
		{
			start4=add_node(start3,ptr1->pow,ptr1->coff);
			ptr1=ptr1->next;
			}
			else if(ptr1->pow < ptr2->pow)
			{
				start4=add_node(start4,ptr2->pow,ptr2->coff);
				ptr2=ptr2->next;
				}
   }
				if(ptr1 == NULL)
				{
					while(ptr2 != NULL)
					{
						start4=add_node(start4,ptr2->pow,ptr2->coff);
						ptr2=ptr2->next;
						}
					}
					if(ptr2 == NULL)
					{
						while(ptr1 != NULL)
						{
							start4=add_node(start4,ptr1->pow,ptr1->coff);
							ptr1=ptr1->next;
							}
						}
          }
          else
                    printf("\noverflow\n");
						return start4;
}
