#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNewNode(int n){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}


struct node *insert(struct node *root, int n){
    if(root==NULL) {
        return createNewNode(n);
    }
    else if(n < (root->data)){
        root->left=insert(root->left, n);
    }
    else{
        root->right=insert(root->right, n);
    }
    return root;

}

struct node* findMin(struct node* node){
    struct node *trav;
    trav=node;
    while(trav->left!=NULL){
        trav=trav->left;
    }
    return trav;
}

struct node* delere(struct node* root, int x){
    if(root==NULL){
        return root;
    }
    else if(x<root->data){
        root->left=delere(root->left, x);
    }
    else if(x>root->data){
        root->right=delere(root->right, x);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            struct node *temp;
            temp = root->left;
            free(root);
            root=root->left;
        }
        else if(root->left==NULL && root->right!=NULL){
            struct node *temp;
            temp = root->right;
            free(root);
            root=root->right;
        }
        else{
            struct node *temp;
            temp=(struct node*)malloc(sizeof(struct node));
            temp = findMin(root->right);
            root->data=temp->data;
            root->right=delere(root->right, temp->data);
        }
    }
    return root;
}


void inorder(struct node *newNode){
    if(newNode!=NULL){
        inorder(newNode->left);
        printf("%d\t",newNode->data);
        inorder(newNode->right);
        
    }
}
void preorder(struct node *newNode){
    if(newNode!=NULL){
    printf("%d\t",newNode->data);
    preorder(newNode->left);
    preorder(newNode->right);
    }
}
void postorder(struct node *newNode){
    if(newNode!=NULL){
    postorder(newNode->left);
    postorder(newNode->right);
    printf("%d\t",newNode->data);
    }
}

void traverse(struct node *root){
    printf("Inorder Traversal:\t");  inorder(root); printf("\n");
    printf("Preorder Traversal:\t");  preorder(root); printf("\n");
    printf("Postorder Traversal:\t");  postorder(root); printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void main(){
    struct node *root=NULL;
    root=insert(root,10);
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,6);
    root=insert(root,3);
    root=insert(root,19);
    traverse(root);
    delere(root, 4);
    traverse(root);
}