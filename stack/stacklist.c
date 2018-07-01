

//stack = a,b,c순으로 들어오면 c,b,a 순으로 나가는 구조

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//연결리스트로 스택 만들기
typedef int element;

typedef struct StackNode {
    
    element item;
    struct StackNode *link;
    
} StackNode;

typedef struct StackType {
    
    StackNode *top; 
    
} StackType;

//init (초기화)
void init(StackType *s){
    
    s->top = NULL;
}

//is_empty (스택의 공백 상태 검사)
int is_empty(StackType *s){
    
    return (s->top == NULL);
}

//push
void push(StackType *s, element item){
    
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    if (temp == NULL) {
        fprintf(stderr, "메모리 할당 에러\n");
        return;
    }
    else {
        temp->item = item;
        temp->link = s->top;
        s->top = temp;
    }
}

//pop
element pop(StackType *s){
    
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        StackNode *temp = s->top;
        int item = temp->item;
        s->top = s->top->link;
        free(temp);
        return item;
    }
}


//peek
element peek(StackType *s){
    
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        return s->top->item;
    }
}

int main(void){
    
    StackType s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", is_empty(&s));
    return 0;
}

