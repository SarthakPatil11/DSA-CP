#include<iostream>
// #include<stdlib.h>

using namespace std;
struct node {
	int val;
	struct node *next;
}*head = nullptr, *tail = nullptr;
int ct = 0;
string pal1 = nullptr, pal2 = nullptr;

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
	struct node *travler = head;
	while(travler != NULL) {
		cout<<travler->val<<"-->";
		travler = travler->next;
	}
	cout<<"NULL."<<endl;
}

void print_middle() {
	struct node *travler = head;
	int counter = 0;
	while(travler != NULL) {
		counter++;
		travler = travler->next;
	}
	counter = (counter / 2) + 1;
	travler = head;
	for (int i = 0; i < counter; i++) {
		if (i == (counter - 1)) cout<<"Middle node: "<<travler->val<<endl;
		travler = travler->next;
	}
}

void delMid() {
	struct node *travler = head, *pr = NULL, *next = NULL;
	int count = 0;
	while (travler != NULL) {
		count++;
		travler = travler->next;
	}
	
	count = (count / 2) + 1;
	
	travler = head;
	while(count) {
		next = travler->next;
		if(count == 1) {
			pr->next = next;
			free(travler);
			return;
		}
		pr = travler;
		travler = next;
		count--;
	}
}

void remove_dup() {
	struct node *travler = head->next, *pr = head, *next = NULL;
	while (travler != NULL) {
		next = travler->next;
		if ((travler->val) == (pr->val)) {
			pr->next = next;
			free(travler);
			travler = next;
			continue;
		}
		pr = travler;
		travler = next;
	}
	return;
}

void rev() {
	struct node *travler = head, *pr = NULL, *next = NULL;
	while(travler != NULL) {
		next = travler->next;
		travler->next = pr;
		pr = travler;
		travler = next;
	}
	tail = head;
	head = pr;
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

void rev_in_s(int size) {
	struct node *travler = head, *pr = NULL, *next = NULL, *first = NULL, *last = NULL;
	int count = 0;
	while (travler != NULL)
	{
		next = travler->next;
		if((count % size) == 0) {
			first = travler;
			do {
				next = travler->next;
				travler->next = pr;
				pr = travler;
				travler = next;
				count++;
			} while((count % size) != 0);
			last = first;
			first = pr;
			if(last != head) {
				 pr->next = first;
			}
		}
		count++;
		pr = travler;
		travler = travler->next;
	}
	
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
	pal1.push_back(travler->val);
	if (travler->next == nullptr) return;
	check_palindrom(travler->next);
	pal2.push_back(travler->val);
	if(travler == head) {
		if (pal1 == pal2) cout<<"Linked list is palindrom..."<<endl;
		else cout<<"Linked list is not palindrom..."<<endl;
	}
}

int main(void) {
	insert(1);
	insert(2);
	insert(2);
	insert(3);
	// insert(5);
	// insert(6);
	printLL();

	// print_middle();
	// printLL();

	// remove_dup();
	// printLL();
	
	// Add1toLL(head);
	// rev_in_s(2);
	// cout<<getNthFromLast(head, 5)<<endl;
	// printLL();
	return 0;
}
