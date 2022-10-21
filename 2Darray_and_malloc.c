#include <stdio.h>
#include <stdlib.h>

int main(){

   int **a, rows,cols;
   
   a=(int**)malloc(rows*sizeof(int*));
   
   for (int i=0;i<rows;i++){
      *(a+i)=(int*)malloc(cols*sizeof(int));
   }

   for (int i=0;i<rows;i++){
      for (int j=0;j<cols;j++){
         scanf("%d",(*(a+i)+j));
      }
   }

   for (int i=0;i<rows;i++){
      for (int j=0;j<cols;j++){
         printf("%d",*(*(a+i)+j));
      }
   }

   return 0;
}