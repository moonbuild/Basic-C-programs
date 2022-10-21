#define MAX_SIZE 10
#include<stdio.h>
#include<stdlib.h>


int queue[100];
int front=-1, rear=-1;

int isFull(){

  if( rear == MAX_SIZE -1 )
      return 1;
  else
      return 0;
}

int isEmpty(){

   if( rear == front )
       return 1;
   else
       return 0;
}


void insert(int x){

   if( isFull() )
       printf("\nQueue is Full....");
   else{
        queue[++rear] = x;
        printf("\n Item inserted is %d", queue[rear]);
   }
}

int delete_(){

   int x;

   if( isEmpty() )
       printf("\nThe Queue is Empty...");
   else
    {
      x = queue[++front];
      printf("\n The deleted item is %d", x);
      return x;
     }
}

int main(){

   int i, x;

   for(i=0 ; i<12 ; i++){
      insert(i);
   }
   
   for(i=0 ; i<12 ; i++){
      x = delete_();
//      printf("\n The delted item is %d", x);
    }
    
    printf("\nfront: %d | rear: %d",front, rear);


}