#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *ptr,*newnode,*star=NULL;
	newnode=(struct node*)malloc(sizeof(struct node*));
	scanf("%d",&newnode->data);
	printf("%d",newnode->data);
	return 0;
}
