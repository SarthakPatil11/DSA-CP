#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct node{
	int val;
	struct node *pr;
	struct node *next;
}*head = NULL, *tail = NULL;

void insert(int val) {
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->val = val;
	temp->next = NULL;
	temp->pr = NULL;
	if(head == NULL) head = temp;
	else {
		tail->next = temp;
		temp->pr = tail;
	}
	tail = temp;
}

void insertB(int val) {
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->val = val;
	temp->pr = NULL;
	if(head == NULL) {
		temp->next = NULL;
		head = temp;
	}
	else {
		temp->next = head;
		head->pr = temp; 
		head = temp;
	}
}

void insertat(int val, int loc) {
	struct node *temp = (struct node *) malloc(sizeof(struct node)), *travler = head, *pr = NULL, *next = NULL;
	int i = 1;
	while(travler != NULL) {
		next = travler->next;
		if(i == loc) {
			temp->val = val;
			temp->next = next;
			temp->pr = pr;
			pr->next = temp;
			next->pr = temp;
		}
		++i;
		pr = travler;
		travler = next;
	}
}

void delB(){
	if(head == NULL) {
		cout<<"LL is empty...\n";
		return;
	}
	struct node *temp = head;
	head = head->next;
	head->pr = NULL;
	free(temp);
	
}

void delE(){
	if(head == NULL) {
		cout<<"LL is empty...\n";
		return;
	}
	struct node *temp = tail;
	tail = tail->pr;
	tail->next = NULL;
	free(temp);
}

void FindMax() {
	if(head == NULL) {
		cout<<"LL is empty...\n";
		return;
	}
	
	struct node *travler = head->next;
	int max_val = head->val;
	
	while(travler != NULL) {		
		if(max_val <= (travler->val)) max_val = travler->val;
		travler = travler->next;
	}
	
	cout<<"Max value is: "<<max_val<<endl;
}

void sort(){
	if(head == NULL) {
		cout<<"LL is empty...\n";
		return;
	}
	
	struct node *travler = head, *travler2 = NULL;
	while(travler != NULL) {
		travler2 = travler->next;
		while(travler2 != NULL) {
			if((travler->val) >= (travler2->val)){
				int temp = travler->val;
				travler->val = travler2->val;
				travler2->val = temp;
			}
			travler2 = travler2->next;
		}
		travler = travler->next;
	}
}

void printS(){
	struct node *travler = head;
	cout<<"NULL <--> ";
	while(travler != NULL) {
		cout<<travler->val<<" <--> ";
		travler = travler->next;
	}
	cout<<"NULL\n";
}

void printL(){
	struct node *travler = tail;
	cout<<"NULL <--> ";
	while(travler != NULL) {
		cout<<travler->val<<" <--> ";
		travler = travler->pr;
	}
	cout<<"NULL\n";
}

int main(void){
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	printS();
	printL();
	cout<<tail->val<<endl;
	
	cout<<"\nInsert begining: \n";
	insertB(0);
	printS();
	printL();
	cout<<tail->val<<endl;
	
	cout<<"\nInsert at 3: \n";
	insertat(100, 3);
	printS();
	printL();
	cout<<tail->val<<endl;
	
	cout<<"\ndelete begining: \n";
	delB();
	printS();
	printL();
	cout<<tail->val<<endl;
	
	cout<<"\nDelete Ending: \n";
	delE();
	printS();
	printL();
	cout<<tail->val<<endl;
	
	cout<<"\nmax value: \n";
	FindMax();
	printS();
	printL();
	cout<<tail->val<<endl;
	
	cout<<"\nSort: \n";
	sort();
	printS();
	printL();
	cout<<tail->val<<endl;
	return 0;
}
