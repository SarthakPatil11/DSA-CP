#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
    int val;
    struct node *next;
};

struct stack {
    int size;
    int top;
    struct node *list;
};

struct stack *create(int size) {
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = size;
    s->top = -1;
    s->list = nullptr;
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

void push(struct stack *s, int val) {
    cout<<"pushing element "<<val<<"..."<<endl;
    if(!isFULL(s)) {
        s->top++;
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->val = val;
        if(s->list == nullptr) {
            temp->next = nullptr;
            s->list = temp;
        }
        else {
            temp->next = s->list;
            s->list = temp;
        }
        cout<<"Element "<<val<<" is pushed..."<<endl;
    }
    else cout<<"Element "<<val<<" can't be pushed..."<<endl;
}

void pop(struct stack *s) {
    if(!isEMPTY(s)) {
        s->top--;
        struct node *next = s->list->next;
        free(s->list);
        s->list = next;
    }
}

void showStack(struct stack *s) {
    struct node *travler = s->list;
    cout<<"Stack:\n";
    if(isEMPTY(s)) return;
    while(travler != nullptr) {
        cout<<travler->val<<endl;
        travler = travler->next;
    }
}

int main(void) {
    struct stack *s1 = create(5);
    cout<<"E: "<<isEMPTY(s1)<<endl;
    cout<<"F: "<<isFULL(s1)<<endl;
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    showStack(s1);
    pop(s1);
    showStack(s1);
    return 0;
}