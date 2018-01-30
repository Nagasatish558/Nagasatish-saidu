#include<stdio.h>
void push(int);
int pop();
int stk[10];
int top=-1;
int main(){
	int n,val,i;
	printf("Enter size of array(1-10):");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements in the array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		push(a[i]);
	for(i=0;i<n;i++){
		val=pop();
		a[i]=val;
	}
	printf("The reversed array is:");
	for(i=0;i<n;i++)
		printf("\t%d",a[i]);
		printf("\n");
	return 0;
}

void push(int val){
	stk[++top]=val;
}

int pop(){
	return (stk[top--]);
}
