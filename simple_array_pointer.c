#include <stdio.h>

int main(){
   int a[5], s;
   int *p;
   p=a;
   // printf("How many values do you want to store?\n");scanf("%d",&s);
   s=5;
   printf("Enter %d values:\n",s);

   for (int i=0; i<s; i++){
      scanf("%d",(p+i));
   }
   
   printf("These are the values:\n");
   for (int j=0; j<s; j++){
      printf("%d ",*(p+j));
   }
   printf("\n");
}