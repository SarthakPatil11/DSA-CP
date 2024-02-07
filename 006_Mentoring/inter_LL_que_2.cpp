#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *next;
}*tail = NULL;

struct node *push(struct node *head, int data) {
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	if(head == NULL) head = tail = temp;
	else {
		tail->next = temp;
		tail = temp;
	}
	return head;
}

void printLL(struct node *head) {
	struct node *travler = head;
	while (travler != NULL) {
		cout<<travler->data<<"-->";
		travler = travler->next;
	}
	cout<<"NULL."<<endl;
}

struct node *mergeLists(struct node *travler1, struct node *travler2) {
	struct node *next1 = nullptr, *next2 = nullptr, *h2 = travler2;
	while (travler1 != nullptr && travler2 != nullptr)
	{
		next1 = travler1->next;
		travler1->next = travler2;

		next2 = travler2->next;
		travler2->next = next1;

		travler1 = next1;
		h2 = travler2 = next2;
	}
	return h2;
}

struct node *deleteList(struct node *travler) {
	struct node *next = nullptr;
	while (travler != nullptr)
	{
		next = travler->next;
		free(travler);
		travler = next;
	}
	return nullptr;
}

struct node *rotate(struct node *travler, int k) {
	struct node *next = nullptr, *head = travler;
	while (travler != nullptr)
	{
		if (k == 1)
		{
			next = travler->next;
			travler->next = nullptr;
			travler = next;
			k--;
			continue;
		}
		if (travler->next == nullptr)
		{
			travler->next = head;
			return next;
		}
		
		travler = travler->next;
		k--;
	}
	return nullptr;
}

int main(void) {
	struct node *head1 = nullptr, *head2 = nullptr;
	head1 = push(head1, 10);
	head1 = push(head1, 20);
	head1 = push(head1, 30);
	head1 = push(head1, 40);
	printLL(head1);
	head2 = push(head2, 11);
	head2 = push(head2, 21);
	head2 = push(head2, 31);
	head2 = push(head2, 41);
	printLL(head2);

	head2 = mergeLists(head1, head2);
	cout<<"list 1: ";
	printLL(head1);
	cout<<"list 2: ";
	printLL(head2);

	// head1 = deleteList(head1);
	// printLL(head1);

	head1 = rotate(head1, 3);
	cout<<"list after rotation: ";
	printLL(head1);
	return 0;
}
