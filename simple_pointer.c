#include <stdio.h>
void main(){
    int a=4, *p;
    p=&a;
    printf("Address stored in variable p: %d\n",p);
    printf("Value stored in variable p: %d\n",*p);
}