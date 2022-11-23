#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void addNode(int x){
    struct node *temp, *trav;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;

    if(head==NULL){
        head=temp;
        temp->next=head;
    }
    else{
        trav=head;
        while(trav->next!=head) trav=trav->next;
        trav->next=temp;
        temp->next=head;
    }
}

void insert(int z, int aft_val){
    struct node *temp, *trav;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=z;
    

    if(head==NULL){
        printf("\t~~Empty~~\n");
        exit(0);
    }
    else if(head->data==aft_val){
        temp->next=head->next;
        head->next=temp;
    }
    else{
        trav=head->next;
        while(trav!=head){
            if(trav->data!=aft_val){
                trav=trav->next;
            }
            else break;
        }
        if(trav==head){
            printf("there is no value:%d\n",aft_val);
            exit(0);
        }
        else{
            temp->next=trav->next;
            trav->next=temp;
        }
    }
}
void delere(int m){
    struct node *trav, *prev, *last;
    trav=head;
    while(trav->next!=head) trav=trav->next;
    last=trav;

    if(head==NULL){
        printf("\t~~Empty~~\n");
        exit(0);
    }
    
    else if(head->data==m){
        head=head->next;
        last->next=head;
    }

    else{
        trav=head->next;
        while(trav!=head){
            if(trav->data!=m){
                prev=trav;
                trav=trav->next;
            }
            else break;
        }
        if(trav==head){
            printf("there is no value: %d\n",m);
            exit(0);
        }
        else{
            prev->next=trav->next;
        }
    }
}
void display(){
    struct node *temp, *trav;
    trav=head;
    while(trav->next!=head){
        printf("%d->",trav->data);
        trav=trav->next;
    }
    printf("NULL\n");

}

void main(){
    for(int i=0; i<10; i++){
        addNode(i);
        display();
    }
    insert(99,4);
    display();
    for(int i=0; i<10; i++){
        delere(i);
        display();
    }
    delere(99);
    display();
}