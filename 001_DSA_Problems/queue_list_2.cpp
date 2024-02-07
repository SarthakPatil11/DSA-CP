#include<iostream>

using namespace std;

typedef struct Node {
    int val;
    struct Node *next;
} node;

typedef struct {
    node *front, *rear;
} queue;


void alloc_queue(queue *q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(queue *q) {
    return (q->front != nullptr);
}

void enqueue(queue *q, int el) {
    node *temp = (node *) malloc(sizeof(node));
    temp->val = el;
    temp->next = nullptr;
    if (q->front == nullptr) q->front = q->rear = temp;
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

bool dequeue(queue *q) {
    if (q->front == nullptr) return false;
    node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    return true;
}

void printQ(queue *q) {
    node *travler = q->front;
    
    cout<<"QUEUE: ";
    while (travler != nullptr)
    {
        cout<<travler->val<<' ';
        travler = travler->next;
    }
    cout<<endl;
}

int main(void)
{
    queue q1;
    alloc_queue(&q1);
    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    enqueue(&q1, 40);
    printQ(&q1);
    dequeue(&q1);
    dequeue(&q1);
    printQ(&q1);
    return 0;
}