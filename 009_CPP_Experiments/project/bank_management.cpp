#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<cstring>
using namespace std;

class account{
	int acno, i;
	char name[50];
	int deposit;
	char type;
	char pass[50];
	int who; //"1" for admin and "0" for user
public:
	void create_account();
	void create_admin_account();
	void show_account() const;
	void modify(int);
	void dep(int);
	void draw(int);
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
	string retpass();
	string admin_name();
	int valid(string temp);
};

int account :: valid(string temp){
	int special = 0, upper = 0, number = 0, status = 1;
	for(int i = 0; i < temp.length(); i++){
		int asci = (int)temp[i];
		if((asci >= 33 && asci <= 45) || asci == 64) special = 1;
		if(asci >= 65 && asci <= 90) upper = 1;
		if(asci >= 48 && asci <= 57) number = 1;
	}
	if(special == 0){
		cout<<"\n\t\t\tYour password don't have any Special character...\n\t\t\tTry again...";
		status = 0;
	}
	if(upper == 0){
		cout<<"\n\t\t\tYour password don't have any Upper character...\n\t\t\tTry again...";
		status = 0;
	}
	if(number == 0){
		cout<<"\n\t\t\tYour password don't have any Number...\n\t\t\tTry again...";
		status = 0;
	}
	return status;
}

void account::create_admin_account(){
	system("CLS");
	who = 1;
	acno = 0;
	cout<<"\n\n\t\t\tEnter The New Admin Name : ";
	cin.ignore();
	cin.getline(name,50);
	type = 'N';
	deposit = 0;
	AGAIN:
	cout<<"\n\t\t\tEnter The password : ";
	cin.getline(pass,50);
	if(valid(pass) == 0) goto AGAIN;
	for(i = 0; i < strlen(pass); i++) pass[i] += 5;
	cout<<"\n\n\t\t\tAccount Created..";
}

