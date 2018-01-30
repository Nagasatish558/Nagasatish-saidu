//Program to find nth node in the InOrder traversal of a BST

#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree *left,*right;
};

void insert(struct tree*,struct tree*);
int count_nodes(struct tree*);
void n_node(struct tree*,int choice);
struct tree *create();
int count,tree[100];

void main(){
	int ch,choice;
	struct tree *newnode,*root=NULL;
	
	do{
		printf("1.create \n2.find Nth node \n3.Exit \n");
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
					printf("Total no of nodes are : %d\n",count);
					printf("enter which no of node you want : ");
					scanf("%d",&choice);
					if(count>=choice){
						n_node(root,choice);
					}
					else
						printf("given no of node is not present ...\n");
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
		tree[count-1]=temp->data;
		count_nodes(temp->right);
	}
	return count;
}

void n_node(struct tree *temp,int choice){
	int i;
	for(i=0;i<count;i++){
		if(i==choice-1)
			printf("the %d element is : %d\n",choice,tree[i]);
	}
}

