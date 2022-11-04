#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;
void addNode(int val){
    struct node *trav, *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;

    trav=head;
    if(head==NULL){
        head=temp;
        temp->prev=NULL;
    }
    else{
        while(trav->next != NULL) trav=trav->next;
        trav->next=temp;
        temp->prev=trav;
    }
}

void insert(int new, int after){
    struct node *trav, *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=new;
    trav=head;

    while(trav!=NULL){
        if(trav->data!=after){
            trav=trav->next;
        }
        else break;
    }

    if(trav==NULL){
        printf("There is no node with data: %d\n",after);
        exit(0);
    }
    temp->next = trav->next;
    trav->next=temp;
    temp->prev=trav;
    if(trav->next!=NULL) (trav->next)->prev=temp;
}

void delete_(int val){
    struct node *trav, *prev;
    trav=head;
    if(head->data==val){
        head=head->next;
        if(head!=NULL) head->prev=NULL;
        free(trav);
    }
    else{
        while(trav!=NULL){
            if(trav->data != val){
                prev=trav;
                trav=trav->next;
            }
            else break;
        }
        if(trav==NULL){
            printf("There is no data: %d\n",val);
            exit(0);
        }
        prev->next=trav->next;
        if(trav->next!=NULL) (trav->next)->prev=prev;
        free(trav);
    }
}

void display(){
    struct node *trav;
    trav=head;

    printf("\n");
    while(trav!=NULL){
        printf("%d->",trav->data);
        trav=trav->next;
    }
    printf("NULL\n");
}

int main(){
    int arr[]={3,5,7,2,1,8,9,6};
    for(int i=0;i<8;i++){
        addNode(arr[i]);
    }
    display();
    insert(10,9);
    insert(15,10);
    display();      
    for(int i=0;i<8;i++){
        delete_(arr[i]);
    }
    display();
    printf("Size of (struct node): %d\n",sizeof(struct node));
    printf("Size of (struct node*): %d\n",sizeof(struct node*));   
    printf("Size of (int): %d\n",sizeof(int));        
    return 0;
}