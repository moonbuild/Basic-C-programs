#include <stdio.h>
#include <stdlib.h>
int main(){
   int **p, rows=3, cols=3, count=1;
   p=(int**)malloc(rows*sizeof(int*));
   for (int i=0; i<rows;i++){
      *(p+i)=(int*)malloc(cols*sizeof(int));
   }

   for (int i=0;i<rows;i++){
      for (int j=0;j<cols;j++){
         *(*(p+i)+j)= count++;
      }
   }
   int temp=0;
   for (int i=0;i<rows;i++){
      for (int j=0;j<cols;j++){
         if (temp==cols){
            printf("\n");
            temp=0;
         }
         printf("%d ",*(*(p+i)+j));
         temp++;
      }
   }
   printf("\n");

   return 0;
}