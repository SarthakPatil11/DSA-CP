#include<iostream>
#include<string>
using namespace std;
struct item{
	int srno;
	string name;
	int price;
	int quntity;
}it[10];
int len;
class shopping_list{
	public:
		int i, j, del_el;
		int add_item(int size){
			for(i = len; i < size+len; i++){
				it[i].srno = i;
				cout<<"Enter the name of item: ";
				cin>>it[i].name;
				cout<<"Enter the price of item: ";
				cin>>it[i].price;
				cout<<"Enter the quantity of that item: ";
				cin>>it[i].quntity;
				cout<<"------------------------------------------\n";
			}
			return i;
		}
		int del_item(int len){
			display(len);
			cout<<"Enter the sr. no. of item: ";
			cin>>del_el;
			for(i = 0; i < len; i++){
				if(i == del_el){
					for(j = i; j < len; j++){
						it[j] = it[j+1];
						it[j].srno--;
					}
				}
			}
			cout<<"------------------------------------------\n";
			return len -= 1;
		}
		int display(int len){
			cout<<"item sr.no.\tname\tprice\tquantity"<<endl;
			cout<<"------------------------------------------\n";
			for(i = 0; i < len; i++) cout<<"\t"<<it[i].srno<<"\t"<<it[i].name<<"\t"<<it[i].price<<"\t"<<it[i].quntity<<endl;
			cout<<"------------------------------------------\n";
		}
};

int main(){
	int size, choice;
	shopping_list SL;
	while(true){
		system("cls");
		cout<<"==========================================\n1: Add item in a list.\n2: Delete item in a list.\n3: Display.\n4: Exit.\nEnter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				ADD:
					cout<<"How many elements you want to add?: ";
					cin>>size;
					len = SL.add_item(size);
				break;
			case 2:
				if(len > 0) len = SL.del_item(len);
				else{
					cout<<"THERE IS NO ITEM IN A LIST...\nGOING TO ADD ITEM(s)\n";
					goto ADD;
				}
				break;
			case 3:
				if(len > 0) SL.display(len);
				else{
					cout<<"THERE IS NO ITEM IN A LIST...\nGOING TO ADD ITEM(s)\n";
					goto ADD;
				}
				break;
			case 4:
				cout<<"*****THANK YOU*****";
				exit(0);
			default:
				cout<<"YOUR ENTERED CHOICE IS INVALIDE...\n";
				break;
		}
		system("pause");
	}
	return 0;
}
