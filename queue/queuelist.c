
//연결리스트로 원형큐 구현

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct QueueNode {
    
    element item;
    struct QueueNode *link;
    
} QueueNode;

typedef struct QueueType{
    
    QueueNode *front, *rear;
    
} QueueType;

//init
void init(QueueType *q){
    
    q->front = NULL;
    q->rear = NULL;
}

//is_empty
int is_empty(QueueType *q){
    
    return (q->front == NULL);
}

//enqueue
void enqueue(QueueType *q, element item){
    
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    if (temp == NULL)
        printf("메모리를 할당할 수 없습니다\n");
    
    else {
        temp->item = item; //데이터 저장
        temp->link = NULL; //링크 필드를 null
        
        if (is_empty(q)) { //큐가 공백일때
            q->front = temp;
            q->rear = temp;
        }
        else { //큐가 공백이 아니면
            q->rear->link = temp; //순서 중요
            q->rear = temp;
        }
    }
}

//dequeue
element dequeue(QueueType *q){
    
    QueueNode *temp = q->front;
    element item = 0;
    
    if(is_empty(q)) //공백 상태일때
        printf("큐가 비어 있습니다.\n");
    
    else{
        item = temp->item; //데이터를 꺼냄
        q->front = q->front->link;
        
        if(q->front == NULL) //공백 상태
            q->rear = NULL;
        
        free(temp); //동적메모리 해제
    }
    return item; //데이터 반환
}

int main(void){
    
    QueueType q;
    init(&q);
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    
    return 0;
}

