#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int x) {
    if (q->rear == MAX_SIZE) return;
    q->data[q->rear++] = x;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) return -1;
    return q->data[q->front++];
}

int queueFront(Queue* q) {
    if (isQueueEmpty(q)) return -1;
    return q->data[q->front];
}



typedef struct {
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    initQueue(&obj->q1);
    initQueue(&obj->q2);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q2, x);

    // Move all elements from q1 → q2
    while (!isQueueEmpty(&obj->q1)) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }

    // Swap q1 and q2
    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q1);   
    
}

int myStackTop(MyStack* obj) {
    return queueFront(&obj->q1);
    
}

bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(&obj->q1);
    
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/