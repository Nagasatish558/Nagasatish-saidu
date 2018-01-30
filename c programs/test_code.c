#include<stdio.h>
main(){
	int n;
	FILE *fp;
	fp=fopen("1.txt","w");
	for(n=120001;n<121000;n++)
		fprintf(fp,"N%d\n",n);
	fclose(fp);
		
}
