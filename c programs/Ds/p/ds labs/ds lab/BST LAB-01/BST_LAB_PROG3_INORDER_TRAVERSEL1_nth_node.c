#include<stdio.h>
#include<malloc.h>
int a[100],i=0;
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root=NULL;
struct node *insert(struct node *,int);
void n_inorder(struct node *);
int main()
{

	int ch,val,n;
	do
	{
		printf("\n*************this is menu***********");
		printf("\n1.insert  an element\n");
		printf("2.inorder traversel nth node\n");
		printf("6.to exit");
		printf("\nenter ur option:");
		scanf("%d",&ch);
		switch(ch)
		{

			case 1:printf("\nenter a value of newnode:");
					scanf("%d",&val);
					root=insert(root,val);
					break;
			case 2:printf("enter a value to know the inorder traversel nth node:");
					scanf("%d",&n);
				   n_inorder(root);
				   /*	int j;
					for(j=0;j<i;j++)
					{
						printf("%d\n",a[j]);
					}*/
					printf("nth inorder traversal node:%d",a[n-1]);
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
void n_inorder(struct node *root)
{
	if(root)
	{
		n_inorder(root->left);
		a[i]=root->data;
		i++;
		n_inorder(root->right);
	}
}
