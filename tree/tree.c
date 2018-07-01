
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    
    int data;
    struct node *left, *right;
    
}node;

node t1 = {3,NULL,NULL};
node t2 = {12,NULL,NULL};
node t3 = {7,&t1,&t2};
node t4 = {22,NULL,NULL};
node t5 = {30,NULL,NULL};
node t6 = {26,&t4,&t5};
node t7 = {18,&t3,&t6};
node t8 = {99,NULL,NULL};
node t9 = {68,NULL,&t8};
node t10 = {35,&t7,&t9};

node * root = &t10;

void preorder(node *root){
    
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root){
    
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(node *root){
    
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

node *search(node *root, int data){
    
    if(root == NULL)
        return NULL;
    if(data == root->data)
        return root;
    else{
        if(data<root->data)
            return search(root->left, data);
        else
            return search(root->right, data);
    }
}

int main(void){
    
    int tree;
    
    printf("preorder: ");
    preorder(root);
    printf("\n");
    printf("inorder: ");
    inorder(root);
    printf("\n");
    printf("postorder: ");
    postorder(root);
    printf("\n");
    
    printf("search: ");
    scanf("%d", &tree);
    
    node * totalnode = search(root, tree);
    if(totalnode == NULL)
        printf("no data\n");
    else
        printf("%d\n", root->data);
    return 0;
}










