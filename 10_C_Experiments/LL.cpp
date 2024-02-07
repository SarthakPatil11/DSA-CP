#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
	int val;
	struct node *next;
}*head = NULL, *tail = NULL;

void add_node(int val) {
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->val = val;
	temp->next = NULL;
	
	if(head == NULL) head = temp;
	else tail->next = temp;			//to insert node at tail you have to know the last node of the LL. so declare the tail node.
	
	tail = temp;
}

void insert_at(int val, int loc) {
	struct node *temp = (struct node *) malloc(sizeof(struct node)), *travler = head, *pr = NULL;
	temp->val = val;
	if(head == NULL) head = temp;
	int i = 0;
	while(travler != NULL) {
		if(i == loc) {
			pr->next = temp;
			temp->next = travler;
		}
		pr = travler;
		travler = travler->next;
		++i;
	}
}

void insert_at_b(int val) {
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->val = val;
	temp->next = head;
	head = temp;
}

void del_at_tail(){
	struct node *sd_tail = NULL, *temp = head;
	while(temp != NULL) {
		if(temp == tail) {
			sd_tail->next = NULL;
			tail = sd_tail;
			free(temp);
			return;
		}
		sd_tail = temp;
		temp = temp->next;
	}
}

void del_node(int val) {
	struct node *pr = NULL, *next = NULL, *travler = head;
	while(travler != NULL) {
		next = travler->next;
		if((travler->val) == val) {
			pr->next = next;
			free(travler);
			return;
		}
		pr = travler;
		travler = travler->next;
	}
}

void del_head() {
	struct node *temp = head->next;
	head = temp;
	free(temp);
}

void reverse(){
	struct node *pr = NULL, *cr = head, *nxt = NULL;
	while(cr != NULL) {
		nxt = cr->next;
		cr->next = pr;
		pr = cr;
		cr = nxt;
	}
	head = pr;
}

void sortLL(){
	if(head == NULL) {
		cout<<"LL is empty...\n";
		return;
	}
	struct node *travler = head, *travler2 = NULL;
	while(travler != NULL) {
		travler2 = travler->next;
		while(travler2 != NULL) {
			if((travler->val) >= (travler2->val)) {
				int temp_val = travler2->val;
				travler2->val = travler->val;
				travler->val = temp_val;
			}
			travler2 = travler2->next;
		}
		travler = travler->next;
	}
}

void printLL() {
	if(head == NULL) return;
	struct node *travler = head;
	while(travler != NULL) {
		cout<<travler->val<<" ---> ";
		travler = travler->next;
	}
	cout<<" NULL.\n";
	return;
}

int main(void) {
	add_node(1);
	add_node(2);
	add_node(3);
	add_node(4);
	add_node(5);
	printLL();
	
	del_at_tail();
	printLL();
	
	del_node(3);
	printLL();
	
	reverse();
	printLL();
	
	insert_at_b(10);
	printLL();
	
	insert_at(20, 1);
	printLL();
	
	del_head();
	printLL();
	
	sortLL();
	cout<<"sort: ";
	printLL();
	return 0;
}
