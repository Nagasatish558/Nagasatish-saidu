#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct tree{
	int data;
	struct tree *left,*right;
};

struct tree *create();
void insert(struct tree*,struct tree*);
void levelorder(struct tree*);
int levelordernodes(struct tree*,int,int[]);
int height(struct tree *root);

main(){
	int ch;
	struct tree *newnode,*root=NULL;
	do{
		printf("1.create \n2.levelorder \n3.exit \n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("enter the data : ");
				newnode=create();
				scanf("%d",&newnode->data);
				if(root==NULL)
					root=newnode;
				else
					insert(root,newnode);
				break;
			case 2:
				if(root==NULL)
					printf("no data in tree...\n");
				else
					levelorder(root);
				printf("\n");
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

void levelorder(struct tree *root){
	int h,i,lastnode,size;
	h=height(root);
	size=pow(2,h);
	int lastlevel[size];
	lastnode=levelordernodes(root,h,lastlevel);
	printf("%d\t",lastnode);
}

int levelordernodes(struct tree *root,int h,int lastlevel[]){
	static int count=0;
	if(root==NULL)
		return;
	else if(h==1){
		lastlevel[count]=root->data;
		count++;
	}
	else if(h>1){
		levelordernodes(root->left,h-1,lastlevel);
		levelordernodes(root->right,h-1,lastlevel);
	}
	return lastlevel[count-1];
}

int height(struct tree *root){
	int lh,rh;
	if(root==NULL){
		return 0;
	}
	else{
		lh=height(root->left);
		rh=height(root->right);
		if(lh>rh)
			return (lh+1);
		else
			return (rh+1);
	}
}
