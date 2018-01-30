//Program to count number of nodes of a BST

#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree *left,*right;
};

void insert(struct tree*,struct tree*);
int count_nodes(struct tree*);
struct tree *create();
int count;

void main(){
	int ch;
	struct tree *newnode,*root=NULL;
	
	do{
		printf("1.create \n2.count no of nodes \n3.Exit \n");
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
				count=0;
				if(root==NULL)
					printf("No data in tree...\n");
				else{
					count=count_nodes(root);
					printf("%d\n",count);
					count=0;
				}
				break;
			
			case 3:
				break;
		}	
	}while(ch!=3);
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

int count_nodes(struct tree *temp){
	
	if(temp!=NULL){
		count_nodes(temp->left);
		count=count+1;
		count_nodes(temp->right);
	}
	return count;
}

