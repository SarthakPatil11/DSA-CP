#include <iostream>
using namespace std;
 
class Distance{
	private:
		int feet, inches;
	public:
		Distance(){
	        feet = inches = 0;
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
	        cout<<"FEET: "<<feet<<" INCH: "<<inches<<endl;
	    }
};

int main(){
	int feet, inch, choice, t = 0;
	cout<<"Enter feet and inch: ";
	cin>>feet>>inch;
	Distance D1(feet, inch);
	D1.displayDistance();
	system("pause");
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
		system("pause");
	}
	return 0;
}
