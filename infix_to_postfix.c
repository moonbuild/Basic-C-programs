#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
int top=-1;
char expr[100];
typedef enum{lp,rp,mul,divi,add,sub,eos,operand} precedence;

int isp[] = {0,19,12,12,13,13,6};
int icp[] = {20,19,12,12,13,13,13,6};

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

    n=strlen(expr);
    push('\0');

    for(int i=0;i<n;i++){
        symbol=expr[i];
        k=getToken(symbol);

        if (k==operand){
            printf("%c",symbol);
        }
        else if(k==rp){
            while(stack[top]!='('){
                printf("%c",pop());
            }
            ch=pop();
        }
        else{
            while(isp[getToken(stack[top])]>=icp[k]) printf("%c",pop());
            push(symbol);
        }
        
    }

    while((k=pop())!='\0'){
        printf("%c",k);
    }
    printf("\n");
    return 0;
}
