#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *values;
    int front, rear, no_el, size;
} queue;

void alloc_queue (queue *q, int size) {
    q->values = (int *)malloc(sizeof(int)* size);
    q->front = 0;
    q->rear = 0;
    q->no_el = 0;
    q->size = size;
}

bool isEmpty(queue *q) {
    return (q->no_el == 0);
}

bool isFull(queue *q) {
    return (q->no_el == q->size);
}

void destroy(queue *q) {
    free(q->values);
}

void enqueue(queue *q, int el) {
    if (isFull(q)) printf("QUEUE IS FULL!!!");
    else {
        q->values[q->rear] = el;
        q->rear = (q->rear + 1) % q->size;
        q->no_el++;
    }
}

void dequeue(queue *q) {
    if (isEmpty(q)) printf("QUEUE IS EMPTY!!!");
    else {
        q->front = (q->front + 1) % q->size;
        q->no_el--;
    }
}

void printQ(queue *q) {
    int size = q->front + q->no_el;
    printf("QUEUE: ");
    for (int i = q->front; i < size; i++)
    {
        printf("%d ", q->values[i]);
    }
    printf("\n");
}

int main(void)
{
    queue q1;
    alloc_queue(&q1, 5);
    printf("%d\n", isEmpty(&q1));   
    printf("%d\n", isFull(&q1));   
    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    enqueue(&q1, 40);
    printQ(&q1);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    printQ(&q1);
    return 0;
}