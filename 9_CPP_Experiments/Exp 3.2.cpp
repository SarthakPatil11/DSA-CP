#include <iostream>
using namespace std;

const int size = 5;
class store{
    private:
        int list[size];
        int front;
        int rear;
    public:
        store(){front = -1,rear = -1;}
        friend class queue;
};

class queue{
    public:
        void put(store &,int);
        int get(store &);
        void show(store);
};

void queue :: put(store &item , int value){
    if(item.rear == size - 1){
        cout<<"QUEUE OVERFLOW...\n";
        return;
    }
    else if(item.front == -1 && item.rear == -1){
        item.front = item.rear = 0;
        item.list[item.rear] = value;
        cout << value << " is added into queue\n";
    }
    else{
        item.rear++;
        item.list[item.rear] = value;
        cout << value << " is added into queue\n";
    }
}

int queue :: get(store & item){
    int element;
    if(item.front == -1 && item.rear == -1){
        cout<<"QUEUE IS EMPTY...\n";
        return -1;
    }
    else if(item.front == item.rear){
        element = item.list[item.front];
        item.front = item.rear = -1;
        return element;
    }
    else{
        element = item.list[item.front];
        item.front++;
        return element;
    }
}

void queue :: show(store item){
    printf("Queue : ");
    for(int i = item.front; i <= item.rear; i++) cout << item.list[i] << " ";
    cout<<endl;
}

int main(){
    store l1;
    queue q1;
    int choice, i, value, size, item;
    while(true){
    	system("cls");
    	cout<<"1: PUT ELEMENT.\n2: GET & DELETE ELEMENT.\n3: SHOW QUEUE.\n4: EXIT.\nENTER YOU CHOICE: ";
	    cin>>choice;
	    switch(choice){
	    	case 1:
	    		cout<<"How many elements you want to put: ";
	    		cin>>size;
	    		cout<<"Enter less than 6 elements: ";
	    		for(i = 0; i < size; i++){
	    			cin>>value;
	    			q1.put(l1,value);
				}
				break;
			case 2:
				item = q1.get(l1);
			    if(item != -1) cout << "Deleled item : " << item <<endl;
				break;
			case 3:
				q1.show(l1);
				break;
			case 4:
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
