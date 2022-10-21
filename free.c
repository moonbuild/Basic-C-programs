#define MAXSIZE 20
#include <stdio.h>
#include <stdlib.h>

int stack[100], top=-1;
char input[100];
typedef enum{mul, divi, add, sub, eos, operand}operator;

void push(int n){
    if (top==MAXSIZE-1){
        printf("Stack is full\n");
        exit(0);
    }
    else{
        stack[++top]=n;
        printf("New stack value: %d\n",stack[top]);
    }
}
int pop(){
    if (top==-1){
        printf("Stack is empty\n");
        exit(0);
    }
    else{
        int n;
        n=stack[top--];
        return n;
    }
}
operator getToken(char *symbol, int *n){

    *symbol = input[(*n)++];
    
    switch(*symbol){
        case '*': return mul;
        case '/': return divi;
        case '+': return add;
        case '-': return sub;
        case '\0': return eos;
        default: return operand;
    }
}

int main(){
    int n=0;
    int op1, op2, res;
    char symbol;
    operator k;

    printf("Enter the postfix notation: \n");
    scanf("%s",input);

    k=getToken(&symbol, &n);

    while(k!=eos){
        if (k==operand){
            push(symbol - '0');
        }
        else{
            op2=pop();
            printf("op2: %d\n", op2);
            op1=pop();
            printf("op1: %d\n", op1);

            switch(k){
                case mul: push(op1*op2); break;
                case divi: push(op1/op2); break;
                case add: push(op1+op2); break;
                case sub: push(op1-op2); break;
            }
        }
        k=getToken(&symbol, &n);
    }
    res = pop();
    printf("Result: %d\n",res);
    return 0;
}