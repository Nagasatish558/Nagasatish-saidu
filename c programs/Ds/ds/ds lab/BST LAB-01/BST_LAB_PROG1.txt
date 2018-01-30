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
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
struct node *find_largest(struct node *);
struct node *delete_t(struct node *,int);
int main()
{
	
	int ch,val,data;
	do
	{
		printf("\n*************this is menu***********");
		printf("\n1.insert  an element\n");
		printf("2.preorder traversal\n");
		printf("3.inorder traversal\n");
		printf("4.postorder traversal\n");
		printf("5.delete_t an element\n");
		printf("6.to exit");
		printf("\nenter ur option:");
		scanf("%d",&ch);
		switch(ch)
		{
			
			case 1:printf("\nenter a value of newnode:");
					scanf("%d",&val);
					root=insert(root,val);
					break;
			case 2:preorder(root);
					break;
			case 3:inorder(root);
				break;
			case 4:postorder(root);
				break;
			case 5:printf("\nenter a value of node to delete_t:");
					scanf("%d",&data);
					root=delete_t(root,data);;
					break;
			case 6:printf("\n**********thank you***********");
			break;
			default:printf("\n INVALID INPUT");
		}
	}while(ch!=6);
/*	struct node *temp;
	temp=find_largest(root);
	if(temp == NULL)
	{
		printf("\n tree is empty");
	}
	else
	{
		printf("\n top most element is:%d",temp->data);
	}
*/	return 0;
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
void preorder(struct node *root)
{
	if(root)
	{
		printf("%d\n",root->data);
		preorder(root->left);
		preorder(root->right);	
	}
}
void postorder(struct node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);	
		printf("%d\n",root->data);
	}
}
struct node *find_largest(struct node *root)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->right==NULL)
	{
		return root;
	}
	else
	{
		return find_largest(root->right);
	}
}

struct node *delete_t(struct node * root,int val)
{
	if(root==NULL)
	{
		printf("\n tree is empty");
	}
	else if(val<root->data)
	{
		root->left=delete_t(root->left,val);
	}
	else if(val>root->data)
	{
		root->right=delete_t(root->right,val);
	}
	else if(root->left && root->right)
	{
		struct node *temp=NULL;
		temp=find_largest(root->left);
		root->data=temp->data;
		root->left=delete_t(root->left,temp->data);
	}
	else
	{
		struct node *temp1=NULL;
		temp1=root;
		if(root->left == NULL && root->right== NULL)
		{
			root=NULL;
		}
		else if(root->left!=NULL)
		{
			root=root->left;
		}
		else if(root->right!=NULL)
		{
			root=root->right;
		}
		free(temp1);	
	}
	return root;
}
