#include <iostream>
//#include<string>
using namespace std;
 
class Distance{
	private:
		int feet, inches;
	public:
		Distance(){
	        feet = 0;
	        inches = 0;
	    }
	    Distance(int f, int i){
	        feet = f;
	        inches = i;
	    }
	      
	    Distance operator-- (){
	        feet -= 2;
	        inches -= 2;
	    }
	      
	    Distance operator++ (){
	        feet += 2;
	        inches += 2;
	    }
	      
	    void displayDistance(){
	        cout<<"FEET: "<<feet<<" INCH:"<<inches<<endl;
	    }
};

int main(){
	int feet, inch, choice;
	cout<<"Enter feet and inch: ";
	cin>>feet>>inch;
	Distance D1(feet, inch);
	D1.displayDistance();
	while(true){
		system("cls");
		cout<<"1: Increment.\n2: Decrement.\n3: Exit.\nEnter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				++D1;
				D1.displayDistance();
				break;
			case 2:
				--D1;
				D1.displayDistance();
				break;
			case 3:
				cout<<"EXITED...\n";
				exit(0);
			default:
				cout<<"ENTERD CHOICE IS INVALIDE...\n";
				break;
		}
//		if(choice == 1) ++D1;
//		else if(choice == 2) --D1;
//		else if(choice == 3) exit(0);
//		else cout<<"ENTERD CHOICE IS INVALIDE..."<<endl;
//		D1.displayDistance();
		system("pause");
	}
	return 0;
}
