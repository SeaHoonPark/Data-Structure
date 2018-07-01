
//201411189 컴퓨터과학과 박세훈

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct StackNode {
    
    element item;
    struct StackNode *link;
    
} StackNode;

typedef struct StackType {
    
    StackNode *top;
    
} StackType;


void init(StackType *s){
    
    s->top = NULL;
}

int is_empty(StackType *s){
    
    return (s->top == NULL);
}


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

element peek(StackType *s){
    
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        return s->top->item;
    }
}


int check_matching(char *m){
    
    StackType s;
    char ch, k;
    int i;
    unsigned long n = strlen(m);
    init(&s);
    
    for(i = 0; i < n; i++){
        ch = m[i];
        
        switch(ch){
            case '(': case '[': case '{':
                push(&s, ch);
                break;
            case ')': case ']': case '}':
                if(is_empty(&s))
                    return  0;
                else{
                    k = pop(&s);
                    if((k == '(' && ch != ')') ||
                       (k == '[' && ch != ']') ||
                       (k == '{' && ch != '}'))
                        return 0;
                    
                    break;
                }
        }
    }
    
    if(!is_empty(&s))
        return 0;
    
    return 1;
}

int main(){
    
    if(check_matching("{A[(i+1)]=0;}") == 1)
        printf("괄호 검사 성공\n");
    else
        printf("괄호 검사 실패\n");
   
}
