#include<stdio.h>
#include<malloc.h>
int h,count=-1;
struct node 
{
int data;
struct node *left;
struct node *right;
};
struct node *tree;
void create_tree(struct node *);
struct node *insertelement(struct node *,int val);
struct node  *max_distance(struct node *);
int height(struct node *tree);
main()
{
int option,val;
struct node *ptr;
create_tree(tree);
do
{
printf("\n *****MAIN MENU*****");
printf("\n 1. Insert Element");
printf("\n 2. Height");
printf("\n 3. max_distance");
printf("\n 4. EXIT");
printf("\n Enter your option: ");
scanf("%d",&option);
switch(option)
{
case 1:
printf("\n Enter the value of the newnode : ");
scanf("%d",&val);
tree=insertelement(tree,val);
break;
case 2:
h=height(tree);
printf("%d",h);
break;
case 3:
//printf("%d",tree->data);
max_distance(tree);
break;
}
}while(option!=4);
return 0;
}
void create_tree(struct node *tree)
{
tree=NULL;
}
struct node *insertelement(struct node *tree, int val)
{
struct node *ptr,*nodeptr,*parentptr;
ptr=(struct node *)malloc(sizeof(struct node));
ptr->data=val;
ptr->left=NULL;
ptr->right=NULL;
if(tree==NULL)
{
tree=ptr;
tree->left=NULL;
tree->right=NULL;
}
else
{
parentptr=NULL;
nodeptr=tree;
while(nodeptr!=NULL)
{
parentptr=nodeptr;
if(val<nodeptr->data)
 nodeptr=nodeptr->left;
else
 nodeptr=nodeptr->right;
}
if(val<parentptr->data)
 parentptr->left=ptr;
else
 parentptr->right=ptr;
}
return tree;
}
int height(struct node *tree)
{
	int l,r,max;
	if(tree==NULL)
	 return 0;
	if(!tree->left&&!tree->right)
	 return 0;
	else
	{
		l=height(tree->left);
		r=height(tree->right);
		
		max=l>r?l:r;
		return (1+max);
	}
}
struct node *max_distance(struct node *tree)
{
count++;
//printf("h=%d c=%d\n",h,count);
if(h==count)
{
if(tree!=NULL)
 printf("value at max distance = %d \t",tree->data);
}
else
{
max_distance(tree->left);
max_distance(tree->right);
}
count--;
}
