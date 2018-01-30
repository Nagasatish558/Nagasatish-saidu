#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
       int n,i,j,k,m;
    scanf("%d %d",&n,&m);
    int a,arr[n];
    for(a=0;a<n;a++){
        arr[a]=0;
    }
    while(m--){
        scanf("%d %d %d",&i,&j,&k);
        if(i<=n && j<=n && i>=0 && j>=0)
            for(a=i-1;a<j;a++)
                arr[a]+=k;

    }
    int max=0;
    for(a=0;a<n;a++)
        if(max<arr[a])
            max=arr[a];
    printf("%d",arr[i]);
    return 0;
}

