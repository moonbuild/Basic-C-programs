#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild, *rchild;
};

struct node *root=NULL, *trav=NULL;
struct node* createTree(){
	struct node *new;
	int x;
	new = (struct node*) malloc(sizeof(struct node));
	printf("Enter the data part of the node, enter -1 for NULL\n");
	scanf("%d",&x);
	if(x==-1){
		return NULL;
	}
	else{
		new->data=x;
		printf("Leftchild of node %d\n",x);
		new->lchild=createTree();
		printf("Right sided of node %d\n",x);
		new->rchild=createTree();
		return new;
	}
}

void inorder(struct node* newNode){
	if(newNode!=NULL){
		inorder(newNode->lchild);
		printf("%d\n",newNode->data);
		inorder(newNode->rchild);
	}
}

void preorder(struct node* newNode){
	if(newNode!=NULL){
		printf("%d\n",newNode->data);
		preorder(newNode->lchild);
		preorder(newNode->rchild);
	}
}

void postorder(struct node* newNode){
	if(newNode!=NULL){
		postorder(newNode->lchild);
		postorder(newNode->rchild);
		printf("%d\n",newNode->data);
	}
}

int main(){
	root=createTree();
	printf("Inorder Traversal: \n");
	inorder(root);
	printf("Preorder Traversal: \n");
	preorder(root);
	printf("Postorder Traversal: \n");
	postorder(root);
	return 0;
}