#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct QNode{
    int data;
    struct QNode* next;
};

struct Queue{
    struct QNode *front, *rear;
};

struct QNode* newNode(int data)
{
    struct QNode* node = (struct QNode*)malloc(sizeof(struct QNode));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Queue* createQ()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int data)
{
    struct QNode* tmp = newNode(data);
    if(q->rear == NULL)
    {
        q->front = q->rear = tmp;
        return;
    }
    q->rear->next = tmp;
    q->rear = tmp;
}

struct QNode* dequeue(struct Queue* q)
{
    if(q->front == NULL)
        return NULL;
    struct QNode* tmp = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = NULL;
    return tmp;
}

int main()
{
    struct Queue *q = createQ();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    struct QNode *n = dequeue(q);
    if (n != NULL)
      printf("Dequeued item is %d", n->data);
    return 0;
}
