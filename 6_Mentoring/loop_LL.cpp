#include<iostream>
using namespace std;

struct node {
    int val;
    struct node *next;
} *head = nullptr;

void loopiLL() {
    struct node *n1 = (struct node*) malloc(sizeof(struct node));
    struct node *n2 = (struct node*) malloc(sizeof(struct node));
    struct node *n3 = (struct node*) malloc(sizeof(struct node));
    struct node *n4 = (struct node*) malloc(sizeof(struct node));
    struct node *n5 = (struct node*) malloc(sizeof(struct node));
    // struct node *t1 = (struct node*) malloc(sizeof(struct node));

    n1->val = 1;
    n1->next = n2;

    n2->val = 2;
    n2->next = n3;

    n3->val = 3;
    n3->next = n4;

    n4->val = 4;
    n4->next = n5;

    // t1->val = 12;
    // t1->next = n5;

    n5->val = 5;
    n5->next = n5;
    
    head = n1;
}

void printLL() {
    if(head == nullptr) cout<<"Linked list is empty!!!"<<endl;
    struct node *travler = head;
    while (travler != nullptr)
    {
        cout<<travler->val<<" --> ";
        travler = travler->next;
    }
    cout<<"NULL."<<endl;
    return;
}

struct node *detect_loop() {
    struct node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout<<"loop detected..."<<endl;
            return slow;
        }
    }
    cout<<"loop not detected..."<<endl;
    return nullptr;
}

void remove_loop() {
    struct node *meet = detect_loop(), *start = head, *pr = nullptr;
    if (meet == start) meet->next = nullptr;
    else {
        while (meet != nullptr && meet != start)
        {
            pr = meet;
            start = start->next;
            meet = meet->next;
        }
        if (pr != nullptr) pr->next = nullptr;
    }
}

int main (void) {
    loopiLL();      //to cerate a loopy linked list.
    detect_loop();
    remove_loop();
    printLL();
    return 0;
}