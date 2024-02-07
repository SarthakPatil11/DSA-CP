#include<iostream>
using namespace std;
class decimal_to_binary{
	int r;
	public:
		decimal_to_binary(int decimal){ //constructor.
			if(decimal == 0) cout<<"BINARY NUMBER: ";
			else{
				r = decimal % 2;
				decimal_to_binary(decimal /= 2);
				cout<<r;
			}
		}
		~decimal_to_binary(){} //destructor.
};
int main(){
	int no;
	cout<<"Enter the DECIMAL NUMBER that you want to convert in binary: ";
	cin>>no;
	decimal_to_binary db(no);
	return 0;
}
