#include<iostream>
using namespace std;

class shape{
	public:
		virtual int draw(){
			cout<<"Draw any shape."<<endl;
		}
};

class circle : public shape{
	public:
		int draw(){
			cout<<"Draw a Circle."<<endl;
		}
};

class square : public shape{
	public:
		int draw(){
			cout<<"Draw a Square."<<endl;
		}
};

class triangle : public shape{
	public:
		int draw(){
			cout<<"Draw a Triangle."<<endl;
		}
};

int main(){
	shape *sp = new shape[4];
	circle c;
	square s;
	triangle t;
	
	sp->draw();
	
	sp = &c;
	sp->draw();
	sp++;
	
	sp = &s;
	sp->draw();
	sp++;
	
	sp = &t;
	sp->draw();
	sp++;
	return 0;
}
