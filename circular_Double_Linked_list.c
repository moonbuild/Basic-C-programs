#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};

struct node *head=NULL;

void addNode(int m){
    struct node *temp, *trav;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=m;

    if(head==NULL){
        head=temp;
        temp->next=head;
        temp->prev=head;
    }
    else{
        
        trav=head;
        while(trav->next!=head) trav=trav->next;
        
        trav->next=temp;
        temp->next=head;
        head->prev=temp;
        temp->prev=trav;
    }
}

void insert(int z, int aft_val){
    struct node *temp, *trav;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=z;
    trav=head;
    int num=7;
    if(trav->data==aft_val){
        (trav->next)->prev=temp;
        temp->next=trav->next;
        temp->prev=trav;
        trav->next=temp;
    }
    else{
        trav=head->next;
        while(trav!=head){
            if(trav->data!=aft_val) trav=trav->next;
            else break;
        }
        if(trav==head){
            printf("there is no value %d\n",aft_val);
            exit(0);
        }
        (trav->next)->prev=temp;
        temp->next=trav->next;
        trav->next=temp;
        temp->prev=trav;
    }
}

void delere(int z){
    struct node *trav, *prev, *last;
    trav=head;
    
    while(trav->next!=head) trav=trav->next;
    last=trav;
    trav=head;
    if(trav->data==z){
        if(trav->next==head) head=NULL;
        else{
            last->next=trav->next;
            head=trav->next;
            (head->next)->prev=last;
        }
    }
    else{
        trav=head;
        while(trav->next!=head){
            if(trav->data!=z){
                prev=trav;
                trav=trav->next;
            }
            else break;
        }
        if(trav->next==head){
            printf("there is no value %d\n",z);
            exit(0);
        }
        else{
            prev->next=trav->next;
            (trav->next)->prev=prev;
            free(trav);
        }
    }
}

void display(){
    struct node *trav=head;
    while(trav->next!=head){
        printf("%d->",trav->data);
        trav=trav->next;
    }
    printf("NULL\n");
}

void main(){
    for(int i=0;i<10;i++){
        addNode(i);
        display();
    }
    
    insert(444,7);
    display();
    for(int i=0;i<10;i++){
        delere(i);
        display();
    }
    delere(444);
}