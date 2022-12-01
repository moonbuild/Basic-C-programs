#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void addNode(int n){
    struct node *trav, *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    p->next=NULL;

    if(head==NULL){
        head=p;
    }
    else{
        trav=head;
        while(trav->next!=NULL) trav=trav->next;
        trav->next=p;
    }
}

void insert(int n, int aft_val){
    struct node *trav, *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    if(head==NULL){
        printf("no aft_val: %d and no nodes", aft_val);
        exit(0);
    }
    else{
        trav=head;
        while(trav!=NULL){
            if(trav->data!=aft_val) trav=trav->next;
            else break;
        }
        if(trav==NULL){
            printf("no aft_val: %d",aft_val);
            exit(0);
        }
        else{
            p->next=trav->next;
            trav->next=p;
        }
    }
}

void delere(int n){
    struct node *trav, *prev;
    trav=head;
    while(trav!=NULL){
        if(trav->data!=n){
            prev=trav;
            trav=trav->next;
        }
        else break;
    }
    if(trav==NULL){
        printf("no value:  %d", n);
    }
    else{
        prev->next=trav->next;
    }

}

void display(){
    struct node *trav;
    trav=head;
    while(trav!=NULL){
        printf("%d->", trav->data);
        trav=trav->next;
    }
    printf("NULL\n");
}

void main(){
    for(int i=1; i<9; i++) addNode(i);
    display();
    insert(22, 8);
    display();
    insert(33,7);
    display();
    delere(8);
    display();

}
