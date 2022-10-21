#include <stdio.h>
#include <stdlib.h>

struct node{int data; struct node *next;};

struct node *head=NULL;

void addNode(int n){
    struct node *temp, *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    p->next=NULL;

    if (head==NULL){
        head=p;
    }
    else{
        temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=p;
    }
}

void insert(int aft_val, int n){
    struct node *temp, *p;
    p=(struct node*)malloc(sizeof(struct node));

    p->data=n;
    
    if(head==NULL){
        printf("U forgot to add values using addNode function\n");
    }
    else{
        temp=head;
        while(temp!=NULL){
            if(temp->data!=aft_val) temp=temp->next;
            else break;
        }
        if (temp==NULL){
            printf("There is no %d value in the liked list\n", aft_val);
            exit(0);
        }

        else{
            p->next=temp->next;
            temp->next=p;
        }
    }
}

void delete_node(int n){
    struct node *temp, *save;
    temp=head;
    while(temp!=NULL){
        
        if (temp->data!=n){
            save=temp;
            temp=temp->next;
        }
        else{break;}
    }
    if (temp==NULL){
        printf("There is no value: %d in the linked list\n", n);
        exit(0);
    }
    else{
        save->next=temp->next;
    }
}

void display(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    for(int i=1;i<11;i++){
        addNode(i);
    }
    display();
    insert(3,44);
    display();
    delete_node(44);
    display();
}