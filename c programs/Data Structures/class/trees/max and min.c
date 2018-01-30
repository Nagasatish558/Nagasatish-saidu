//Program to find largest and smallest elements of a BST

#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree *left,*right;
};

void insert(struct tree*,struct tree*);
int maximum(struct tree*);
int minimum(struct tree*);
struct tree *create();
int max,min;

void main(){
	int ch;
	struct tree *newnode,*root=NULL,*temp;
	
	do{
		printf("1.create \n2.Smallest and Largest \n3.Exit \n");
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
				else{
					temp=root;
					max=min=temp->data;
					max=maximum(root);
					min=minimum(root);
					printf("largest element is : %d\n",max);
					printf("smallest element is : %d\n",min);
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

int maximum(struct tree *temp){
	
	if(temp!=NULL){
		maximum(temp->left);
		if(max<temp->data)
			max=temp->data;
		maximum(temp->right);
	}
	return max;
}
int minimum(struct tree *temp){
	
	if(temp!=NULL){
		minimum(temp->left);
		if(min>temp->data)
			min=temp->data;
		minimum(temp->right);
	}
	return min;
}

