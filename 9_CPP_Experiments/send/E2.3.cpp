#include<iostream>
using namespace std;
class Eg{
    int x,a;
    const char *p; 
    public:
        Eg(){
            cout <<endl<<"Enter two values : ";
            cin >>x >>a;
        }
        Eg(const Eg& B){  //Copy constructor
            x=B.x;  a=B.a;
        }
        Eg(int c){ //Dynamic constructor
            if(c){
                p=new char[7];
                p="Dynamic";
                cout<<p<<"ally created"<<endl;
            }
        }
        void display(){
            cout<<"\nx : "<<x<<"\ta : "<<a<<endl;
        }
};

int main(){
    system("CLS");
    Eg A;
    Eg B=A;
    cout<<"A : ";
    A.display();
    cout<<"Copy Constuctior B : ";
    B.display();
    cout<<"Dynamic Constuctior is ";
    Eg C(1);
    return 0;
}

