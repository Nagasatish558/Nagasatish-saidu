#include<stdio.h>
#include<string.h>
void string(char [],int);
main(){
	int l;
	char name[20];
	printf("enter any string : ");
	scanf("%s",name);
	l=strlen(name);
	string(name,l);
}
void string(char name[],int l){
	static int i=0;
	if(i<l){
		if(name[i]>=65&&name[i]<=90)
			printf("%c",name[i]);
		i++;
		string(name,l);
	}	
}
