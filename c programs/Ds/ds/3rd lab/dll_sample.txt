#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
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
		printf ("\n 5.Add a node before a given node  ");
		printf ("\n 6.Add a node after a given node");
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
					start=delete_node(start);
					break;
			case 10:
					start=delete_after(start);
					break;
			case 11:
					start=delete_before(start);
					break;
		}
		}while(n!=14);
}
struct node *create_ll(struct node *start){
	struct node *ptr,*nn;
	int num;
	printf("\nENter -1 to end the list");
	printf("\n Enter the data: ");
	scanf("%d",&num);
	while(num!=-1){
		nn=(struct node *)malloc(sizeof(struct node));
		nn->data=num;
		if(start==NULL){
			nn->prev=NULL;
			nn->next=NULL;
			start=nn;
		}
		else{
			ptr=start;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			nn->prev=ptr;
			ptr->next=nn;
			nn->next=NULL;
		}
		printf("\nEnter the data:");
		scanf("%d",&num);
		
	}
	return start;
}
struct node *reverse(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	while(ptr->prev!=NULL){
			printf("\t%d",ptr->data);
		ptr=ptr->prev;
	}
		printf("\t%d",ptr->data);

	return start;
}
struct node *display_ll(struct node *start){
	struct node *ptr;
	if(start==NULL){
		printf("\nunderflow condition occured:");
		return start;
	}
	else{
		ptr=start;
		printf("\n");
		while(ptr!=NULL){
			printf("\t%d",ptr->data);
			ptr=ptr->next;
		}
	}
	return start;
}
struct node *insert_beg(struct node *start){
	struct node *ptr,*nn;
	int num;
	printf("\nenter the new node value:");
	scanf("%d",&num);
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=num;
	nn->prev=NULL;
	start->prev=nn;
	nn->next=start;
	start=nn;
	return start;
}
struct node *insert_end(struct node *start){
	struct node *ptr,*nn;
	int num;
	printf("\nEnter the data for new node:");
	scanf("%d",&num);
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=num;
	ptr->next=nn;
	nn->prev=ptr;
	nn->next=NULL;
	return start;
}
struct node *insert_before(struct node *start){
	struct node *ptr,*nn,*preptr;
	int num,val;
	printf("\nEnter the data for new node:");
	scanf("%d",&num);
	printf("\nEnter the value of the existing node:");
	scanf("%d",&val);
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=num;
	ptr=start;
	while(ptr->data!=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	nn->prev=preptr;
	nn->next=ptr;
	ptr->prev=nn;
	preptr->next=nn;
	return start;
	
}
struct node *insert_after(struct node *start){
	struct node *ptr,*preptr,*nn;
	int num,val;
	printf("\nEnter the data for new node:");
	scanf("%d",&num);
	printf("\nEnter the value of the existing node:");
	scanf("%d",&val);
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=num;
	ptr=start;
	while(ptr->data!=val)
		ptr=ptr->next;
		if(ptr->next==NULL){
			start=insert_end(start);
			return start;
		}
	nn->next=ptr->next;
	nn->prev=ptr;
	ptr->next->prev=nn;
	ptr->next=nn;
	return start;
}
struct node *delete_beg(struct node *start){
	struct node *ptr;
	ptr=start;
	start=start->next;
	start->prev=NULL;
	free(ptr);
	return start;
}
struct node *delete_end(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;	
	}
	ptr->prev->next=NULL;
	free(ptr);
	return start;
}
struct node *delete_node(struct node *start){
	struct node *ptr;
	int sn;
	ptr=start;
	printf("\nEnter the node value to delete:");
	scanf("%d",&sn);
	while(ptr->data!=sn){
		ptr=ptr->next;
	}
	ptr->prev->next=ptr->next;
	ptr->next->prev=ptr->prev;
	free(ptr);
	return start;
}
struct node *delete_before(struct node *start){
	struct node *ptr;
	int sn;
	printf("\nEnter the node value to delete before it:");
	scanf("%d",&sn);
	ptr=start;
	while(ptr->next->data!=sn){
		ptr=ptr->next;
	}
	ptr->prev->next=ptr->next;
	ptr->next->prev=ptr->prev;
	free(ptr);
	return start;
}
struct node *delete_after(struct node *start){
	struct node *ptr,*preptr;
	int sn;
	printf("\nEnter the node value to delete after it:");
	scanf("%d",&sn);
	ptr=start;
	while(ptr->data!=sn){
		ptr=ptr->next;
	}
	preptr=ptr->next;
	ptr->next=preptr->next;
	preptr->next->prev=ptr;
	free(preptr);
	return start;
}
