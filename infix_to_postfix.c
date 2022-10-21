#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100];
int top=-1;
int expr[100];
typedef enum{lp,rp,mul,divi,add,sub,eos,operand} precedence;

int isp[] = {0,19,12,12,13,13,6}
int icp[] = {20,19,12,12,13,13,13,6}

void push(char n){
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
        char n;
        n=stack[top--];
        return n;
    }
}

precedence getToken(char c){
    switch(c){
        case '(': return lp;
        case ')': return rp;
        case '*': return mul;
        case '/': return divi;
        case '+': return add;
        case '-': return sub;
        case '\0': return eos;
        default: return operand;
    }
}

int main(){
    precedence k;
    char symbol, ch;
    int i=0;
    int n;
    printf("Enter the infix notation: ");
    scanf("%s",expr);

    n=strlen(exp);
    push("\0");

    for(int i=0;i<n;i++){
        symbol=expr[i];
        k=getToken(symbol);

        if (k==)
    }
}