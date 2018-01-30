//Program to create BST and perform insertion deletion and 4 traversal operations

#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree *left,*right;
};

void insert(struct tree*,struct tree*);
void inorder(struct tree*);
void preorder(struct tree*);
void postorder(struct tree*);
struct tree *create();
struct tree *delete(struct tree*,int val);

void main(){
	int ch,val;
	struct tree *newnode,*root=NULL;
	
	do{
		printf("1.create \n2.inorder \n3.preorder \n4.postorder \n5.delete \n6.Exit \n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the data : ");
				newnode=create();
				scanf("%d",&newnode->data);
				if(root==NULL)
					root=newnode;
				else
					insert(root,newnode);
				break;
			case 2:
				if(root==NULL)
					printf("No data in tree...\n");
				else
					inorder(root);
				printf("\n");
				break;
			case 3:
				if(root==NULL)
					printf("no data in tree...\n");
				else
					preorder(root);
				printf("\n");	
				break;
			case 4:
				if(root==NULL)
					printf("no data in tree...\n");
				else
					postorder(root);
				printf("\n");
				break;
			case 5:
				if(root==NULL)
					printf("No data in tree...\n");
				else{
					printf("Enter which element to be deleted : ");
					scanf("%d",&val);
					root=delete(root,val);
				}
				printf("\n");
				break;
		}	
	}while(ch!=6);
}

struct tree *create(){
	struct tree *temp;
	temp=(struct tree*)malloc(sizeof(struct tree));
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void insert(struct tree *root,struct tree *newnode){
	if(newnode->data<root->data){
		if(root->left==NULL)
			root->left=newnode;
		else
			insert(root->left,newnode);
	}
	else if(newnode->data>root->data){
		if(root->right==NULL)
			root->right=newnode;
		else
			insert(root->right,newnode);
	}
}

void inorder(struct tree *temp){
	if(temp!=NULL){
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}	
}

void preorder(struct tree *temp){
	if(temp!=NULL){
		printf("%d",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder(struct tree *temp){
	if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		printf("%d",temp->data);
	}
}

struct tree *delete(struct tree *tree,int val){
	struct tree *cur,*parent,*suc,*psuc,*ptr;
	if(tree==NULL){
		printf("the tree is empty...");
		return(tree);
	}
	parent=tree;
	cur=tree->left;
	while(cur!=NULL&&val!=cur->data){
		parent=cur;
		cur=(val<cur->data)?cur->left:cur->right;
	}
	if(cur==NULL){
		printf("the value to be deleted is not present...\n");
		return(tree);
	}
	if(cur->left==NULL)
		ptr=cur->right;
	else if(cur->right==NULL)
		ptr=cur->left;
	else{
		suc=psuc=cur;
		cur=cur->left;
		while(suc->left!=NULL){
			psuc=suc;
			suc=suc->left;
		}
		if(cur==psuc)
			suc->left=cur->right;
		else{
			suc->left=cur->left;
			psuc->left=suc->right;
			suc->right=cur->right;
		}
		ptr=suc;
	}
	if(parent->left==cur)
		parent->left=ptr;
	else
		parent->right=ptr;
	free(cur);
	return tree;
}
