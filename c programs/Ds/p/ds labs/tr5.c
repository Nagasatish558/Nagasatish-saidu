#include<stdio.h>
#include<malloc.h>
int count=-1,n;
struct node 
{
int data;
struct node *left;
struct node *right;
};
struct node *tree;
void create_tree(struct node *);
struct node *insertelement(struct node *,int);
struct node  *nthlevel(struct node *);
main()
{
int option,val;
struct node *ptr;
create_tree(tree);
do
{
printf("\n *****MAIN MENU*****");
printf("\n 1. Insert Element");
printf("\n 2. Nth Level");
printf("\n 3. exit");
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
printf("\n Enter the level: ");
scanf("%d",&n);
nthlevel(tree);
break;
}
}while(option<3);
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
struct node *nthlevel(struct node *tree)
{
count++;
if(n==count)
 printf("%d \t",tree->data);
else
{
nthlevel(tree->left);
nthlevel(tree->right);
}
count--;
}
