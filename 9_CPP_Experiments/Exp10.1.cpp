#include<iostream>
using namespace std;
template<class T>
class node
{
	public:
		node*next;
		T val;
		node(T val){
			next=NULL;
			this->val=val;
		}
};

template<class T>
class List
{
	node<T>*current,*head;
	public:
		List(){
			current = head = NULL;
		}
		void add(T val){
			node<T> *n=new node<T>(val);
			if(head == NULL){
				head=n;
				current=head;
				return;
			}
			current->next=n;
			current=current->next;
		}
		void print(){
			current=head;
			cout<<"[ ";
			while(current!=NULL){
				cout<<current->val<<" ";
				current=current->next;
			}
			cout<<" ]";
		}
};

int main(){
	cout<<"For int: "<<endl;
	List<int> l;
	l.add(1);
	l.add(2);
	l.add(3);
	l.add(4);
	l.add(5);
	l.print();
	
	cout<<"\nFor string: "<<endl;
	List<string> l2;
	l2.add("Sarthak");
	l2.add("Suyash");
	l2.add("Omkar");
	l2.add("Prathamesh");
	l2.print();
}
