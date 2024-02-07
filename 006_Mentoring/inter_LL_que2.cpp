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
	if(head == NULL) {
		head = temp;
		tail = head;
	}
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
	cout<<"NULL.\n";
}

void delMid(struct node *head) {
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

struct node *rev(struct node *first, struct node *last) {
	struct node *travler = first, *pr = NULL, *next = NULL;
	last = first;
	while(travler != NULL) {
		next = travler->next;
		travler->next = pr;
		pr = travler;
		travler = next;
	}
	first = last;
}

struct node *reverse (struct node *head, int k)
   { 
       // Complete this method
       struct node* temp = head;
       struct node* last = nullptr;
       int flag = 0;
       while(temp!=nullptr) {
           struct node* curr = temp;
           struct node* prev = nullptr;
           struct node* ahead = curr->next;
           struct node* first = curr;
           int i = 0;
           while(i<k && temp!=nullptr) {
               temp = temp->next;
               curr->next = prev;
               prev = curr;
               curr = ahead;
               if(curr!=nullptr) {
                   ahead = curr->next;
               }
               i++;
           }
           if(flag==0) {
               head = prev;
               last = first;
               flag=1;
           } else {
               last->next = prev;
               last = first;
           }
       }
       return head;
   }

// void rev_in_renge(struct node *head, int size) {
// 	struct node *travler = head, *f, *l;
// 	int count = 0;
// 	while (travler != NULL) {
// 		f = travler;
// 		if ((count % size) == 0)
// 		{
// 			l = travler;
// 			f = rev(f, l);
// 		}
// 		count++;
// 		travler = travler->next;
// 	}
// }

int main(void) {
	struct node *head = NULL, *f = NULL, *l = NULL;
	head = push(head, 10);
	head = push(head, 20);
	head = push(head, 30);
	head = push(head, 40);
	head = push(head, 50);
	printLL(head);
	// delMid(head);
	f = reverse(head, 3);
	printLL(f);
	return 0;
}