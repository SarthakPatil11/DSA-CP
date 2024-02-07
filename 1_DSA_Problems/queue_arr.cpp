#include<iostream>

using namespace std;

#define SIZE 5
struct queue{
    int arr[SIZE];
    int front, rear;
};

bool isEmpty(struct queue *q) {
    return (q->rear == -1) ? 1 : 0;
}

bool isFull(struct queue *q) {
    return (q->rear == SIZE-1) ? 1 : 0;
}

int enqueue(struct queue *q, int el) {
    if (!isFull(q))
    {
        if (q->rear == -1) q->front++;
        q->rear++;
        q->arr[q->rear] = el;
        return q->rear+1;
    }
    cout<<"QUEUE IS FULL!!!"<<endl;
    return SIZE;
}

int dequeue(struct queue *q) {
    if (!isEmpty(q))
    {
        if (q->front == q->rear) {
            q->front = q->rear = -1;
            return -1;
        }
        q->front++;
        return (q->rear - q->front) + 1;
    }
    cout<<"QUEUE IS EMPTY!!!"<<endl;
    return -1;
}

void printQ(struct queue *q) {
    cout<<"QUEUE: ";
    if (!isEmpty(q))
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            cout<<q->arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    cout<<"QUEUE IS EMPTY!!!"<<endl;
}

int main(void)
{
    struct queue * q1 = (struct queue *)malloc(sizeof(struct queue));
    q1->front = q1->rear = -1;
    cout<<enqueue(q1, 1)<<endl;
    // cout<<isFull(q1)<<endl;
    // cout<<isEmpty(q1)<<endl;
    cout<<enqueue(q1, 2)<<endl;
    cout<<enqueue(q1, 3)<<endl;
    cout<<enqueue(q1, 4)<<endl;
    cout<<enqueue(q1, 5)<<endl;
    cout<<enqueue(q1, 6)<<endl;
    cout<<enqueue(q1, 7)<<endl;
    printQ(q1);
    cout<<dequeue(q1)<<endl;
    cout<<dequeue(q1)<<endl;
    printQ(q1);
    cout<<dequeue(q1)<<endl;
    cout<<dequeue(q1)<<endl;
    cout<<dequeue(q1)<<endl;
    cout<<dequeue(q1)<<endl;
    return 0;
}