#include <stdio.h>
#include <stdlib.h>

 void main(){
    int *p, n=4;
    p = (int*)malloc(n*sizeof(int));
    printf("Enter 5 integers: ");
    for(int i=0; i<n; i++){
        scanf("%d", (p+i));
    }
    printf("The values you entered are: ");
    for(int j=0; j<n; j++){
        printf("%d, ",*(p+j));
    }
    printf("\n");
    free(p);
 }