#define capacity 10
#include <stdio.h>
#include <stdlib.h>

int queue[100];
int front=0,rear=0;

int isFull(){
    if((rear+1)%capacity==front) return 1;
    else return 0;
}
int isEmpty(){
    if (front==rear) return 1;
    else return 0;
}
int insert(int n){
    if (isFull()){
        printf("Queue is full\n");
    }
    else{
        rear= (rear+1)%capacity;
        queue[rear]=n;
        printf("New value in queue:%d\n",queue[rear]);
    }
}
int del(){
    if(isEmpty()){
        printf("Queue is empty\n");
        exit(0);
    }
    else{
        int n;
        front=(front+1)%capacity;
        n = queue[front];
        return n;
    }
}

int main(){
    for(int i=0;i<10;i++){
        printf("i: %d\n",i);
        insert(i);
    }
    for(int i=0;i<10;i++){
        printf("%d ",queue[rear-i]);0
    }
}
