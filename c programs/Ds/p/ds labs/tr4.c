#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *tree;
void create(struct node *);
struct node *insert(struct node *,int);
struct node *smallest(struct node *);
struct node *largest(struct node *);
int main()
{
	int option,val;
	struct node *ptr;
	create(tree);
	do
	{
		printf("\n menu");
		printf("\n 1.insertion");
		printf("\n 2.smallest no");
		printf("\n 3.largest no");
		printf("\n 4.exit");
		printf("\n enter ur option");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n enter value of the node:");
				scanf("%d",&val);
				tree=insert(tree,val);
				break;
			case 2:
				ptr=smallest(tree);
				printf("\n smallest element of tree is:%d",ptr->data);
				break;
			case 3:
				ptr=largest(tree);
				printf("\n largest element is %d",ptr->data);
				break;
			}
		}while(option<4);
		return 0;
	}
	void create(struct node *tree)
	{
		tree=NULL;
		}
		struct node *insert(struct node *tree ,int val)
		{
		struct node *ptr,*nodeptr,*parentptr;
		ptr=(struct node *)malloc(sizeof(struct node *));
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
struct node *smallest(struct node *tree)
{
	if((tree==NULL)||(tree->left==NULL))
	return tree;
	else
	return smallest(tree->left);
}
struct node *largest(struct node *tree)
{
	if((tree==NULL) || (tree->right==NULL))
	return tree;
	else
	return largest(tree->right);
}
