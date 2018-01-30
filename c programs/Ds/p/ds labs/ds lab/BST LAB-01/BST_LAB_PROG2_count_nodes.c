#include<stdio.h>
#include<malloc.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root=NULL;
struct node *insert(struct node *,int);
int count_nodes(struct node *);
int main()
{
	
	int ch,val,data;
	do
	{
		printf("\n*************this is menu***********");
		printf("\n1.insert  an element\n");
		printf("2.count of total nodes\n");
		printf("6.to exit");
		printf("\nenter ur option:");
		scanf("%d",&ch);
		switch(ch)
		{
			
			case 1:printf("\nenter a value of newnode:");
					scanf("%d",&val);
					root=insert(root,val);
					break;
			case 2:printf("total nodes in a tree is :%d",count_nodes(root));
					break;
			case 6:printf("\n**********thank you***********");
			break;
			default:printf("\n INVALID INPUT");
		}
	}while(ch!=6);
	return 0;
}
struct node *insert(struct node *root,int data)
{
	if(root==NULL)
	{
		struct node *newnode=NULL;
		newnode=(struct node *)malloc(sizeof(struct node));
		root=newnode;
		root->data=data;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		 if(data<=root->data)
		{
			root->left=insert(root->left,data);
		}
		else if(data>root->data)
		{
			root->right=insert(root->right,data);
		}
	}
	
	return root;
}
void inorder(struct node *root)
{
	  
	if(root)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);	
	}
}
int count_nodes(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return count_nodes(root->left) + count_nodes(root->right) + 1;
	}
	
}
