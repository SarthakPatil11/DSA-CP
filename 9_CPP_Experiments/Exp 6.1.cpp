#include<iostream>
using namespace std;
class shapes{
	private:
		const float pi = 3.14;
	public:
		void volume(float s){
			cout<<"VOLUME OF CUBE: "<<s*s*s<<endl;
		}
		void volume(int r, int h){
			cout<<"VOLUME OF CYLINDER: "<<pi*(r*r)*h<<endl;
		}
		void volume(int r){
			cout<<"VOLUME OF SPHERE: "<<(4/3)*pi*(r*r*r)<<endl;
		}
};

int main(){
	shapes s1;
	int choice, r, h;
	float s;
	while(true){
		system("cls");
		cout<<"1: Volume of a cube.\n2: Volume of a cylinder.\n3: Volume of a sphere.\n4: Exit.\nEnter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the lenght of side: ";
				cin>>s;
				s1.volume(s);
				break;
			case 2:
				cout<<"Enter the radius and height: ";
				cin>>r>>h;
				s1.volume(r, h);
				break;
			case 3:
				cout<<"Enter the radius: ";
				cin>>r;
				s1.volume(r);
				break;
			case 4:
				cout<<"Exited...";
				exit(0);
			default:
				cout<<"YOUR CHOICE IS INVALIDE...";
				break;
		}
		system("pause");
	}
	return 0;
}
