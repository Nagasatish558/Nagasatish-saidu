#include<stdio.h>
int pow(int,int);
main(){
	int x,y,power;
	printf("enter any numebr : ");
	scanf("%d",&x);
	printf("enter any numebr : ");
	scanf("%d",&y);
	power=pow(x,y);
	printf("Power value is : %d\n",power);
}
int pow(int x,int y){
	static int i=1,sum=1;
	if(i<=y){
		sum=sum*x;
		i++;
		pow(x,y);
	}
	else
		return sum;
}
