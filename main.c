#define MAX_SIZE 20
#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top=-1;
typedef enum{mul,divi,add, sub, eos, operand} operator;
char input[100];

void push(int x){
    if (top==MAX_SIZE-1){
        printf("\nStack is full");
        exit(0);
    }

    stack[++top]=x;
    printf("\n%d is pushed into stack...",x);
}

int pop(){
    if (top==-1){
        printf("\nStack is Empty...");
        exit(0);
    }
    return(stack[top--]);
}

operator getToken(char *symbol, int *n){
    *symbol = input[(*n)++];

    switch(*symbol){
        case '*': return mul;
        case '/': return divi;
        case '-': return sub;
        case '+': return add;
        case '\0':return eos;
        default: return operand;
    }
}

int main(){
    int n=0;
    int op1, op2, res;
    char symbol;
    operator k;
    printf("\nEnter the input in postiz notation: ");
    scanf("%s", input);
    k = getToken(&symbol, &n);

    while(k!=eos){
        if(k==operand){
            push(symbol-'0');
        }
        else{
            op2=pop();
            printf("\nop2=%d", op2);
            op1 = pop();
            printf("\nop1=%d", op1);

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
    printf("\n Result = %d", res);
    return 0;
}
