#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void insert();
void delete();
void infirst();
void inspos();
void display();
struct node *head=NULL,*current,*new,*temp,*prev,*nn;
main(){
	int ch;
	do{
		printf("0.insert at first 1.insert 2.delete 3.disply 4.exit\n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 0:
				infirst();
				break;
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 5:
				inspos();
				break;
		}
	}while(ch!=4);
}
void inspos(){
	nn=(struct node*)malloc(sizeof(struct node));
	int i,pos,data;
	printf("enter any number and pos: ");
	scanf("%d%d",&data,&pos);
	 
  	if(head!=NULL){
    	if(pos==0){
        	nn->data=data;
	        nn->next=head;
	        head=nn;
    	}
    	else{
	        temp=head;
	        for(i=0;temp->next!=NULL;i++){
	            if(pos==i+1 &&temp->next->next!=NULL){
	                nn->data=data;
	                nn->next=temp->next->next;
	                temp->next=nn;
	
	            }
	            temp=temp->next;
	        }
	        if(pos==i){
	            nn->data=data;
	            nn->next=NULL;
	            temp->next=nn;
	
	        }
        }
    }
  	else if(pos==0){
      nn->data=data;
      nn->next=NULL;
      head=nn;      
  	}
    
	
}
void insert(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter any number : ");
	scanf("%d",&new->data);
	new->next=NULL;
	if(head==NULL){
		head=current=new;
	}
	else{
		current->next=new;
		current=new;
	}
}
void infirst(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter any number : ");
	scanf("%d",&new->data);
	
	if(head==NULL){
		new->next=NULL;
		head=new;
		
	}
	else{
		new->next=head;
		head=new;
	}
}
void delete(){
	int del,a=1;
	if(head==NULL){
		printf("list is empty...\n");
	}
	else{
		printf("enter which element you want to delete : ");
		scanf("%d",&del);
		if(head->data==del){
			printf("given number is deleted...\n");
			head=head->next;
		}
		else{
			for(temp=head;temp->next!=NULL;temp=temp->next){
				if(temp->data==del){
					a=0;
					break;
				}
				else{
					prev=temp;
				}
			}
			if(a==0){
				printf("given number is deleted...\n");
				prev->next=temp->next;
			}
			else if(temp->data==del){
				printf("given number is deleted...\n");
				prev->next=NULL;
			}
			else{
				printf("given element is not present in the list ...\n");
			}
		}
	}
}
void display(){
	if(head==NULL){
		printf("list is empty...\n");
	}
	else{
		printf("the list is : \n");
		for(temp=head;temp->next!=NULL;temp=temp->next){
			printf("%d\t",temp->data);
		}
		printf("%d\n",temp->data);
	}
}
