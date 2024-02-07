#include<iostream>
using namespace std;
class demo{
	public:
		int c, b, d;
		int Display(){
			return c = b * b;
		}
		int Show(){
			return d = b + b;
		}
};

int main(){
	demo d;
	d.b = 20;
	cout<<"Display : "<< d.Display();
//	cout<<"Show : "<< a.Show();
}
