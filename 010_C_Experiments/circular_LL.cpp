#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int val;
	struct node *next;
}*head = NULL, *tail = NULL;

void insert(int val) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->val = val;
	temp->next = head;
	if(head == NULL) head = temp;
	else tail->next = temp;
	tail = temp;
}

void insertAt(int val, int loc) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->val = val;
	if(head == NULL || loc == 1) head = tail = temp;
	else {
		struct node *travler = head, *pr = NULL;
		int i = 1;
		do {
			cout<<i<<endl;
			if (loc == i) {
				if((travler->next) == head) {
					temp->next = head;
					pr->next = temp;
					tail = temp;
				}
				else {
					temp->next = travler;
					pr->next = temp;
				}
			}
			++i;
			pr = travler;
			travler = travler->next;
		} while(travler != head);
	}
}

void printLL(){
	if (head == NULL) {
		cout<<"LL is empty...\n";
		return;
	}
	struct node *travler = head;
	do {
		cout<<travler->val<<" --> ";
		travler = travler->next;
	} while(travler != head);
	cout<<"AGAIN HEAD.\n";
}

int main(void) {
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	printLL();
	
	insertAt(7, 6);
	printLL();
	insertAt(33, 4);
	printLL();
	
	return 0;
}
