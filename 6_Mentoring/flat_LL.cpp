#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next, *upnext;
}*tail = nullptr;

struct node *push(struct node *head, int data) {
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
    temp->upnext = nullptr;
	if(head == NULL) head = tail = temp;
	else {
		tail->next = temp;
		tail = temp;
	}
	return head;
}

void printLL(struct node *head) {
    struct node *travler = head, *up = nullptr;
    if(head == nullptr) return;
    while (travler != nullptr)
    {
        if(travler->upnext != nullptr) up = travler->upnext;

        cout<<travler->data<<"-->";

        if(travler->next == nullptr) {
            cout<<"NULL."<<endl;
            travler = up;
            up = nullptr;
            continue;
        }
        travler = travler->next;
    }
    return;
}

void flatLL(struct node *head) {
    struct node *travler = head, *up = nullptr;
    if(head == nullptr) return;
    while (travler != nullptr)
    {
        if(travler->upnext != nullptr) up = travler->upnext;

        if(travler->next == nullptr) {
            travler->next = up;
            up = nullptr;
        }
        travler = travler->next;
    }
    return;
}

void printFLL(struct node *head) {
	struct node *travler = head;
	while (travler != NULL) {
		cout<<travler->data<<"-->";
		travler = travler->next;
	}
	cout<<"NULL."<<endl;
}

int main(void) {
    struct node *head1 = nullptr, *head2 = nullptr, *head3 = nullptr;
    head1 = push(head1, 1);
    head1 = push(head1, 2);
    head1 = push(head1, 3);
    head1 = push(head1, 4);

    head2 = push(head2, 5);
    head2 = push(head2, 6);
    head2 = push(head2, 7);
    head2 = push(head2, 8);

    head3 = push(head3, 9);
    head3 = push(head3, 10);
    head3 = push(head3, 11);
    head3 = push(head3, 12);

    head1->upnext = head2;
    head2->upnext = head3;
    
    printLL(head1);

    flatLL(head1);
    printFLL(head1);
    return 0;
}