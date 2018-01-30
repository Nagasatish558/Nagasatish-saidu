#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int grade;
	char name[30];
	struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *start);
struct node *display(struct node *start);
main()
{	
	printf("\nEnter the grade -1 to end the list:");
	start=create(start);
	printf("\nThe students above grade 7 are:");
	start=display(start);
}
struct node *create(struct node *start){
	struct node *ptr,*nn;
	int num;
	char nme[30];
	printf("\nEnter the grade:");
	scanf("%d",&num);
	printf("\nEnter the Name:");
	scanf("%s",nme);
	while(num!=-1)
	{
		nn=(struct node *)malloc(sizeof(struct node));
		nn->grade=num;
		strcpy(nn->name,nme);
		if(start==NULL)
		{
			nn->next=NULL;
			start=nn;
		}
		else{
				ptr=start;
				while(ptr->next!=NULL){
					ptr=ptr->next;
				}
				ptr->next=nn;
				nn->next=NULL;
							
		}
		printf("\nEnter the grade:");
		scanf("%d",&num);
		printf("\nEnter the Name:");
		scanf("%s",nme);
	}
	return start;
}
struct node *display(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL){
		if(ptr->grade>7)
			printf("\n%s",ptr->name);
		ptr=ptr->next;
	}
	printf("\n");
	return start;
	
}
