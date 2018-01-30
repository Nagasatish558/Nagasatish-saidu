#include<stdio.h>
struct node
{
	int r_ll;
	struct node *next;
};
int main()
{
	struct node *first;
	first=(struct node*)malloc(sizeof(struct node));
	first->r_ll=23;
	first->next=NULL;
	printf("%d",first->r_ll);
	return 0;
}
