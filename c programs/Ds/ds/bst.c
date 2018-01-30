#include <stdio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node * left;
	struct node * right;
};
int count=-1,n;
struct node *root=NULL;
struct node *insert(struct node *,int );
struct node *inorder(struct node *);
struct node *preorder(struct node *);
struct node *postorder(struct node *);
int largest(struct node *);
int smallest(struct node *);
int nodes(struct node *);
int height(struct node *);
struct node *predessor(struct node *,int );
struct node *ansestor(struct node *,int );
struct node *nthorder(struct node *);
int main()
{
	int option,data;
	
	
	do
	{
		printf("\n***Main menu***\n1:Insert\n2:Inorder\n3:Preorder\n4:Postorder");
		printf("\n5:Largest node\n6:Smallest node\n7:Total nodes\n8:Height of tree\n9:Ansestor path\n10:predessor path\n");
		printf("\n********\nEnter your choice:\n");
		
		scanf("%d",&option);
		switch(option)
		{
			case 1:printf("Enter the values of node:\n");
			scanf("%d",&data);
			root=insert(root,data);
			
				break;
			case 2:printf("In order is \n\n");
				root=inorder(root);
				break;
			case 3:printf("Pre order is \n\n");
				root=preorder(root);
				break;
			case 4:printf("Post order is \n\n");
				root=postorder(root);
				break;
			case 5:printf("Largest node is %d\n",largest(root));
				break;
			case 6:printf("Smallest node is %d\n",smallest(root));
				break;
			case 7:printf("Total number of nodes in tree is %d\n",nodes(root));
				break;
			case 8:printf("Height of tree is %d\n",height(root));
				break;
			case 9:printf("Enter the node value to get ansestor path:");
				scanf("%d",&data);
				ansestor(root,data);
				break;
			case 10:printf("Enter the node value to get predessor path:");
				scanf("%d",&data);
				predessor(root,data);
				break;
			case 11:
				printf("Enter the nth order to get elements:\n");
				scanf("%d",&n);
				nthorder(root);
				count=-1;
				break;
		}
	}while(option!=-1);
	printf("Thank you and visit again\n");
return 0;
}
struct node *insert(struct node *root,int data)
{
	if(root==NULL)
	{
		struct node *ptr;
		ptr=(struct node *)malloc(sizeof(struct node *));
		ptr->data=data;
		root=ptr;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		if(data<root->data)
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
struct node *inorder(struct node *root)
{
	if(root!= NULL)
	{
		
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
	return root;
}
struct node *preorder(struct node *root)
{
	if(root)
	{
		printf("%d\t",root->data);
		inorder(root->left);
		
		inorder(root->right);
	}
	return root;
}
struct node *postorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		inorder(root->right);
		printf("%d\t",root->data);
	}
	return root;
}
int largest(struct node *root)
{
	if(root)
	{
		if(root->right)
			largest(root->right);
		else
			return root->data;
	}

}
int smallest(struct node *root)
{
	if(root)
	{
		if (root->left)
			smallest(root->left);
		else
			return root->data;
	}
}
int nodes(struct node *root)
{
	if(root)
	{
		return nodes(root->left)+nodes(root->right)+1;
	}
	else
	{
		return 0;	
	}
}
int height(struct node *root)
{
	if(root)
	{
		if(height(root->left)>height(root->right))
			return nodes(root->left)+1;
		else
			return nodes(root->right)+1;	
	}
	else
	{
		return 0;	
	}
}
struct node *ansestor(struct node *root,int data)
{
	if((!root) || (root->data==data))
	{
		return 0;	
	}
	else
	{
		printf("%d\t",root->data);
		if(data<root->data)
		{
			return ansestor(root->left,data);
		}
		else if(data>root->data)
		{
			return ansestor(root->right,data);
		}	
	}
	
}
struct node *predessor(struct node *root,int data)
{
	
	return root;
}
struct node *nthorder(struct node *root)
{
	if(root)
	{
		count++;
		
		if(n==count)
		{
			
			printf("%d\t",root->data);	
		}
		else
		{
			
			nthorder(root->left);
			nthorder(root->right);
		}
		count--;
	}
}
struct node *maxdistance(struct node *root)
{
	
	return root;
}
