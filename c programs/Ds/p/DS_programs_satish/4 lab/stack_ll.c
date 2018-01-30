#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *push(struct node *);
struct node *pop(struct node *);
struct node *peep(struct node *);
struct node *display(struct node *);
main()
{
	int n;
	do{
		printf("\n*******MENU*******\n1.PUSH\n2.POP\n3.PEEP\n4.DISPLAY\n5.EXIT\n\nEnter your choice");
		scanf("%d",&n);
		switch(n){
			case 1:
				start=push(start);
				break;
			case 2:
				start=pop(start);
				break;
			case 3:
				start=peep(start);
				break;
			case 4:
				start=display(start);
				break;
		}
	}while(n!=5);
}
struct node *push(struct node *start){
	struct node *nn,*ptr;
	int num;
	printf("\n Enter the value:");
	scanf("%d",&num);
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=num;
	nn->next=NULL;
	if(start==NULL)
	{
		start=nn;
	}
	else{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=nn;
	}
	return start;
}
struct node *pop(struct node *start){
	struct node *ptr=start;
	if(start==NULL){
		printf("\n STACK IS UNDERFLOW");
		return start;
	}
	else{
	while(ptr->next!=NULL)
		ptr=ptr->next;
	printf("poped element is %d",ptr->data);
	free(ptr);
	return start;}
}
struct node *peep(struct node *start){
	struct node *ptr=start;
	if(start==NULL){
		printf("\nSTACK UNDERFLOW");
		return start;
	}		
	while(ptr->next!=NULL)
		ptr=ptr->next;
	printf("\n top element is %d",ptr->data);
	return start;
}
struct node *display(struct node *start){
	struct node *ptr=start;
	if(start==NULL){
		printf("\nSTACK UNDERFLOW");
		return start;
	}
	while(ptr!=NULL){
		printf("\t%d",ptr->data);
		ptr=ptr->next;
	}
	return start;
}
		
