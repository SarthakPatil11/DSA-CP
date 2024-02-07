#include<iostream>
#include<stdlib.h>
using namespace std;

struct stack {
    int size;
    int top;
    int *arr;
};

struct stack *create(int size) {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc(size * sizeof(int));
    return s;
}

bool isFULL(struct stack *s) {
    if(s->top == (s->size - 1)) {
        cout<<"Stack is Full..."<<endl;
        return 1;
    }
    else return 0;
}

bool isEMPTY(struct stack *s) {
    if(s->top == -1) {
        cout<<"Stack is Empty..."<<endl;
        return 1;
    }
    else return 0;
}

void showStack(struct stack *s){
    if(!isEMPTY(s)) {
        for(int i = s->top; i > -1; --i) cout<<s->arr[i]<<endl;
    }
}

void push(struct stack *s, int val) {
    if(!isFULL(s)) {
        s->top++;
        s->arr[s->top] = val;
        cout<<"Element pushed: "<<s->arr[s->top]<<endl;
    }
}

void pop(struct stack *s) {
    if(!isEMPTY(s)) {
        cout<<"Element poped: "<<s->arr[s->top]<<endl;
        s->top--;
    }
}

int main(void) {
    struct stack *s1 = create(20);
    cout<<isFULL(s1)<<endl;
    cout<<isEMPTY(s1)<<endl;
    push(s1, 10);
    cout<<isEMPTY(s1)<<endl;
    push(s1, 20);
    cout<<isEMPTY(s1)<<endl;
    push(s1, 30);
    push(s1, 40);
    showStack(s1);
    pop(s1);
    showStack(s1);
    return 0;
}