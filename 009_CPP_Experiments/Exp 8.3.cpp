#include<iostream>
using namespace std;

class person{
	protected:
		int adhar_no;
	public:
		void set_adhar_no(int adn){
			adhar_no = adn;
		}
		void disp_adhar(){
			cout<<"Adhar no. : "<<adhar_no<<endl;
		}
};

class age : virtual public person{
	protected:
		int age;
	public:
		void set_age(int a){
			age = a;
		}
		void disp_age(){
			cout<<"Age : "<<age<<endl;
		}
};

class name : virtual public person{
	protected:
		string name;
	public:
		void set_name(string n){
			name = n;
		}
		void disp_name(){
			cout<<"Name : "<<name<<endl;
		}
};

class eligible : public age, public name{
	public:
		void eligibelyn(){
			cout<<"--------------------------------\n";
			disp_adhar();
			disp_name();
			disp_age();
			if(age > 17) cout<<"This person is Eligible.";
			else cout<<"This person is Not Eligible.";
		}
};

int main(){
	eligible e;
	int age, adn;
	string name;
	cout<<"Enter the adhar no.: ";
	cin>>adn;
	cout<<"Enter name of person: ";
	cin>>name;
	cout<<"Enter age of person: ";
	cin>>age;
	e.set_adhar_no(adn);
	e.set_age(age);
	e.set_name(name);
	e.eligibelyn();
	return 0;
}
