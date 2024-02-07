#include<iostream>
#include<string>
using namespace std;
class Bank_acc{
	public:
		string name, acc_type;
		int acc_no;
		double bal, temp_amount;
		int assign_initial_values(){
			cout<<"Enter the holder name : ";
			getline(cin, name);
			cout<<"Enter the acc type : ";
			getline(cin, acc_type);
			cout<<"Enter the acc_no : ";
			cin>>acc_no;
			cout<<"Enter the balance : ";
			cin>>bal;
			cout<<"----------------------Entered data-----------------------\nHolder name : "<<name<<"\nAcc_type : "<<acc_type<<"\nAcc_no : "<<acc_no<<"\nBalance : "<<bal<<"\n---------------------------------------------------------"<<endl;
		}
		
		int Diposit(){
			cout<<"Enter the dipositing amount : ";
			cin>>temp_amount;
			bal += temp_amount;
			cout<<"----------YOUR AMOUNT IS SUCCESFULLY DIPOSITED.----------\nAmount is "<<temp_amount<<"\nCurrent balance is "<<bal<<"\n---------------------------------------------------------"<<endl;
		}
		
		int Withdraw(){
			cout<<"Enter the withdrawing amount : ";
			cin>>temp_amount;
			bal -= temp_amount;
			cout<<"----------YOUR AMOUNT IS SUCCESFULLY WITHDRAW.-----------\nAmount is "<<temp_amount<<"\nCurrent balance is "<<bal<<"\n---------------------------------------------------------"<<endl;
		}
		
		int Disp_name_bal(){
			cout<<"------------------YOUR ACCOUNT'S DATA.-------------------\nHOLDER NAME : "<<name<<"\nBALANCE : "<<bal<<"\n---------------------------------------------------------"<<endl;
		}
};
int main(){
	Bank_acc BA;
	int choice;
	cout<<"======================ENTER BANK DETAILS=======================\n";
	BA.assign_initial_values();
	while(true){
		cout<<"===============================================================\n";
		cout<<"1: DIPOSIT AMOUNT.\n2: WITHDRAW AMOUNT.\n3: DISPLAY HOLDER NAME AND BLANCE.\n4: EXIT.\nENTER YOU CHOICE: ";
		cin>>choice;
		switch(choice){
			case 1:
				BA.Diposit();
				break;
			case 2:
				BA.Withdraw();
				break;
			case 3:
				BA.Disp_name_bal();
				break;
			case 4:
				cout<<"==========================THANK YOU!===========================\n";
				exit(0);
			default:
				cout<<"ENTERED CHOICE IS INVALIDE...\n";
				break;
		}
	}
	return 0;
}
