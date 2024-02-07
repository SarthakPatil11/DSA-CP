#include<iostream>
#include<string>
using namespace std;

class staff{
	private:
		string code, name;
	public:
		void staff_details(string prf){
			cout<<"Enter the code for "<<prf<<": ";
			cin>>code;
			cout<<"Enter the name of "<<prf<<": ";
			cin>>name;
		}
		void disp_staff(string prf){
			cout<<prf<<" CODE: "<<code<<"\n"<<prf<<" NAME: "<<name;
		}
};

class teacher : public staff{
	private:
		string subject, publication;
	public:
		void enter_teacher_data(){
			staff_details("teacher");
			cout<<"Enter the subject of teacher: ";
			cin>>subject;
			cout<<"Enter the publication of teacher: ";
			cin>>publication;
		}
		void display_teacher_data(){
			disp_staff("TEACHER");
			cout<<"\nTEACHER SUBLJECT: "<<subject<<"\nTEACHER PUBLICATION: "<<publication<<endl;
		}
};

class officer : public staff{
	private:
		string grade;
	public:
		void enter_officer_data(){
			staff_details("officer");
			cout<<"Enter the grade of officer(eg. A, B, etc.): ";
			cin>>grade;
		}
		void display_officer_data(){
			disp_staff("OFFICER");
			cout<<"\nOFFICER GRADE: "<<grade<<endl;
		}
};

class typist : public staff{
	private:
		string speed;
	public:
		void enter_speed(string sub_prof){
			staff_details("typist");
			cout<<"Enter the speed of"<<sub_prof<<" typist: ";
			cin>>speed;
		}
		void display_typist_data(string sub_prof){
			disp_staff("OFFICER");
			cout<<endl<<sub_prof<<"TYPIST SPEED: "<<speed<<endl;
		}
};

class regular : public typist{
	public:
		void enter_rtypist_data(){
			enter_speed("regular");
		}
		void disp_rtypist_data(){
			display_typist_data("REGULAR");
		}
};

class casual : public typist{
	private:
		int daily_wages;
	public:
		void enter_ctypist_data(){
			enter_speed("casual");
			cout<<"Enter the daily wages of casual typist: ";
			cin>>daily_wages;
		}
		void disp_ctypist_data(){
			display_typist_data("CASUAL");
			cout<<"\nDAILY WAGES OF CASUAL TYPIST: "<<daily_wages<<endl;
		}
};

int main(){
	teacher t;
	officer f;
	regular tr;
	casual tc;
	int choice;
	while(true){
		main:
		system("cls");
		cout<<"1: Enter the data of staff.\n2: Display the data of staff.\n3: Exit.\nEnter choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				int choice1;
				while(true){
					system("cls");
					cout<<"1: Enter the data of teacher.\n2: Enter the data of officer.\n3: Enter the data of regular typist.\n4: Enter the data of casual typist.\n5: Back.\nEnter choice: ";
					cin>>choice1;
					system("cls");
					switch(choice1){
						case 1:
							t.enter_teacher_data();
							break;
						case 2:
							f.enter_officer_data();
							break;
						case 3:
							tr.enter_rtypist_data();
							break;
						case 4:
							tc.enter_ctypist_data();
							break;
						case 5:
							goto main;
						default:
							cout<<"ENTERED CHOICE IS INVALIDE..."<<endl;
							break;
					}
					system("pause");
				}
			break;
			case 2:
				int choice2;
				while(true){
					system("cls");
					cout<<"1: Display the data of teachers.\n2: Display the data of officers.\n3: Display the data of regular typists.\n4: Display the data of casual typists.\n5: Back.\nEnter choice: ";
					cin>>choice2;
					system("cls");
					switch(choice2){
						case 1:
							t.display_teacher_data();
							break;
						case 2:
							f.display_officer_data();
							break;
						case 3:
							tr.disp_rtypist_data();
							break;
						case 4:
							tc.disp_ctypist_data();
							break;
						case 5:
							goto main;
						default:
							cout<<"ENTERED CHOICE IS INVALIDE..."<<endl;
							break;
					}
					system("pause");
				}
			break;
			case 3:
				cout<<"EXITED...";
				exit(0);
			default:
				cout<<"ENTERED CHOICE IS INVALIDE..."<<endl;
			break;
		}
		system("pause");
	}
	return 0;
}
