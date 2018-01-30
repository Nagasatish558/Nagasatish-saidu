#include<stdio.h>
#include<stdlib.h>
struct node{
	int coeff,power;
	struct node *next;
};
struct node *head=NULL,*start=NULL,*add=NULL,*sub=NULL,*new,*ptr,*temp,*current,*prev;
void Poly1();
void Poly2();
void Display();
void addition();
void substraction();
main(){
	
	int ch;
	do{
		printf("1.Create first Polynomial \n2.Creat second polynomial \n3.Addition \n4.Substraction \n5.Display \n6.Clear previous equations \n7.Exit \n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				Poly1();
				break;
			case 2:
				Poly2();
				break;
			case 3:
				add=NULL;
				addition();
				break;
			case 4:
				sub=NULL;
				substraction();
				break;
			case 5:
				Display();
				break;
			case 6:
				head=NULL;
				start=NULL;
				printf("\n");
				break;
			case 7:
				break;
		}
				
	}while(ch!=7);
	
}
void Poly1(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter coefficient : ");
	scanf("%d",&new->coeff);
	printf("enter exponet value : ");
	scanf("%d",&new->power);
	new->next=NULL;
	if(head==NULL){
		printf("given node inserted....\n\n");
		head=new;
	}
	else{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		printf("given node inserted....\n\n");
		temp->next=new;
	}
	
}
void Poly2(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter coefficient : ");
	scanf("%d",&new->coeff);
	printf("enter exponet value : ");
	scanf("%d",&new->power);
	new->next=NULL;
	if(start==NULL){
		printf("given node inserted....\n\n");
		start=new;
	}
	else{
		for(temp=start;temp->next!=NULL;temp=temp->next);
		printf("given node inserted....\n\n");
		temp->next=new;
	}
}
void Display(){
	printf("First equation details : \n");
	if(head==NULL){
		printf("list is empty...\n\n");
	}
	else{
		printf("the list is : \n");
		for(temp=head;temp->next!=NULL;temp=temp->next){
			printf("%dX^%d + ",temp->coeff,temp->power);
		}
		printf("%dX^%d \n\n",temp->coeff,temp->power);
	}
	
	printf("Second equation details : \n");
	if(start==NULL){
		printf("list is empty...\n\n");
	}
	else{
		printf("the list is : \n");
		for(temp=start;temp->next!=NULL;temp=temp->next){
			printf("%dX^%d + ",temp->coeff,temp->power);
		}
		printf("%dX^%d \n\n",temp->coeff,temp->power);
	}
	
}
void addition(){
	int a=0;
	for(ptr=head;ptr!=NULL;ptr=ptr->next){
		new=(struct node*)malloc(sizeof(struct node));
		for(temp=start;temp!=NULL;temp=temp->next){
			if(ptr->power==temp->power){
				a=1;
				break;
			}
		}
		if(a==1){
				new->coeff=ptr->coeff+temp->coeff;
				new->power=ptr->power;
				new->next=NULL;
				if(add==NULL){
					add=new;
				}
				else{
					for(current=add;current->next!=NULL;current=current->next);
					current->next=new;
				}
				
		}
			else{
				new->coeff=ptr->coeff;
				new->power=ptr->power;
				new->next=NULL;
				if(add==NULL){
					add=new;
				}
				else{
					for(current=add;current->next!=NULL;current=current->next);
					current->next=new;
				}
			}
	}
	
	for(ptr=start;ptr!=NULL;ptr=ptr->next){
		for(temp=add;temp!=NULL;temp=temp->next){
			if(ptr->power!=temp->power){
				a=1;
			}
			else{
				a=0;
				break;
			}
		}
		if(a==1){
				new=(struct node*)malloc(sizeof(struct node));
				new->coeff=ptr->coeff;
				new->power=ptr->power;
				new->next=NULL;
				if(add==NULL){
					add=new;
				}
				else{
					for(current=add;current->next!=NULL;current=current->next);
					current->next=new;
				}
				
			}
		
	}
	//Sorting the equation....
	
	int dat,dat1;
	for(temp=add;temp!=NULL;temp=temp->next){
		for(prev=temp;prev!=NULL;prev=prev->next){
			if(temp->power<prev->power){
				dat=temp->coeff;
				dat1=temp->power;
				temp->coeff=prev->coeff;
				temp->power=prev->power;
				prev->coeff=dat;
				prev->power=dat1;
			}
		}
		
	}
		
	printf("\nThe equation After addition : \n");
	for(temp=add;temp->next!=NULL;temp=temp->next){
		printf("%dX^%d + ",temp->coeff,temp->power);
	}
	printf("%dX^%d \n\n",temp->coeff,temp->power);
	
}
void substraction(){
	
	int a=0;
	for(ptr=head;ptr!=NULL;ptr=ptr->next){
		new=(struct node*)malloc(sizeof(struct node));
		for(temp=start;temp!=NULL;temp=temp->next){
			if(ptr->power==temp->power){
				a=1;
				break;
			}
		}
		if(a==1){
				new->coeff=ptr->coeff-temp->coeff;
				new->power=ptr->power;
				new->next=NULL;
				if(sub==NULL){
					sub=new;
				}
				else{
					for(current=sub;current->next!=NULL;current=current->next);
					current->next=new;
				}
				
		}
			else{
				new->coeff=ptr->coeff;
				new->power=ptr->power;
				new->next=NULL;
				if(sub==NULL){
					sub=new;
				}
				else{
					for(current=sub;current->next!=NULL;current=current->next);
					current->next=new;
				}
			}
	}
	
	for(ptr=start;ptr!=NULL;ptr=ptr->next){
		for(temp=sub;temp!=NULL;temp=temp->next){
			if(ptr->power!=temp->power){
				a=1;
			}
			else{
				a=0;
				break;
			}
		}
		if(a==1){
				new=(struct node*)malloc(sizeof(struct node));
				new->coeff=ptr->coeff;
				new->power=ptr->power;
				new->next=NULL;
				if(sub==NULL){
					sub=new;
				}
				else{
					for(current=sub;current->next!=NULL;current=current->next);
					current->next=new;
				}
				
		}
		
	}
	//Sorting the equation....
	
	int dat,dat1;
	for(temp=sub;temp!=NULL;temp=temp->next){
		for(prev=temp;prev!=NULL;prev=prev->next){
			if(temp->power<prev->power){
				dat=temp->coeff;
				dat1=temp->power;
				temp->coeff=prev->coeff;
				temp->power=prev->power;
				prev->coeff=dat;
				prev->power=dat1;
			}
		}
		
	}
		
	printf("\nThe equation After substraction : \n");
	for(temp=sub;temp->next!=NULL;temp=temp->next){
		printf("%dX^%d + ",temp->coeff,temp->power);
	}
	printf("%dX^%d \n\n",temp->coeff,temp->power);
	
}
