#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next,*before;
};
void display();
void IBegin();
void IEnd();
void IA();
void IB();
void DBegin();
void DEnd();
void DA();
void DB();
void Sort();

struct node *head=NULL,*current,*new,*temp,*prev;
main(){
	int ch;
	do{
		printf("1.insert \n2.delete \n3.disply \n4.Sort \n5.exit\n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				do{
					printf("1.insert at begin of LL \n2.insert at end of LL \n3.insert at after perticular node \n4.insert at before perticular node\n5.exit\n");
					printf("enter your choice : ");
					scanf("%d",&ch);
					switch(ch){
						case 1:
							IBegin();
							break;
						case 2:
							IEnd();
							break;
						case 3:
							IA();
							break;
						case 4:
							IB();
							break;
						case 5:
							break;
					}
				}while(ch!=5);
				break;
			case 2:
				do{
					printf("1.delete at begin of LL \n2.delete at end of LL \n3.delete at after perticular node \n4.delete at before perticular node\n5.exit\n");
					printf("enter your choice : ");
					scanf("%d",&ch);
					switch(ch){
						case 1:
							DBegin();
							break;
						case 2:
							DEnd();
							break;
						case 3:
							DA();
							break;
						case 4:
							DB();
							break;
						case 5:
							break;
					}
				}while(ch!=5);
				break;
			case 3:
				display();
				break;
			case 4:
				Sort();
				break;
			case 5:
				ch=6;
				break;
		}
	}while(ch!=6);
}
void IBegin(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter any data : ");
	scanf("%d",&new->data);
	new->before=NULL;
	new->next=NULL;
	if(head==NULL){
		printf("given node inserted....\n");
		head=new;
	}
	else{
		printf("given node inserted....\n");
		new->next=head;
		head->before=new;
		head=new;
	}
}
void IEnd(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter any data : ");
	scanf("%d",&new->data);
	new->before=NULL;
	new->next=NULL;
	if(head==NULL){
		printf("given node inserted....\n");
		head=new;
	}
	else{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		printf("given node inserted....\n");
		temp->next=new;
		new->before=temp;
	}
}
void IA(){
	int n,a=0;
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter any data : ");
	scanf("%d",&new->data);
	new->before=NULL;
	new->next=NULL;
	if(head==NULL){
		printf("LL is empty...\n");
	}
	else{
		printf("enter which node after you want to insert : ");
		scanf("%d",&n);
		for(temp=head;temp!=NULL;temp=temp->next){
			if(temp->data==n){
				a=1;
				break;
			}
		}
		if(a==1){
			printf("given node inserted....\n");
			if(temp->next==NULL){
				new->before=temp;
				temp->next=new;
			}
			else{
				new->next=temp->next;
				temp->next->before=new;
				temp->next=new;
				new->before=temp;
			}
		}
		else
			printf("given node is not in the LL...\n");
	}
}
void IB(){
	int n,a=0;
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter any data : ");
	scanf("%d",&new->data);
	new->next=NULL;
	if(head==NULL){
		printf("LL is empty...\n");
	}
	else{
		printf("enter which node before you want to insert : ");
		scanf("%d",&n);
		for(temp=head,prev=NULL;temp!=NULL;prev=temp,temp=temp->next){
			if(temp->data==n){
				a=1;
				break;
			}
		}
		if(a==1){
			printf("given node inserted....\n");
			if(prev==NULL){
				new->next=temp;
				temp->before=new;
				head=new;
			}
			else{
				new->next=temp;
				temp->before=new;
				prev->next=new;
				new->before=prev;
			}
		}
		else
			printf("given node is not in the LL...\n");
	}
}
void DBegin(){
	if(head==NULL){
		printf("list is empty...\n");
	}
	else{
		temp=head;
		printf("given number is deleted...\n");
		head=head->next;
		head->before=NULL;
		free(temp);
	}
}
void DEnd(){
	int del,a=0;
	if(head==NULL){
		printf("list is empty...\n");
	}
	else{
		for(temp=prev=head;temp->next!=NULL;prev=temp,temp=temp->next);
		printf("given number is deleted...\n");
		prev->next=NULL;
		free(temp);
	}
}
void DA(){
	int del,a=1;
	if(head==NULL){
		printf("list is empty...\n");
	}
	else{
		printf("enter which element after you want to delete : ");
		scanf("%d",&del);
		
			for(temp=head,prev=NULL;temp->next!=NULL;prev=temp,temp=temp->next){
				if(temp->data==del){
					a=0;
					break;
				}
			}
			if(a==0){
				printf("given number is deleted...\n");
				if(prev==NULL){
					prev=temp;
					temp->next=prev->next->next;
					temp->next->before=prev;
				}
				else if(temp->next->next==NULL){
					temp->next=NULL;
				}
				else{
					prev=temp;
					temp->next=prev->next->next;
					temp->next->before=prev;//check
				}
			}
			else{
				printf("given element is not present in the list ...\n");
			}
	}
}
void DB(){
	int del,a=1;
	if(head==NULL){
		printf("list is empty...\n");
	}
	else{
		printf("enter which element before you want to delete : ");
		scanf("%d",&del);
		if(head->data==del){
			printf("there is no node before this node...\n");
		}
		else{
			for(temp=head,prev=NULL;temp->next!=NULL;prev=temp,temp=temp->next){
				if(temp->next->data==del){
					a=0;
					break;
				}
			}
			if(a==0){
				printf("given number is deleted...\n");
				if(prev==NULL){
					head=temp->next;
					head->before=NULL;
					free(temp);
				}	
				else{
					prev->next=temp->next;
					temp->next->before=prev;
					free(temp);
				}
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
void Sort(){
	int dat;
	for(temp=head;temp!=NULL;temp=temp->next){
		for(prev=temp;prev!=NULL;prev=prev->next){
			if(temp->data>prev->data){
				dat=temp->data;
				temp->data=prev->data;
				prev->data=dat;
			}
		}
		
	}
	printf("the LL is sorted......\n");
}
