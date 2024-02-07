#include<iostream>
using namespace std;
class pattern{
	int i, j, space;
	public:
		int L_half_trangle(){
			//L_half_trangle using '&'
			for(i = 0; i < 4; i++){
		        for(j = 0; j <= i; j++) cout<<"& ";
			    cout<<endl;
			}
			cout<<endl;
			return 0;
		}
		
		int Full_trangle(){
			//Full_trangle using '&'
			for(i = 1; i <= 4; i++)
		    {
		        for(space = 4; space > i; space--) cout<<" ";
		        for(j = 0; j < i; j++) cout<<"& ";
		        cout<<endl;
		    }
    		cout<<endl;
			return 0;
		}
		
		int R_half_trangle(){
			//R_half_trangle using '&'
			space = 6;
		    for(i = 0; i < 4; i++)
		    {
		        for(j = 0; j < space; j++) cout<<" ";
		        space -= 2;
		        for(j = 0; j <= i; j++) cout<<"& ";
		        cout<<endl;
		    }
		    cout<<endl;
			return 0;
		}
};

int main(){
	int choice;
	pattern p;
	while(true){
		system("cls");
		cout<<"1: LEFT HALF TRAGLE.\n2: FULL TRANGLE.\n3: RIGHT HALF TRANGLE.\n4: Exit.\nENTER YOUR CHOICE: "<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				p.L_half_trangle();
				break;
			case 2:
				p.Full_trangle();
				break;
			case 3:
				p.R_half_trangle();
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
