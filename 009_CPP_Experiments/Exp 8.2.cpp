#include<iostream>
using namespace std;

class shape{
	public:
		virtual int draw() = 0;
//		shape(){
//			draw();		//IF YOU REMOVE THE COMMENT OF THIS ONE IT WILL SHOW THE COMPILER ERROR BECAUSE WE CAN'T CREATE THE OBJ OF ABSTRACT CLASS.
//		}
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
	shape *sp;
	circle c;
	square s;
	triangle t;
	
	sp = &c;
	sp->draw();
	
	sp = &s;
	sp->draw();
	
	sp = &t;
	sp->draw();
	return 0;
}
