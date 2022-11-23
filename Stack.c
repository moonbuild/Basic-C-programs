#define MaxSize 5
#include <stdio.h>
#include <stdlib.h>

typedef struct{int key;}element;

element stack[50];
top=-1;


int isFull(){
    if (top==MaxSize-1){return 1;}
    else return 0;
}

int isEmpty(){
    if (top==-1) return 1;
    else return 0;
}

void push(element e){
    if(isFull()){
        printf("Stack is full\n");
    }
    
    else{
        stack[++top]=e;
        printf("Value: %d has been added to stack\n",stack[top].key);
    }
}

int pop(){
    if(isEmpty()){
        printf("Stack is empty\n");
        exit(0);
    }
    else{
        int n = stack[top--].key;
        return n;
    }
}

int main(){
    element e[50];
    for(int i=0;i<10;i++){
        e[i].key= i+1;
        push(e[i]);
    }
    for(int i=0;i<5;i++){
        printf("The popped item is %d\n", pop());
    }    
}