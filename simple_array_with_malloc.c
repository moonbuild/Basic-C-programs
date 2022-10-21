#include <stdio.h>
#include <stdlib.h>

int main(){
   int *p,inp;
   
   p= (int*)malloc(sizeof(int));
   printf("How many values do u want to store?\n"); scanf("%d",&inp);
   printf("Enter the values: \n");
   for (int i=0; i<inp;i++){
      scanf("%d",(p+i));
   }
   for (int i=0; i<inp;i++){
      printf("The value you entered is stored at %d and its value is %d\n",(p+i), *(p+i));
   }
   
   return 0;
}