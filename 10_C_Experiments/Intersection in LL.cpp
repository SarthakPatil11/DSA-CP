#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
	int val;
	struct node *next;
};

struct node* create(int how){
	struct node *head = NULL, *tail = NULL;
	for(int i = 0; i < how; i++){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		cout<<"Enter the value: ";
		cin>>temp->val;
		temp->next = NULL;
		if(i == 0) head = temp;
		else tail->next = temp;
		tail = temp;
	}
	return head;
}

struct node* printLL(struct node *h){
	struct node *travler = h, *pr = NULL;
	while(travler != NULL) {
		cout<<travler->val<<" ---> ";
		pr = travler;
		travler = travler->next;
	}
	cout<<" NULL.\n";
	return pr;
}

struct node* FindInter(struct node *head1, struct node *head2) {
	struct node *travler1 = head1, *travler2 = head2;
	while(travler1 != NULL){
		travler2 = head2;
		while(travler2 != NULL) {
			if(travler1 == travler2) return travler1;
			travler2 = travler2->next;
		}
		travler1 = travler1->next;
	}
}

int main(void) {
	struct node *h1 = create(3);
	struct node *t1 = printLL(h1);
	
	struct node *h2 = create(1);
	struct node *t2 = printLL(h2);
	
	struct node *h3 = create(2);
	struct node *t3 = printLL(h3);
	
	t1->next = h3;
	t2->next = h3;
	printLL(h1);
	printLL(h2);
	printLL(h3);
	
	struct node *inter = FindInter(h1, h2);
	cout<<"Intersection is: "<<inter->val;
	return 0;
}
