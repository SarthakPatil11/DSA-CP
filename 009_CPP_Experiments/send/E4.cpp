#include <iostream>
using namespace std;

const int size = 5;

class stack{
    private:
        int array[size];
        static int top;
    public:
        void push(int);
        void pop();
        void showStack();
        void static showTop();
};

int stack :: top;

inline void stack :: push(int item){
    if(top >= size){
        cout << "\nStack Overflow\n";
        return;
    }
    array[top] = item;
    cout << array[top] << " is pushed into stack\n";
    top++;
}

inline void stack :: pop(){
    if(top == 0){
        printf("Stack Underflow\n");
        return;
    }
    top--;
    cout << array[top] << " is poped\n";
}

inline void stack :: showStack(){
    cout << "stack : ";
    int i = top - 1;
    while(i >= 0){
        cout << array[i] << " ";
        i--;
    }
    cout<<endl;
}

void stack :: showTop(){
    cout << "Top : " << top << endl;
}

int main(){
    stack s1;
    int choice, i, value, size;
    while(true){
    	system("cls");
    	cout<<"1: PUSH ELEMENT.\n2: POP ELEMENT.\n3: SHOW STACK.\n4: SHOW TOP.\n5: EXIT.\nENTER YOU CHOICE: ";
	    cin>>choice;
	    switch(choice){
	    	case 1:
	    		cout<<"How many elements you want to push: ";
	    		cin>>size;
	    		cout<<"Enter less than 6 elements: ";
	    		for(i = 0; i < size; i++){
	    			cin>>value;
	    			s1.push(value);
				}
				break;
			case 2:
				s1.pop();
				break;
			case 3:
				s1.showStack();
				break;
			case 4:
				s1.showTop();
				break;
			case 5:
				cout<<"EXIT..."<<endl;
				exit(0);
			default:
				cout<<"ENTERED CHOICE IS INVALIDE..."<<endl;
				break;
		}
		system("pause");
    }
    return 0;
}

