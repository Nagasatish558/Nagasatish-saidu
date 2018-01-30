#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display_ll(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *start);
struct node *insert_after(struct node *start);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *start);
struct node *delete_after(struct node *start);
main()
{
	int ch;
		do{
				printf("*******MAIN MENU********");
				printf("\n\n\tLINKED LIST\n\n");
				printf("\n1.Create linked list\n");
				printf("\n2.Display:\n");
				printf("\n3.Insert at beginning:\n");
				printf("\n4.Insert at ending:\n");
				printf("\n5.Insert before:\n");
				printf("\n6.Insert after:\n");
				printf("\n7.Deletion beginning:\n");
				printf("\n8.Deletion ending:\n");
				printf("\n9.Deletion before:\n");
				printf("\n10.Deletion after:\n");
				printf("\nenter your option:\t");
				scanf("%d",&ch);
				switch(ch){
					case 1:
						start=create_ll(start);
						printf("\nLinked list is created\n");
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
					case 5:
						start=insert_before(start);
						break;
					case 6:
						start=insert_after(start);
						break;
					case 7:
						start=delete_beg(start);
						break;
					case 8:
						start=delete_end(start);
						break;
					case 9:
						start=delete_before(start);
						break;
					case 10:
						start=delete_after(start);
						break;
					default:
						printf("**********INVALID CHOICE************");
						break;
				}
			}while(ch!=7);
}
struct node *create_ll(struct node *start)
{
	struct node *nn,*ptr;
	int n;
	start=NULL;
	printf("\n******-1 to end:\n");
	printf("\nenter a number:\n");
	scanf("%d",&n);
	while(n!=-1)
	{
		nn=(struct node *)malloc(sizeof(struct node));
		nn->data=n;
		if(start==NULL)
		{
			nn->next=nn;
			start=nn;
		}
		else{
				ptr=start;
				while(ptr->next!=start){
					ptr=ptr->next;
				}
				ptr->next=nn;
				nn->next=start;
							
		}
		printf("\nenter the number:\n");
		scanf("%d",&n);
	}
	return start;
}
struct node *display_ll(struct node *start){
	if(start==NULL){
		printf("\nlinked list is underflow:::::::::\n");
	}
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start){
		printf("\n\n\t%d\n",ptr->data);
		ptr=ptr->next;
	}
	printf("\n\n\t%d\n",ptr->data);
	return start;
}
struct node *insert_beg(struct node *start){
	struct node *nn,*ptr;
	int n;
	printf("\nenter a no:\n");
	scanf("%d",&n);
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=n;
	ptr=start;
	while(ptr->next!=start){
		ptr=ptr->next;
	}
	ptr->next=nn;
	nn->next=start;
	start=nn;
	return start;
}
struct node *insert_end(struct node *start){
	struct node *ptr, *nn;
	int n;
	printf("\n enter a no:\n");
	scanf("%d",&n);
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=n;
	ptr=start;
	while(ptr->next!=start){
		ptr=ptr->next;
	}
	ptr->next=nn;
	nn->next=start;
	return start;
}
struct node *insert_before(struct node *start){
	struct node *nn, *ptr, *preptr;
	int n,val;
	printf("\n enter a number:\n");
	scanf("%d",&n);
	printf("\n enter the number before which tha data has to be entered:\n");
	scanf("%d",&val);
	nn=(struct node *)malloc(sizeof(struct node *));
	nn->data=n;
	ptr=start;
	while(ptr->data!=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	nn->next=ptr;
	preptr->next=nn;
	return start;
}
struct node *insert_after(struct node *start)
{
	struct node *nn, *ptr, *preptr;
	int n,val;
	printf("\n enter the node:\n");
	scanf("%d",&n);
	printf("enter the number after which the data has to entered:\n");
	scanf("%d",&val);
	nn=(struct node *)malloc(sizeof(struct node *));
	nn->data=n;
	ptr=start;
	while(ptr->data!=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	nn->next=ptr->next;
	ptr->next=nn;
	return start;
}
struct node *delete_beg(struct node *start){
	if(start==NULL){
		printf("\nlinked list is null:\n");
	}
	struct node *ptr,*preptr;
	preptr=start;
	ptr=start;
	while(ptr->next!=start){
		ptr=ptr->next;
	}
	ptr->next=preptr->next;
	start=ptr->next;
	free(preptr);
	return start;
}
struct node *delete_end(struct node *start){
	struct node *ptr, *preptr;
	ptr=start;
	while(ptr->next!=start){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=start;
	free(ptr);
	return start;
}
struct node *delete_before(struct node *start){
	struct node *ptr, *preptr;
	int n;
	printf("\nenter the after number u want to delete:\n");
	scanf("%d",&n);
	ptr=start;
	while(ptr->next->data!=n){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
struct node *delete_after(struct node *start){
	struct node *ptr, *preptr;
	int n;
	printf("\nenter the before number u want to delete:\n");
	scanf("%d",&n);
	preptr=start;
	ptr=start->next;
	while(preptr->data!=n){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
