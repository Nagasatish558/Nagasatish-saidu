#include<stdio.h>
void towers(int,char,char,char);
main(){
	int n;
	printf("enter number of disks : ");
	scanf("%d",&n);
	char beg='A';
	char aux='B';
	char end='C';
	towers(n,beg,aux,end);
}
void towers(int n,char beg,char aux,char end){
	if(n==1)
		printf("move disc from %c to %c\n",beg,end);
	else{
		towers(n-1,beg,end,aux);
		towers(1,beg,aux,end);
		towers(n-1,aux,beg,end);
	}
}
