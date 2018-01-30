#include<stdio.h>
#include<time.h>
main(){
	clock_t t;
	t=clock();
	fun();
	t=clock()-t;
	
	double time_taken=((double)t)/CLOCKS_PER_SEC;
	printf("\nfun()took %f seconds to execute \n", time_taken);
	return 0;
}
fun(){
int i,k;
for(k=1;k<1000;k++){
	hi:
	for(i=2;i<=(k/2);i++){ 
	if(k==2)
		continue;	
	if(k%i==0){
		k++;
	goto hi;
	}
}
printf("\n%d is a prime num",k);

}
}
