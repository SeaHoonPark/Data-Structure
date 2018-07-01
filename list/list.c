#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

typedef struct ListType{
    ListNode *head;
    int length;
}ListType;

//init(초기화)
void init(ListType *list){
    list->head = NULL;
    list->length = 0;
}

//insert(삽입 함수)
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node){
    if( *phead == NULL ){
        new_node->link = NULL;
        *phead = new_node;
    }
    else if( p == NULL ){
        new_node->link = *phead;
        *phead = new_node;
    }
    else {
        new_node->link = p->link;
        p->link = new_node;
    }
}

//remove(삭제 함수)
void remove_node(ListNode **phead, ListNode *p, ListNode *removed){
    if( p == NULL )
        *phead = (*phead)->link;
    else
        p->link = removed->link;
    free(removed);
}

//is_empty(비었는지 검사)
int is_empty(ListType *list){
    if( list->head == NULL ) return 1;
    else return 0;
}

//get_length(길이 검사)
int get_length(ListType *list){
    return list->length;
}

//get_node_at()
ListNode *get_node_at(ListType *list, int pos){
    int i;
    ListNode *tmp_node = list->head;
    if( pos < 0 ) return NULL;
    for (i=0; i<pos; i++)
        tmp_node = tmp_node->link;
    return tmp_node;
}

//add(리스트에 데이터 추가)
void add(ListType *list, int position, element data){
    ListNode *p;
    if ((position >= 0) && (position <= list->length)){
        ListNode*node= (ListNode *)malloc(sizeof(ListNode));
        if( node == NULL )
            printf("메모리 할당 에러");
        node->data = data;
        p = get_node_at(list, position-1);
        insert_node(&(list->head), p, node);
        list->length++;
    }
}

//add_last(리스트 마지막에 추가)
void add_last(ListType *list, element data){
    add(list, get_length(list), data);
}

//addZ_first(리스트 첫번째에 추가)
void add_first(ListType *list, element data){
    add(list, 0, data);
}

//delete(리스트 한 부분의 데이터 삭제)
void delete(ListType *list, int pos){
    if (!is_empty(list) && (pos >= 0) && (pos < list->length)){
        ListNode *p = get_node_at((list), pos - 1);
        ListNode *removed = get_node_at(list, pos);
        remove_node(&(list->head), p, removed);
        list->length--;
    }
}

//get_entry
element get_entry(ListType *list, int pos){
    ListNode *p;
    if( pos >= list->length )
        printf("위치 오류");
    p = get_node_at(list, pos);
    return p->data;
}

//display(출력 함수)
void display(ListType *list){
    int i;
    ListNode *node=list->head;
    printf("( ");
    for(i=0; i<list->length; i++){
        printf("%d ",node->data);
        node = node->link;
    }
    printf(" )\n");
}

//is_in_list(리스트 안에 있는지 검사)
int is_in_list(ListType *list, element item){
    ListNode *p;
    p = list->head;
    while( (p != NULL) ){
        if( p->data == item )
            break;
        p = p->link;
    }
    if( p == NULL) return 0;
    else return 1;
}

//clearAll(모든걸 삭제)
void clearAll(ListType *list){
    list->length = 0;
}

//replace(어떠한 데이터와 어떠한 데이터의 값 스위치)
void replace(ListType *list, element pos, element item) {
    ListNode *p;
    p = list->head;
    ListNode *q;
    q = list->head;
    ListNode temp;
    
    while ((p != NULL)) {
        if (p->data == pos) {
            temp.data = p->data;
            break;
        }
        p = p->link;
    }
    while ((q != NULL)) {
        if (q->data == item) {
            p->data = q->data;
            q->data = temp.data;
            break;
        }
        q = q->link;
    }
}

int main(void){
    
    ListType list1;
    init(&list1);
    
    add(&list1, 0, 20);
    add_last(&list1, 30);
    add_first(&list1, 10);
    add_last(&list1, 40);
    display(&list1);
    
    delete(&list1, 3);
    display(&list1);
    
    replace(&list1, 10, 30);
    display(&list1);
    
    delete(&list1, 0);
    display(&list1);
    
    
    printf("%s",is_in_list(&list1, 20)== 1 ? "성공\n": "실패\n");
    printf("%d\n", get_entry(&list1, 0));
    
    clearAll(&list1);
    display(&list1);
    printf("\n");
    return 0;
}

