#include<stdio.h>
#include<stdlib.h>
struct node{
	char sname[100];
	char sid[20];
	float cgpa;
	struct node *next;
};
struct node *head=NULL,*current,*new,*temp,*prev;
void sdetails();
void first_class();
main(){
	int ch;
	do{
		printf("1.Insert Student \n2.Display first class students \n3.Exit \n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				sdetails();
				break;
			case 2:
				first_class();
				break;
			case 3:
				break;
		}
	}while(ch!=3);
}
void sdetails(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the student name : ");
	scanf("%s",new->sname);\
	printf("Enter the student id : ");
	scanf("%s",new->sid);
	printf("Enter the student cgpa : ");
	scanf("%f",&new->cgpa);
	new->next=NULL;
	if(head==NULL){
		printf("Student details are added...\n");
		head=new;
	}
	else{
		printf("Student details are added...\n");
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=new;
	}
}
void first_class(){
	printf("First class students details : \n");
	printf("SId\t\tSName\t\tCGPA\n");
	for(temp=head;temp!=NULL;temp=temp->next){
		if(temp->cgpa>=7){
			printf("%s\t\t%s\t\t%f\n",temp->sid,temp->sname,temp->cgpa);
		}
	}
}
