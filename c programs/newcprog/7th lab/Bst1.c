#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *right;
	struct node *left;;
};
struct node *tree;
void create_tree(struct node *);
struct node *insert(struct node *,int);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
int totalnodes(struct node *);
struct node *delete(struct node *,int);
int main(){
	int option,val;
	struct node *ptr;
	create_tree(tree);
	do{
		printf("\n1.insert Element\n2.preorder\n3.postorder\n4.inorder\n5.delete\n6.Count the total number of nodes");
		printf("\nEnter your option: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("\n Enter the value of the new node: ");
				scanf("%d",&val);
				tree=insert(tree,val);
				break;
			case 2:
				printf("\n The elements of the tree are: \n");
				preorder(tree);
				break;
			case 3:
				printf("\n The elements of the tree are: \n");
				inorder(tree);
				break;
			case 4:
				printf("\n The elements of the tree are: \n");
				postorder(tree);
				break;
			case 5:
				printf("\n Enter the element to be deleted: ");
				scanf("%d",&val);
				tree=delete(tree,val);
				break;
			case 6:
				printf("\n The total number of nodes in the tree is %d",totalnodes(tree));
				break;
				
		}
	}while(option!=0);
}
void create_tree(struct node *tree){
	tree=NULL;
}
struct node *insert(struct node *tree,int val){

	struct node *ptr,*nodeptr,*parentptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->left=NULL;
	ptr->right=NULL;
	if(tree==NULL){
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}
	else{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL){
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
void preorder(struct node *tree){
		if(tree!=NULL){
		printf("%d\t",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}	
}
void inorder(struct node *tree){
	if(tree!=NULL){
		inorder(tree->left);
		printf("%d\t",tree->data);
		inorder(tree->right);
	}
}
void postorder(struct node *tree){
	if(tree!=NULL){ 
		preorder(tree->left);
		preorder(tree->right);
		printf("%d\t",tree->data);
	}
}
struct node *delete(struct node *tree,int val){
	struct node *cur,*parent,*suc,*psuc,*ptr;
	if(tree->left==NULL){
		printf("\n The tree is empty");
		return(tree);
	}
	parent=tree;
	cur=tree->left;
	while(cur!=NULL && val!=cur->data){
		parent=cur;
		cur=(val<cur->data)?cur->left:cur->right;
	}
	if(cur == NULL){
		printf("\n The value to be deleted is not present in the tree:");
		return(tree);
	}
	if(cur->left==NULL)
		ptr=cur->right;
	else if(cur->right ==NULL)
		ptr=cur->left;
	else{
		psuc=cur;
		suc=suc->left;
		while(suc->left!=NULL){
			psuc=suc;
			suc=suc->left;
		}
		if(cur==psuc){
			suc->left=cur->right;
		}
		else{
			suc->left=cur->left;
			psuc->left=suc->right;
			suc->right=cur->right;
		}
		
	}
}
int totalnodes(struct node *tree){
	if(tree==NULL)
		return 0;
	else
		return (totalnodes(tree->left)+totalnodes(tree->right)+1);
}
