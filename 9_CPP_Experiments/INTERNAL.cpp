#include<iostream>
using namespace std;

class Animal{
	public:
//		virtual int move(){
//			cout<<"Animal is moving..."<<endl;			//IF YOU COMMENT OUT THE MOVE AND REMOVE COMMENTS OF THIS FUNCTION THEN IT BECOMES LATE BINDING.
//		}
		int move(){
			cout<<"Animal is moving..."<<endl;			//IF YOU COMMENT OUT THE VIRTUAL MOVE AND REMOVE COMMENTS OF THIS FUNCTION THEN IT BECOMES EARLY BINDING.
		}
};

class Animalchild : public Animal{
	public:
		int move(){
			cout<<"Animal's child is moving..."<<endl;
		}
};

int main(void){
	Animal *a;
	Animalchild ac;
	a = &ac;
	a -> move();
	return 0;
}
