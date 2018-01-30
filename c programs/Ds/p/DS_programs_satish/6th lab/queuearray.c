#include<stdio.h>
#define max 10
int queue[max];
int front=-1,rear=-1;
void insert(void);
int delete(void);
int peek(void);
void display(void);
int main(){
	int option,val;
	do{
		printf("\n***Maintmenu****\n1.Insert\n2.delete\n3.peep\n4.Display\n5.Exit\nEnter Your opiton:");
		scanf("%d",&option);
		switch(option){
			case 1:
				insert();
				break;
			case 2:
				val=delete();
				if(val!=-1)
					printf("Deleleted element is %d",val);
				break;
			case 3:
				val=peek();
				if(val!=-1)
					printf("\n The first value in the queue is %d",val);
					break;
			case 4:
				display();
				break;				
		}
	}while(option!=5);
}
void insert(){
	int num;
	printf("Enter the number to be inserted in the queue");
	scanf("%d",&num);
	if(front==0&&rear==max-1)
		printf("Over Flow");
	else if(front==-1&&rear==-1){
		front=rear=0;
		queue[rear]=num;
	}
	else{
		rear++;
		queue[rear]=num;
	}
}
int delete(){
	int val;
	if(front==-1&&rear==-1){
		printf("underflow");
		return -1;
	}
	val=queue[front];
	if(front==rear)
		front=rear=-1;
	else{
		if(front==max-1)
			front=0;
		else
			front++;
		}
		return val;
}
int peek(){
	if(front==-1&&rear==-1){
		printf("\n Queue is empty");
		return -1;
	}
	else{
		return queue[front];
	}
}
void display(){
	int i;
	printf("\n");
	if(front==-1&&rear==-1)
		printf("\n Queue is Empty");
	else{
		if(front<rear)
		{
			for(i=front;i<=rear;i++)
				printf("\t %d", queue[i]);
		}
		else{
			for(i=front;i<max;i++)
				printf("\t %d", queue[i]);
			for(i=0;i<rear;i++)
				printf("\t %d", queue[i]);
				
		}
	}
}
