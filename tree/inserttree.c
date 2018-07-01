
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
}node;

void preorder(node *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

node *search(node* root, int data) {
    if (root == NULL)
        return NULL;
    if (data == root->data)
        return root;
    else {
        if (data < root->data)
            return search(root->left, data);
        else
            return search(root->right, data);
    }
}

//key를 이진 탐색 트리 root에 삽입한다.
//key가 이미 root안에 있으면 삽입하지 않는다.
void insert_node(node **root, int data){

    node *p, *t, *n; //p = 부모노드, t = 현재 노드, n = 새로운 노드
    t = *root;
    p = NULL;
    
    //탐색을 먼저 수행
    while (t != NULL) {
        if (data == t->data) //탐색 성공
            return;
        p = t;
        if (data < t->data)
            t = t->left;
        else
            t = t->right;
    }
    
    //key가 트리 안에 없으므로 삽입 가능
    n = (node*)malloc(sizeof(node));
    if (n == NULL)
        return;
    
    //데이터 복사
    n->data = data;
    n->left = n->right = NULL;
    
    //부모 노드와 링크 연결
    if (p != NULL) {
        if (data < p->data)
            p->left = n;
        else
            p->right = n;
    }
    else
        *root = n;
}


int main(void) {
    
    int data;
    node *root = NULL;
    
    
    insert_node(&root, 3);
    insert_node(&root, 12);
    insert_node(&root, 7);
    insert_node(&root, 22);
    insert_node(&root, 30);
    insert_node(&root, 26);
    insert_node(&root, 18);
    insert_node(&root, 99);
    insert_node(&root, 68);
    insert_node(&root, 35);
    
    
    printf("전위\n");
    preorder(root);
    printf("\n");
    
    printf("중위\n");
    inorder(root);
    printf("\n");
    
    printf("후위\n");
    postorder(root);
    printf("\n");
    
    printf("탐색할 수 입력\n");
    scanf("%d", &data);
    node *temp = search(root, data);
    if (temp == NULL)
        printf("없음\n");
    else
        printf("있음\n");
    return 0;
}