void account::create_account(){
	system("CLS");
	who = 0;
	cout<<"\n\t\t\tEnter the new Account No. : ";
	cin>>setw(1)>>acno;
	while(!cin.good()){
		cout<<"\t\t\tERROR: FAULTY INPUT...\n\t\t\tTRY AGAIN...\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout<<"\n\t\t\tEnter the new Account No. : ";
		cin>>acno;
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	
	cout<<"\n\n\t\t\tEnter the Name of the new Account holder : ";
	cin.getline(name,50);
	cout<<"\n\t\t\tEnter Type of the new Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>setw(1)>>deposit;
	while(!cin.good()){
		cout<<"\t\t\tERROR: FAULTY INPUT...\n\t\t\tTRY AGAIN...\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout<<"\n\t\t\tEnter The Initial amount : ";
		cin>>deposit;
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	
	AGAIN1:
	cout<<"\n\t\t\tEnter The password : ";
	cin.getline(pass,50);
	if(valid(pass) == 0) goto AGAIN1;
	for(i = 0; i < strlen(pass); i++) pass[i] += 5;
	cout<<"\n\n\t\t\tAccount Created..";
}

string account::admin_name(){
	return name;
}

void account::show_account() const{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tAccount Holder Name : "<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}

void account::modify(int flag){
	if(flag == 0){
		cout<<"\n\t\t\tAccount No. : "<<acno;
		cout<<"\n\t\t\tModify Account Holder Name : ";
		cin.ignore();
		cin.getline(name,50);
		cout<<"\n\t\t\tModify Type of Account : ";
		cin>>type;
		type=toupper(type);
	}
	else{
		AGAIN2:
		cout<<"\n\t\t\tModify password : ";
		cin.ignore();
		cin.getline(pass,50);
		if(valid(pass) == 0) goto AGAIN2;
		for(i = 0; i < strlen(pass); i++) pass[i] += 5;
	}
}

void account::dep(int x){
	deposit+=x;
}

void account::draw(int x){
	deposit-=x;
}

void account::report() const{
	if(who == 0) cout<<setw(1)<<" "<<acno<<setw(7)<<" "<<name<<setw(11)<<" "<<type<<setw(14)<<deposit<<endl;
//	if(who == 0) cout<<setw(1)<<" "<<acno<<setw(7)<<" "<<name<<setw(11)<<" "<<type<<setw(9)<<deposit<<setw(8)<<" "<<pass<<endl;
}

int account::retacno() const{
	return acno;
}

string account::retpass(){
	return pass;
}

int account::retdeposit() const{
	return deposit;
}

char account::rettype() const{
	return type;
}

void write_account(int);
void display_sp(int);
void modify_account(int, int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
int login(int);

int main(){
	char ch_main, ch1, ch2;
	int num, status, acc;
	while(true){
		MAIN:
		system("CLS");
		cout<<"\n\n\t\t\t\t======================\n";
		cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
		cout<<"\n\t\t\t\t======================\n";
		cout<<"\n\t\t\t\t1. ADMIN LOGIN.";
		cout<<"\n\t\t\t\t2. USER LOGIN.";
		cout<<"\n\t\t\t\t3. EXIT.";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-3): ";
		cin>>ch_main;
		switch(ch_main){
			case '1':
				if(login(1) == 1){
					while(true){
						system("CLS");
						cout<<"\n\n\t\t\t\t======================\n";
						cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
						cout<<"\n\t\t\t\t======================\n";
					
							cout<<"\t\t\t\t    ::ADMIN MENU::\n";
							cout<<"\n\t\t\t\t1. NEW ADMIN ACCOUNT.";
							cout<<"\n\t\t\t\t2. NEW ACCOUNT.";
							cout<<"\n\t\t\t\t3. ALL ACCOUNT HOLDER LIST.";
							cout<<"\n\t\t\t\t4. CLOSE AN ACCOUNT.";
							cout<<"\n\t\t\t\t5. MODIFY AN ACCOUNT.";
							cout<<"\n\t\t\t\t6. BACK.";
							cout<<"\n\n\t\t\t\tSelect Your Option (1-6): ";
							cin>>ch1;
					
							switch(ch1)
							{
								case '1':
									write_account(1);
									break;
								case '2':
									write_account(0);
									break;
								case '3':
									display_all();
									break;
								case '4':
									status, acc = login(0);
									if(status == 1){
										system("CLS");
										delete_account(acc);
									}
									else cout<<"ENTERED ACCOUNT NO. AND/OR PASSWORD ARE/IS WRONG...";
									break;
								 case '5':
								 	status, acc = login(0);
								 	if(status == 1){
								 		system("CLS");
										modify_account(acc, 0);
									 }
									 else cout<<"ENTERED ACCOUNT NO. AND/OR PASSWORD ARE/IS WRONG...";
									break;
								 case '6':
								 	goto MAIN;
									break;
								 default :cout<<"\n\t\t\t\tYOUR CHOICE IS INVALIDE...";
							}
							cin.ignore();
							cin.get();
					}
				}
				else cout<<"ENTERED ADMIN NAME AND/OR PASSWORD ARE/IS WRONG...";
				break;
			case '2':
				status, acc = login(0);
				if(status == 1){
					while(true){
						system("CLS");
						cout<<"\n\n\t\t\t\t======================\n";
						cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
						cout<<"\n\t\t\t\t======================\n";
					
							cout<<"\t\t\t\t    ::USER MENU::\n";
							cout<<"\n\t\t\t\t1. DEPOSIT AMOUNT.";
							cout<<"\n\t\t\t\t2. WITHDRAW AMOUNT.";
							cout<<"\n\t\t\t\t3. BALANCE ENQUIRY.";
							cout<<"\n\t\t\t\t4. MODIFY AN ACCOUNT.";
							cout<<"\n\t\t\t\t5. CHANGE PASSWORD.";
							cout<<"\n\t\t\t\t6. BACK.";
							cout<<"\n\n\t\t\t\tSelect Your Option (1-6): ";
							cin>>ch2;
					
							switch(ch2)
							{
								case '1':
									system("CLS");
									deposit_withdraw(acc, 1);
									break;
								case '2':
									system("CLS");
									deposit_withdraw(acc, 2);
									break;
								case '3':
									system("CLS");
									display_sp(acc);
									break;
								case '4':
								 	system("CLS");
									modify_account(acc, 0);
									break;
								case '5':
									system("CLS");
									modify_account(acc, 1);
									break;
								 case '6':
								 	goto MAIN;
									break;
								 default :cout<<"\n\t\t\t\tYOUR CHOICE IS INVALIDE...";
							}
							cin.ignore();
							cin.get();
					}
				}
				else cout<<"ENTERED ACCOUNT NO. AND/OR PASSWORD ARE/IS WRONG...";
				break;
			case '3':
				cout<<"\n\t\t\t\tEXITED...";
				exit(0);
			default: 
				cout<<"\n\t\t\t\tYOUR CHOICE IS INVALIDE...";
				break;
		}
		cin.ignore();
		cin.get();
	}
	return 0;
}

void write_account(int who){
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	if(who == 1) ac.create_admin_account();
	else ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n){
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist";
}

void modify_account(int n, int flag){
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			if(flag == 0){
				ac.show_account();
				cout<<"\n\t\t\t=========================================="<<endl;
				cout<<"\n\t\t\tEnter The New Details of account"<<endl;
				ac.modify(flag);
				int pos=(-1)*static_cast<int>(sizeof(account));
				File.seekp(pos,ios::cur); //fncallat1353
			    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			    cout<<"\n\n\t\t\tRecord Updated";
			    found=true;
			}
			else{
				ac.show_account();
				cout<<"\n\t\t\t=========================================="<<endl;
				cout<<"\n\t\t\tEnter The New password of account"<<endl;
				ac.modify(flag);
				int pos=(-1)*static_cast<int>(sizeof(account));
				File.seekp(pos,ios::cur); //fncallat1353
			    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			    cout<<"\n\n\t\t\tRecord Updated";
			    found=true;
			}
		}
	}
	File.close();
	if(found==false) cout<<"\n\n\t\t\tRecord Not Found ";
}

void delete_account(int n){
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\nRecord Deleted ..";
}

void display_all(){
	system("CLS");
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"================================================\n";
	cout<<"A/c no.      NAME           Type      Balance\n";
	cout<<"================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

void deposit_withdraw(int n, int option){
	int amt;
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false) //eof() is end of file.
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>setw(1)>>amt;
				while(!cin.good()){
					cout<<"\t\t\tERROR: FAULTY INPUT...\n\t\t\tTRY AGAIN...\n";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
					cin>>amt;
				}
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>setw(1)>>amt;
				while(!cin.good()){
					cout<<"\t\t\tERROR: FAULTY INPUT...\n\t\t\tTRY AGAIN...\n";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
					cin>>amt;
				}
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}

int login(int who){
    int acc,im = 0, i;
    char name[50];
    char pass[50];
    account ac;
    fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
    if(!File){
        cout<<"\n\n\t\t\t\tFile could not be open !! Press any Key...";
        return 0;
    }
    system("CLS");
	cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\t\tLOGIN";
	cout<<"\n\t\t\t\t======================\n";
    if(who == 1){															//admin
    	cout<<endl<<"\n\t\t\t\tEnter Admin Name : ";
    	cin.ignore();
	    cin.getline(name,50);
	    cout<<"\n\t\t\t\tEnter your password : ";
	    cin>>pass;
	    for(i = 0; i < strlen(pass); i++) pass[i] += 5;
    	while(!File.eof()){
	        File.read(reinterpret_cast<char *> (&ac), sizeof(account));
	        cout<<"\n"<<name<<"\t";
	        for(i = 0; i < strlen(pass); i++) cout<<pass[i];
	        if((ac.admin_name() == name) && (ac.retpass() == pass)) im=1;
    	}
    	File.close();
    	return im;
	}
	else{																	//user
		cout<<endl<<"\n\t\t\t\tEnter account no. : ";
	    cin>>acc;
	    cout<<"\n\t\t\t\tEnter your password : ";
	    cin>>pass;
	    for(i = 0; i < strlen(pass); i++) pass[i] += 5;
		while(!File.eof()){
	        File.read(reinterpret_cast<char *> (&ac), sizeof(account));
	        if((ac.retacno() == acc) && (ac.retpass() == pass)) im=1;
	    }
	    File.close();
    	return im, acc;
	}
}
