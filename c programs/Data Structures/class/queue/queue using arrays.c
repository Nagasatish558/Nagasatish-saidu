#include<stdio.h>
#define MAX 5
int queue[MAX],front=-1,rear=-1;
void enqueue();
void dequeue();
void display();
main(){
	
	int ch;
	do{
		printf("1.Enqueue \n2.Dequeue \n3.Display \n4.Exit \n");
		printf("Enter your choice : ");
		scanf("%d",&ch);	
		switch(ch){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			
		}
		
	}while(ch!=4);
	
}

void enqueue(){
	
	if(rear==MAX-1)
		printf("overflow condition.....\n");
	else{
		if(front==-1){
			front=rear=0;
			printf("enter any number : ");
			scanf("%d",&queue[rear]);
		}
		else{
			rear++;
			printf("enter any number : ");
			scanf("%d",&queue[rear]);
		}
			
	}
	
}
void dequeue(){
	if(front==-1)
		printf("underflow condition....\n");
	else{
		printf("deleted element is : %d\n",queue[front]);
		front++;
	}
	if(front==rear)
		front=rear=-1;

}
void display(){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d\t",queue[i]);
	}
	printf("\n");
}
