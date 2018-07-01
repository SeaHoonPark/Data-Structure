

//stack = a,b,c순으로 들어오면 c,b,a 순으로 나가는 구조

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6 //배열로 스택 만들시 배열의 크기

//배열로 스택 만들기

typedef int element;

typedef struct StackType{
    
    element stack[MAX]; //스택의 길이 선언
    int top; //가장 최근에 입력되었던 자료를 가리키는 변수
    
} StackType;

//init ()
void init(StackType *s) {
    s->top = -1; //스택이 공백 상태면 -1
}

//is_empty(스택이 공백상태인지 검사)
int is_empty(StackType *s) {
    
    return(s->top == -1); //공백이면 -1
}

//is_full(스택이 포화상태인지 검사)
int is_full(StackType *s) {
    
    return(s->top == (MAX)-1);
}

//push(스택에 데이터 추가)
void push(StackType *s, element item) {
    
    if (is_full(s)) { ////데이터 추가시 포화 상태면 에러 메시지 출력
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else //포화 상태가 아니면 top을 가리키면서 계속 증가해 나감
        s->stack[++(s->top)] = item;
}

//pop(스택의 데이터 삭제)
element pop(StackType *s) {
    
    if (is_empty(s)) { //공백일 시 삭제할 데이터 없으므로 공백 에러 메시지 출력
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else //공백이 아니면 배열에서 감소시키면서 나감
        return s->stack[(s -> top)--];
}

//peek(요소를 스택에서 삭제하지 않고 보기만 하는 연산)
element peek(StackType *s) {
    
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return s->stack[s->top];
}

int main(void) {
    
    StackType s;
    
    init(&s);
    
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", is_empty(&s));

    return 0;
}


