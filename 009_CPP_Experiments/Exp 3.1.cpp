#include <iostream>
using namespace std;

class checkbook{
    private:
        int list[20];
        int index;
        int sum;
    public:
        checkbook(){ index = 0;sum = 0;}
        void friend add_item(checkbook &,int);
        void friend total(checkbook);
};


void add_item(checkbook & item,int value){
    item.list[item.index] = value;
    item.index++;
    item.sum += value;
}

void total(checkbook item){
    cout << "SUM OF ENTERED LIST OF ITEMS : " << item.sum <<endl;
}

int main(){
    checkbook cb;
    int i, no, value;
    again:
    	system("cls");
	    cout<<"Enter how many elements you want to enter (less than 20): ";
	    cin>>no;
    if(no > 20){
    	cout<<"ENTER LESS THAN 20 ITEMS..."<<endl;
    	system("pause");
		goto again;
	}
    else{
    	cout<<"Enter the items value: ";
	    for(i = 0; i < no; i++){
	    	cin>>value;
	    	add_item(cb,value);
		}
		total(cb);
	}
	return 0;
}
