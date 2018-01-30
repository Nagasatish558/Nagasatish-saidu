#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct student
{
	char name[20];
	int roll_n;
	float percentge;
	struct student *next;
};
struct student *start=NULL;
int main()
{
	struct student *newnode,*ptr1;
	int n;float per;
	printf("\nto stop creation -1:");
	scanf("%d",&n);
 	while(n!=-1)
	{
		newnode=(struct student *)malloc(sizeof(struct student));
		printf("\nenter the student name:");
		scanf("%s",newnode->name);
		printf("\nenter the student roll number:");
		scanf("%d",&newnode->roll_n);
		printf("\nenter the student percentage:");
		scanf("%f",&newnode->percentge);
		if(start==NULL)
		{
			start=newnode;
			newnode->next=NULL;	
		}		
		else
		{
			ptr1=start;
			while(ptr1->next!=NULL)
			{
				ptr1=ptr1->next;
			}
			ptr1->next=newnode;
			newnode->next=NULL;
		}
		printf("\nto stop creation -1:");
		scanf("%d",&n);
	}
	printf("\nenter the percentage to print the student above that percent:");
	scanf("%f",&per);
	printf("\nTHESE BELOW ARE STUDENT WHO GOT ABOVE %f PERCENTAGE MARKS:\n",per);
	ptr1=start;
	printf("student_name,rol_number,percentage\n ");
	while(ptr1!=NULL)
	{
		if(ptr1->percentge>per)
		{
			printf("%s\t%d\t%f\n",ptr1->name,ptr1->roll_n,ptr1->percentge);
		}
		ptr1=ptr1->next;
	}
	return 0;
}
