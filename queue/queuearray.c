

//원형큐 구현(배열로)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 8

typedef int element;

typedef struct QueueType{
    
    element queue[MAX];
    int front;
    int rear;
    
} QueueType;

//init
void init(QueueType *q){
    
    q->front = 0;
    q->rear = 0;
    
}

//is_empty
int is_empty(QueueType *q){
    
    return q->front == q->rear;
}

//is_full
int is_full(QueueType *q){
    
    return (q->rear+1)% MAX == q->front;
}

//enqueue
void enqueue(QueueType *q, element item){
    
    if( is_full(q) )
        printf("큐가 포화상태입니다\n");
    q->rear = (q->rear+1) % MAX;
    q->queue[q->rear] = item;
}

//dequeue
element dequeue(QueueType *q){
    
    if( is_empty(q) )
        printf("큐가 공백상태입니다\n");
    q->front = (q->front+1) % MAX;
    return q->queue[q->front];
}

//main
int main(void){
    
    QueueType q;
    
    init(&q);
    printf("front=%d rear=%d\n", q.front, q.rear);
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    
    printf("dequeue()=%d\n", dequeue(&q));
    printf("dequeue()=%d\n", dequeue(&q));
    printf("dequeue()=%d\n", dequeue(&q));
    
    printf("front=%d rear=%d\n", q.front, q.rear);
}




















