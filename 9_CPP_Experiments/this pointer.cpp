#include<iostream>
using namespace std;
//class text{
//	int a, b;
//	public:
//		int show(){
//			a = 10;
//			b = 20;
//			cout<<"Object address: "<<this;
//			cout<<"a: "<<this.a;
//			cout<<"b: "<<this.b;
//		}
//		
//};

class item{
	int code;
	float price;
	public:
		void getdata(int a, float b){
			code = a;
			price = b;
		}
		void show(void){
			cout<<"code: "<<code<<endl;
			cout<<"price: "<<price<<endl;
		}
};

const int size = 2;
int main(){
	item *p = new item[size];
	item *d = p;
	itn x, i;
	
}
