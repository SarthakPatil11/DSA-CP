#include<iostream>
using namespace std;
class pascal{
	int i, j, k, height, coef;
	public:
		pascal(void){
			cout<<"\nRUNNING DEFAULT CONSTROCTOR."<<endl;
			height = 3;
		}
		pascal(int no){
			cout<<"\nRUNNING CONSTROCTOR WITH ONE PARAMETER."<<endl;
			height = no;
		}
		int print_pascal(){
			for(i = 1; i <= height; i++){
				coef = 1;
				for(k = i; k < height; k++) cout<<" ";
				for(j = 1; j <= i; j++){
					cout<<coef<<" ";
					coef = coef * (i - j)/j;
				}
				cout<<endl;
			}
		}
};

int main(){
	int choice, no;
	cout<<"Enter the height of the trangle: ";
	cin>>no;
	pascal p1;
	p1.print_pascal();
	pascal p2(no);
	p2.print_pascal();
	return 0;
}
