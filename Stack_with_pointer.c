#include <stdio.h>
#include <stdlib.h>

typedef struct{int key;}element;

element *stack;
int capacity = 5;
int top=-1;

void stackFull(){
    stack = (element*)realloc(stack, 2*capacity*sizeof(element));
    printf("Stack is full, increasing size of stack from %d to %d\n",capacity, capacity*2);
    capacity*=2;
}

int isFull(){
    if (top==capacity-1){return 1;}
    else return 0;
}

int isEmpty(){
    if (top==-1) return 1;
    else return 0;
}

void push(int n){
    if(isFull()){
        stackFull();
    }
    else{
        (stack + ++top)->key = n;
        printf("Value: %d has been added to stack\n",(stack+top)->key);
    }
}

int pop(){
    if(isEmpty()){
        printf("Stack is empty\n");
        exit(0);
    }
    else{
        int n = (stack+(top--))->key;
        return n;
    }
}

int main(){
    stack = (element*)malloc(capacity*sizeof(element));
    for(int i=0;i<30;i++){
        push(i+1);
    }
    for(int i=0;i<30;i++){
        printf("The popped item is %d\n", pop());
    }    
}