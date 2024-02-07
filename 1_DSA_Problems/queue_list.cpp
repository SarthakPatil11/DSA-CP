#include<iostream>

using namespace std;

// int size = 0;

struct node{
    int val;
    struct node *next = nullptr;
};

struct queue {
    struct node *front = nullptr, *rear = nullptr;
};

bool isEmpty(struct queue *q){
    return (q->rear == nullptr) ? 1 : 0;
}

void enqueue(struct queue *q, int el) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->val = el;
    temp->next = nullptr;

    if (q->front == nullptr) q->front = q->rear = temp;
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
    // return ++size;
}

void dequeue(struct queue *q){
    if (q->front != nullptr)
    {
        q->front = q->front->next;
    }
    else cout<<"QUEUE IS EMPTY!!!"<<endl;
    // return --size;
}

void printQ(struct queue *q) {
    struct node *travler = q->front;
    
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
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = q->rear = nullptr;
    
    cout<<isEmpty(q)<<endl;
    enqueue(q, 10);
    cout<<isEmpty(q)<<endl;
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    printQ(q);
    dequeue(q);
    printQ(q);
    dequeue(q);
    printQ(q);
    dequeue(q);
    printQ(q);
    dequeue(q);
    printQ(q);
    return 0;
}