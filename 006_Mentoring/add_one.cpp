#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
	int val;
	struct node *next;
}*head = NULL, *tail = NULL;
int ct = 0;
string pal1, pal2;

void insert(int val) {
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->val = val;
	temp->next = NULL;
	if(head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

void printLL() {
    if(head == nullptr) cout<<"Linked list is empty!!!"<<endl;
    struct node *travler = head;
	while(travler != NULL) {
		cout<<travler->val<<"-->";
		travler = travler->next;
	}
	cout<<"NULL."<<endl;
}

int Add1toLL(struct node *travler) {
	if(travler == NULL) return 1;
	int carry = Add1toLL(travler->next);
	if ((travler->val) == 9 && carry == 1) {
		if(travler == head) {
			travler->val = 0;
			struct node *temp = (struct node *) malloc(sizeof(struct node));
			temp->val = 1;
			temp->next = head;
			head = temp;
			return 0;
		}
		travler->val = 0;
		return 1;
	}
	travler->val = travler->val + carry;
	return 0;
}

int getNthFromLast(struct node *travler, int N) {
	int n = -1;
	if(travler != nullptr && N > 0) {
		n = getNthFromLast(travler->next, N);
		ct++;
		if (ct == N) return travler->val;
		else if (travler == head && ct < N) return -1;
	}
	return n;
}

void check_palindrom(struct node *travler) {
	if (travler == nullptr) return;
	pal1.push_back((char)travler->val);
	check_palindrom(travler->next);
	pal2.push_back((char)travler->val);
	if(travler == head) {
		if (pal1 == pal2) cout<<"Linked list is palindrom..."<<endl;
		else cout<<"Linked list is not palindrom..."<<endl;
	}
}

int del_last_key(struct node *travler, int k) {
	if (travler == nullptr) return 0;
	struct node *pr = travler;
	travler = travler->next;

	int flag = del_last_key(travler, k);
	
	if (travler != nullptr && travler->val == k && flag == 0) {
		pr->next = travler->next;
		return 1;
	}
	else if (pr == head && pr->val == k) {
		head = pr->next;
		return 1;
	}
	return flag;
}

void skipMiddleN(struct node *travler, int m, int n) {
	struct node *pr = nullptr;
	while (travler != nullptr)
	{
		if (m == 0 && n > 0) {
			if (travler == head) {
				head = travler->next;
				travler = head;
			}
			else {
				pr->next = travler->next;
				travler = travler->next;
			}
			--n;
			continue;
		}
		--m;
		pr = travler;
		travler = travler->next;
	}
}

int main(void) {
	insert(1);
	insert(9);
	insert(9);
	// insert(4);
	// insert(5);
	// insert(6);
	// insert(7);
	printLL();

	Add1toLL(head);
	printLL();

	// check_palindrom(head);
	// printLL();

	// del_last_key(head, 1);
	// printLL();

	// skipMiddleN(head, 1, 3);
	// printLL();

	return 0;
}